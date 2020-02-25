class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        // if (A.length == 0 || B.length == 0 || A[0].length == 0 || B[0].length == 0) {
        //     return new int[0][1];
        // }
        int row = A.length, column = B[0].length;
        int[][] resultMatrix = new int[row][column];
        
        for (int i=0; i<row; ++i) {
            for(int j=0; j<A[0].length; ++j) {
                if(A[i][j] != 0) {
                    for(int k=0; k<column; ++k) {
                        resultMatrix[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }
        
        return resultMatrix;
    }
}

