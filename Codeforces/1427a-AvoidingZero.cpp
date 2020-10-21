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
#define deb(x)          cout<<#x<<" "<<x<<endl
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

bool comp(int a, int b)
{
    return a>b;
}
 
int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi ar(n);
        int summ = 0;
        f(i,n){
            cin>>ar[i];
            summ += ar[i];
        }
        if(summ != 0){
            if(summ>0)
                sort(ar.begin(), ar.end(), comp);
            else
                sort(ar.begin(), ar.end());
            cout<<"YES\n";
            f(i,n) cout<<ar[i]<<" ";
            cout<<endl;
        }
        else 
            cout<<"NO"<<endl;
    }
    
    return 0;
}