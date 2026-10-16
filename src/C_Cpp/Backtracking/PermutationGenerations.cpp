#include <iostream>
#include <vector>
using namespace std;

//assume elements in nums are unique;
//this time i choose to replace visited[n] with 'mask': a number whose binary form represents
//the states of indexes (picked or not picked)
//note that using an 'int' variable only limits n to <=30
void helper(vector<int> &nums, int &n, int i, vector<int> &curr, int &mask, vector<vector<int>> &result){
    if (i==n){
        result.push_back(curr);
        return;
    }

    for (int j=0; j<n; j++){
        if ((mask & (1<<j))==0){ //if visited[j]=false
            curr[i]=nums[j];

            mask+=(1<<j); //visited[j]=true

            helper(nums, n, i+1, curr, mask, result);

            mask-=(1<<j); //visited[j]=false
        }
    }

    return;
}

void printResult(vector<vector<int>> &result){
    for (vector<int> x: result){
        for (int u: x) cout<<u<<" ";
        cout<<endl;
    }
}

void permute(vector<int> &nums){
    int n=nums.size();
    vector<int> curr(n);
    vector<vector<int>> result;
    int mask=0; //bitmask

    helper(nums, n, 0, curr, mask, result);
    printResult(result);
    return;
}

int main(){
    vector<int> nums={2, 5, 1, 0};
    permute(nums);

    return 0;
}