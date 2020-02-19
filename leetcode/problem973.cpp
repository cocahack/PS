int diagonal_distance(const vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1];
}

bool comp(const vector<int>& lhs, const vector<int>& rhs) {
    if(diagonal_distance(lhs) != diagonal_distance(rhs))
        return diagonal_distance(lhs) < diagonal_distance(rhs);
    return true;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
