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
    
    int t; cin>>t;
    while(t--)
    {
        int n, k;
        ll ct = 0, sum = 0, q;
        cin>>n>>k;
        vi qi(n);
        f(i,n)
            cin>>qi[i];
            
        int j = 0;
        q = qi[0];
        while (q >= k){
            ct++;
            sum = q-k;
            j++;
            if(j < n){
                q = qi[j];
                q += sum;
            }
            else{
                ct += (sum/k);
                break;
            }
        }
        ct++;
        cout<<ct<<endl;
    }
    
    return 0;
}