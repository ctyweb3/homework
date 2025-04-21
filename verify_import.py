import os
import pandas as pd
import mysql.connector
from mysql.connector import Error
from dotenv import load_dotenv
from tabulate import tabulate

def verify_import():
    """验证Excel数据是否成功导入MySQL"""
    load_dotenv()
    
    try:
        # 连接到MySQL数据库
        connection = mysql.connector.connect(
            host=os.getenv('DB_HOST'),
            user=os.getenv('DB_USER'),
            password=os.getenv('DB_PASSWORD'),
            database=os.getenv('DB_NAME')
        )
        
        if connection.is_connected():
            print("成功连接到MySQL数据库")
            
            cursor = connection.cursor(dictionary=True)
            
            # 获取表的数据
            table_name = "xlsx_data"
            cursor.execute(f"SELECT * FROM `{table_name}` LIMIT 10")
            rows = cursor.fetchall()
            
            if rows:
                print("\n数据库中的前10条记录:")
                print(tabulate(rows, headers="keys", tablefmt="pretty"))
                
                # 获取总记录数
                cursor.execute(f"SELECT COUNT(*) as count FROM `{table_name}`")
                count = cursor.fetchone()['count']
                print(f"\n数据库表 '{table_name}' 中共有 {count} 条记录")
                
                # 获取Excel文件中的数据进行比较
                xlsx_path = os.getenv('XLSX_FILE_PATH')
                if os.path.exists(xlsx_path):
                    df = pd.read_excel(xlsx_path)
                    print(f"\nExcel文件 '{xlsx_path}' 中共有 {len(df)} 行数据")
                    
                    # 判断记录数是否匹配
                    if count == len(df):
                        print("\n✅ 验证成功: 数据库中的记录数与Excel文件中的行数一致")
                    else:
                        print("\n❌ 验证失败: 数据库中的记录数与Excel文件中的行数不一致")
            else:
                print("数据库表中没有数据")
        
        # 关闭连接
        if connection.is_connected():
            cursor.close()
            connection.close()
            print("\nMySQL连接已关闭")
            
    except Error as e:
        print(f"验证过程中出错: {e}")

if __name__ == "__main__":
    verify_import() 