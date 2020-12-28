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

    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2 || y1==y2){
        if(x1==x2){
            x3 = x1+(y2-y1);
            cout<<x3<<" "<<y1<<" "<<x3<<" "<<y2;
        }
        else {
            y3 = y1+(x2-x1);
            cout<<x1<<" "<<y3<<" "<<x2<<" "<<y3;
        }
    }
    else if(abs(x2-x1) == abs(y2-y1)){
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
    }
    else 
        cout<<-1;

    return 0;
}