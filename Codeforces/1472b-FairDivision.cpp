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

bool subsetSum(vi arr, int n, int sum)
{
    int dp[n+1][sum+1];
    f(i, n+1)
        f(j, sum+1){
            if(i==0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j] = true;
        }
    
    fx(i,1,n+1)
        fx(j,1,sum+1){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
        }
    return dp[n][sum];
}

bool equalSumPartition(vi arr)
{
    int sum = 0;
    f(i, arr.size())
        sum += arr[i];
    if(sum%2 != 0)
        return false;
    else
        return subsetSum(arr, arr.size(), sum/2);
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        int n, sum=0; cin>>n;
        vi wt(n); f(i,n){ cin>>wt[i]; sum+=wt[i]; }
        if(sum%2) cout<<"NO\n";
        else {
            if(n%2){
                if(equalSumPartition(wt)) cout<<"YES\n";
                else cout<<"NO\n";
            //     sortall(wt);
            //     int sum2 = sum/2, x=0;
            //     f(i,n){
            //         if(x>sum2) break;
            //         x+=wt[i];
            //     }
            //     if(x==sum2) cout<<"YES\n";
            //     else if(x-1 == sum2 && wt[0]==1)cout<<"YES\n";
            //     else cout<<"NO\n";
            }
            else cout<<"YES\n";
        }
    }

    return 0;
}