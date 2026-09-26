public class BinarySearch2D {
    public static boolean searchMatrix(int[][] matrix, int target) {
        int m=matrix.length, n=matrix[0].length;
        //we consecutively 'cut' the rows and connect them respectively into a huge
        //array of size m*n (in our head)
        int left=0, right=m*n-1;

        int mid=-1, row=-1, col=-1;
        //then perform a binary search in this imaginary array
        while (left<=right){
            mid=left+(right-left)/2;

            //here's how we identify the row and column indexes of the original matrix
            row=mid/n; col=mid%n;


            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) right=mid-1;
            else left=mid+1;
        }

        return false;
    }

    public static void main(String[] args) {
        int[][] matrix={{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
        int target=10;

        System.out.println(searchMatrix(matrix, target));
    }
}
