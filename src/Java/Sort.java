import binary_tree.MinHeap;
public class Sort {
    /*assume that we're wanting to sort the array in ascending order;
    if we want to sort the array descendingly, change some comparators
    in each funtion (or method)*/
    public static void bubbleSort(int[] array){
        if (array.length==1) return;
        for (int i=0; i<array.length-1; i++){
            for(int j=0; j<array.length-1-i; j++){
                if (array[j]>array[j+1]){
                    int temp=array[j+1];
                    array[j+1]=array[j];
                    array[j]=temp;
                }
            }
        }
    } //not very efficient as it has O(n^2) time complexity
    
    public static void selectionSort(int[] array){
        for (int i=0; i<array.length-1; i++){
            int min=i;
            for (int j=i+1; j<array.length; j++){
                if (array[min]>array[j]){
                    min=j;
                }
            }
            int temp=array[i];
            array[i]=array[min];
            array[min]=temp;
        }
    } /*an algorithm that keeps track of the minimum value
    during each iteration, and swaps elements*/

    public static void insertionSort(int[] array){
        for (int i=1; i<array.length; i++){
            int temp=array[i];
            int j=i-1;
            while (j>=0 && array[j]>temp){
                array[j+1]=temp;
                j--;
            }
            array[j+1]=temp;
        }
    } //O(n^2) runtime, whose best case is o(n) compared to O(n^2) of Selection Sort

    private static void mergeHelper(int[] leftArr, int[] rightArr, int[] array){
        int lSize=array.length/2;
        int rSize=array.length-lSize;

        int i=0, l=0, r=0; //indices: i for array, l for leftArr, r for rightArr

        //check the conditions for merging
        while (l<lSize && r<rSize){
            if (leftArr[l]<rightArr[r]){
                array[i++]=leftArr[l];
                l++;
            }
            else{
                array[i++]=rightArr[r];
                r++;
            }
        }

        //now we deal with the case all elements of one array got pushed to "array" before another
        while (l<lSize){
            array[i++]=leftArr[l];
            l++;
        } //in case we haven't done pushing elements from leftArr to array

        while (r<rSize){
            array[i++]=rightArr[r];
            r++;
        } //in case we haven't done pushing elements from rightArr to "array"
    }
    public static void mergeSort(int[] array){
        int l=array.length;
        if (l<=1) return;
        int mid=l/2;
        int[] leftArr=new int[mid];
        int[] rightArr=new int[l-mid];

        int i=0, j=0;
        while (i<l){
            if (i<mid) leftArr[i]=array[i];
            else rightArr[j++]=array[i];
            i++;
        }

        mergeSort(leftArr); mergeSort(rightArr);
        mergeHelper(leftArr, rightArr, array);
    } //mergeSort is a recursive function (or method), with O(n*log(n)) runtime and O(n) space

    private static int partition(int[] array, int start, int end){
        int pivot=array[end];
        int i=start-1;
        for (int j=start; j<end; j++){
            if (array[j]<pivot){
                int temp=array[++i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
        //now swap arr[i+1] and array[end], to "divide" the array
        int temp=array[++i];
        array[i]=array[end];
        array[end]=temp;
        return i; //i is the new pivot index
    }
    public static void quickSort(int[] array, int start, int end){
        if (end<=start) return;
        int pivot=partition(array, start, end);
        quickSort(array, start, pivot-1);
        quickSort(array, pivot+1, end);
    } //quick sort is a recursive algorithm
    
    //we also have Heap Sort based on Binary Heap:
    public static void heapSort(int[] array){
        MinHeap newHeap=new MinHeap(array);
        for (int i=0; i<array.length; i++) array[i]=newHeap.extractMin();
    }

    public static void main(String[] args) {
        int[] array={9, 1, 8, 2, 7, 3, 6, 4, 5, 1};
        System.out.println("Before getting sorted:");
        for (int i: array) System.out.print(i+" ");

        heapSort(array);
        System.out.println("\nAfter getting sorted:");
        for (int i: array) System.out.print(i+" ");
    }
}