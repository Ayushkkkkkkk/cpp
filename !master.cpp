#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

const string RandString = "20257I0MPJMLKOQA";



#define fastio() 		ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define LL 				long long
#define LLD				long double
#define nline 			"\n"
#define pb 				push_back
#define ppb 			pop_back
#define mp 				make_pair
#define ff 				first
#define ss 				second
#define set_bits 		__builtin_popcountll
#define sz(x) 			((int)(x).size())
#define all(x) 			(x).begin(), (x).end()
#define set_bits 		__builtin_popcountll
#define lower(s1) 		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
#define upper(s1) 		transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
#define getunique(v) 	{sort(all(v)); v.erase(unique(all(v)), v.end());}
#define vt vector
#define decimal 		cout << fixed << setprecision(15) ;
#define W(t)        	while(t--)


void lnx() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
}

typedef long long 			ll;
typedef unsigned long long 	ull;
typedef long double 		lld;


ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while (lb < rb) {
		ll mb = (lb + rb) / 2;
		f(mb) ? rb = mb : lb = mb + 1;
	}
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while (lb < rb) {
		ll mb = (lb + rb + 1) / 2;
		f(mb) ? lb = mb : rb = mb - 1;
	}
	return lb;
}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void _print(ll t) 		{cerr << t;}
void _print(int t) 		{cerr << t;}
void _print(string t) 	{cerr << t;}
void _print(char t) 	{cerr << t;}
void _print(lld t) 		{cerr << t;}
void _print(double t) 	{cerr << t;}
void _print(ull t) 		{cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T>  		void _print(vector <T> v);
template <class T>  		void _print(set <T> v);
template <class T>  		void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T>  		void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) 			{cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); 		cerr << "}";}
template <class T> 			void _print(vector <T> v) 			{cerr << "[ "; for (T i : v) 	{_print(i); cerr << " ";} 	cerr << "]";}
template <class T> 			void _print(set <T> v) 				{cerr << "[ "; for (T i : v) 	{_print(i); cerr << " ";} 	cerr << "]";}
template <class T> 			void _print(multiset <T> v) 		{cerr << "[ "; for (T i : v) 	{_print(i); cerr << " ";} 	cerr << "]";}
template <class T, class V> void _print(map <T, V> v) 			{cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} 	cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} 	cerr << "]";}
template <class T> 			void _print(unordered_set <T> v) 	{cerr << "[ "; for (T i : v) 	{_print(i); cerr << " ";} 	cerr << "]";}


