#include <bits/stdc++.h>
using namespace std;
int L, C;
char chars[15];
vector<string> answers;
string vowels = "aeiou";
bool check_str(string& s)
{
    int num_vowels = 0, not_vowels = 0;
    bool checked = false;
    for(char c : s){
        checked = false;
        for(char v : vowels){
            if(c == v){
                num_vowels++;
                checked = true;
            }
        }
        if(!checked) not_vowels++;
    }

    return num_vowels >= 1 && not_vowels >= 2;
}

void make_answer(string s, int last_idx)
{
    if(last_idx >= C && s.size() < L) return;
    if(s.size() == L) {
        if(check_str(s)) answers.push_back(s);
        return;
    }
    for(int i = last_idx+1; i<C; ++i){
        make_answer(s + chars[i], i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;
    for(int i=0; i<C; ++i) cin >> chars[i];

    sort(chars, chars+C);

    make_answer("", -1);

    for(string s : answers) cout << s << "\n";
    
    return 0;
}
