#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define nline '\n'

void solver(){
    int n ; cin>>n;
    if(n==1){
        cout<<"NO"<<nline;
        return;
    }
    if(n % 2 == 0 || n % 4==0){
        cout<<"YES"<<nline;
    }
    else{
        cout<<"NO"<<nline;
    }
}

int main(){
    int tt; cin>>tt;
    while(tt--){
        solver();
    }
}