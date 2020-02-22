/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return numeric_limits<int>::max();
        }
        if (root->left == nullptr && root->right == nullptr) {
            return depth;
        }
        
        return min(dfs(root->left, depth+1), dfs(root->right, depth+1));
    }
public:
    int minDepth(TreeNode* root) {
        int answer = dfs(root, 1);
        return answer == numeric_limits<int>::max() ? 0 : answer;
    }
};
