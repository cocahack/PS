#include<bits/stdc++.h>
using namespace std;
bool reach[101][101] {0, };
int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (int i = 0; i < n; i++){
        reach[i][i] = true;
    }

    for(int i = 0; i < results.size(); ++i){
        reach[results[i][0]-1][results[i][1]-1] = true;
    }

    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i){
        bool good = true;
        for (int j = 0; j < n; ++j){
            if (!reach[i][j] && !reach[j][i]){
                good = false;
                break;
            }
        }
        answer += good ? 1 : 0;
    }
    return answer;
}
