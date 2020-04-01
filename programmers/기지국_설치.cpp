#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, covered = 0, r = 2*w + 1;

    for(auto s : stations) {
        int uncovered = s - w - (covered + 1);
        if (uncovered > 0) {
            answer += uncovered / r;
            if(uncovered % r) answer++;
        }
        covered = s + w;
    }
    
    if(covered < n) {
        answer += (n - covered) / r;
        if((n - covered) % r) answer++; 
    }

    return answer;
}

