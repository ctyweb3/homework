import pandas as pd
import numpy as np

# 创建样本数据
data = {
    '姓名': ['张三', '李四', '王五', '赵六', '钱七'],
    '年龄': [25, 30, 35, 40, 45],
    '电话': ['13800138000', '13900139000', '13700137000', '13600136000', '13500135000'],
    '邮箱': ['zhangsan@example.com', 'lisi@example.com', 'wangwu@example.com', 
            'zhaoliu@example.com', 'qianqi@example.com'],
    '地址': ['北京市海淀区', '上海市浦东新区', '广州市天河区', '深圳市南山区', '杭州市西湖区'],
    '入职日期': pd.date_range(start='2020-01-01', periods=5),
    '薪资': [10000.50, 15000.75, 20000.25, 25000.00, 30000.80]
}

# 创建DataFrame
df = pd.DataFrame(data)

# 保存为Excel文件
df.to_excel('data.xlsx', index=False)

print('示例Excel文件已创建: data.xlsx') 