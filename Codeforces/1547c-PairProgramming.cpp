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
        int k,n,m; cin>>k>>n>>m;
        vi a(n), b(m);
        f(i,n) cin>>a[i];
        f(i,m) cin>>b[i];
        int x = 0, y = 0, ok = 1;
        vi ans;
        while(x<n || y<m){
            if(a[x] == 0 && x<n){
                ans.pb(0);
                x++; k++;
            }
            else if(b[y] == 0 && y<m){
                ans.pb(0);
                y++; k++;
            }
            else if(a[x] <= k && x<n){
                ans.pb(a[x]);
                x++;
            }
            else if(b[y] <= k && y<m){
                ans.pb(b[y]);
                y++;
            }
            else{
                cout<<"-1\n";
                ok = 0;
                break;
            }
        }
        if(ok){
            f(i,ans.size())
                cout<<ans[i]<<" ";
            cout<<nl;
        }
    }

    return 0;
}