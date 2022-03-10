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

//  CHECK WHETHER GIVEN STRING IS SUBSEQUENCE OF ANOTHER STRING
//  2-pointer is better approach for this problem - O(n) time complexity
int dp[10007][10007];

int LCS(string x, string y, int n, int m){
    mem0(dp);
    fx(i,1,n+1)
        fx(j,1,m+1){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    return dp[n][m];
}

void twoPointerApproach(string x, string y, int n, int m){
    int i=0, j=0;
    while(i < n && j < m){
        if(x[i] == y[j]){
            i++; j++;
        }
        else 
            j++;
    }
    cout<<"Using 2-pointer approach: ";
    if(i == n) cout<<"Yes\n";
    else cout<<"No\n";

}

int main()
{
    rex;

    string a = "AXY";
    string b = "ADXCPY";
    cout<<"Whether string \""<<a<<"\" is a subsequence of string \""<<b<<"\": ";
    if(LCS(a,b,a.length(), b.length()) == a.length())
        cout<<"Yes\n";
    else 
        cout<<"No\n";
    
    twoPointerApproach(a,b,a.length(),b.length());

    return 0;
}