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

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        vector<vector<char>> a(10, vector<char>(10));
        int ans = 0;
        f(i,10){
            f(j,10){
                cin>>a[i][j];
                if(i == 0 || i == 9 || j == 0 || j == 9){
                    if(a[i][j] == 'X')
                        ans++;
                }
                else if(i == 1 || i == 8 || j == 1 || j == 8){
                    if(a[i][j] == 'X')
                        ans += 2;
                }
                else if(i == 2 || i == 7 || j == 2 || j == 7){
                    if(a[i][j] == 'X')
                        ans += 3;
                }
                else if(i == 3 || i == 6 || j == 3 || j == 6){
                    if(a[i][j] == 'X')
                        ans += 4;
                }
                else if(i == 4 || i == 5 || j == 4 || j == 5){
                    if(a[i][j] == 'X')
                        ans += 5;
                }
            }
        }
        cout<<ans<<nl;
    }

    return 0;
}

