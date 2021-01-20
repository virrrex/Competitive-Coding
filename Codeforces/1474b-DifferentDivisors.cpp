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

const int n = 100001;
vi prime(n,0);
vi primes;
void primeSieve()
{
    for(int i=2; i<=n; i++){
        if(prime[i] == 0){
            for(ll j=(ll)i*i; j<=(ll)n; j+=i)
                prime[j] = 1;
        }
    }
    for(int i=2; i<=n; i++)
        if(prime[i] == 0)
            primes.pb(i);
}

int main()
{
    rex;

    int t; cin>>t;
    primeSieve();
    while(t--)
    {
        int d; cin>>d;
        ll ans;
        int a = *lower_bound(all(primes), 1+d);
        int b = *lower_bound(all(primes), a+d);
        ans = (ll) a*b;
        cout<<ans<<endl;
    }

    return 0;
}