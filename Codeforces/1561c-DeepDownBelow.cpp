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
        vector<vi> caves(n);
        vpii armor;
        f(i,n){
            int x,y; cin>>x;
            int mx = -1;
            f(j,x){
                cin>>y; caves[i].pb(y);
                if(mx == -1)
                    mx = y+1;
                if(mx + j - y <= 0)
                    mx += (y-(mx+j) + 1);
            }
            armor.pb({mx, caves[i].size()});
        }
        
        sortall(armor);
        
        int l = armor[0].ff, r = armor[n-1].ff;
        int ans = -1;
        while(l <= r){
            int mid = (l+r)/2;
            int curr = mid, ok = 1;
            f(i,n){
                if(curr >= armor[i].ff)
                    curr += armor[i].ss;
                else{
                    ok = 0;
                    break;
                }
            }
            if(ok){
                ans = mid; r = mid-1;
            }
            else
                l = mid+1;
        }
        
        cout<<ans<<nl;
    }

    return 0;
}