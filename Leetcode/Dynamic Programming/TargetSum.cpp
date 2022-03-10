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

// SAME AS COUNT SUBSET WITH GIVEN DIFF PROBLEM
// HANDLED ELEMENTS WITH VALUE 0

int countSubsetSum(vi arr, int n, int sum)
{
    int dp[n+1][sum+1];
    f(i,sum+1) dp[0][i] = 0;
    int zct = 0; dp[0][0] = 1;
    fx(i,1,n+1){ 
        if(arr[i-1]==0) zct++; 
        dp[i][0] = pow(2,zct);
    }

    fx(i,1,n+1)
        fx(j,1,sum+1){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
        }
    return dp[n][sum];
}

int targetSum(vi arr, int n, int target)
{
    int sum = accumulate(all(arr), 0);
    if(target > sum) return 0;
    if((sum-target)%2 != 0) return 0;
    int s1 = (sum - target)/2;
    return countSubsetSum(arr, n, s1);
}

int main()
{
    rex;

    vi arr = {1,1,2,3};
    int n = arr.size();
    int target = 1;
    cout<<"No. of ways target = "<<target<<" is achievable using + and - operations are: "<<(targetSum(arr, n, target));

    return 0;
}