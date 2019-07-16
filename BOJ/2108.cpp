#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <unordered_map>
#include <list>
#include <iomanip>
#include <cmath>
using namespace std;

int global_max = -4001 , global_min = 4001, sum = 0, freq[8001]{0,};
vector<int> inputs;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    inputs.resize(n, 0);
    cin >> inputs[0], global_max = global_min = inputs[0], sum += inputs[0], freq[inputs[0]+4000]++;
    for(int i=1; i<n; ++i){
        cin >> inputs[i];
        sum += inputs[i];
        freq[inputs[i]+4000]++;
        if(global_max < inputs[i]) global_max = inputs[i];
        if(global_min > inputs[i]) global_min = inputs[i];
    }
    sort(inputs.begin(), inputs.end());

    int max_freq = freq[inputs[0]+4000];
    for(int i=0; i<8001; ++i){
        if(max_freq < freq[i]){
            max_freq = freq[i];
        }
    }
    vector<int> modes;
    for(int i=0; i<8001; ++i){
        if(freq[i] == max_freq){
            modes.push_back(i-4000);
        }
    }

    cout << (int)round((double)sum / (double)n) << "\n";
    cout << inputs[n/2] << "\n";
    cout << (modes.size() > 1 ? modes[1] : modes[0]) << "\n";
    cout << global_max - global_min << "\n";


    return 0;
}
