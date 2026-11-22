#include <iostream>
#include <vector>

using namespace std;

//all elements in 'nums' are positive
//find all arrays containing (maybe duplicate) elements in 'nums', such that they sum up to be 'target'

void helper(vector<int> &nums, int &target, vector<vector<int>> &res, int i, vector<int> currState, int total){
    if (total==target){
        res.push_back(currState);
        return;
    }

    if (i>=nums.size() || total>target) return;
    
    currState.push_back(nums[i]);
    helper(nums, target, res, i, currState, total+nums[i]);

    currState.pop_back();
    helper(nums, target, res, i+1, currState, total);

    return;
}

vector<vector<int>> combinationSum(vector<int> &nums, int target){
    vector<vector<int>> res;
    vector<int> currState={};

    helper(nums, target, res, 0, currState, 0);

    return res;
}

int main(){
    vector<int> nums={2, 3, 2, 5, 10, 4, 7};
    int target=7;
    vector<vector<int>> ans=combinationSum(nums, target);

    for (vector<int> &X: ans){
        for (int &x: X) cout<<x<<" ";
        cout<<'\n';
    }

    return 0;
}