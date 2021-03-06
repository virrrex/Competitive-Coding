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
#define mod             1000003
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
#define int int64_t

int power(int n, int p)
{
    int ans = 1;
    while(p){
        if(p&1){
            ans *= n;
            ans %= mod;
        }
        p /= 2;
        n *= n;
        n %= mod;
    }
    return ans;
}

int32_t main()
{
    rex;

    string s; cin>>s;
    map<char, string> mp;
    mp['>'] = "1000";
    mp['<'] = "1001";
    mp['+'] = "1010";
    mp['-'] = "1011";
    mp['.'] = "1100";
    mp[','] = "1101";
    mp['['] = "1110";
    mp[']'] = "1111";
    string intm = "";
    for(char i: s)
    intm += mp[i];
    int ans = 0;
    for(int i=intm.size()-1; i>=0; i--){
        if(intm[i] == '1'){
            int kk = power(2,intm.size()-1-i);
            kk %= mod;
            ans += kk;
            ans %= mod;
        }
    }
    cout<<ans<<endl;

    return 0;
}