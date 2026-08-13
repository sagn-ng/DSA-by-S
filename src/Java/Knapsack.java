public class Knapsack {
    public static int solveTabulation(int[] values, int[] weights, int capacity){
        int itemCount=weights.length;
        int[][] table=new int[itemCount+1][capacity+1];
        for (int item=1; item<=itemCount; item++){
            for (int c=1; c<=capacity; c++){
                if (weights[item-1]>c) table[item][c]=table[item-1][c];
                else{
                    table[item][c]=Math.max(table[item-1][c], values[item-1]+table[item-1][c-weights[item-1]]);
                } //we have 2 options for each item: take, or not take
            }
        } //we mark table[][] as 1-indexed, so to use table[][] indices for values[] and weights[], we must minus 1
        return table[itemCount][capacity];
    } //tabulation

    //left here, waiting to solve by Memoization =))
}

class KnapsackTest{
    public static void main(String[] args) {
        int[] values={300, 200, 400, 500};
        int[] weights={2, 1, 5, 3};
        int capacity=10;
        System.out.println(Knapsack.solveTabulation(values, weights, capacity));
    }
}