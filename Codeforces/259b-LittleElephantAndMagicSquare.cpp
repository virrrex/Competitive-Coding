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

    int magic[3][3];
    f(i,3)f(j,3) cin>>magic[i][j];
    int sx = magic[0][1] + magic[0][2];
    int sy = magic[1][0] + magic[1][2];
    int sz = magic[2][0] + magic[2][1];
    int mx = max(sx,max(sy,sz));
    int sum = 0;
    while(sum != mx){
        mx++;
        magic[0][0] = mx-sx;
        magic[1][1] = mx-sy;
        magic[2][2] = mx-sz;
        sum = magic[0][0]+magic[1][1]+magic[2][2];
    }
    f(i,3){f(j,3) cout<<magic[i][j]<<" "; cout<<endl;}

    return 0;
}