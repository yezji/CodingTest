def solution(x):
    origin = x
    value = 0
    while (x > 0): # sum each digit
        value += x % 10
        x = x // 10
    return origin % value == 0

x = [18, 10, 12, 11, 13]
for data in x:
    print(solution(data))