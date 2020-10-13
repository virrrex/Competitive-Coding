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
Let's call a sequence good if the sum of all its elements is 0.

You have a sequence of integers A1,A2,…,AN. You may perform any number of operations on this sequence
(including zero). In one operation, you should choose a valid index i and decrease Ai by i. Can you make
the sequence good using these operations?
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int sum = 0;
        f(i,n){
            int tt; cin>>tt;
            sum += tt;
        }
        sum<0 ? cout<<"NO\n" : cout<<"YES\n";
    }
    
    return 0;
}