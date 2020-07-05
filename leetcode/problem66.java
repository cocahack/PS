iclass Solution {
    public int[] plusOne(int[] digits) {
        boolean carrying = true;
        for(int i = digits.length - 1; i >= 0; i--) {
            if(carrying) {
                digits[i]++;
                carrying = false;
                if(digits[i] == 10) {
                    digits[i] = 0;
                    carrying = true;
                } 
            } else {
                break;
            }
        }
        
        if(!carrying) {
            return digits;
        }
    
        int len = digits.length + 1;
        int[] ret = new int[len];
        ret[0] = 1;
        
        for(int i = 1; i < len; ++i) {
            ret[i] = digits[i-1];
        }
        
        return ret;
    }
}

