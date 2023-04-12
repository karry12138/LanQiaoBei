"""
本题为填空题，只需要算出结果后，在代码中
使用输出语句将所填结果输出即可。
小明对数位中含有2、0、1、9的数字很感
兴趣，在1到40 中这样的数包括
1、2、9、10至 32、39和40，共28个，
他们的和是 574，平方和是 14362。
注意，平方和是指将每个数分别平方后求和。
请问，在1到2019 中，所有这样的数的平方
和是多少？
"""
sum = 0
for i in range(1,2020):
    s = str(i)
    if "2" in s or "0" in s or "1" in s or "9" in s:
        sum+=i*i
print(sum)
result = 2658417853