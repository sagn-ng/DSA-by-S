#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int minMultiCost(vector<int> &arr, int i, int j, vector<vector<int>> &c){
    if (i==j) return 0;

    if (c[i][j] != -1) return c[i][j];

    int m = INT_MAX;

    for (int k=i; k<j; k++){
        int curr = minMultiCost(arr, i, k, c) + minMultiCost(arr, k+1, j, c)
        + arr[i-1]*arr[k]*arr[j];

        m = min(curr, m);
    }

    c[i][j] = m;
    return m;
}

int matrixMulti(vector<int> &arr){
    int n=arr.size();
    if (n<=1) return 0;

    vector<vector<int>> c(n, vector<int>(n, -1));

    return minMultiCost(arr, 1, n-1, c);
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};
    int res = matrixMulti(arr);
    cout << res << endl;
    return 0;
}