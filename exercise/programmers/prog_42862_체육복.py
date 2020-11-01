def solution(n, lost, reserve):
    answer = n
    clothes = [1 for i in range(n+2)] # extra space for -1 at both ends
    clothes[0] = -1
    clothes[n+1] = -1

    for idx in reserve:
        clothes[idx] += 1
    for idx in lost:
        clothes[idx] -= 1

    for idx in range(1, n+1):
        if clothes[idx] >= 1: # if not losted
            continue
        if clothes[idx-1] > 1: # # check [idx-1] have extra
            clothes[idx-1] -= 1
            clothes[idx] += 1
        elif clothes[idx+1] > 1: # check [idx+1] have extra
            clothes[idx+1] -= 1
            clothes[idx] += 1
        if clothes[idx] == 0:
            answer -= 1
    return answer

n = [5, 5, 3, 3]
lost = [[2, 4], [2, 4], [3], [1, 2, 3]]
reserve = [[1, 3, 5], [3], [1], [2, 3]]
for i, j, k in zip(n, lost, reserve):
    print("testcase: {0}".format(solution(i, j, k)))