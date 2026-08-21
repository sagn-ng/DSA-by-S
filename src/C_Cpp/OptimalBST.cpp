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



int main(){
    vector<int> p_test1={4,2,6,3};
    cout<<minBSTSuccessful(p_test1);
    return 0;
}