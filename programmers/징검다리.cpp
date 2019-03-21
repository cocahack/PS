#include <bits/stdc++.h>
using namespace std;

bool is_possible(int distance, vector<int> rocks, int n, int min_dist)
{
    int gap, last = -1, erased = 0;
    for(int i=0; i <= rocks.size(); ++i){
        gap = ( last == -1 ? rocks[i] :
                ( i == rocks.size() ? distance - rocks.back() : rocks[i] - rocks[last] ) );
        if(gap < min_dist){
            erased++;
        } else {
            last = i;
        }
    }

    return erased <= n;
}

int solution(int distance, vector<int> rocks, int n) {
    int lo = 0, hi = distance, mid;
    sort(rocks.begin(), rocks.end());

    while(lo + 1 < hi){
        mid = (lo + hi) / 2;
        if(is_possible(distance, rocks, n, mid)){
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return is_possible(distance, rocks, n, lo) ? lo : hi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solution(25,
                     {2, 14, 11, 21, 17},
                     2);

    return 0;
}
