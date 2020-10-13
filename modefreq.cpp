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

/*There are N numbers in a list A=A1,A2,…,AN. Chef needs to find the mode of the frequencies of the
numbers. If there are multiple modal values, report the smallest one. In other words, find the
frequency of all the numbers, and then find the frequency which has the highest frequency. If
multiple such frequencies exist, report the smallest (non-zero) one.

More formally, for every v such that there exists at least one i such that Ai=v, find the number
of j such that Aj=v, and call that the frequency of v, denoted by freq(v). Then find the value w
such that freq(v)=w for the most number of vs considered in the previous step. If there are multiple
values w which satisfy this, output the smallest among them.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n, freq=0, val=0; cin>>n;
        map<int, int> ct, res;
        f(i,n)
        {
            int _; cin>>_;
            ct[_]++;
        }
        for(auto it: ct)
            res[it.ss]++;
        
        for(auto it: res)
        {
            if(it.ss > val)
            {
                val = it.ss;
                freq = it.ff;
            }
            else if(it.ss == val && freq > it.ff)
                freq = it.ff;
        }
        cout<<freq<<endl;
    }
    
    return 0;
}