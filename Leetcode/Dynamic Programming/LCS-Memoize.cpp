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

// LONGEST COMMON SUBSUQUENCE
int static dp[1001][1001];

int LCS(string x, string y, int n, int m)
{
    if(n == 0 || m == 0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    if(x[n-1] == y[m-1])
        return dp[n][m] = 1 + LCS(x,y, n-1, m-1);
    else 
        return dp[n][m] = max(LCS(x,y, n, m-1), LCS(x,y, n-1, m));
}

int main()
{
    rex;

    memset(dp, -1, sizeof(dp));
    string x="abcdgf", y="abedfha";
    // cin>>x>>y;
    cout<<"Size of longest common subsequence is: "<<LCS(x,y, x.length(), y.length());

    return 0;
}