template<typename T>             vector<T>& operator--            (vector<T> &v) {for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v) {for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v) {for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v) {for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T, U>& operator--           (pair<T, U> &p) {--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T, U>& operator++           (pair<T, U> &p) {++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p) {is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {return mp(a.first - b.first, a.second - b.second);}
template<typename T, typename U> pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {return mp(a.first + b.first, a.second + b.second);}
template<typename T, typename U> void umin(T& a, U b) {if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b) {if (a < b) a = b;}



#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define int long long


#define sum(a)     	( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    	(*min_element((a).begin(), (a).end()))
#define maxe(a)    	(*max_element((a).begin(), (a).end()))
#define miniA(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxiA(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) 	( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) 	( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())


#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)


const int basen = 8;
const int base = pow(10, basen);
vector<vector<uint32_t>> prec10 = {{uint32_t(base)}};
vector<vector<int>> prec2 = {{(1ll << 32) % base, (1ll << 32) / base}};

// with doubles up to a.size() = b.size() = 3e4
#ifdef BIGINT_USE_FFT
vector<uint32_t> _mul_fft_(const vector<uint32_t> &a, const vector<uint32_t> &b) {
    vector<int> ta(a.size() * 2), tb(b.size() * 2);
    for (int i = 0; i < a.size(); ++i) {
        ta[i * 2] = (a[i] & uint16_t(-1));
        ta[i * 2 + 1] = (a[i] >> 16);
    }
    for (int i = 0; i < b.size(); ++i) {
        tb[i * 2] = (b[i] & uint16_t(-1));
        tb[i * 2 + 1] = (b[i] >> 16);
    }
    auto tc = fft::multiply(ta, tb);
    tc.resize(tc.size() + 5, 0);
    for (int i = 0; i + 1 < tc.size(); ++i) {
        tc[i + 1] += (tc[i] >> 16);
        tc[i] &= uint16_t(-1);
    }
    vector<uint32_t> res(tc.size() / 2);
    for (int i = 0; i < res.size(); ++i) {
        res[i] = ((uint32_t(tc[i * 2 + 1]) << 16) ^ uint32_t(tc[i * 2]));
    }
    while (!res.empty() && res.back() == 0)
        res.pop_back();
    return res;
}
#endif

vector<uint32_t> _mul_(const vector<uint32_t> &a, const vector<uint32_t> &b) {
    if (a.empty() || b.empty()) return {};
    #ifdef BIGINT_USE_FFT
    if (min(a.size(), b.size()) > 350)
        return _mul_fft_(a, b);
    #endif
    vector<uint64_t> tmp(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            uint64_t prod = uint64_t(a[i]) * b[j];
            tmp[i + j] += (prod & uint32_t(-1));
            tmp[i + j + 1] += (prod >> 32);
        }
    }

    for (int i = 0; i + 1 < tmp.size(); ++i) {
        tmp[i + 1] += (tmp[i] >> 32);
        tmp[i] &= uint32_t(-1);
    }

    vector<uint32_t> c(tmp.begin(), tmp.end());

    while (!c.empty() && c.back() == 0) c.pop_back();
    return c;
};

// works with doubles with v.size() up to 3e5
vector<uint32_t> convert(const vector<int> &v) {
    auto _add_ = [](vector<uint32_t> &a, const vector<uint32_t> &b) {
        a.resize(max(a.size(), b.size()) + 1, 0);

        uint32_t carry = 0;
        int i;
        for (i = 0; i < b.size(); ++i) {
            a[i] += b[i];
            uint32_t next_carry = (a[i] < b[i]);
            a[i] += carry;
            next_carry |= (carry && a[i] == 0);
            swap(carry, next_carry);
        }

        while (carry) {
            if ((++a[i++]) != 0)
                break;
        }

        while (!a.empty() && a.back() == 0) a.pop_back();
    };

    while ((1 << prec10.size()) < v.size()) {
        prec10.emplace_back(_mul_(prec10.back(), prec10.back()));
    }

    using It = vector<int>::const_iterator;
    function<vector<uint32_t>(It, It, int)> conv = [&](It it1, It it2, int hint) {
        if (it1 + 1 == it2) {
            return vector{uint32_t(*it1)};
        }

        int ln = it2 - it1;
        while ((1 << hint) >= ln) --hint;
        assert(1 << (hint + 1) >= ln);

        auto imid = it1 + (1 << hint);

        auto vl = conv(it1, imid, hint - 1);
        auto vr = conv(imid, it2, hint - 1);

        vr = _mul_(vr, prec10[hint]);
        _add_(vr, vl);

        return vr;
    };

    return conv(v.begin(), v.end(), prec10.size() - 1);
}

// works with doubles up to 3e6 or more
vector<int> convert(const vector<uint32_t> &v) {
    const int basen = 8;
    const int base = pow(10, basen);
    auto _add_ = [&](vector<int> &a, const vector<int> &b) {
        a.resize(max(a.size(), b.size()) + 1, 0);
        for (int i = 0; i < b.size(); ++i)
            a[i] += b[i];
        for (int i = 0; i + 1 < b.size() || a[i] >= base; ++i) {
            if (a[i] >= base) {
                a[i] -= base;
                ++a[i + 1];
            }
        }
        while (!a.empty() && a.back() == 0)
            a.pop_back();
    };

    auto _slow_mult_ = [&](const vector<int> &a, const vector<int> &b) {
        vector<long long> tmp(a.size() + b.size() + 1, 0);
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                long long prod = 1ll * a[i] * b[j];
                long long div = prod / base;
                tmp[i + j] += prod - base * div;
                tmp[i + j + 1] += div;
            }
        }
        for (int i = 0; i + 1 < tmp.size(); ++i) {
            long long div = tmp[i] / base;
            tmp[i + 1] += div;
            tmp[i] -= div * base;
        }
        while (!tmp.empty() && tmp.back() == 0)
            tmp.pop_back();
        return vector<int>(tmp.begin(), tmp.end());
    };

    #ifdef BIGINT_USE_FFT
    auto _fft_mult_ = [&](const vector<int> &a, const vector<int> &b) {
        vector<int> ta(a.size() * 2), tb(b.size() * 2);
        static_assert(basen % 2 == 0, "basen has to be even");
        const static int M = pow(10, basen / 2);
        for (int i = 0; i < a.size(); ++i) {
            ta[i * 2] = a[i] % M;
            ta[i * 2 + 1] = a[i] / M;
        }
        for (int i = 0; i < b.size(); ++i) {
            tb[i * 2] = b[i] % M;
            tb[i * 2 + 1] = b[i] / M;
        }
        auto tc = fft::multiply(ta, tb);
        tc.resize(tc.size() / 2 * 2 + 10, 0);
        for (int i = 0; i + 1 < tc.size(); ++i) {
            tc[i + 1] += tc[i] / M;
            tc[i] %= M;
        }
        vector<int> res(tc.size() / 2);
        for (int i = 0; i < res.size(); ++i)
            res[i] = tc[i * 2] + tc[i * 2 + 1] * M;
        while (!res.empty() && res.back() == 0)
            res.pop_back();
        return res;
    };
    #endif

    auto _mult_ = [&](const vector<int> &a, const vector<int> &b) {
        #ifdef BIGINT_USE_FFT
        if (min(a.size(), b.size()) > 380) {
            return _fft_mult_(a, b);
        }
        #endif

        return _slow_mult_(a, b);
    };

    while ((1 << prec2.size()) < v.size()) {
        prec2.emplace_back(_mult_(prec2.back(), prec2.back()));
    }

    using It = vector<uint32_t>::const_iterator;
    function<vector<int>(It, It, int)> conv = [&](It it1, It it2, int hint) {
        if (it1 + 1 == it2) {
            return vector{int((*it1) % base), int((*it1) / base)};
        }

        int ln = it2 - it1;
        while ((1 << hint) >= ln) --hint;
        assert(1 << (hint + 1) >= ln);

        auto imid = it1 + (1 << hint);

        auto vl = conv(it1, imid, hint - 1);
        auto vr = conv(imid, it2, hint - 1);

        vr = _mult_(vr, prec2[hint]);
        _add_(vr, vl);

        return vr;
    };

    return conv(v.begin(), v.end(), prec2.size() - 1);
}

