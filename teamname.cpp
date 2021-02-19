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

int uniqFirst(vector<char> a, vector<char> b)
{
    set<char> s = s;
    for(auto c: a) s.insert(c);
    int same = 0;
    for(auto i: b){
        if(s.find(i) != s.end())
            same++;
    }
    return same;
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        map<string, vector<char>> mp;
        f(i,n){
            string s; cin>>s;
            mp[s.substr(1)].pb(s[0]);
        }
        int ans = 0;
        for(auto i: mp)
            for(auto j: mp)
                if(i.ff != j.ff){
                    int same = uniqFirst(i.ss, j.ss);
                    ans += (i.ss.size() - same) * (j.ss.size() - same);
                }
        cout<<ans<<endl;
    }

    return 0;
}