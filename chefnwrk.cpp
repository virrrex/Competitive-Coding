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

/*Chef has N small boxes arranged on a line from 1 to N. For each valid i, the weight of the i-th
box is Wi. Chef wants to bring them to his home, which is at the position 0. He can hold any number
of boxes at the same time; however, the total weight of the boxes he's holding must not exceed K
at any time, and he can only pick the ith box if all the boxes between Chef's home and the ith box
have been either moved or picked up in this trip.

Therefore, Chef will pick up boxes and carry them home in one or more round trips. Find the
smallest number of round trips he needs or determine that he cannot bring all boxes home.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vi wt(n);
        int sum = 0, pos = 0;
        f(i,n)
        {
            cin>>wt[i];
            if(wt[i] > k)
                pos = -1;
        }
        
        if(pos == -1)
            cout<<-1<<endl;
        else 
        {
            f(i,n)
            {
                sum += wt[i];
                if(sum > k)
                {
                    pos++;
                    sum=wt[i];
                }
            }
            pos++;
            cout<<pos<<endl;
        }
    }
    
    return 0;
}