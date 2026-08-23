#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

struct Stage{
    double R; //current reliability
    int C;  //cost spent
};

double reliabilityCalc(double r, int copies){
    return 1.0 - pow(1.0-r, copies);
}   //reliability for a component with copies of a device connected in parallel

vector<Stage> maxHelper(int i, vector<double> &r, vector<int> &c, int budget,
vector<int> &minRemaining, vector<vector<Stage>> &dp, vector<int> &visited){
    if (i==0){
        visited[0]=1;
        Stage u; u.R=1.0; u.C=0;
        dp[0]={u};
        return dp[0];
    }   //the initial state

    if (visited[i]==1) return dp[i]; //if we've evaluated it before

    int n=r.size()-1; //the number of devices
    vector<Stage> prevStage=maxHelper(i-1, r, c, budget, minRemaining, dp, visited);  //memoization
    
    for (Stage S: prevStage){
        int j=1;    //the number of the i_th device
        while (true){
            int currentCost = S.C+j*c[i];
            if (currentCost+minRemaining[i]>budget) break; //if there's not enough money for the rest
            
            Stage next;
            next.C=currentCost;
            next.R=S.R*reliabilityCalc(r[i], j);

            dp[i].push_back(next);

            j++;
        }
    }

    visited[i]=1;   //mark the i_th device as considered
    return dp[i];
}

double maxReliability(vector<double> &r, vector<int> &c, int budget){
    int n=r.size()-1;

    vector<int> visited(n+1);
    vector<vector<Stage>> dp(n+1);
    //1-indexed but must include the case of 0

    vector<int> minRemaining(n+1);
    for (int j=n-1; j>=0; j--) minRemaining[j]=minRemaining[j+1]+c[j+1];

    vector<Stage> finalStage=maxHelper(n, r, c, budget, minRemaining, dp, visited);

    double res=0.0;
    for (Stage S: finalStage){
        res=max(res, S.R);
    } //find the highest reliability evaluated
    return res;
}

int main(){
    vector<double> r={-1.0, 0.9, 0.8, 0.5};
    vector<int> c={-1, 30, 15, 20};
    //r<> and c<> have -1 as the "padding" value to make elements there 1-indexed

    int budget=105;
    cout<<maxReliability(r, c, budget); //expected output: 0.648
    return 0;
}