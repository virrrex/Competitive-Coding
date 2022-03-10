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

//  MATRIX CHAIN MULTIPLICATION
int dp[1001][1001];

int MCM(vi ar, int i, int j){
    int mn = INT_MAX;
    if(i>=j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    for(int k=i; k <= j-1; k++){
        int tmpans = MCM(ar, i, k) + MCM(ar, k+1, j) + ar[i-1]*ar[k]*ar[j];
        mn = min(mn, tmpans);
    }
    return dp[i][j] = mn;
}

int main()
{
    rex;
    mem1(dp);
    vi ar = {10,20,30,40,30};
    int i=1, j=ar.size()-1;
    cout<<"Minimum cost to multiply these matrices are: "<<MCM(ar, i, j);

    return 0;
}