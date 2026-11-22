#include <stdio.h>
#include <stdlib.h>
#define FOR(i, start, end) for((i)=(start); (i)<(end); (i)++)
#define MALLOC(T, size) (T*)malloc(sizeof(T)*(size))

//only for n<=30

const int inf=1000000;

//travel from i, go through all vertices in 'mask', ending at '1'
int minCost(int** cost, int n, int i, int mask, int** dp){
    if (mask==0) return cost[i][1];

    if (dp[i][mask]!=inf) return dp[i][mask];

    int next;
    FOR(next, 1, n+1){ //for(next=1, next<=n)
        if ((mask & (1<<next)) == 0) continue; //skip vertices that are not in our set

        int updatedMask = mask - (1<<next);
        int nextCost=minCost(cost, n, next, updatedMask, dp);

        if (cost[i][next]+nextCost<dp[i][mask]){
            dp[i][mask] = cost[i][next]+nextCost;
        }
    }

    return dp[i][mask];
}

int solveTSP(int** cost, int n){
    int FULL_MASK=(1<<(n+1))-3;
    //maximum value of mask: 111....100 (length of n+1, 1_th and 0_th are off) = 
    //FULL_MASK = 2^(n+1) - 1 = 111...101

    int** dp=MALLOC(int*, n+1);
    int k, j;
    FOR(k, 1, n+1){
        dp[k]=MALLOC(int, FULL_MASK);
        FOR(j, 1, FULL_MASK) dp[k][j]=inf;
    }

    int mask=FULL_MASK-1; //111...00 (length of n+1, already marked 1 as the starting point, 0_th bit is off)
    
    int ans=minCost(cost, n, 1, mask, dp);

    FOR(k, 1, n+1) free(dp[k]);
    free(dp);

    return ans;
}

int main(){
    int n, i, j;
    scanf("%d", &n);

    int** cost=MALLOC(int*, n+1);
    FOR(i, 1, n+1){
        cost[i]=MALLOC(int, n+1);
        FOR(j, 1, n+1) scanf("%d", &cost[i][j]);
    }

    int ans=solveTSP(cost, n);
    printf("%d", ans);

    FOR(i, 1, n+1) free(cost[i]);
    free(cost);

    return 0;
}