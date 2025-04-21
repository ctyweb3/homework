import os
import sys
import pandas as pd
import mysql.connector
from mysql.connector import Error
from dotenv import load_dotenv
import numpy as np

def create_connection():
    """创建到MySQL数据库的连接"""
    load_dotenv()
    
    try:
        # 先尝试连接到服务器，无需数据库名
        connection = mysql.connector.connect(
            host=os.getenv('DB_HOST'),
            user=os.getenv('DB_USER'),
            password=os.getenv('DB_PASSWORD')
        )
        
        if connection.is_connected():
            print("成功连接到MySQL服务器")
            return connection
    except Error as e:
        print(f"连接MySQL数据库时出错: {e}")
        return None

def create_database(connection):
    """创建数据库和表结构"""
    try:
        cursor = connection.cursor()
        db_name = os.getenv('DB_NAME')
        
        # 创建数据库（如果不存在）
        cursor.execute(f"CREATE DATABASE IF NOT EXISTS `{db_name}`")
        cursor.execute(f"USE `{db_name}`")
        
        connection.commit()
        print(f"数据库 '{db_name}' 创建或选择成功")
    except Error as e:
        print(f"创建数据库时出错: {e}")

def import_data_from_xlsx(connection):
    """从xlsx文件导入数据到MySQL"""
    try:
        # 读取xlsx文件
        xlsx_path = os.getenv('XLSX_FILE_PATH')
        if not os.path.exists(xlsx_path):
            print(f"文件不存在: {xlsx_path}")
            return
        
        df = pd.read_excel(xlsx_path)
        
        # 显示数据结构
        print(f"Excel文件包含 {len(df)} 行数据和以下列:")
        print(df.columns.tolist())
        
        cursor = connection.cursor()
        
        # 使用数据库
        cursor.execute(f"USE `{os.getenv('DB_NAME')}`")
        
        # 动态根据DataFrame列创建表
        columns = df.columns.tolist()
        column_definitions = []
        
        # 检查列名中的特殊字符
        column_map = {}
        for i, col in enumerate(columns):
            safe_col = f"column_{i}" if not col.isalnum() else col
            column_map[col] = safe_col
        
        for col in columns:
            safe_col = column_map[col]
            dtype = df[col].dtype
            
            # 确定MySQL列类型
            if pd.api.types.is_integer_dtype(dtype):
                column_definitions.append(f"`{safe_col}` INT")
            elif pd.api.types.is_float_dtype(dtype):
                column_definitions.append(f"`{safe_col}` FLOAT")
            elif pd.api.types.is_datetime64_dtype(dtype):
                column_definitions.append(f"`{safe_col}` DATETIME")
            else:
                # 检查文本列的最大长度
                max_length = df[col].astype(str).str.len().max()
                if max_length <= 255:
                    column_definitions.append(f"`{safe_col}` VARCHAR(255)")
                else:
                    column_definitions.append(f"`{safe_col}` TEXT")
        
        # 删除旧表并创建新表
        table_name = "xlsx_data"
        cursor.execute(f"DROP TABLE IF EXISTS `{table_name}`")
        create_table_query = f'''
        CREATE TABLE `{table_name}` (
            id INT AUTO_INCREMENT PRIMARY KEY,
            {', '.join(column_definitions)}
        )
        '''
        cursor.execute(create_table_query)
        
        # 插入数据
        # 防止批量插入过多数据导致的问题
        batch_size = 100
        total_rows = len(df)
        
        for start_idx in range(0, total_rows, batch_size):
            end_idx = min(start_idx + batch_size, total_rows)
            batch_df = df.iloc[start_idx:end_idx]
            
            for _, row in batch_df.iterrows():
                # 动态构建SQL插入语句
                safe_columns = [column_map[col] for col in columns]
                placeholders = ', '.join(['%s'] * len(columns))
                columns_str = ', '.join([f"`{col}`" for col in safe_columns])
                
                insert_query = f"INSERT INTO `{table_name}` ({columns_str}) VALUES ({placeholders})"
                
                # 获取行数据并处理特殊类型
                values = []
                for col in columns:
                    val = row[col]
                    # 处理NaN值
                    if pd.isna(val):
                        values.append(None)
                    # 处理numpy类型
                    elif isinstance(val, (np.int_, np.float_)):
                        values.append(val.item())
                    else:
                        values.append(val)
                
                cursor.execute(insert_query, values)
            
            connection.commit()
            print(f"成功导入批次 {start_idx//batch_size + 1}/{(total_rows+batch_size-1)//batch_size}, "
                  f"进度: {min(end_idx, total_rows)}/{total_rows} 行")
        
        print(f"成功将所有 {total_rows} 行数据导入到MySQL数据库")
        
        # 显示一些表统计信息
        cursor.execute(f"SELECT COUNT(*) FROM `{table_name}`")
        count = cursor.fetchone()[0]
        print(f"表 '{table_name}' 中的记录数: {count}")
        
    except Error as e:
        print(f"导入数据时出错: {e}")
    except Exception as e:
        print(f"处理Excel文件时出错: {e}")
        import traceback
        print(traceback.format_exc())

def main():
    """主函数"""
    # 创建数据库连接
    connection = create_connection()
    if not connection:
        sys.exit(1)
    
    # 创建数据库
    create_database(connection)
    
    # 导入数据
    import_data_from_xlsx(connection)
    
    # 关闭连接
    if connection.is_connected():
        connection.close()
        print("MySQL连接已关闭")

if __name__ == "__main__":
    main() 