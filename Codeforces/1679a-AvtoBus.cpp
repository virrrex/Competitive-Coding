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
        ll n; cin>>n;
        if (n < 4) {
            cout<<-1<<nl;
            continue;
        }
        bool notSix = false, notFour = false;
        if(n % 6 == 0 || n % 6 == 2 || n % 6 == 4) cout<<(n+5)/6<<" ";
        else notSix = true;

        if(n % 4 == 0 || n % 4 == 2) {
            cout<<n/4<<" ";
            if(notSix) cout<<n/4;
        }
        else {
            notFour = true;
            if(!notSix) cout<<n/6;
        }

        if(notSix && notFour) cout<<-1;
        cout<<nl;
    }
    return 0;
}

// 548 -> 92 137
// 548 % 6 = 2 => 6+2 = 8 => 548/6 = 91.3 => 90 + (8/4) = 92
// 549 % 6 = 3 => odd not possible
// 547 % 6 = 1 => odd not possible
// 550 % 6 = 4 => 550/6 = 91 + (4/4) = 92

// 550 % 4 = 2 => 4+2 = 6 => 550/4 = 137.5 => 136 + (6/6) = 137