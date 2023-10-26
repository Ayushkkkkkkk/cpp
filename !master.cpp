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



#define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 65536, stdin), p1 == p2) ? EOF : *p1 ++)
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++
#define putchar(x) (p3 - obuf < 1000000) ? (*p3++ = x) : (fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = x)
using namespace std;
static char buf[29999999], *p1 = buf, *p2 = buf, obuf[29999999], *p3 = obuf;
template <typename item>
inline void read (register item &x) {
    x = 0;
	register char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
}
static char cc[15];
template <typename item>
inline void print (register item x) {
	register int len = 0;
	do cc[len++] = x % 10 + '0', x /= 10; while (x);
	while (len--) putchar(cc[len]);
}
int N;ll A[2000006];
const ll inf=1e16,mod=1e9+7;
struct node{int x,y;ll cnt;}B[4000006];
int tot;ll d[2000006];
int stk[2000005],tail;
void add(ll &x,const ll y){
	if((x+=y)>=mod)x-=mod;
}
bool cmp(node a,node b){
	return a.x<b.x;
}
bool cmp1(node a,node b){
	return a.y>b.y;
}
struct BIT{
	ll val[2000005];
	void init(){
		for(int i=0;i<=2*N;++i)val[i]=0ll;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void modify(int pos,ll v){
		v%=mod;
		for(int i=pos;i<=2*N;i+=lowbit(i))add(val[i],v);
	}
	ll query(int pos){
		ll res=0ll;
		for(int i=pos;i;i-=lowbit(i))add(res,val[i]);
		return res;
	}
}b0,b2,b3;
struct BIT1{
	ll val[2000005];
	void init(){
		for(int i=0;i<=2*N;++i)val[i]=0ll;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void modify(int pos,ll v){
		for(int i=pos;i<=2*N;i+=lowbit(i))val[i]+=v;
	}
	ll query(int pos){
		ll res=0ll;
		for(int i=pos;i;i-=lowbit(i))res+=val[i];
		return res;
	}
}B1;
ll res1[1000005],res2[1000005],sum[2000005];


void test() {
	read(N);ll mx=0ll;tot=0;
	for(int i=1;i<=N;++i)read(A[i]),mx=max(mx,A[i]),res1[i]=res2[i]=0ll;
	if(N==1){print(0);putchar(' ');print(0);putchar('\n');return ;}
	A[0]=inf;for(int i=N+1;i<=2*N;++i)A[i]=A[i-N];
	for(int i=1;i<2*N;++i){
		sum[i]=sum[i-1];
		if(A[i+1]<A[i])sum[i]+=A[i]-A[i+1];
	}
    for(int i=0;i<2*N;++i)d[i]=A[i]-A[i+1];tail=0;
    for(int i=0;i<2*N;++i){
    	if(d[i]<0ll){
    		while(d[i]<0ll){
    			if(d[stk[tail]]<-d[i]){
    				B[++tot]=node{stk[tail],i,d[stk[tail]]};
    				d[i]+=d[stk[tail]];d[stk[tail--]]=0ll;
				}else {
					B[++tot]=node{stk[tail],i,-d[i]};
					d[stk[tail]]+=d[i];d[i]=0ll;
					if(!d[stk[tail]])--tail;
				}
			}
		}else if(d[i]>0ll)stk[++tail]=i; 
	}
	while(tail){
		B[++tot]=node{stk[tail],2*N,d[stk[tail]]};
		d[stk[tail--]]=0ll;
	}
    for(int i=1;i<=N;++i)res1[i]=sum[i+N-2]-sum[i-1]+mx-A[i];
    b0.init();b2.init();b3.init();B1.init();
	sort(B+1,B+tot+1,cmp);int nd=1;
    for(int i=0;i<=2*N;++i){
    	while(nd<=tot&&B[nd].x<=i){
    		b0.modify(B[nd].y,1ll*(B[nd].y-B[nd].x)*(B[nd].y-B[nd].x)%mod*(B[nd].cnt%mod)%mod);
    		B1.modify(B[nd].y,B[nd].cnt);b2.modify(B[nd].y,1ll*B[nd].y*B[nd].cnt%mod);
    		b3.modify(B[nd].y,1ll*B[nd].y*B[nd].y%mod*B[nd].cnt%mod); ++nd;
		}
    	if(i+1<=N){
    		res2[i+1]=(res2[i+1]+mod-(b0.query(i+N-1)+mod-b0.query(i))%mod)%mod;
    		ll allcnt=B1.query(i+N-1)-B1.query(i);res2[i+1]=(res2[i+1]+1ll*N*N%mod*((mx-A[i+1]-allcnt)%mod)%mod)%mod;
			allcnt%=mod;res2[i+1]=(res2[i+1]+1ll*i*i%mod*allcnt)%mod;
			ll c3=b3.query(i+N-1)-b3.query(i)+mod,c2=b2.query(i+N-1)-b2.query(i)+mod;c3%=mod;c2%=mod;
			res2[i+1]=(res2[i+1]+mod-2ll*i*c2%mod)%mod;
			res2[i+1]=(res2[i+1]+c3)%mod;   
		} 
		if(i-(N-2)<=N&&i-(N-2)>=1)res2[i-(N-2)]=(res2[i-(N-2)]+b0.query(i)-b0.query(i-(N-2)-1)+mod)%mod;
	} nd=1;B1.init();b2.init();b3.init();sort(B+1,B+tot+1,cmp1);
	for(int i=2*N;i>=1;--i){
		while(nd<=tot&&B[nd].y>=i){
			if(B[nd].x){
				B1.modify(B[nd].x,B[nd].cnt); b2.modify(B[nd].x,1ll*B[nd].x*B[nd].cnt%mod);
			    b3.modify(B[nd].x,1ll*B[nd].x*B[nd].x%mod*B[nd].cnt%mod);
			}
			++nd; 
		}
		if(i-(N-1)<=N&&i-(N-1)>=1){
			int l=i-(N-1);
			ll c1=B1.query(i-1)-B1.query(l-1),c2=b2.query(i-1)-b2.query(l-1)+mod,c3=b3.query(i-1)-b3.query(l-1)+mod;
		//	cout<<l<<" "<<c1<<endl;
			c2%=mod;c3%=mod;c1%=mod;
		    res2[l]=(res2[l]+1ll*i*i%mod*c1%mod)%mod;
		    res2[l]=(res2[l]-2ll*i*c2%mod+mod)%mod;
		    res2[l]=(res2[l]+c3)%mod;
		}
	}
	for(int i=1;i<=N;++i){
		print(res1[i]);putchar(' ');
		print(res2[i]);putchar('\n');
	}
}



int32_t main() {
	lnx();
	int t;
	cin >> t;
	W(t) {
		test();
	}
	fwrite(obuf, p3 - obuf, 1, stdout);
}


