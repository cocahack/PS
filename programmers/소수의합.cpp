#include <iostream>

using namespace std;
constexpr int MAX = 10000000;
bool sieve[MAX+1] {0,};

long long solution(int N) {
    long long answer = 0;

    for(int i = 2; i * i<= N; ++i) {
        int j = 2, num = i * j;
        if(sieve[i]) continue;
        while (num <= N) {
            sieve[num] = true;
            ++j;
            num = i * j;
        }
    }

    sieve[2] = false;

    for(int i=2; i <= N; ++i){
        answer += (sieve[i] ? 0 : i);
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solution(11) << "\n";

    return 0;
}
