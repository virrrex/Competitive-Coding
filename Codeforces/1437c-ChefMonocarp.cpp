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

int n;
vector<int>v;
int dp[200][405];
int solve(int idx,int t){
	if(idx==n)
		return 0;

	if(dp[idx][t]!=-1) 
        return dp[idx][t];

	int mn=INT_MAX;
	for(int i=t; i<=max(t,v[idx]); i++){
		mn=min(mn,abs(v[idx]-i)+solve(idx+1,i+1));
	}
	return dp[idx][t]=mn;
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
		cin>>n;
		v.resize(n);
		f(i,n) cin>>v[i];
		sortall(v);
		int ans = solve(0,1);
		cout<<ans<<endl;
    }

    return 0;
}