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
Consider a sequence A1,A2,…,AN, where initially, Ai=i for each valid i. You may perform any number of
operations on this sequence (including zero). In one operation, you should choose two valid indices i and
j, compute the greatest common divisor of Ai and Aj (let's denote it by g), and change both Ai and Aj to g.

You are given a sequence B1,B2,…,BN. Is it possible to obtain this sequence, i.e. change A to B, using the
given operations?
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi b(n);
        f(i,n) cin>>b[i];
        bool yes = true;
        f(i,n)
            yes &= (i+1) % b[i] == 0;
        yes ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    
    return 0;
}