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

int n;
vector<vi> tree;
vi cc;
vector<unordered_map<int,int>> store;
vi branch;
vector<set<pii>> created;

void link(int node)
{
    branch[node]=node;
    for(auto &child: tree[node]){
        link(child);
        if(cc[node] == 1)
            branch[node] = branch[child];
    }
}

void DFS(int node)
{
    for(auto &to: tree[node])
    {
        int c = to;
        if(cc[node] == 1)
            c = branch[node];
        if(cc[c] == 0){
            store[node][cc[node]]++;
            store[c][1]++;
            continue; 
        }
        DFS(c);
        for(auto &it:store[c])
            store[node][cc[node]*it.ff]+=it.ss;
    }
}
      
int main()
{
    rex;

    cin>>n;
    tree.resize(n+1);
    cc.resize(n+1,0);
    store.resize(n+1);
    branch.resize(n+1);
    created.resize(n+1);
    fx(i,2,n+1){
        int x; cin>>x;
        tree[x].pb(i);
        cc[x]++;  
    }
    link(1);
    DFS(1);
    int q; cin>>q;
    while(q--)
    {
        int node, w; cin>>node>>w;
        node = branch[node];
        auto it = created[node].lower_bound(pii{w,-1});
        if(it!=created[node].end() && it->ff==w){
            cout<<(it->ss)<<endl;
            continue;
        }
        int p = 0;
        for(auto &i: store[node]){
            if(i.ff && w%i.ff==0)
                p += (w/i.ff)*i.ss;  
        }
        created[node].insert(pii{w,w-p});
        cout<<(w-p)<<endl;
    }

    return 0;
}