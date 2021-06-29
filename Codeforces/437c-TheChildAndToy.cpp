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

    int v, e; cin>>v>>e;
    vpii vtx;
    vi vmap(v+1, 0);
    f(i,v){
        int x; cin>>x;
        vtx.pb({x,i+1});
        vmap[i+1] = x;
    }
    sort(all(vtx), greater<pii>());
    vi adj[v+1];
    f(i,e){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll ans = 0;
    vi vis(v+1,0);
    for(auto it: vtx){
        if(!vis[it.ss]){
            vis[it.ss] = 1;
            for(auto x: adj[it.ss])
                if(!vis[x])
                    ans += (ll)vmap[x];
        }
    }
    cout<<ans<<nl;

    return 0;
}