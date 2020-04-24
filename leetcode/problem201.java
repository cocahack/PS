class Solution {
    private void makeBits(int num, int[] bits) {
        for(int i=0; i<32; ++i) bits[i] = 0;
        int idx = 31;
        while(num>0) {
            bits[idx--] = num % 2;
            num /= 2;
        }
        
        
    }
    
    private int makeInt(int[] bits) {
        int ret = 0, base = 1;
        for(int i=31; i>=0; --i) {
            ret += base * bits[i];
            base *= 2;
        }
        return ret;
    }
    
    public int rangeBitwiseAnd(int m, int n) {
        int[] mBits = new int[32];
        int[] nBits = new int[32];
        
        makeBits(m, mBits);
        makeBits(n, nBits);
        
        int changeStart = -1, changeEnd = -1;
        
        for(int i=0; i<32; ++i) {
            if(mBits[i] != nBits[i]) {
                if(changeStart == -1) {
                    changeStart = i;
                    break;
                } 
            }
        }
        
        if(changeStart == -1) return m;
        
        
        for(int i=changeStart; i < 32; ++i) {
            nBits[i] = 0;
        }
        
        return makeInt(nBits);
    }
}

