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

/*You are given a strictly convex polygon with N vertices (numbered 1 through N). For each valid i,
the coordinates of the i-th vertex are (Xi,Yi). You may perform the following operation any number
of times (including zero):

-Consider a parent polygon. Initially, this is the polygon you are given.
-Draw one of its child polygons ― a simple non-degenerate polygon such that each of its sides is a
chord of the parent polygon (it cannot be a side of the parent polygon). The operation cannot be
performed if the parent polygon does not have any child polygons.
-The child polygon which you drew becomes the new parent polygon.

Your goal is to draw as many sides of polygons in total as possible (including the polygon given
at the start). Find this maximum total number of sides.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
       int n; cin>>n;
       int res = 0;
       vpii xy;
       f(i,n){
           int x, y;
           cin>>x>>y;
           xy.pb(make_pair(x,y));
       }
       if(n<3){
            res = 0;
            break;
       }
       while(n > 5)
       {
           res += n;
           n /= 2;
       }
       if(n == 3 || n == 4 || n == 5)
           res += n; 

        cout<<res<<endl;
    }
    
    return 0;
}