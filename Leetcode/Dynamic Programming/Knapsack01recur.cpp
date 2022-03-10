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

int dp[102][1002];

int knapsack(vi wt, vi val, int w, int n){
    if(n == 0 || w == 0)
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(wt[n-1] <= w)
        return dp[n][w] = max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
    else if(wt[n-1] > w)
        return dp[n][w] = knapsack(wt, val, w, n-1);
}

int main()
{
    rex;
    
    memset(dp, -1, sizeof(dp));
    int n = 5;
    vi wt = {7, 8, 2, 2, 3};
    int w = 11;
    vi val = {10, 12, 66, 9, 8};
    cout<<knapsack(wt, val, w, n);


    return 0;
}