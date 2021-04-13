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

    vs s(4);
    f(i,4) cin>>s[i];
    int mx = 0;
    f(i,3){
        f(j,3){
            int cb = 0, cw = 0;
            (s[i][j]=='#')? cb++ : cw++;
            (s[i][j+1]=='#')? cb++ : cw++;
            (s[i+1][j]=='#')? cb++ : cw++;
            (s[i+1][j+1]=='#')? cb++ : cw++;
            cb = max(cb,cw);
            mx = max(mx, cb);
        }
    }
    if(mx >=3) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}