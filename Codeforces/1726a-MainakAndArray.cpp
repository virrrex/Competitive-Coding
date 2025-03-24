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
        int n; cin>>n;
        vi a(n); f(i,n) cin>>a[i];

        int mx = 0, mn = 3000, mxidx = -1, mnidx = -1;
        f(i,n){
            if(a[i] > mx){
                mx = a[i];
                mxidx = i;
            }
            if(a[i] < mn){
                mn = a[i];
                mnidx = i;
            }
        }
        vi mxidxs, mnidxs;
        bool maxmin = false;
        f(i,n){
            if(a[i] == mx){
                mxidxs.pb(i);
                if(i == n-1)
                    maxmin = true;
                else if(a[i+1] == mn)
                    maxmin = true;
            }
            if(a[i] == mn){
                mnidxs.pb(i);
                if(i == 0)
                    maxmin = true;
            }
        }

        if(maxmin)
            cout<<mx-mn<<nl;
        else {
            int ans = -1;
            ans = max(mx-a[0], a[n-1]-mn);
            f(i,n){
                if(a[i] == mx){
                    if(i != n-1)
                        ans = max(ans, mx-a[i+1]);
                }
                if(a[i] == mn){
                    if(i != 0)
                        ans = max(ans, a[i-1]-mn);
                }
            }
            f(i,n-1){
                ans = max(ans, a[i]-a[i+1]);
            }
            cout<<ans<<nl;
        }
            // cout<<max({mx-a[0], a[n-1]-mn, mx-a[mxidx+1], a[mnidx-1]-mn})<<nl;
        
    }

    return 0;
}

//

// 1 x x x x x 11
// x 1 x x x 11 x
// 2 1 x x x 11 5
// 5 4 1 4 11 10 2

// max then min adjacecnt || min in 0th || max in n-1th => ans(max-min)
// else 
// max(max-0th, n-1th-min, max - amx+1, amin-1 - min)
// max(diff of adjacents)