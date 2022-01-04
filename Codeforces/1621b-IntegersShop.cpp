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
#define all(x)          (x).begin(), (x).end()
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
        int minL, maxR, valL = 0, valR = 0, maxn = 0, minval = 0;
        f(i,n){
            int l, r, c; cin>>l>>r>>c;
            if(i == 0){
                minL = l; maxR = r;
                valL = valR = c;
                maxn = r-l+1;
                minval = c;
            }
            else {
                if(l < minL) minL = l, valL = c;
                else if(l == minL) valL = min(valL, c);
                if(r > maxR) maxR = r, valR = c;
                else if(r == maxR) valR = min(valR, c);
                if(r - l + 1 > maxn){
                    maxn = r - l + 1;
                    minval = c;
                }
                else if(r - l + 1 == maxn)
                    minval = min(minval, c);
            }
            int ans = valL + valR;
            if(maxR - minL + 1 == maxn)
                ans = min(ans, minval);
            cout<<ans<<nl;
        }
    }

    return 0;
}