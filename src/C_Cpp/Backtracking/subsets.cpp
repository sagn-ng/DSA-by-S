#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> &currAns, int i){
    if (i==nums.size()){
        res.push_back(currAns);
        return;
    }

    //first choice
    helper(nums, res, currAns, i+1);

    //second choice
    currAns.push_back(nums[i]);

    helper(nums, res, currAns, i+1);

    currAns.pop_back(); //return to the previous state

    return;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curAns={};
    helper(nums, res, curAns, 0);

    return res;
}

int main(){
    vector<int> nums={1, 2, 3};
    vector<vector<int>> ans=subsets(nums);

    for (vector<int> &X: ans){
        for (int &x: X) cout<<x<<" ";
        cout<<'\n';
    }

    return 0;
}