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

//  PRINT SHORTEST COMMON SUPERSEQUENCE
int dp[10007][10007];

string printSCS(string x, string y, int n, int m){
    mem0(dp);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i=n, j=m;
    string ans = "";
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            ans = x[i-1] + ans;
            i--; j--;
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            ans = y[j-1] + ans;
            j--;
        }
        else{
            ans = x[i-1] + ans;
            i--;
        }
    }
    while(i>0){
        ans = x[i-1] + ans;
        i--;
    }
    while(j>0){
        ans = y[j-1] + ans;
        j--;
    }
    return ans;
}

int main()
{
    rex;

    string x="AGGTAB", y="GXTXAYB";
    cout<<"Shortest common supersequence is: "<<printSCS(x,y,x.length(), y.length());

    return 0;
}