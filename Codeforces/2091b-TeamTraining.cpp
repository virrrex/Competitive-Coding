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

bool isSquare(ll n){
    ll root = sqrt(n);
    return (root*root == n);
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        ll n,x; cin>>n>>x;
        vll a(n); F(i,n) cin>>a[i];
        sortall(a);

        ll ans = 0, mult = 1, mn = 1e11;

        for(ll i=n-1; i>=0; i--){
            mn = min(mn, a[i]);
            if(mn * mult >= x){
                ans++;
                mn = 1e11;
                mult = 1;
            }
            else
                mult++;
        }

        cout<<ans<<nl;
    }
    return 0;
}
// sort(4 5 3 3 2 6) = 2 3 3 4 5 6
// 5 3 2 3 2 => 2 2 3 3 5
// 6 1 3 6 3 2 => 1 2 3 3 6 6