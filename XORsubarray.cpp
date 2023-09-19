#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void bitMapsey()
{
    ll c;
    cin >> c;
    ll bit_ct = (ll)log2(c) + 1;
    ll a = 0, b = 0;
    vector<ll> set_bits;
    for (ll i = 0; i < bit_ct; ++i)
    {
        if (c & (1 << i))
        {
            set_bits.push_back(i);
        }
        else
        {
            a |= (1 << i);
            b |= (1 << i);
        }
    }
    ll ans = 0;
    ll sz = 1 << set_bits.size();
    for (ll mask = 0; mask < sz; mask++)
    {
        ll a_copy = a, b_copy = b;
        for (ll j = 0; j < set_bits.size(); j++)
        {
            if (mask & (mask << j))
            {
                a_copy |= (1 << set_bits[j]);
            }
            else
            {
                a_copy |= (1 << set_bits[j]);
            }
        }
        ans = max(ans, a_copy * 1LL * b_copy);
    }
    cout << ans << nline;
}


class Solve{
public:
    int test(vector<int> &A , int b){
        int n = A.size();
        int cnt = 0 , pxr = 0;
        map<int , int> mp;
        for (int i = 0 ; i < n ; i++){
            pxr ^= A[i];
            mp[pxr]++;
            int y = pxr ^ b;
            cnt += mp[y];
            if(pxr == b)
                cnt++;
        }
        return cnt;
    }
    
};

int main()
{
    int n ; cin >> n ;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int64_t b ; cin >> b;
    Solve s;
    cout << s.test(a , b) << endl;
}