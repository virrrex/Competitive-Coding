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
        int n, k; cin>>n>>k;
        vi a(n); f(i,n) cin>>a[i];
        sortall(a);
        int ans = 1e8, cnt = 1;
        fx(i,1,n){
            if(a[i]-a[i-1] <= k)
                cnt++;
            else{
                ans = min(ans, n-cnt);
                cnt = 1;
            }
        }
        ans = min(ans, n-cnt);
        ans = (ans == 1e8) ? 0: ans;
        
        cout<<ans<<nl;
    }

    return 0;
}

// sort(17 3 1 20 12 5 17 12) = 1 3 5 12 12 17 17 20
// 2 3 19 10 8 => 2 3 8 10 19
// 8 3 1 4 5 10 7 3 => 1 3 3 4 5 7 8 10
// 1 2 4 5 6