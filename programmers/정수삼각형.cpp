#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cache;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    cache = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(), 0));
    cache[0][0] = triangle[0][0];
    for(int i=1; i<triangle.size(); ++i){
        for(int j=0; j<triangle[i].size(); ++j){
            if(j == 0){
                cache[i][j] = cache[i-1][j];
            } 
            else if (j == triangle[i].size() - 1){
                cache[i][j] = cache[i-1][j-1];
            }
            else {
                cache[i][j] = max(cache[i-1][j-1], cache[i-1][j]);
            }
            cache[i][j] += triangle[i][j];
        }
    }
    for(auto a : *cache.rbegin()){
        answer = max(answer, a);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout <<  solution({
        {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}
    });

    return 0;
}
