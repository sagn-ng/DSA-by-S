package binary_tree;
public class Fenwick {
    private int[] tree;
    private int trueLength;

    Fenwick(int sz){
        if (sz<=0) throw new IllegalArgumentException("The given size must be greater than 0!");
        else{
            trueLength=sz;
            tree=new int[trueLength+1];
        }
    } //create an empty "tree" array with given size

    Fenwick(int[] arr){
        if (arr==null || arr.length==0){
            throw new IllegalArgumentException("Input array must not be null or empty!");
        }
        trueLength=arr.length;
        tree=new int[trueLength+1];
        for (int i=1; i<=trueLength; i++){
            tree[i]=arr[i-1];
        }
        /*make a tree as a copy of "arr" but with 1-based indexing
        as fenwick tree doesn't work with 0-based*/

        for (int i=1; i<=trueLength; i++){
            int j=i + (i & (-i)); //find the "parent" index
            if (j<=trueLength) tree[j]+=tree[i]; //add the value of a child node to its parent
        }
    } //create a full "tree" array (from another given array)

    public int getSize(){
        return this.trueLength;
    }

    public int getOriginVal(int idx){
        if (idx<0 || idx>=trueLength){
            throw new IndexOutOfBoundsException("index "+idx+" out of bound");
        }
        return rangeSum(idx, idx);
    } //get arr[i]

    public int prefixSum(int i){
        if (i<0 || i>=trueLength){
            throw new IndexOutOfBoundsException("index "+i+" out of bound");
        }
        i++; //convert to 1-based indexing
        int sum=0;
        while (i>0){
            sum+=tree[i];
            i -= (i & (-i));
        }
        return sum;
    } //sum of elements with indices in the interval [0, i] of the input array

    public int rangeSum(int left, int right){
        if (left<0 || left>=trueLength){
            throw new IndexOutOfBoundsException("Left index "+left+" out of bounds for length "+trueLength);
        }
        if (right<0 || right>=trueLength){
            throw new IndexOutOfBoundsException("Right index "+right+" out of bounds for length "+trueLength);
        }
        if (left>right){
            throw new IllegalArgumentException("Left index must be <= Right index");
        }
        return prefixSum(right) - (left==0 ? 0 : prefixSum(left-1));
    } //sum of elements with indices in the interval [left, right] of the input array
    
    public void pointUpdate(int idx, int x){
        if (idx<0 || idx>=trueLength){
            throw new IndexOutOfBoundsException("valid index (indices) for 0-based input array");
        }
        else{
            int i=idx+1;
            while (i<=trueLength){
                this.tree[i]+=x;
                i += (i & (-i));
            }
        }
    } /*idx is an index of the input array (0-based),
    so we need to add 1 to fit with our fenwick array, which is 1-based*/

    public void set(int idx, int k){
        int val=rangeSum(idx, idx); //get the value at index "idx" of the input array
        pointUpdate(idx, k-val); //obviously: val + (k - val) = k
    }
}

class FenwickTest {
    public static void main(String[] args) {
        int[] arr={1,4,5,6,7,8,9,4,5};
        Fenwick myTree=new Fenwick(arr);
        System.out.println(myTree.prefixSum(3)); //sum of elements from index 0 to 3 of arr

        System.out.println(myTree.rangeSum(0, 4)); //sum of elements with indices in [0, 4] of arr
    }
}