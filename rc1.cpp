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
#define rex             ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(x)          (x).begin(), (x).end()
#define sortall(x)      sort(all(x))
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<< "=" <<x<<","<<#y<<"="<<y<<endl
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

bool fun(vi a, vi b){
    return a[3]>b[3];
}

bool fun2(pii a, pii b){
    return a.ss>b.ss;
}

int main()
{
    rex;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int w,h; cin>>w>>h;
    int n,m,r; cin>>n>>m>>r;
    vector<vi> building(n, vi(4));
    vpii antenna;
    f(i,n)      // x    y   latency     connection-speed
        cin>>building[i][0]>>building[i][1]>>building[i][2]>>building[i][3];
    f(i,m){
        int range, connection; cin>>range>>connection;
        antenna.pb({range, connection});
    }

    sort(all(building), fun);
    sort(all(antenna), fun2);
    
    vector<vi> antpos;
    int nm = 0;
    while(nm < n && nm < m){
        vi tmp;
        tmp.pb(nm);
        tmp.pb(building[nm][0]);
        tmp.pb(building[nm][1]);
        antpos.pb(tmp);
        nm++;
    }

    //  OUTPUT
    cout<<antpos.size()<<nl;
    f(i,antpos.size())
        cout<<antpos[i][0]<<" "<<antpos[i][1]<<" "<<antpos[i][2]<<nl;

    return 0;
}