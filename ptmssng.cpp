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

/*
Chef has N axis-parallel rectangles in a 2D Cartesian coordinate system. These rectangles may
intersect, but it is guaranteed that all their 4N vertices are pairwise distinct.

Unfortunately, Chef lost one vertex, and up until now, none of his fixes have worked
(although putting an image of a point on a milk carton might not have been the greatest idea
after all…). Therefore, he gave you the task of finding it! You are given the remaining 4N−1
points and you should find the missing one.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n, x, y, a=0, b=0; cin>>n;
        f(i, 4*n-1)
        {
            cin>>x>>y;
            a ^= x;
            b ^= y;
        }
        cout<<a<<" "<<b<<endl;
    }
    
    return 0;
}