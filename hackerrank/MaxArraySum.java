import java.util.Arrays;

public class MaxArraySum {

    public static class Solution {

        /**
         * 풀이 방법 cache[i] 를 0부터 i 까지의 부분 배열에서, 문제의 조건(인접하지 않는 요소들의 합의 최댓값)을 만족하는 최댓값으로 정의한다.
         * see also. (Hackerrank Editorial)
         * <code>
         * int dp[100005];
         *
         * int maxSubsetSum(vector<int> arr) {
         *
         *     dp[0]=max(0,arr[0]);
         *     if(arr.size()==1)
         *         return dp[0];
         *     for(int i=1;i<arr.size();i++)
         *     {
         *         dp[i]=max(dp[i-2],max(dp[i-1],dp[i-2]+arr[i]));
         *     }
         *     int n=arr.size();
         *     return max(dp[n-1],dp[n-2]);
         * }
         * </code>
         */
        static int maxSubsetSum(int[] arr) {
            if (arr.length == 1) {
                return Math.max(arr[0], 0);
            }
            int[] cache = Arrays.copyOf(arr, arr.length);

            int ret = Math.max(arr[0], arr[1]);
            cache[1] = Math.max(cache[0], cache[1]);

            for (int i = 2; i < arr.length; i++) {
                cache[i] = Math.max(cache[i-2] + arr[i], cache[i]);
                cache[i] = Math.max(cache[i], cache[i-2]);
                cache[i] = Math.max(cache[i], cache[i-1]);
                ret = Math.max(ret, cache[i]);
            }

            return Math.max(ret, 0);
        }

    }

}

