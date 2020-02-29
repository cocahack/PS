class StringIterator {
    private String compressedString;
    private int ptr;
    private int count;
    private char currentChar;
    
    public StringIterator(String compressedString) {
        this.compressedString = compressedString;
    }
    
    public char next() {
        if(!hasNext()) {
            return ' ';
        }
        setNext();
        
        count--;
        return currentChar;
    }
    
    public boolean hasNext() {
        return !(count == 0 && ptr == compressedString.length());
    }
    
    private void setNext() {
        if(count != 0 || ptr == compressedString.length()) {
            return;
        }
        
        currentChar = compressedString.charAt(ptr);
        
        int startIdx = ptr + 1, endIdx = compressedString.length();
        
        for(int idx = startIdx; idx < compressedString.length(); ++idx) {
            if(Character.isDigit(compressedString.charAt(idx))) {
                continue;
            } else {
                endIdx = idx;
                break;
            }
        }
        count = Integer.parseInt(compressedString.substring(startIdx, endIdx));
        ptr = endIdx;
    }
}

