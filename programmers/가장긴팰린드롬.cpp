#include <bits/stdc++.h>
using namespace std;
int cache[2501][2501]{0,};

int solution(string s)
{
    memset(cache, 0, sizeof cache)   ;

    int answer = 0;
    for(int len = 0; len < s.size(); ++len){
        for(int i = 0; i < s.size() - len ; ++i){
            int j = i + len;
            if(i == j) cache[i][j] = 1;
            else if(i + 1 == j) cache[i][j] = s[i] == s[j] ? 2 : 0;
            else if(s[i] != s[j]) cache[i][j] = 0;
            else cache[i][j] = (cache[i+1][j-1] ? cache[i+1][j-1] + 2 : 0);

            answer = max(answer, cache[i][j]);
        }
    }

    return answer;
}
