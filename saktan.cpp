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

/*Sakshi is well-known for troubling others. This time, her friends Nikki and Mansi planned to take
revenge and teach her a lesson, so they changed her matrix by performing the following operation Q times:

Choose any valid cell (x,y).
Add 1 to all the cells in row x.
Add 1 to all the cells in column y.

Find number cells containing odd integers*/

int main()
{   
    rex;

    int t; cin>>t;
    while (t--)
    {
        ll n, m, q;
        cin>>n>>m>>q;
        int r[100001] = {0}, c[100001] = {0};
        while(q--)
        {
            int a, b;
            cin>>a>>b; a--; b--;
            r[a]++; c[b]++;
        }
        ll rOdd = 0, cOdd = 0, rEven = 0, cEven = 0;
        f(i,n)
            if(r[i] % 2)
                rOdd++;
            else 
                rEven++;
        f(i,m)
            if(c[i] % 2)
                cOdd++;
            else 
                cEven++;
        cout<<rOdd*cEven + rEven*cOdd<<endl;
    }
    
    return 0;
}