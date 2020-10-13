#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fx(i,x,n)       for(int i = x; i < n; i++)
#define Fx(i,x,n)       for(ll i = x; i < n; i++)
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
There are N stick holders with negligible size (numbered 1 through N) in a row on the ground. Akbar places
all the sticks in them vertically; for each valid i, the initial height of the stick in the i-th holder is
Ai. Birbal has a stick cutter and his task is to completely cut all these sticks, i.e. reduce the heights
of all sticks to 0.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        set<int> stick;
        int a;
        f(i,n)
        {
            cin>>a;
            if(a != 0)
                stick.insert(a);
        }
        int res = stick.size();
        cout<<res<<endl;
    }
    
    return 0;
}