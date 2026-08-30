#include <iostream>
#include <vector>
using namespace std;

//we number the color from 1 to m
bool safeColorAssignment(vector<vector<bool>> &adj, vector<int> &color, int v, int c){
    int n=adj.size();

    for (int i=0; i<n; i++){
        if (adj[v][i] && c==color[i]) return false;
    }

    return true;
}

//color[i]=0 means "vertex i hasn't been colored"
bool AssignColor(vector<vector<bool>> &adj, vector<int> &color, int m, int v){
    int n=adj.size();
    if (v==n){
        return true;
    }

    for (int c=1; c<=m; c++){
        if (safeColorAssignment(adj, color, v, c)){
            color[v]=c;
            if (AssignColor(adj, color, m, v+1)) return true;

            color[v]=0;
        }
    }

    return false;
}

void Coloring(vector<vector<bool>> &adj, int m){
    int n=adj.size();
    vector<int> color(n);

    bool res=AssignColor(adj, color, m, 0);
    if (res){
        for (int i=0; i<n; i++){
            cout<<"vertex: "<<i<<" - color: "<<color[i]<<'\n';
        }
    }

    else cout<<"No such color assignment exists!";

    return;
}

int main(){
    vector<vector<bool>> adj={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    int m=3;

    Coloring(adj, m); //output: 1-2-3-2
    return 0;
}