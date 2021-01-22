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

int main()
{
    rex;

    int n,m,d; cin>>n>>m>>d;
    vector<vi> ar(n,vi(m));
    vi src;
    f(i,n)f(j,m) {cin>>ar[i][j]; src.pb(ar[i][j]); }
    bool ok = 1;
    f(i,src.size())
        if(abs(src[i]-src[0]) % d != 0){
            ok = 0;
            break;
        }
    if(!ok)
        cout<<"-1\n";
    else{
        sortall(src);
        int st = 0, en = src.size()-1, ans = INT_MAX;
        while(en>=st){
            int mid1 = (en-st)/3 + st;
            int mid2 = 2*((en-st)/3) + st;
            int t1 = 0, t2 = 0;
            f(i,n){
                f(j,m){
                    t1 += abs(ar[i][j] - src[mid1]) / d;
                    t2 += abs(ar[i][j] - src[mid2]) / d;
                }
            }
            ans = min(ans, min(t1,t2));
            if(t1 >= t2)
                st = mid1 + 1;
            else 
                en = mid2 - 1;
        }
        cout<<ans<<endl;
    }

    return 0;
}