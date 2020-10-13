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

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        if(n == 1) {cout<<1<<endl; continue;}
        if(ceil(log2(n)) == floor(log2(n))) {
            cout<<-1<<endl;
            continue;
        }
        vi num(n); int a = 1;
        f(i,n) num[i] = i+1;
        num[0] = 2; num[1] = 3; num[2] = 1;
        fx(i,3, n){
            if(ceil(log2(num[i])) == floor(log2(num[i]))){
                swap(num[i], num[i+1]); i++;
            }
        }
        f(i,n)
            cout<<num[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}