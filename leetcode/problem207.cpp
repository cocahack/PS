
class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> order;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses, vector<int>());
        
        for(auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        
        
        visited = vector<bool>(numCourses, false);
    
        for(int i=0; i<numCourses; ++i) {
            if(!visited[i]) {
                dfs(i);
            }
        }
        
        reverse(order.begin(), order.end());
        
        for(int i=0; i<order.size(); ++i){
            for (int j=i+1; j<order.size(); ++j) {
                for(auto there: graph[order[j]]){
                    if(there == order[i]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    void dfs(int here) {
        visited[here] = true;
        for(auto there: graph[here]) {
            if (!visited[there]) {
                dfs(there);
            }
        }
    
        order.push_back(here);
    }
};
