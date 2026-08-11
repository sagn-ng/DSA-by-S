package binary_tree;

public class FenwickTest {
    public static void main(String[] args) {
        int[] arr={1,4,5,6,7,8,9,4,5};
        Fenwick myTree=new Fenwick(arr);
        System.out.println(myTree.prefixSum(3)); //sum of elements from index 0 to 3 of arr

        System.out.println(myTree.rangeSum(0, 4)); //sum of elements with indices in [0, 4] of arr
    }
}
