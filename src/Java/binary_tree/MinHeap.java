package binary_tree;
public class MinHeap {
    //we allow duplicates here
    private int capacity;
    public int[] heapArray; //we take the array as 0-based indexed
    public int currentSize;
    //we can use an ArrayList of Integer objects,
    //so that we don't have to worry about "capacity", "currentSize",
    // and in the insertKey method, a boolean return value isn't required.
    //but i would prefer a normal array as i want to build it all myself=))
    public MinHeap(int n){
        capacity=n;
        currentSize=0;
    }

    public MinHeap(int[] arr){
        capacity=1000;
        heapArray=new int[capacity];
        currentSize=0;
        for (int i: arr) insert(i);
    }

    private void swap(int[] arr, int i, int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    private int parent(int key){return (key-1)/2;}
    private int left(int key){return 2*key+1;}
    private int right(int key){return 2*key+2;}

    public int getMin(){
        return heapArray[0];
    } //only return the root key, not delete it

    public int extractMin(){
        if (currentSize<=0) return Integer.MAX_VALUE;

        /*make the root's value be the "last", as we reduce the size of heapArray,
        then sift-down with the new root's value:*/
        int root=heapArray[0];
        heapArray[0]=heapArray[currentSize-1];
        currentSize--;

        MinHeapify(0);
        return root;
    } //we can just return void but (maybe) for convenience in the future

    private void MinHeapify(int key){
        //given that key's left and right subtree satisfy the Heap Invariant
        int l=left(key), r=right(key);
        int smallest=key;

        //check whether we're able to "sift" or not, if yes, sift to the smaller child
        if (l<currentSize /*check if it exists*/ && heapArray[l]<heapArray[smallest]) smallest=l;

        if (r<currentSize /*check if it exists*/ && heapArray[r]<heapArray[smallest]) smallest=r;

        if (smallest!=key){ //if we're able to "sift"
            swap(heapArray, key, smallest);
            MinHeapify(smallest);
        }
    } //MinHeapify = sift-down

    private void increaseKey(int key, int new_val){
        heapArray[key]=new_val; //assign the new value

        /*heapArray[key] now gets a bigger value, so the Heap Invariant might not
        be satisfied for the subtree rooted at "key", so we must re-Heapify it:*/
        MinHeapify(key);
    } //replace the key's value with new_val which is guaranteed to be greater than the current value"

    private void decreaseKey(int key, int new_val){
        heapArray[key]=new_val;

        /*heapArray[key] now gets a smaller value, so the Heap Invariant might not
        be satisfied for the original tree, but now we can just sift-up:*/
        while (key>0 && heapArray[key]<heapArray[parent(key)]){
            swap(heapArray, key, parent(key));
            key=parent(key);
        } //this is called "sift-up"

    } //replace the key's value with new_val which is guaranteed to be smaller than the current value"

    public void updateKey(int key, int new_val){
        if (heapArray[key]>new_val) decreaseKey(key, new_val);
        else if (heapArray[key]<new_val) increaseKey(key, new_val);
        return;
    } //combine increaseKey and decreaseKey into a single method

    public boolean insert(int val){
        if (currentSize==capacity) return false; //the heap is now full
        int i=currentSize++; //increase the size;

        heapArray[i]=val;
        while (i>0 && heapArray[i]<heapArray[parent(i)]){
            swap(heapArray, i, parent(i));
            i=parent(i);
        }
        return true;
    } //if the Heap Invariant is not satisfied, we must sift-up

    public boolean deleteKey(int key){
        if (key>=currentSize || key<0) return false;
        decreaseKey(key, Integer.MIN_VALUE);
        /*by this way, we know exacly where the "Integer.MIN_VALUE" would go,
        that's the root, so we can easily remove it out of the heap*/
        extractMin();
        return true;
    }
}

class MinHeapTest{
    public static void main(String[] args) {
        int[] arr={3,2,1,15,5,4,45,2,3};
        MinHeap myHeap=new MinHeap(arr);
        for (int i=0; i<myHeap.currentSize; i++) System.out.print(myHeap.heapArray[i]+" ");
    }
}