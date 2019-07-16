#include <bits/stdc++.h>

using namespace std;
int width, height;
vector<string> solve(vector<string> crossword, vector<string> words, int y, int x)
{
    //if(y==height && w == width) return crossword;
    
    int start_x, start_y, end_x, end_y, i, j;
    bool find_start = false;
    
    for(int i=y; i<height; ++i){
        for(int j=x; j<width; ++j){
            if(crossword[i][j] == '-'){start_y = i; start_x = j; find_start = true; break;}
        }
        if(find_start) break;
    }
    
    if(i==height && j == width && !find_start) return crossword;
    
    int len = 0;
    if(crossword[start_y+1][start_x]=='-'){
        int dy = 1, dx = 0, s_x = start_x, s_y = start_y;
        while(1){
            if(crossword[s_y+dy][s_x+dx]!='-') break;
            len++;
            s_x += dx;
            s_y += dy;
        }
    }
}

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    width = crossword[0].size();
    height = crossword.size();
    vector<string> w;
    string tmp = "";
    for(char c : words){
        if(c!=';'){
            tmp += c;
        }else{
            w.push_back(tmp);
            tmp = "";
        }
    }

}
