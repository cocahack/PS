class Solution {
    public int findLonelyPixel(char[][] picture) {
        if(picture.length == 0) {
            return 0;
        }
        int row = picture.length;
        int col = picture[0].length;
        
        int rowCount[] = new int[row];
        int colCount[] = new int[col];
        
        for(int i=0; i<row; ++i) {
            for(int j=0; j<col; ++j) {
                if(picture[i][j] == 'B') {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int answer = 0;
        
        for(int i=0; i<row; ++i) {
            if(rowCount[i] == 1) {
                for(int j=0; j<col; ++j) {
                    if(picture[i][j] == 'B') {
                        answer += (colCount[j] == 1 ? 1 : 0);
                    }
                }
            }
        }
        
        return answer;
    }
}

