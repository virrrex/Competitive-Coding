#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fx(i,x,n)       for(int i = x; i < n; i++)
#define endl            '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

long double distance(int x1, int y1, int x2, int y2)
{
    long double ans;
    ans = sqrt( pow((x1-x2),2) + pow((y1-y2),2) );
    return ans;
}

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        ll x, y; cin>>x>>y;
        int n, m, k; cin>>n>>m>>k; 
        const int N=5010;
        int a[N],b[N],c[N],d[N],e[N],f[N];
        long double ab1[N],ab2[N],cd1[N],cd2[N];
        
        f(i,n) cin>>a[i]>>b[i];
        f(i,m) cin>>c[i]>>d[i];
        f(i,k) cin>>e[i]>>f[i];
        
        f(i,n){
            ab1[i] = distance(x,y,a[i],b[i]);
            ab2[i] = 1e10;
            f(j,k)
                ab2[i] = min(ab2[i], distance(a[i],b[i],e[j],f[j]));
        }
        f(i,m){
            cd1[i] = distance(x,y,c[i],d[i]);
            cd2[i] = 1e10;
            f(j,k)
                cd2[i] = min(cd2[i], distance(c[i],d[i],e[j],f[j]));
        }
        long double ans = 1e10;
        f(i,n)
            f(j,m)
            ans = min({ans, ab1[i]+distance(a[i],b[i],c[j],d[j])+cd2[j],
                         cd1[j]+distance(c[j],d[j],a[i],b[i])+ab2[i]});
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    
    return 0;
}