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

ll prime[10000001] = {0};
void primeSieve(ll n)
{
    // ll prime[n+1] = {0};         // causes segmentation fault
    // ll prime[10000001] = {0};    // causes segmentation fault
    for(ll i=2; i<=n; i++){
        if(prime[i] == 0){
            for(ll j=i*i; j<=n; j+=i)
                prime[j] = 1;
        }
    }
}

int main()
{
    rex;

    int t; cin>>t;
    primeSieve(10000001);
    while(t--)
    {
        ll n; cin>>n;
        ll ans = 0;
        fx(i,2,n+1){
            if(prime[i] == 0)
                ans += n/i;
        }
        cout<<ans<<nl;
    }

    return 0;
}



// list of prime numbers till 10^7 (664579)
/*
lcm * gcd = a*b
F = a*b/gcd^2

1,2 1,3 1,5 1,7; (no. of primes till n)
2,4 2,6 2,10; (no. of primes till n/2)
3,6 3,9; (no. of primes till n/3)
4,8; (no. of primes till n/4)
5,10
*/