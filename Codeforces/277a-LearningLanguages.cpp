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

void dfs(int node, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it])
            dfs(it, vis, adj);
    }
}

int dfsOfGraph(int v, int n, vector<int> adj[]){
    vector<int> vis(v+1, 0);
    int c = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i] && ++c)
           dfs(i, vis, adj);
    }
    return c;
}

int main()
{
    rex;

    int n, m; cin>>n>>m;
    vector<int> adj[n+1+m];
    bool ok = false;
    fx(i,1,n+1){
        int k; cin>>k;
        if(k != 0) ok = true;
        f(j,k){
            int x; cin>>x;
            adj[i].pb(n+x);
            adj[n+x].pb(i);
        }
    }
    if(ok)
        cout<<dfsOfGraph(n+m, n, adj) - 1<<nl;
    else
        cout<<n<<nl;

    return 0;
}