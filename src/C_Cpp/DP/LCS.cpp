#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//memoization
int helper(string &text1, string &text2, vector<vector<int>> &memo, int i, int j){
    if (i==0 || j==0) return 0;
    if (memo[i][j]!=-1) return memo[i][j];

    if (text1[i-1]==text2[j-1]){
        memo[i][j]=1+helper(text1, text2, memo, i-1, j-1);
    }
    else{
        int prev1=helper(text1, text2, memo, i, j-1);
        int prev2=helper(text1, text2, memo, i-1, j);
        memo[i][j]=max(prev1, prev2);
    }

    return memo[i][j];
}
int longestCommonSubsequence(string text1, string text2) {
    int m=text1.size(), n=text2.size();
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
    return helper(text1, text2, memo, m, n);
}

int main(){
    cout<<longestCommonSubsequence("aggtab", "gxtxayb"); //output: 4 ("gtab")
    return 0;
}