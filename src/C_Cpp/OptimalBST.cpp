#include <iostream>
#include <climits>
#include <vector>
using namespace std;
//successful search only
int minBSTSuccessful(vector<int> &p){
    int n=p.size();
    vector<vector<int>> c(n+1, vector<int>(n+1)); //(n+1) x (n+1) table

    for (int diff=1; diff<=n; diff++){
        for (int i=0; i+diff<=n; i++){
            int j=i+diff;
            int p_range=0, min_temp=INT_MAX;

            for (int r=i+1; r<=j; r++){
                p_range+=p[r-1]; //i, r, j in c<> are 1-indexed

                min_temp=min(min_temp, c[i][r-1]+c[r][j]);
            }
            c[i][j]=p_range+min_temp;
        }
    }

    return c[0][n];
} //tabulation

//unsuccessful search
int minBSTUnsuccessful(vector<vector<int>> &dp, vector<int> &p, vector<int> &q, int i, int j){
    if (i==j) return 0;

    if (dp[i][j]!=-1) return dp[i][j];

    dp[i][j]=INT_MAX;

    for (int r=i+1; r<=j; r++){
        int left_cost=minBSTUnsuccessful(dp, p, q, i, r-1);
        int right_cost=minBSTUnsuccessful(dp, p, q, r, j);
        dp[i][j]=min(dp[i][j], left_cost+right_cost);
    }

    int w_range=q[i];
    for (int r=i+1; r<=j; r++) w_range += (p[r-1]+q[r]);

    dp[i][j]+=w_range;
    return dp[i][j];
}

int main(){
    vector<int> p_test1={4,2,6,3};
    cout<<"An example for successful search only: "<<minBSTSuccessful(p_test1)<<'\n';

    vector<int> p_test2={3,3,1,1};
    vector<int> q={2,3,1,1,1};
    vector<vector<int>> dp(5, vector<int>(5, -1));
    cout<<"An example for including unsuccessful search: "<<minBSTUnsuccessful(dp, p_test2, q, 0, 4);
    return 0;
}