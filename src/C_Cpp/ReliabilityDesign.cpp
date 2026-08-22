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