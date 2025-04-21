import pandas as pd
import pymysql
import os
from sqlalchemy import create_engine

# MySQL数据库连接信息
DB_HOST = 'localhost'
DB_USER = 'root'  # 请修改为您的数据库用户名
DB_PASSWORD = '112358'  # 请修改为您的数据库密码
DB_NAME = 'student_db'
DB_PORT = 3306

# 创建数据库连接
def create_database():
    # 连接到MySQL服务器
    conn = pymysql.connect(
        host=DB_HOST,
        user=DB_USER,
        password=DB_PASSWORD,
        port=DB_PORT
    )
    cursor = conn.cursor()
    
    # 创建数据库（如果不存在）
    cursor.execute(f"CREATE DATABASE IF NOT EXISTS {DB_NAME} DEFAULT CHARACTER SET utf8mb4")
    
    # 关闭连接
    cursor.close()
    conn.close()
    
    print(f"数据库 '{DB_NAME}' 已创建或已存在")

# 创建表
def create_tables():
    # 连接到指定数据库
    conn = pymysql.connect(
        host=DB_HOST,
        user=DB_USER,
        password=DB_PASSWORD,
        database=DB_NAME,
        port=DB_PORT
    )
    cursor = conn.cursor()
    
    # 创建学生表
    cursor.execute("""
    CREATE TABLE IF NOT EXISTS students (
        id INT AUTO_INCREMENT PRIMARY KEY,
        student_id VARCHAR(20) UNIQUE NOT NULL,
        name VARCHAR(100) NOT NULL,
        class_name VARCHAR(100) NOT NULL,
        source_file VARCHAR(100) NOT NULL
    )
    """)
    
    # 提交更改并关闭连接
    conn.commit()
    cursor.close()
    conn.close()
    
    print("表已创建")

# 导入Excel数据到MySQL
def import_excel_to_mysql(file_path):
    # 读取Excel文件
    df = pd.read_excel(file_path)
    
    # 提取文件名（不含扩展名）作为来源标识
    file_name = os.path.basename(file_path)
    
    # 重命名列
    # 假设Excel表格的列是这样的顺序：序号、学号、姓名、班级
    df.columns = ['index', 'student_id', 'name', 'class_name']
    
    # 如果第一行是标题行且被错误读取为数据，则删除
    if isinstance(df.iloc[0, 0], int) and df.iloc[0, 0] == 1:
        df = df.iloc[1:].reset_index(drop=True)
    
    # 添加来源文件列
    df['source_file'] = file_name
    
    # 只保留需要的列
    df = df[['student_id', 'name', 'class_name', 'source_file']]
    
    # 连接到数据库
    engine = create_engine(f'mysql+pymysql://{DB_USER}:{DB_PASSWORD}@{DB_HOST}:{DB_PORT}/{DB_NAME}?charset=utf8mb4')
    
    # 将DataFrame导入到MySQL
    df.to_sql('students', engine, if_exists='append', index=False)
    
    print(f"成功导入 {len(df)} 条记录，来自文件 {file_name}")

# 主函数
def main():
    # 创建数据库和表
    create_database()
    create_tables()
    
    # 导入Excel文件
    files_to_import = ['24级1班.xlsx', '24级2班.xlsx']
    
    for file in files_to_import:
        import_excel_to_mysql(file)
    
    print("所有数据导入完成")

if __name__ == '__main__':
    main()