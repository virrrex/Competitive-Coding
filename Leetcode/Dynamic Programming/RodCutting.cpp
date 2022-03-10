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

// SAME AS UNBOUNDED KANPSACK
int rodCutting(vi length, vi price, int n, int len)
{
    int dp[n+1][len+1];
    f(i,n+1) dp[i][0] = 0;
    f(i,len+1) dp[0][i] = 0;
    fx(i,1,n+1)
        fx(j,1,len+1){
            if(length[i-1] <= j)
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    return dp[n][len];
}

int main()
{
    rex;

    int n = 8;
    // vi length = {1,2,3,4,5,6,7,8};
    vi length = {3,5,1,2};
    vi price = {1,5,8,9};
    // vi price = {1,5,8,9,10,17,17,20};
    cout<<rodCutting(length, price, length.size(), n);

    return 0;
}