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
    
    int k; cin>>k;
    int t; cin>>t;
    while(t--)
    {
        int n, m; cin>>n;
        ll sum = (n*(n+1))/2; ll half = sum/2, check=0, diff;
        f(i,n)
        {
            check += (i+1);
            if(check > half)
            {
                m = i;
                break;
            }
        }
        diff = check - half; ll tot=0;
        fx(i,m+1,n)
        {
            if(i+1 == diff)
                continue;
            else
                tot+=i+1;
        }
        tot += diff;
        int d = abs((sum-tot) - tot);
        cout<<d<<endl;
        f(i,m+1)
        {
            if(i+1 == diff)
                cout<<1;
            else
                cout<<0;
        }
        fx(i,m+1,n)
            cout<<1;
        cout<<endl;

    }
    
    return 0;
}