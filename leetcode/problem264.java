class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Integer> pQueue = new PriorityQueue<>();
        Set<Integer> checked = new HashSet<>();
        int count = 1;
        pQueue.add(1);
        checked.add(1);

        long[] factors = {2l,3l,5l};
        while(count < n) {
            int cur = pQueue.poll();
            count++;
            for(long factor : factors) {
                long next = (long) cur * factor;
                if (next > Integer.MAX_VALUE) {
                    break;
                }

                int safeNext = (int) next;
                if(!checked.contains(safeNext)) {
                    pQueue.add(safeNext);
                    checked.add(safeNext);
                }
            }
        }
        return pQueue.poll();
    }
}

