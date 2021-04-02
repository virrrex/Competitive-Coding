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

int dp[601][101][101];
int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    unordered_map<string,int> mp;
    for(int i=0; i<strs.size(); i++){
        int one = 0;
        for(int j=0; j<strs[i].size(); j++){
            if(strs[i][j] == '1')
                one++;
        }
        mp[strs[i]] = one;
    }
    for(int i=1; i<=len; i++){
        for(int j=0; j<=m; j++){
            for(int k=0;k<=n;k++){
                int ones = mp[strs[i-1]];
                int zeros = strs[i-1].size()-ones;
                int res = dp[i-1][j][k];
                if (zeros<=j && ones<=k) 
                    res = max(res, dp[i-1][j-zeros][k-ones]+1);
                dp[i][j][k] = res;
            }
        }
    }
    return dp[len][m][n];
}

int main()
{
    rex;

    memset(dp, 0, sizeof dp);
    int m,n;
    vs strs;
    strs = {"10","0001","111001","1","0"}; m = 5; n = 3;
    cout<<findMaxForm(strs,m,n);

    return 0;
}