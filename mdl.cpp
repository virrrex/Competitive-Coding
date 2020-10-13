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

/*You are given a sequence A1,A2,…,AN of distinct integers. While the sequence contains at least
three elements, look at its first three elements, find the median among these elements and delete it.
What will the final sequence be?*/

int main()
{   
    rex;

    int t; cin>>t;
    while (t--)
    {
        int n, mx, mn, ix=0, in=0; cin>>n;
        vi a(n);
        f(i,n) cin>>a[i];
        mx = a[0]; mn = a[0];
        for(int i=1; i<n; i++)
        {
            if(a[i] > mx)
                {mx = a[i]; ix = i;}
            if(a[i] < mn)
                {mn = a[i]; in = i;}
        }
        if(ix<in)
            cout<<mx<<" "<<mn<<endl;
        else 
            cout<<mn<<" "<<mx<<endl;
    }
    
    return 0;
}