def solution(d, budget):
    answer = 0
    total = 0
    for data in sorted(d):
        total += data
        if total > budget:
            return answer
        answer += 1
    return answer

d = [[1, 3, 2, 5, 4], [2, 2, 3, 3]]
budget = [9, 10]
for i, j in zip(d, budget):
    print(solution(i, j))