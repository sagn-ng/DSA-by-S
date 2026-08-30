import java.util.ArrayList;
import java.util.List;

class NQueens {
    private boolean safeSquare(int[][] board, int row, int col, int n){
        int i, j, k;

        for (i=0; i<row; i++){
            if (board[i][col]==1) return false;
        }

        for (i=row-1, j=col-1, k=col+1; i>=0; i--){
            if (j>=0){
                if (board[i][j]==1) return false;
                j--;
            }
            
            if (k<n){
                if (board[i][k]==1) return false;
                k++;
            }
        }

        return true;
    }

    private void placeQueens(List<List<String>> result, int[][] board, int row, int n){
        if (row==n){
            List<String> curBoard=new ArrayList<>();
            char[] curRow;
            int idx;
            for (int i=0; i<n; i++){
                curRow=new char[n];
                idx=0;
                for (int j=0; j<n; j++){

                    if (board[i][j]==1) curRow[idx++]='Q';
                    else curRow[idx++]='.';
                }

                curBoard.add(new String(curRow));
            }

            result.add(curBoard);

            return;
        }

        for (int i=0; i<n; i++){
            if (safeSquare(board, row, i, n)){
                board[row][i]=1;
                placeQueens(result, board, row+1, n);
            }

            board[row][i]=0;
        }
    }

    public List<List<String>> solveNQueens(int n) {
        int[][] board=new int[n][n];
        List<List<String>> result=new ArrayList<>();

        placeQueens(result, board, 0, n);

        return result;
    }
}