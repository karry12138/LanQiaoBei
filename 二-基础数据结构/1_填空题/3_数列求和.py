"""
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

给定数列 
1,1,1,3,5,9,17,⋯从第4项开始，每项都是前3项的和。

求第 20190324 项的最后 4 位数字。

运行限制

最大运行时间：1s
最大运行内存: 128M
"""

"""想法:只取最后四位"""
"""字符串索引X -> %10000"""
a,b,c=1,1,1
for i in range(4,20190325):
    new = (a+b+c)%10000
    a=b
    b=c
    c=new
print(new)