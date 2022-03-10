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

int countSubsetSum(vi arr, int n, int sum)
{
    int dp[n+1][sum+1];
    f(i, sum+1) dp[0][i] = 0;
    f(i, n+1) dp[i][0] = 1;

    fx(i,1,n+1)
        fx(j,1,sum+1){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
        }
    return dp[n][sum];
}

int countSubsetWithGivenDiff(vi arr, int n, int diff)
{
    // s1 - s2 = diff
    // s1 + s2 = sum
    // s1 = (diff + sum)/2      more optimize: (sum-diff)/2
    int sum = accumulate(all(arr), 0);
    int s1 = (diff + sum)/2;
    return countSubsetSum(arr, n, s1);
}

int main()
{
    rex;

    int n=4;
    vi arr = {1,1,2,3};
    int diff = 1;
    cout<<"Count of Subsets with diff = "<<diff<<" is: "<<(countSubsetWithGivenDiff(arr, n, diff));

    return 0;
}