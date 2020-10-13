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

/*You are given a sequence A1,A2,…,AN. For each valid i, the star value of the element Ai is the
number of valid indices j<i such that Aj is divisible by Ai.

Chef is a curious person, so he wants to know the maximum star value in the given sequence.*/

int main()
{   
    rex;

    int t; cin>>t;
    while (t--)
    {
        int n, x; cin>>n;
        vi a; set <int> star;
        f(i,n)
        {
            cin>>x, a.pb(x); int c = 0;
            for(int j = i; j>0; j--)
            {
                if(a[j-1] % a[i] == 0)
                    c++;
            }
            star.insert(c);
        }
        auto it = star.end(); it--;
        cout<<*it<<endl;    
    }
    
    return 0;
}