#include <iostream>
#include <vector>
#include <string>
using namespace std;

//generate binary sequences of length n that don't contain 2 consecutive 1s
void recursion(int n, char*c, int size){
    if (size==n){
        string s(c);
        cout<<s<<endl;
        return;
    }

    if (size==0 || c[size-1]=='0'){
        c[size]='0';
        recursion(n, c, size+1);

        c[size]='1'; //backtrack and try the other case
        recursion(n, c, size+1);
    }

    else{
        c[size]='0';
        recursion(n, c, size+1);
    }

    return;
}

void generateStrs(int n){
    if (n<=0){
        cout<<"the argument must be a positive integer!\n";
        return;
    }
    char *c=new char[n+1];
    c[n]='\0';

    recursion(n, c, 0);
    delete[] c;
    return;
}

int main(){
    generateStrs(5);
    return 0;
}