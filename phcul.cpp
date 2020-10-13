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

double distance(int x1, int y1, int x2, int y2)
{
    double ans;
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
        double min = 10000000000, d1, d2, d3, e1, e2, e3;
        vll red(2*n), green(2*m), blue(2*k);
        f(i,2*n) cin>>red[i];
        f(i,2*m) cin>>green[i];
        f(i,2*k) cin>>blue[i];
        
        for(int i=0; i<2*n; i+=2)
        {
            d1 = distance(red[i], red[i+1], x, y);
            for(int j = 0; j<2*m; j+=2)
            {
                d2 = distance(red[i], red[i+1], green[j], green[j+1]);
                for(int l = 0; l<2*k; l+=2)
                {
                    d3 = distance(green[j], green[j+1], blue[l], blue[l+1]);
                    if((d1 + d2 + d3)<min)
                        min = d1 + d2 + d3;
                }
            }
        }
        for(int i=0; i<2*m; i+=2)
        {
            e1 = distance(green[i], green[i+1], x, y);
            for(int j = 0; j<2*n; j+=2)
            {
                e2 = distance(green[i], green[i+1], red[j], red[j+1]);
                for(int l = 0; l<2*k; l+=2)
                {
                    e3 = distance(red[j], red[j+1], blue[l], blue[l+1]);
                    if((e1 + e2 + e3)<min)
                        min = e1 + e2 + e3;
                }
            }
        }
        cout<<fixed<<setprecision(10)<<min<<endl;
    }
    
    return 0;
}