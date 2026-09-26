#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n=s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    /*dp[i][j] stores the length of the longest palindromic
    subsequence of the subtring from index i to j*/

    for (int diff=0; diff<n; diff++){
        for (int i=0; i+diff<n; i++){
            if (diff==0){
                dp[i][i]=1; //a character is also palindromic
                continue;
            }

            int j=i+diff;

            if (s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else{
            /*since the longest palindromic subsequence's
            first and last characters cannot lie at index
            i and j at the same time, we have:*/
            dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}

int main(){
    string s="bbbab";
    cout<<longestPalindromeSubseq(s); //output: 4 ("bbbb" is the longest palindromic subsequence)
    return 0;
}