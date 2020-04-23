#include <bits/stdc++.h>

using namespace std;

class Compare
{
public:
    bool operator() (const vector<int>& lhs, const vector<int>& rhs) const
    {
        if(lhs[1] != rhs[1]) return lhs[1] > rhs[1];
        return lhs[0] > rhs[0];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    int idx = 0, time = 0;
    priority_queue<vector<int>, deque<vector<int>>, Compare> q;
    q.push(jobs[idx++]);

    while(q.size()) {
        auto job = q.top();
        q.pop();

        if(job[0] <= time) {
            time += job[1];
            answer += time - job[0];
        } else {
            time = job[0] + job[1];
            answer += job[1];
        }

        while(idx < jobs.size()) {
            if(jobs[idx][0] <= time) {
                q.push(jobs[idx++]);
            } else {
                break;
            }
        }
        
        if(q.empty()) {
            if(idx < jobs.size()) {
                q.push(jobs[idx++]);
            }
        }
    }

    return answer / jobs.size();
}

