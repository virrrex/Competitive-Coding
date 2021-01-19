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

    int n,m; cin>>n>>m;
    if(m == 0){cout<<"YES\n"; return 0;}
    vi dirt(m); f(i,m) cin>>dirt[i];
    sortall(dirt);
    if(dirt[0]==1 || dirt[m-1]==n) {cout<<"NO\n"; return 0;}
    int flag = 0;
    f(i,m-2){
        if(dirt[i+1]-dirt[i] == 1 && dirt[i+2]-dirt[i+1] == 1){
            flag = 1;
            break;
        }
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";

    return 0;
}