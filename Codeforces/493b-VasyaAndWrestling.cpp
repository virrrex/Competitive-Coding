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

    int n; cin>>n;
    vi a1, a2;
    ll sum1 = 0, sum2 = 0;
    bool last = true;
    f(i,n){
        int x; cin>>x;
        if(x>=0) {
            a1.pb(x); 
            sum1 += x;
            last = true;
        }
        else{
            x *= -1;
            sum2 += x;
            a2.pb(x);
            last = false;
        }
    }
    if(sum1>sum2) cout<<"first\n";
    else if(sum2>sum1) cout<<"second\n";
    else{
        if(a1>a2) cout<<"first\n";
        else if(a2>a1) cout<<"second\n";
        else{
            if(last) cout<<"first\n";
            else cout<<"second\n";
        }
    }

    return 0;
}