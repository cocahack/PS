#include <utility>
#include <unordered_map>
using namespace std;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<pair<int, int>, pair_hash> p;
        for(auto pp : points) {
            p.insert(make_pair(pp[0], pp[1]));
        }
        
        const int INF = 40000 * 40000 + 1;
        int answer = INF;
        for(int i=0; i<points.size(); ++i) {
            for(int j=i+1; j<points.size(); ++j) {
                auto point1 = p.find(make_pair(points[i][0], points[j][1]));
                auto point2 = p.find(make_pair(points[j][0], points[i][1]));
                if(point1 == p.end() || point2 == p.end() || points[i][0] == points[j][0] || points[i][1] == points[j][1]) {
                    continue;
                }
                answer = min(answer, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
        }
        
        return answer == INF ? 0 : answer;
    }
};
