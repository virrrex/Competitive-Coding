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
       ll a, b; cin>>a>>b;
       ll xk, yk; cin>>xk>>yk;
       ll xq, yq; cin>>xq>>yq;

       set<pll> king, queen;

       king.insert({xk+a, yk+b});
       king.insert({xk+a, yk-b});
       king.insert({xk-a, yk+b});
       king.insert({xk-a, yk-b});
       king.insert({xk+b, yk+a});
       king.insert({xk-b, yk+a});
       king.insert({xk+b, yk-a});
       king.insert({xk-b, yk-a});

       queen.insert({xq+a, yq+b});
       queen.insert({xq+a, yq-b});
       queen.insert({xq-a, yq+b});
       queen.insert({xq-a, yq-b});
       queen.insert({xq+b, yq+a});
       queen.insert({xq-b, yq+a});
       queen.insert({xq+b, yq-a});
       queen.insert({xq-b, yq-a});

       int fork = 0;
    
       for(auto i: king)
            if(queen.find(i) != queen.end())
                fork++;

       cout<<fork<<nl;
    }

    return 0;
}

