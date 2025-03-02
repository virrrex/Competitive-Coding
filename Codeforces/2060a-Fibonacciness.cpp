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

    int t; cin>>t;
    while(t--)
    {
        int a1,b,c,d; cin>>a1>>b>>c>>d;
        vi a;
        int a3 = a1 + b;
        a.pb(a1); a.pb(b); a.pb(a3); a.pb(c); a.pb(d);

        int count = 0;
        int maxCount = 0;
        
        fx(i,1,101) {
            a[2] = i;
            count = 0;
            f(i,3){
                if(a[i] + a[i+1] == a[i+2])
                    count++;
            }
            maxCount = max(maxCount, count);
        }

        for(int i=-110; i<=0; i++){
            a[2] = i;
            count = 0;
            f(i,3){
                if(a[i] + a[i+1] == a[i+2])
                    count++;
            }
            maxCount = max(maxCount, count);
        }
        
        cout<<maxCount<<nl;
    }

    return 0;
}


// 1 3 2 1
// 1 3 4 2 1 => 1 
// 1 3 -1 2 1 => 2