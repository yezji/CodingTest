#include <iostream>
#include <vector>
#include <string>
// #include <deque>
#include <queue>
#include <algorithm>
using namespace std;

/*
struct Paper {
    int index;
    int priority;

    Paper(int index, int priority) {
        this->index = index;
        this->priority = priority;
    }  
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<Paper> list;
    for (int i=0; i<priorities.size(); i++) list.emplace_back(Paper(i, priorities[i]));
    
    while (!list.empty()) {
        Paper first = list.front();
        list.pop_front();

        bool isMax = false;
        int max_value = first.priority;
        for (int i=0; i<list.size(); i++) if (max_value < list[i].priority) max_value = list[i].priority;
        if (max_value == first.priority) isMax = true;

        if (!isMax) {
            list.emplace_back(first);
        }
        else {
            answer++;
            if (first.index == location) return answer;
        }
    }
}*/

// 최적화한 답
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> printer;
    for (int i=0; i<priorities.size(); i++) printer.push(i);

    while(!printer.empty()) {
        int now_idx = printer.front();
        printer.pop();

        if (priorities[now_idx] != *max_element(priorities.begin(), priorities.end())) {
            printer.push(now_idx);
        }
        else {
            answer++;
            priorities[now_idx] = -1;
            if (now_idx == location) return answer;
        }
    }
}

int main() {
    vector<int> priorities;
    int location;
    
    location = 2;
    priorities = {2, 1, 3, 2};
    cout << solution(priorities, location) << endl;
    
    location = 0;
    priorities = {1, 1, 9, 1, 1, 1};
    cout << solution(priorities, location) << endl;

    return 0;
}