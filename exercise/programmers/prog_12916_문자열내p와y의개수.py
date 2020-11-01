def solution(s):
    s = s.lower()
    return s.count('p') == s.count('y')
    
s = ["pPoooyY", "Pyy"]
for data in s:
    print("answer is: {0}".format(solution(data)))