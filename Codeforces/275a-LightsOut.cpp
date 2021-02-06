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

int main()
{
    rex;

    int m[3][3], ans[5][5];
    f(i,3) f(j,3){
        int x; cin>>x;
        m[i][j] = x&1;
        ans[i+1][j+1] = 1;
    }
    fx(i,1,4){
        fx(j,1,4){
            if(m[i-1][j-1] == 1){
                ans[i][j] ^= 1;
                ans[i+1][j] ^= 1; ans[i-1][j] ^= 1;
                ans[i][j+1] ^= 1; ans[i][j-1] ^= 1;
            }
        }
    }
    fx(i,1,4){
        fx(j,1,4)
            cout<<ans[i][j];
        cout<<endl;
    }

    return 0;
}