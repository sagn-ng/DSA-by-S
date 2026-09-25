#include <iostream>
#include <vector>
using namespace std;

void findNext(vector<vector<int>> &result, vector<int> &curSet, int curSum,
    int pos, vector<int> &nums, int target){
    int n=nums.size();

    //if we checked the entire array nums<> and couldn't find a solution:
    if (pos==n && curSum!=target) return;

    if (curSum==target){
        result.push_back(curSet);
    } /*we don't "return" immediately since we still consider negative
    elements from index "pos" to the end*/

    if (pos<n){ //this allows the traverse to continue
        for (int i=pos; i<n; i++){
            curSet.push_back(nums[i]); curSum+=nums[i];

            findNext(result, curSet, curSum, i+1, nums, target);

            //backtrack:
            curSet.pop_back(); curSum-=nums[i];

        }
    }
    
    return;
}

void findSubsets(vector<int> &nums, int target){
    vector<int> curSet;
    vector<vector<int>> result;
    int curSum=0;

    findNext(result, curSet, curSum, 0, nums, target);

    if (result.size()==0) cout<<"No subset found";

    else{
        int N=result.size();
        cout<<"There are "<<N<<" subsets found:\n";

        for (int i=0; i<N; i++){
            for (int u: result[i]) cout<<u<<" ";
            if (i!=N-1) cout<<'\n';
        }
    } //print every subset found
}

int main(){
    vector<int> nums={1,10,-2,7,6,2,-1,5}; //make sure that elements of nums<> are unique
    int target=8;

    findSubsets(nums, target);
    return 0;
}