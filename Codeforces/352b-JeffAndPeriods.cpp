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
    map<int,vi> mp;
    f(i,t){
        int x; cin>>x;
        mp[x].pb(i);
    }
    set<pii> ans;
    for(auto i: mp){
        if(i.ss.size() == 1)
            ans.insert({i.ff, 0});
        else if(i.ss.size() == 2)
            ans.insert({i.ff, i.ss[1]-i.ss[0]});
        else{
            int cd = i.ss[1]-i.ss[0];
            bool ok = 1;
            fx(j,2,i.ss.size()){
                if(i.ss[j]-i.ss[j-1] != cd){
                    ok = 0;
                    break;
                }
            }
            if(ok)
                ans.insert({i.ff, cd});
        }
    }
    cout<<ans.size()<<endl;
    for(auto i: ans)
        cout<<i.ff<<" "<<i.ss<<endl;

    return 0;
}