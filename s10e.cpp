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

/*On each day, Chef considers the price of the phone to be good if it is strictly smaller than
all the prices he has observed during the previous five days. If there is no record of the price
on some of the previous five days (because Chef has not started checking the price on that day yet),
then Chef simply ignores that previous day ― we could say that he considers the price on that
day to be infinite.

Now, Chef is wondering ― on how many days has he considered the price to be good? Find the number
of these days.*/

int main()
{   
    rex;

    int t; cin>>t;
    while (t--)
    {
        int n, count = 0; cin>>n;
        vi v(n);
        f(i,n) cin>>v[i];
        f(i,n)
        {
            int flag = 0, k=0;
            for(int j=i; j>0; j--)
            {
                if(k<5)
                {
                    if(v[i] >= v[j-1])
                    {
                        flag = 1;
                        break;
                    }
                }
                else 
                    break;
                k++;
            }
            if(flag == 0)
                count++;
        }
        cout<<count<<endl;
    }
    
    return 0;
}