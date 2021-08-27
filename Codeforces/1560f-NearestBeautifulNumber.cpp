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

string to_string(int n){
    ostringstream ss;
    ss << n;
    return ss.str();
}

string solve(int i, int n, int dist, string nw, int k, string ori){
    if (dist > k)
        return "";
    
    if (nw.substr(0, i) < ori.substr(0, i))
        return "";
    
    if (i >= n)
        return nw;
    
    for (char val = '0'; val <= '9'; ++val) {
        nw[i] = val;
        bool found = false;
        for (int j = 0; j < i; ++j) {
            if (nw[j] == val) {
                found = true;
                break;
            }
        }
        string chk = solve(i + 1, n, dist + (found == false), nw, k, ori);
        if (chk.length())
            return chk;
    
    }
    return "";
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        int n, k; cin>>n>>k;
        string s = to_string(n);
        string ans = solve(0, s.length(), 0, string(s.length(), '0'), k, s);
        cout<<ans<<nl;
    }

    return 0;
}