#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int fib(int n){
    int f[n+2];
    f[0] = 0;
    f[1] = 1;
    loop(i,2,n+1){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}