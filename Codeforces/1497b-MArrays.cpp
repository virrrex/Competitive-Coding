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

    int t; cin>>t;
    while(t--)
    {
        int n, m; cin>>n>>m;
        vi b(m,0);
        vi a(n); 
        int ans = 0;
        f(i,n){
            cin>>a[i];
            a[i] %= m;
            b[a[i]]++;
        }
        if(b[0]) ans++;
        fx(i,1,m){
            if(b[i]){
                if(abs(b[i] - b[m-i]) <= 1)
                    ans++;
                else 
                    ans += abs(b[i] - b[m-i]);
                b[m-i] = 0;
            }
        }
        cout<<ans<<nl;
    }

    return 0;
}