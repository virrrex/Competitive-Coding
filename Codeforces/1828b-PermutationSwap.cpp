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
        int n; cin>>n;
        vi a(n);
        int ans = -1;
        f(i,n) {
            cin>>a[i];
            if(a[i] != i+1) {
                if(ans == -1)
                    ans = abs(a[i] - (i+1));
                else
                    ans = __gcd(ans, abs(a[i] - (i+1)));
            }
        }
        cout<<ans<<nl;
    }
    return 0;
}

// 3 1 2
// 2 1 1

// 3 4 1 2
// 2 2 2 2

// 4 2 6 7 5 3 
// 3 0 3 3 0 3

// 1 6 7 4 9 2 3 8 5
// 0 4 4 0 5 4 4 0 4

// 1 5 3 4 2 6
// 0 3 0 0 3 0

// 3 10 5 2 9 6 7 8 1 4
// 2 8  2 2 4 0 0 0 8 6

// 1 11 6 4 8 3 7 5 9 10 2
// 0 9  3 0 3 3 0 3 0 0  9
