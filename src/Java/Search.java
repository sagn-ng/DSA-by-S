public class Search {
    public static int linearSearch(int[] array, int value){
        int i;
        for (i=0; i<array.length; i++){
            if (array[i]==value) return i;
        }
        return -1;
    }

    public static int binarySearch(int[] array, int value){
        int left=0, right=array.length-1;
        while (left<=right){
            int mid=left+(right-left)/2;
            if (array[mid]==value) return mid;
            else if (array[mid]>value) right=mid-1;
            else left=mid+1;
        }
        return -1;
    } //suppose that we have a non-decreasing array

    public static int interpolationSearch(int[] array, int value){
        int high=array.length-1, low=0;
        while (value>=array[low] && value<=array[high] && low<=high){
            int probe = low + (value-array[low])*(high-low)/(array[high]-array[low]);
            System.out.println("probe: "+probe);
            if (array[probe]==value) return probe;
            else if (array[probe]<value){
                low=probe+1;
            }
            else high=probe-1;
        }
        return -1;
    } //suppose that we have a non-decreasing array

    public static void main(String[] args) {
        int[] array={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
        int idx=binarySearch(array, 256);
        if (idx!=-1) System.out.println("element found at index: "+idx);
        else System.out.println("element not found!");
    }
}