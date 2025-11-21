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
        f(i,n) cin>>a[i];
        sortall(a);
        if(a[0] == a[n-1]) {
            cout<<0<<nl;
            continue;
        }

        int mx = 1, curr = 1;

        fx(i,1,n) {
            if(a[i] == a[i-1]) {
                curr++;
                mx = max(mx, curr);
            }
            else {
                curr = 1;
            }
        }

        int ans = n - mx;
        while(mx < n) {
            ans++;
            mx *= 2;
        }
        cout<<ans<<nl;
    }
    return 0;
}

// 1 2 3 4 5
// 1 op copy, 2. swap: 11345, 3. op copy, 5. op swap: 11115, 7. copy+swap: 11111
// 1->2, 2->4, 4->8, 8->16
// 3->6, 6->12, 12->24