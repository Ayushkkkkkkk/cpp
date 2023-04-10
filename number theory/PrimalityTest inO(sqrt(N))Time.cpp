#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;

bool isprime(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void solve(){
	ll tt;
	cin>>tt;
	while(tt--){
	    ll n;
	    cin>>n;
	   if(isprime(n)){
	       cout<<"yes"<<nline;
	   }
	   else{
	       cout<<"no"<<nline;
	   }
	}
}

int main(){
	solve();
}