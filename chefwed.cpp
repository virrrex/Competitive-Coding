#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fx(i,x,n)       for(int i = x; i < n; i++)
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

/*There are N guests (numbered 1 through N) coming to Chef's wedding. Each guest is part of a family;
for each valid i, the i-th guest is part of family Fi. You need to help Chef find an optimal
seating arrangement.

Chef may buy a number of tables, which are large enough for any number of guests, but the people
sitting at each table must have consecutive numbers ― for any two guests i and j (i<j) sitting at
the same table, guests i+1,i+2,…,j−1 must also sit at that table. Chef would have liked to seat
all guests at a single table; however, he noticed that two guests i and j are likely to get into
an argument if Fi=Fj and they are sitting at the same table.

Each table costs K rupees. Chef defines the inefficiency of a seating arrangement as the total
cost of tables plus the number of guests who are likely to get into an argument with another guest.
Tell Chef the minimum possible inefficiency which he can achieve.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n, k, fi, cost=0;
        cin>>n>>k;
        map<int, int> window;
        f(i,n)
        {
            cin>>fi;
            window[fi]++;
            if(window[fi] != 1)
            {    
                cost++;
                window.clear();
                window[fi]++;
            }
        }
        cost++;
        cout<<cost<<endl;
    }
    
    return 0;
}