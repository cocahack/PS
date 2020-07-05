class Solution {
    public int hammingDistance(int x, int y) {
        int target = x ^ y;
        int count = 0;
        while(target > 0) {
            count += target & 1;
            target >>= 1;
        }
        return count;
    }
}

