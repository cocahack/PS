#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int ULIMIT = 1e6;
constexpr int MOD = 1e9 + 7;

ll f[3001]{0,};
string words[3001];

ll mod_mul(ll left, ll right) {
    return ((left % MOD) * (right % MOD)) % MOD;
}

class Trie {
public:
    Trie* children[26]{nullptr,};
    int nums[26]{0,};
    bool is_end = false;
    Trie()= default;
    ~Trie() {
        for (auto &i : children) delete i;
    }

    void insert(int left, int right, int idx) {
        for(int i = left; i < right;) {
            if(words[i].size() == idx) {
                i++;
                is_end = true;
                continue;
            }
            char target;
            if(i == right - 1 || words[i][idx] != words[i+1][idx] ) {
                int ci = words[i][idx] - 'A';
                nums[ci]++;
                i++;
                continue;
            } else {
                target = words[i][idx];
            }
            int j;
            for(j = i + 2; j < right; ++j) {
                if(words[j][idx] != target) break;
            }

            int ci = target - 'A';
            if(children[ci] == nullptr) {
                children[ci] = new Trie();
            }
            nums[ci] = j - i;
            children[ci]->insert(i, j, idx + 1);
            i = j;
        }
    }

};

ll get_cases(Trie* node) {
    int chunks = 0;
    if(node->is_end) chunks++;

    ll tot = 1ll;
    for (int i=0; i<26; ++i){
        if(node->nums[i] > 1) tot = mod_mul(tot, get_cases(node->children[i]));
        if(node->nums[i]) chunks++;
    }
    return mod_mul(tot, f[chunks]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string s;
    cin >> N;

    f[0] = 1;
    for(int i=1; i<=N; ++i) {
        cin >> words[i-1];
        f[i] = mod_mul(f[i-1], i);
    }
    sort(words, words+N);

    Trie root = Trie();
    root.insert(0, N, 0);

    cout << get_cases(&root) % MOD;

    return 0;
}

