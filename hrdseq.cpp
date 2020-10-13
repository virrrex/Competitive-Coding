#include <bits/stdc++.h>
using namespace std;

#define pb      push_back
#define ff      first
#define ss      second
#define ll      long long
#define f(i,n)  for(int i = 0; i < n; i++)
#define F(i,n)  for(ll i = 0; i < n; i++)
#define fk(i,k,n) for(int i = k; i < n; i++)
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

/*First element of sequence is 0. Next element of the sequence is defined by:
- If prev element occurred once, next element is 0.
- Else x is index of prev element. Look where last time the prev element occurred previously, in l index
  Next element is (x-l).
Find how many times n occurred in this sequence, n being size of the sequence. Find the number of times
last element occurred in this sequence.*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi ct(130,0), sq, vct(130);
        ct[0] = 1; sq.pb(0);
        fk(i,1,n)
        {
            if(ct[sq[i-1]] == 1)
            {
                sq.pb(0);
                ct[0]++; vct[sq[i-1]] = i-1;
            }
            else 
            {
               int z = i-1 - vct[sq[i-1]]; 
               vct[sq[i-1]] = i-1; sq.pb(z);
               ct[z]++;
            }
        }
        for(auto it: sq) cout<<(it)<<" ";   cout<<endl;
        cout<<ct[sq[n-1]]<<endl;
    }
    
    return 0;
}