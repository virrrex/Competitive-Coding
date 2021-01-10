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

    int n; cin>>n;
    vpii xy;
    f(i,n){
        int x, y; cin>>x>>y;
        xy.pb({x,y});
    }
    if(n<5) cout<<0<<endl;
    else{
        int count = 0;
        f(i,n){
            int u=0, d=0, l=0, r=0;
            f(j,n){
                if(xy[i].ff == xy[j].ff && xy[i].ss > xy[j].ss) d++;
                if(xy[i].ff == xy[j].ff && xy[i].ss < xy[j].ss) u++;
                if(xy[i].ss == xy[j].ss && xy[i].ff > xy[j].ff) l++;
                if(xy[i].ss == xy[j].ss && xy[i].ff < xy[j].ff) r++;
            }
            if(u>=1 && d>=1 && l>=1 && r>=1) count++;
        }
        cout<<count<<endl;  
    }

    return 0;
}