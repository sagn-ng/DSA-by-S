#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool safeVertexChoice(vector<vector<bool>> &adj, int count, vector<int> &path, vector<bool> &visited, int v){
    return (adj[path[count-1]][v] && !visited[v]);
}

//we make vertex 0 as our fixed starting point of every cycle
void checkCycle(vector<vector<int>> &result, vector<vector<bool>> &adj, int V, int count, vector<int> &path, vector<bool> &visited){
    if (count==V){
        if (adj[path[V-1]][0]){ //if there is an edge between 0 and the last vertex of path<>
            if (path[1]<path[V-1]){ //avoid reflection
                result.push_back(path);
            }
        }
    }

    for (int v=1; v<V; v++){
        if (safeVertexChoice(adj, count, path, visited, v)){
            path[count]=v;
            visited[v]=true;
            
            checkCycle(result, adj, V, count+1, path, visited);

            visited[v]=false;
        }
    }

    return;
}

void HamiltonianCycles(vector<vector<bool>> &adj){
    int V=adj.size();

    vector<bool> visited(V, false);
    vector<int> path(V);
    vector<vector<int>> result;

    checkCycle(result, adj, V, 1, path, visited); //vertex 0 is fixed

    int s=result.size(); //number of Hamiltonian Cycles found
    if (s==0) cout<<"There aren't any Hamiltonian Cycles in this graph!\n";
    
    //otherwise, we print the result
    else{
        for (int i=0; i<s; i++){
            for (int j=0; j<V; j++){
                cout<<result[i][j]<<" - ";
            }
            cout<<result[i][0];
        }
    }
    return;
}

int main(){
    vector<vector<bool>> adj={{0,1,0,1,0},
                              {1,0,1,1,1},
                              {0,1,0,0,1},
                              {1,1,0,0,1},
                              {0,1,1,1,0}};

    HamiltonianCycles(adj); //output: 0 - 1 - 2 - 4 - 3
    return 0;
}