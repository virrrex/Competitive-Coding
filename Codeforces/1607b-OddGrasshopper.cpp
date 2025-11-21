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
#define nl              '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x)          x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        ll x, n; cin>>x>>n;
        int parity;
        if(x%2 == 0) parity = -1;
        else parity = 1;

        ll res = x;
        if(n % 4 == 0) res = x;
        else if(n % 4 == 1) res = x + (parity * n);
        else if(n % 4 == 2) res = x - parity;
        else if(n % 4 == 3) res = x - (parity * (n + 1));

        cout<<res<<nl;
    }
    return 0;
}

// even: 0 -1 1 4 0 -5 1 (-1 +2 +3 -4 -5 +6 +7 -8 -9 +10 ...)
                     //  (-1 +1 +4 -0 -5 +1 +8 -0 -9 +1 +12 -0 -13)
                     //  -1*(odd pattern)
// odd: 1 2 0 -3 1 6 0   ( 1 -2 -3 +4 +5 -6 -7 +8 +9 -10 ...)
                     //  (+1 -1 -4 +0 +5 -1 -8 +0 +9 -1 -12 +0 +13)
// every 4th second, 0
// every 3rd second, -(second+1) *parity
// every 2nd second, -1 *parity
// every 1st second, +1 *parity