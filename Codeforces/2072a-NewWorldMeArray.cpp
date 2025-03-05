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
        int n; double k,p; cin>>n>>k>>p;

        if(ceil(abs(k/p)) <= n)
            cout<<ceil(abs(k/p))<<nl;
        else
            cout<<-1<<nl;
    }

    return 0;
}

//
// 21 100 10 
// 100/10 = 10, 10<21 true, so 10

// 9 -420 42
// abs(-420/42) = 10, 10<9 false, so -1

// 5 -7 2
// ceil(abs(-7/2)) = 3 + 1, 4<5 true, so 4

// 13 37 7
// ceil(abs(37/7)) = 5+1, 6<13 true, so 6

// 20 31 1
// ceil(abs(31/1)) = 31, 31<20 false, so -1

// 1 -2 2
// ceil(abs(-2/2)) = 1, 1<=1 true, so 1