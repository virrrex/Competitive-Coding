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
#define deb2(x, y)      cout<<#x<< "=" <<x<<","<<#y<<"="<<y<<endl
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

int solve(ll a1, ll a2, ll b1, ll b2, int res)
{
    if(res>8)
        return res;
    if(a1 == b1 && a2 == b2)
        return res;
    
    ll e = a1 + 2*a2;
    ll w = a1 - 2*a2;
    ll n2 = a2 + 2*a1, n1;
    if(n2>0)
        n1 = a1;
    else{
        n2 = -n2;
        n1 = -a1;
    }
    ll s2 = a2 - 2*a1, s1;
    if(s2>0)
        s1 = a1;
    else{
        s2 = -s2;
        s1 = -a1;
    }
    res++;
    int east = solve(e, a2, b1, b2, res);     
    int west = solve(w, a2, b1, b2, res);     
    int north = solve(n1, n2, b1, b2, res);     
    int south = solve(s1, s2, b1, b2, res);     
    res = min(east, min(west, min(north, south)));
    return res;
}

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        ll a1, a2, b1, b2;
        int res = 0, ans;
        cin>>a1>>a2>>b1>>b2;
        ans = solve(a1, a2, b1, b2, res);
        cout<<ans<<endl;
    }
    
    return 0;
}