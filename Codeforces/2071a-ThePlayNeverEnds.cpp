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
        if(n == 1 || (n-1)%3==0)
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }

    return 0;
}

// abc
// 1 2 3 4 5 6 7 8 9 10

// 1: c spectator
// 2: a/b wins c plays: no
// 3: 1-(ab)a wins, 2-(ac) a wins, 3-(bc): no
// 4: 1-(ab)a wins, 2-(ac) a wins, 3-(bc) b wins, 4-(ab): yes
// 5: 1-(ab)a wins, 2-(ac) a/c wins, 3-(bc) c wins, 4-(ac) a/b wins, 5-(ab): yes
// 6: 