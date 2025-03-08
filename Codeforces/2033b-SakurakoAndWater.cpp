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
#define all(x)          x.begin(), x.end()
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

bool isSquare(ll n){
    ll root = sqrt(n);
    return (root*root == n);
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<vi> matrix(n, vi(n));
        f(i,n) f(j,n) cin>>matrix[i][j];
        int ans = 0;

        f(jj,n){ // i = 0
            int i = 0;
            int minVal = 0;
            int j = jj;
            while(j<n){
                minVal = min(minVal, matrix[i][j]);
                i++;
                j++;
            }
            ans += minVal;

        }

        fx(ii,1,n){ // j = 0
            int j = 0;
            int minVal = 0;
            int i = ii;
            while(i<n){
                minVal = min(minVal, matrix[i][j]);
                i++;
                j++;
            }
            ans += minVal;
        }

        cout<<ans*-1<<nl;

    }
    return 0;
}
