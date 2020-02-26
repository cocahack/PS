/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    private List<List<Integer>> answer = new ArrayList<>();
    
    private void dfs(Node root, int depth) {
        if (root == null) {
            return ;
        }
        if (answer.size() == depth) {
            answer.add(new ArrayList<Integer>());
        }
        for (Node child: root.children) {
            dfs(child, depth + 1);
        }
        answer.get(depth).add(root.val);
    }
    
    public List<List<Integer>> levelOrder(Node root) {
        dfs(root, 0);
        return answer;
    }
}

