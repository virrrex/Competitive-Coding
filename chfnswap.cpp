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

/*
A swap is nice if there is an integer M (1≤M<N) such that the sum of the first M elements of the resulting
sequence is equal to the sum of its last N−M elements. Find the number of nice swaps.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll sum = (n*(n+1))/2; ll res;
        if(sum>3 && sum%2 == 0)
        {
            long double i = (sqrtl(4*sum + 1) - 1.0)/2.0;
            ll pos = i;
            ll halfsum = (pos*(pos+1))/2;
            if(sum/2 == halfsum)
            {
                res = (pos*(pos-1)+(n-pos)*(n-pos-1))/2+(n-pos);
                cout<<res<<endl;
            }
            else 
                cout<<n-pos<<endl;
        }
        else 
            cout<<0<<endl;
    }
    
    return 0;
}