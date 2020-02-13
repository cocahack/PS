class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int, int>> q;
        int N = wordList.size();
        
        vector<bool> visited(N+1, false);
        
        for(int i=0; i<N; ++i) if(beginWord == wordList[i]) {
            q.push({i, 1});
            break;
        }
        
        if(q.empty()){
            wordList.push_back(beginWord);
            q.push({N, 1});
            ++N;
            
        }
        
        while(q.size()) {
            auto node = q.front();
            q.pop();
            
            string& curr_word = wordList[node.first];
            int count = node.second;
            cout << curr_word << " " << count << "\n";
            if(curr_word == endWord) {
                return count;
            }
            
            if(visited[node.first]) continue;
            visited[node.first] = true;
            
            for(int i=0; i<N; ++i) {
                int diff_count = 0;
                for(int j=0; j<curr_word.size(); ++j) {
                    if (curr_word[j] != wordList[i][j]) diff_count++;
                }
                
                if (diff_count == 1 && !visited[i]) {
                    q.push({i, count+1});
                }
            }
            
        }
        
        return 0;
    }
};
