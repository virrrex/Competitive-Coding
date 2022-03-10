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

int knapsack(vi wt, vi val, int w, int n){
    int dp[n+1][w+1];
    for(int i=0; i<n+1; i++)
        dp[i][0] = 0;
    for(int i=0; i<w+1; i++)
        dp[0][i] = 0;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<w+1; j++){
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    // f(i,n+1){f(j,w+1)cout<<dp[i][j]<<" ";cout<<endl;}cout<<endl;
    return dp[n][w];
}

int main()
{
    rex;
    
    int n = 5;
    vi wt = {7, 8, 2, 2, 3};
    int w = 11;
    vi val = {10, 12, 66, 9, 8};
    cout<<knapsack(wt, val, w, n);


    return 0;
}