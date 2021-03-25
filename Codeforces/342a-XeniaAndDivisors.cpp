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

    int n; cin>>n;
    vi a(n), d(10,0); 
    bool ok = true;
    f(i,n){
        cin>>a[i];
        if(a[i] == 5 || a[i] == 7)
            ok = false;
        d[a[i]]++;
    }
    int div = n/3;
    if(d[1] != div)
        ok = false;
    if(d[2] + d[3] != div)
        ok = false;
    if(d[4] + d[6] != div)
        ok = false;
    
    int a136 = d[3];
    if(d[3] <= d[6])
        d[6] -= a136;
    else ok = false;
    int a124 = d[4], a126;
    if(d[4] <= d[2])
        d[2] -= a124;
    else ok = false;
    if(d[2] == d[6])
        a126 = d[2];
    else ok = false;

    if(!ok){
        cout<<"-1\n";
        return 0;
    }

    f(i,a124) cout<<"1 2 4\n";
    f(i,a126) cout<<"1 2 6\n";
    f(i,a136) cout<<"1 3 6\n";

    return 0;
}