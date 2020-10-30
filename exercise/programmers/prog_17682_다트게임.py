def solution(dartResult):
    answer = 0
    scores = ["", "", ""]
    idx = 0
    for i in range(len(dartResult)):
        if dartResult[i] == "S":
            idx+=1
        elif dartResult[i] == "D":
            scores[idx] = int(scores[idx])**2
            idx+=1
        elif dartResult[i] == "T":
            scores[idx] = int(scores[idx])**3
            idx+=1
        elif dartResult[i] == "*":
            scores[idx-1] = int(scores[idx-1])*2
            if idx-2 >= 0:
                scores[idx-2] = int(scores[idx-2])*2
        elif dartResult[i] == "#":
            scores[idx-1] = int(scores[idx-1])*-1
        else: # "0"~"10"일 때 처리
           scores[idx] += dartResult[i] # 문자열로 "10" 처리
    for data in scores:
        answer += int(data)
    return answer

dartResults = ["1S2D*3T", "1D2S#10S", "1D2S0T", "1S*2T*3S", "1D#2S*3S", "1T2D3D#", "1D2S3T*"]
for data in dartResults:
    print("answer is: {0}".format(solution(data)))