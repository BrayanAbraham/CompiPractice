/*
A n*n square with a missing tiles.
n = 2**k (k<=1)
Fill the n*n square with L shaped tiles
*/
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<vector<int> > tiling(vector<vector<int> >arr,int n,int s1,int s2, int p1, int p2){
    if(n==2){
        if(p1==s1){
            loop(i,s2,s2+2){
                arr[s1+1][i]-=1;
            }
            if(p2==s2){
                arr[s1][s2+1]-=1;
            }else{
                arr[s1][s2] -= 1;
            }
        }else{
            loop(i,s2,s2+2){
                arr[s1][i] -= 1;
            }
            if (p2 == s2){
                arr[s1+1][s2+1] -= 1;
            }else{
                arr[s1+1][s2] -= 1;
            }
        }
    }else{
        if(p1 >= s1+(n/2)){
            arr[s1+int(n/2)-1][s2+int(n/2)-1] -= 1;
            arr = tiling(arr, n/2, s1,s2, s1+int(n/2)-1, s2+int(n/2)-1);
            arr[s1+int(n/2)-1][s2+int(n/2)] -= 1;
            arr = tiling(arr, n/2, s1, s2+int(n/2),s1+int(n/2)-1, s2+int(n/2));
            if(p2 >= s2+(n/2)){
                arr[s1+int(n/2)][s2+int(n/2)-1] -= 1;
                arr = tiling(arr, n/2, s1+int(n/2), s2,s1+int(n/2), s2+int(n/2)-1);
                arr = tiling(arr, n/2, s1+int(n/2), s2+int(n/2), p1,p2);
            }else{
                arr[s1+int(n/2)][s2+int(n/2)] -= 1;
                arr = tiling(arr, n/2, s1+int(n/2), s2, p1,p2);
                arr = tiling(arr, n/2, s1+int(n/2), s2 + int(n/2), s1+int(n/2), s2+int(n/2));
            }
        }else{
            arr[s1+int(n/2)][s2+int(n/2)-1] -= 1;
            arr = tiling(arr, n/2, s1+int(n/2), s2,s1+int(n/2), s2+int(n/2)-1);
            arr[s1+int(n/2)][s2+int(n/2)] -= 1;
            arr = tiling(arr, n/2, s1+int(n/2), s2 +int(n/2), s1+int(n/2), s2+int(n/2));
            if(p2 >= s2+(n/2)){
                arr[s1+int(n/2)-1][s2+int(n/2)-1] -= 1;
                arr = tiling(arr, n/2, s1,s2, s1+int(n/2)-1, s2+int(n/2)-1);
                arr = tiling(arr, n/2, s1, s2+int(n/2), p1,p2);
            }else{
                arr[s1+int(n/2)-1][s2+int(n/2)] -= 1;
                arr = tiling(arr, n/2, s1,s2, p1,p2);
                arr = tiling(arr, n/2, s1, s2+int(n/2),s1+int(n/2)-1, s2+int(n/2));
            }
        }
    }
    return arr;
}

int main(){
    int n=8;
    vector<vector<int> > arr(n,vector<int>(n,1));
    arr[6][1] -= 1;
    loop(i,0,n){
        loop(j,0,n){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    arr = tiling(arr,n,0,0,6,1);
    loop(i,0,n){
        loop(j,0,n){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}