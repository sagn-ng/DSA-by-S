#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class MinStack {
public:
    stack<int> mySt;
    stack<int> storeMin;
    //storeMin stores the minimum value of mySt, up to the current state
    MinStack() {
    }
    
    void push(int val) {
        mySt.push(val);
        int x=val;

        if (!storeMin.empty()){
            x=min(val, storeMin.top());
        }

        storeMin.push(x);
    }
    
    void pop() {
        mySt.pop();
        storeMin.pop();
    }
    
    int top() {
        return mySt.top();
    }
    
    int getMin() {
        return storeMin.top();
    }
};