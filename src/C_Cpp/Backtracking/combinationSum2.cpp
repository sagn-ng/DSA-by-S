#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//all elements in 'nums' are positive
//find all arrays containing (maybe duplicate) elements in 'nums', such that they sum up to be 'target'
//however, each element must be used at most once

void helper(vector<int> &nums, vector<vector<int>> &res, int target, vector<int> currAns, int i, int total){
    if (total==target){
        res.push_back(currAns);
        return;
    }

    if (i>=nums.size() || total>target) return;

    for (int j=i; j<nums.size(); j++){
        if (total+nums[j]>target) continue; //since we will sort later to reduce unnecessary iterations

        if (j>i && nums[j]==nums[j-1]) continue; //avoid duplicate combinations caused by duplicate elements

        //make sure that each element is used at most once:
        currAns.push_back(nums[j]); //first choice: we take
        helper(nums, res, target, currAns, j+1, total+nums[j]);

        currAns.pop_back(); //backtracking, we don't take
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> res;

    helper(candidates, res, target, {}, 0, 0);

    return res;
}

//example:

int main(){
    vector<int> candidates={9,2,2,4,6,1,5};
    int target=8;

    vector<vector<int>> res=combinationSum2(candidates, target);

    for (vector<int> &X: res){
        for (int &x: X) cout<<x<<" ";
        cout<<'\n';
    }

    return 0;
}