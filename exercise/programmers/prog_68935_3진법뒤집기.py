def solution(n):
    answer = 0
    expo = 0
    three = ''
    while n > 0:
        three += str(n%3)
        n //= 3 # decimal round off (* '/' result is float type)
    for data in reversed(three):
        answer += int(data) * (3 ** expo)
        expo += 1
    return answer

n = [1, 45, 125]
for data in n:
    print("answer is: {0}".format(solution(data)))