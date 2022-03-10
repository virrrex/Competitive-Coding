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
//  Count the number of ways we can parenthesize the expression so that 
//  the value of expression evaluates to true.

//  EVALUATE EXPRESSION TO TRUE

int dp[1001][1001][2];
int evaluateExpression(string s, int i, int j, bool isTrue){
    if(i > j)
        return 0;
    if(i == j){
        bool x = (s[i]=='T'? true: false);
        return (isTrue == x);
    }
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;
    for(int k=i+1; k<=j-1; k+=2){
        int lt = evaluateExpression(s, i, k-1, true);
        int lf = evaluateExpression(s, i, k-1, false);
        int rt = evaluateExpression(s, k+1, j, true);
        int rf = evaluateExpression(s, k+1, j, false);
        
        if(s[k] == '&'){
            if(isTrue)
                ans  += lt*rt;
            else
                ans += lf*rf + lt*rf + lf*rt;
        }
        else if(s[k] == '|'){
            if(isTrue)
                ans += lt*rt + lt*rf + lf*rt;
            else
                ans += lf*rf;
        }
        else if(s[k] == '^'){
            if(isTrue)
                ans += lt*rf + lf*rt;
            else 
                ans += lt*rt + lf*rf;
        }
    }
    return dp[i][j][isTrue] = ans;
}

int main()
{
    rex;

    mem1(dp);
    string s = "T&F|T^F";
    int i=0, j=s.length()-1;
    cout<<"No. of ways to make "<<s<<" expression TRUE is "<<evaluateExpression(s,i,j,true)<<nl;

    return 0;
}