int rem(const vector<uint32_t> &v, int mod) {
    ll ans = 0;
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        ans = ((ans << 32) + v[i]) % mod;
    }
    return ans;
}

int rem(const vector<int> &v, int mod) {
    ll ans = 0;
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        ans = ((ans * base) + v[i]) % mod;
    }
    return ans;
}

string to_string(const vector<uint32_t> &v) {
    if (v.empty()) return "0";
    string res;
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        for (int j = 31; j >= 0; --j) {
            char c = '0' + ((v[i] >> j) & 1);
            if (c == '0' && res.empty()) continue;
            res += c;
        }
    }
    return res;
}



	
void test() {
	int n ; cin >> n ;
	vector<vector<int>> a(n , vector<int>(5 , 0));
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < 5 ; j++){
			cin >> a[i][j];
		}
	}
	
	int m = 5;
	
	for (int d1 = 0 ; d1 < m ; d1++){
		for (int d2 = d1 + 1 ; d2 < m ; d2++){
			int cntd1 = 0;
			int cntd2 = 0;
			int common = 0;
			
			for (int i = 0 ; i < n ; i++){
				if(a[i][d1]){
					cntd1++;
				}
				if(a[i][d2]){
					cntd2++;
				}
				if(a[i][d1] && a[i][d2]){
					common++;
				}
			}
			
			if(cntd1 >= n / 2 && cntd2 >= n / 2 && cntd1 + cntd2 - common == n){
				cout << "YES" << nline;
				return;
			}
		}
	}
	cout << "NO" << nline;
}


int32_t main() {
	lnx();
	int t;
	cin >> t;
	W(t) {
		test();
	}
}
