#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fx(i,x,n)       for(int i = x; i < n; i++)
#define Fx(i,x,n)       for(ll i = x; i < n; i++)
#define endl            '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x)          x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

// gcd(a,b) = gcd(a, abs(a-b))
// gcd(a+k, b+k) = gcd(a+k, a-b)
// gcd(a+k,b+k,c+k,d+k) = gcd(a+k,a-b,a-c,a-d)

int main()
{
    rex;

    ll n, m; cin>>n>>m;
    vll a(n), b(m), v;
    F(i,n) cin>>a[i];
    F(i,m) cin>>b[i];
    if(n == 1){
        F(i,m)
            cout<<a[0]+b[i]<<" ";
    }
    else{
        Fx(i,1,n)
            v.pb(abs(a[0] - a[i]));
        ll g = v[0];
        F(i,v.size())
            g = __gcd(g, v[i]);
        F(i,m)
            cout<<__gcd(g, a[0]+b[i])<<" ";
    }
    cout<<endl;
    
    return 0;
}