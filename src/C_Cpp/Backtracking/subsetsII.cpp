#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//see the problem leetcode 90: subsets II

void helper(vector<int> &nums, int &n, vector<vector<int>> &res, vector<int> &currAns, int i){
    if (i==n){
        res.push_back(currAns);
        return;
    }

    vector<int> temp=currAns;
    
    currAns.push_back(nums[i]);

    helper(nums, n, res, currAns, i+1); //all the subsets that contain nums[i]

    while (i+1<n && nums[i]==nums[i+1]) i++;    //avoid duplicates

    currAns=temp;
    helper(nums, n, res, currAns, i+1);

    return;
}

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    sort(nums.begin(), nums.end());

    int n=nums.size();
    vector<vector<int>> res;
    vector<int> currAns;
    
    helper(nums, n, res, currAns, 0);

    return res;
}

//example
int main(){
    vector<int> nums={1, 2, 2, 3};
    vector<vector<int>> res=subsetsWithDup(nums);

    for (vector<int> &X: res){
        for (int &x: X) cout<<x<<" ";
        cout<<'\n';
    }

    return 0;
}