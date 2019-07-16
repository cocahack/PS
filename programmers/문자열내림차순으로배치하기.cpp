#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), [](const char& a, const char& b) { return a > b;});
    return s;
}
