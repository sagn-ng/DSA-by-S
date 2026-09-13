#include <iostream>
#include <string>
#include <vector>
using namespace std;

void constructLPS(string &pat, vector<int> &lps){
    int len=0, M=pat.size(), i=1;

    while (i<M){
        if (pat[i]==pat[len]){
            len++;
            lps[i++]=len;
        }

        else{
            if (len>0) len=lps[len-1];
            else lps[i++]=0;
        }
    }
} //"preprocessing" the string pat w/ its LPS array

vector<int> KMP(string &txt, string &pat){
    int N=txt.size(), M=pat.size(), i=0, j=0;

    vector<int> lps(M);
    constructLPS(pat, lps);
    vector<int> result;

    while (i<N){
        if (txt[i]==pat[j]){
            i++; j++;
            if (j==M) result.push_back(i-M);
        }

        else{
            if (j!=0) j=lps[j-1];
            else i++;
        }
    }

    return result;
}

int main(){
    string txt="25sang10sang", pat="sang";
    vector<int> result=KMP(txt, pat);

    if (result.size()==0) cout<<"pat doesn't exist in txt";
    else{
        cout<<"Indices found: ";
        for (int u: result) cout<<u<<" "; //output: 2 8
    }

    return 0;
}