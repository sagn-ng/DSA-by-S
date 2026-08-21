#include <iostream>
#include <climits>
#include <vector>
using namespace std;
//successful search only
int optimalBST(vector<int> &keys, vector<int> &p){
    int n=keys.size();
    vector<vector<int>> c(n, vector<int>(n)); //n x n table

    for (int diff=0; diff<=n-1; diff++){ //j - i = 0, 1,...,n-1
        for (int i=0; i+diff<=n-1; i++){
            int j=i+diff;
            int p_range=0, min_temp = INT_MAX;

            for (int r=i; r<=j; r++){
                p_range+=p.at(r);
                
                if (r==0) min_temp=min(min_temp, c.at(1).at(j));
                else if (r==n-1) min_temp=min(min_temp, c.at(i).at(n-2));

                else min_temp=min(min_temp, c.at(i).at(r-1)+c.at(r+1).at(j));
            }

            c.at(i).at(j)=p_range+min_temp;
        }
    }

    return c[0][n-1];
} //tabulation, but making c as a (n+1) x (n+1) table would be easier

int main(){
    vector<int> keys={10,20,30,40};
    vector<int> p={4,2,6,3};
    cout<<optimalBST(keys, p);
    return 0;
}