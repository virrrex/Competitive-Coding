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
#define all(x)          x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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

    int n; cin>>n;
    int x,y;
	int ocu = 0, ocl = 0;
	int odd_even_pair = 0;
 
    f(i,n){
        cin>>x>>y;
		if(((x%2) && !(y%2)) || (!(x%2) && (y%2)))
			odd_even_pair = 1;
		if(x%2)
			ocu++;
		if(y%2)
			ocl++;
    }
    if(!(ocu%2) && !(ocl%2))
		cout<<0<<endl;
	else if(((ocu%2) && !(ocl%2)) || (!(ocu%2) && (ocl%2))){
		cout<<-1<<endl;
	}
	else if(odd_even_pair)
		cout<<1<<endl;
	else
		cout<<-1<<endl;


    return 0;
}