#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int res=-1000000000; //a variable that stores the result
    int curMaxSub=0;    //a "prefix" - the maximum subarray's sum until now
    for (int u: nums){
        if (curMaxSub<0) curMaxSub=0; //avoid negative prefix 
        curMaxSub+=u;
        res=max(res, curMaxSub); //re-evaluate the result
    }
    return res;
}

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
    //output: 6 (4, -1, 2, 1)
    return 0;
}