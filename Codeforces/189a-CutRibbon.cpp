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

int main()
{
    rex;

    int n, a,b,c; cin>>n>>a>>b>>c;
    vi dp(5000, 0);
    dp[a] = dp[b] = dp[c] = 1;
    fx(i,1,n+1){
        if(i>a and dp[i-a])
            dp[i] = dp[i-a] + 1;
        if(i>b and dp[i-b])
            dp[i] = max(dp[i], dp[i-b] + 1);
        if(i>c and dp[i-c])
            dp[i] = max(dp[i], dp[i-c] + 1);
    }
    cout<<dp[n];

    return 0;
}