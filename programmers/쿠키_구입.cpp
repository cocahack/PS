#include <bits/stdc++.h>
using namespace std;
int sum[2001]{0,};

unordered_map<int, vector<pair<int, int>>> range_sums;

int get_sum(int start, int end) {
    return start == 0 ? sum[end] : sum[end] - sum[start-1];
    return sum[end] - sum[start];
}

int solution(vector<int> cookies) {
    int N = cookies.size(), answer = 0;
    sum[0] = cookies[0];
    for(int i=1; i<N; ++i) sum[i] = sum[i-1] + cookies[i];

    // 첫째 아들의 끝점
	for(int i=0; i<N; ++i) {
        int start1 = i, end1 = i, sum1 = get_sum(start1, end1);
        int start2 = i+1, end2 = i+1, sum2 = get_sum(start2, end2);
        
        while(start1 >=0 && end2 < N) {
            sum1 = get_sum(start1, end1);
            sum2 = get_sum(start2, end2);
            if(sum1 == sum2) {
                answer = max(answer, sum1);
                if(start1 >= 1) start1--;
                else start2++;
                continue;
            }
            
            if(sum1 < sum2) {
                start1--;
            } else {
                end2++;
            }
        }
    }
    
    return answer;
}

