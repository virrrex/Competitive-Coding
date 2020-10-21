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
        int n; cin>>n;
        string s[n];
        f(i,n)
            cin>>s[i];
        int a = s[0][1], b = s[1][0], c = s[n-1][n-2], d = s[n-2][n-1];
        vpii pr;
        if(a == b){
            if(c == a) pr.pb({n, n-1});
            if(d == a) pr.pb({n-1, n});
        }
        else if(c == d){
            if(a == c) pr.pb({1,2});
            if(b == c) pr.pb({2,1});
        }
        else{
            pr.pb({2,1});
            if(c == a) pr.pb({n, n-1});
            if(d == a) pr.pb({n-1, n});
        }
        cout<<pr.size()<<endl;
        for(auto x: pr)
            cout<<x.ff<<" "<<x.ss<<endl;
    }

    return 0;
}