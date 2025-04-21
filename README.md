# Excel到MySQL数据导入工具

此工具用于将Excel (xlsx)文件数据导入到MySQL数据库。程序会自动识别Excel文件的列结构，并创建相应的数据库表。

## 功能特点

- 自动读取Excel文件数据
- 动态创建匹配Excel结构的数据库表
- 支持各种数据类型（整数、浮点数、文本等）
- 批量导入数据

## 安装依赖

```bash
pip install -r requirements.txt
```

## 配置

编辑`.env`文件设置数据库连接参数：

```
DB_HOST=localhost     # 数据库主机名
DB_USER=root          # 数据库用户名
DB_PASSWORD=password  # 数据库密码
DB_NAME=xlsx_data     # 数据库名
XLSX_FILE_PATH=data.xlsx  # Excel文件路径
```

## 使用方法

1. 将您的Excel文件放在项目目录下，并在`.env`文件中更新`XLSX_FILE_PATH`
2. 运行程序：

```bash
python xlsx_to_mysql.py
```

## 注意事项

- 确保MySQL服务正在运行
- Excel文件中的列名将作为数据库表的字段名
- 程序会自动根据Excel的数据类型选择合适的数据库字段类型
- 如果表已存在，将会被删除并重新创建 