def solution(n, arr1, arr2):
    answer = []
    for one, two in zip(arr1, arr2):
        arr = bin(one|two)[2:] # calc bit one or two
        zeros = ''
        for i in range(n-len(arr)):
            zeros += '0'
        arr = zeros + arr # fill with '0'
        arr = arr.replace('0', ' ')
        arr = arr.replace('1', '#')
        answer.append(arr)
    return answer

n = [5, 6]
arr1 = [[9, 20, 28, 18, 11], [46, 33, 33 ,22, 31, 50]]
arr2 = [[30, 1, 21, 17, 28], [27 ,56, 19, 14, 14, 10]]
for i, j, k in zip(n, arr1, arr2):
    print("answer is: {0}".format(solution(i, j, k)))