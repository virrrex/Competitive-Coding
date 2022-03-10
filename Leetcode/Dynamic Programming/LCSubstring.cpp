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
#define all(x)          (x).begin(), (x).end()
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

// LONGEST COMMON SUBSTRING
int dp[10007][10007];

int LCSubstring(string x, string y, int n, int m)
{
    mem0(dp);
    int ans = 0, idx, idy;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = 0;
            if(dp[i][j] > ans){
                ans = dp[i][j];
                idx = i; idy = j;
            }
        }
    }

    //  Print
    int i=idx, j=idy;
    string res = "";
    while(i>0 && j>0){
        res = x[i-1] + res;
        i--; j--;
    }
    cout<<res<<nl;

    return ans;
}

int main()
{
    rex;

    string x="GeeksforGeeks", y="GeeksQuiz";
    cout<<"Size of longest common substring is: "<<LCSubstring(x,y,x.length(), y.length());

    return 0;
}