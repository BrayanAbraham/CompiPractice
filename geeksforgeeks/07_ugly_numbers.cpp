/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 
11 ugly numbers. By convention, 1 is included.

Given a number n, the task is to find n’th Ugly number.
*/
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int ugly_no(int n){
    int arr[n];
    arr[0] = 1;
    int i2,i3,i5;
    i2=i3=i5=0;
    int next2 = arr[i2]*2;
    int next3 = arr[i3]*3;
    int next5 = arr[i5]*5;
    loop(i,1,n){
        int nextugly = min(next2,min(next3,next5));
        arr[i] = nextugly;
        if(nextugly == next2){
            i2++;
            next2 = arr[i2]*2;
        }
        if(nextugly == next3){
            i3++;
            next3 = arr[i3]*3;
        }
        if(nextugly == next5){
            i5++;
            next5 = arr[i5]*5;
        }
    }
    return arr[n-1];
}

int main(){
    int n;
    cin>>n;
    cout<<ugly_no(n);
    return 0;
}
