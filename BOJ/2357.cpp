#include <bits/stdc++.h>
using namespace std;
constexpr int ULIMIT = 1e5;

int N, M;
int arr[ULIMIT];
int max_seg[ULIMIT*4], min_seg[ULIMIT*4];
int UPPER_LIMIT = numeric_limits<int>::max(), LOWER_LIMIT = 0;

int init(int* tree, int left, int right, int node, bool is_max_tree) {
  if(left == right) {
    return tree[node] = arr[left];
  }

  int mid = (left + right) / 2;
  int left_val = init(tree, left, mid, node * 2, is_max_tree);
  int right_val = init(tree, mid+1, right, node * 2 + 1, is_max_tree);

  return tree[node] = is_max_tree ? max(left_val, right_val) : min(left_val, right_val);
}

int query(int left, int right, int node, int node_left, int node_right, bool is_max_tree) {
  if(left > node_right || right < node_left) return is_max_tree ? LOWER_LIMIT : UPPER_LIMIT;
  if(left <= node_left && node_right <= right) return is_max_tree ? max_seg[node] : min_seg[node];

  int mid = (node_left + node_right) / 2;
  return is_max_tree ?
    max(query(left, right, node * 2, node_left, mid, is_max_tree),
        query(left, right, node * 2 + 1, mid+1, node_right, is_max_tree)) :
    min(query(left, right, node * 2, node_left, mid, is_max_tree),
        query(left, right, node * 2 + 1, mid+1, node_right, is_max_tree));
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  init(min_seg, 0, N-1, 1, false);
  init(max_seg, 0, N-1, 1, true);

  int l, r, min_val, max_val;

  for (int i = 0; i < M; ++i) {
    cin >> l >> r;
    min_val = query(l-1, r-1, 1, 0, N-1, false);
    max_val = query(l-1, r-1, 1, 0, N-1, true);

    cout << min_val << " " <<  max_val << "\n";
  }

  return 0;
}

