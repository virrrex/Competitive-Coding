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
    
    ll kMaxValue = 10000;
    vll primes;
    primes.pb(2);
    vll summed;
    ll sum = 2;
    cin>>kMaxValue;
    for(ll i = 3; i <= kMaxValue; i += 2)
    {
        bool isPrime = true;
        for(auto p : primes)
        {
            if(p*p > i)
                break;
            if(i % p == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            primes.pb(i);
            sum += i;
            if(sum%mod <= kMaxValue)
                summed.pb(sum);
        }
    }
    sum = 0;
    for(ll i=0; i<summed.size(); i++){
        if( binary_search(primes.begin(), primes.end(), summed[i]) )
            sum++;
    }

    // for(auto i : primes)
    //     cout<<i<<" ";   cout<<endl;
    for(auto i : summed)
        cout<<i<<" ";   cout<<endl;
    cout<<sum<<endl;
    return 0;
}

