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
    vi ar(n+1,0);
    f(j,m){
        int x,y,z; cin>>x>>y>>z;
        set<int> ans;
        fx(i,1,4) ans.insert(i);
        if(ar[x] != 0)
            ans.erase(ar[x]);
        else if(ar[y] != 0)
            ans.erase(ar[y]);
        else if(ar[z] != 0)
            ans.erase(ar[z]);

        if(ar[x] == 0){
            ar[x] = *ans.begin();
            ans.erase(ans.begin());
        }
        if(ar[y] == 0){
            ar[y] = *ans.begin();
            ans.erase(ans.begin());
        }
        if(ar[z] == 0){
            ar[z] = *ans.begin();
            ans.erase(ans.begin());
        }
    }
    fx(i,1,n+1)
        cout<<ar[i]<<" ";

    return 0;
}