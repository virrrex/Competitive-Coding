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

/*Chef has a lightsaber which has an attack power denoted by P. He keeps hitting Darth with the lightsaber. Every time he hits,
Darth's health decreases by the current attack power of the lightsaber (by P points), and afterwards, P decreases to ⌊P2⌋.

If the attack power becomes 0 before Darth's health becomes 0 or less, Chef dies. Otherwise, Darth dies. You are given Darth's
initial health H and the initial attack power P. Tell Chef if he can beat Darth or if he should escape.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int h, p;
        cin>>h>>p;
        if(h > p)
        {
            if(p > ((h*3) /5))
                cout<<1<<endl;
            else if (p < (h/2))
                cout<<0<<endl;
            else 
            {
                while(h != 0 && p != 0)
                {
                    if(h>p)
                        h-=p;
                    else 
                        h=0;
                    p/=2;
                }
                if(h)
                    cout<<0<<endl;
                else 
                    cout<<1<<endl;
            }
        }
        else 
            cout<<1<<endl;
    }
    
    return 0;
}