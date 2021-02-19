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

vi xprim(1000001, 0);
void SieveOfAtkin(int limit) 
{
    limit++;
    bool sieve[limit]; 
    for (int i = 0; i < limit; i++) 
        sieve[i] = false; 
    for (int x = 1; x * x < limit; x++) { 
        for (int y = 1; y * y < limit; y++) { 
            int n = (4 * x * x) + (y * y); 
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) 
                sieve[n] ^= true; 
            n = (3 * x * x) + (y * y); 
            if (n <= limit && n % 12 == 7) 
                sieve[n] ^= true; 
            n = (3 * x * x) - (y * y); 
            if (x > y && n <= limit && n % 12 == 11) 
                sieve[n] ^= true; 
        } 
    } 
    for (int r = 5; r * r < limit; r++) { 
        if (sieve[r]) { 
            for (int i = r * r; i < limit; i += r * r) 
                sieve[i] = false; 
        } 
    }
    xprim[2]=1; xprim[3]=2; xprim[4]=2;
    for (int a = 5,z=2; a < limit; a++){
        if (sieve[a])
            z++;
        xprim[a] = z;
    }
}

int main()
{
    rex;

    int mx=0;
    int t; cin>>t;
    vi xx, yy;
    while(t--)
    {
        int x, y; cin>>x>>y; xx.pb(x); yy.pb(y);
        mx = max(mx, x);
    }
    SieveOfAtkin(mx);
    f(i,xx.size()){
        if(xprim[xx[i]] > yy[i])
            cout<<"Divyam\n";
	    else 
	        cout<<"Chef\n";
    }

    return 0;
}
