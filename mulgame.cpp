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

    int t; cin>>t;
    while(t--)
    {
        int n, q, m; cin>>n>>q>>m;
        vi a(n); f(i,n) cin>>a[i];
        vi dp(1000001, 0);
        map<pii, int> mp;
        while(q--){
            int l,r; cin>>l>>r;
            l--; r--;
            if(a[l] > m)
                continue;
            else if(a[l] <= m && a[r] > m){
                dp[a[l]]++; dp[m+1]--;
            }
            else if(a[r] <= m){
                dp[a[l]]++; dp[m+1]--;
                mp[{a[l], a[r]}]++;
            }
        }
        for(auto it: mp){
            int le = it.ff.ff, ri = it.ff.ss, ct = it.ss;
            int c = ri+2*le;
            dp[c-le] -= ct; dp[c] += ct;
            while(c+ri <= m){
                c += ri;
                dp[c] -= ct; 
                dp[c+le] += ct;
                c += le;
            }
        }
        fx(i,1,m+1)
            dp[i] += dp[i-1];
        int ans = *max_element(all(dp));
        cout<<ans<<endl;
    }

    return 0;
}