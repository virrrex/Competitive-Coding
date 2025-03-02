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
        int n, k; cin>>n>>k;
        vi a(n); f(i,n) cin>>a[i];
        sortall(a);
        int ans = 0;

        for(int i=0, j=n-1; i<j;){
            if(a[i] + a[j] == k){
                ans++;
                i++; j--;
            }
            else if(a[i] + a[j] < k)
                i++;
            else
                j--;
        }

        cout<<ans<<nl;
    }

    return 0;
}

// 16 9
// 3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3

//    1 1 2 3 3 3 4 5 5 5 6 7 8 9 9 9

//    pair of 9 = (1,8) (2,7) (3,6) (4,5)

