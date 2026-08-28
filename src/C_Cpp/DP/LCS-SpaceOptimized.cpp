#include <iostream>   
#include <string>    
#include <vector>
#include <cmath> 
using namespace std;

/*we notice that if we choose memoization or tabulation with dp<> or memo<>,
when evaluating dp[i][j] (or memo[i][j]), we only need to care about the
current row (index i) and the previous row (index i-1), so we can optimize
the solution by creating 2 1D arrays, the space complexity
will be O(m) or O(n) instead of O(m*n)*/

int longestCommonSubsequence(string &s1, string &s2){
    int m=s1.size(), n=s2.size();

    /*initialize 2 vectors to store the current and previous rows of dp*/
    vector<int> prev(n + 1), cur(n + 1);
    /*base case is covered as we have initialized
    the prev and cur vectors to 0*/

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]){
                //characters match, increment LCS length
                cur[j] = 1 + prev[j - 1];
            }
            else
                /*characters don't match, consider the
                maximum from above or left*/
                cur[j] = max(prev[j], cur[j - 1]);
        }
      
        prev = cur; //update the previous row with the current row
    }

    return prev[n]; //return the length of the LCS
}

int main(){
    string s1="aggtab";
    string s2="gxtxayb";
    cout<<longestCommonSubsequence(s1, s2); //output: 4 ("gtab")
    return 0;
}