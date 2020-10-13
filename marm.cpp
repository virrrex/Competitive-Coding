#include <bits/stdc++.h>
using namespace std;

#define pb      push_back
#define ff      first
#define ss      second
#define ll      long long
#define f(i,n)  for(int i = 0; i < n; i++)
#define F(i,n)  for(ll i = 0; i < n; i++)
#define endl    '\n'
#define mod     1000000007
#define rex     ios_base::sync_with_stdio(0);cin.tie(0)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

/*Chef is really interested in the XOR operation. He wants to take a sequence A0,A1,…,AN−1 and
for each i from 0 to K−1 inclusive (in this order, one by one), perform the following operation:

Let's denote a=Ai%N and b=AN−(i%N)−1 before this operation.
Change Ai%N to a⊕b, i.e. a XOR b.*/

int main()
{   
    rex;

    int t; cin>>t;
    while (t--)
    {
        ll n, k, x;
        cin>>n>>k;
        vll ar;
        if (k >= n * 3)
            k = n*3 + (k % (n*3));
        F(i,n) cin>>x, ar.pb(x);
        F(i,k)
            ar[i%n] ^= ar[n - (i%n) -1];
        F(i,n)
            cout<<ar[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}