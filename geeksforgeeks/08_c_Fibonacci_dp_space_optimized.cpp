#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int fib(int n){
    int a=0,b=1,c;
    if (n==0){
        return a;
    }
    loop(i,2,n+1){
        c = a+b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}