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
#define nl              '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x)          x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
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
        vs rect(n);
        vi stars;
        int a,b,c,d;
        f(i,n) cin>>rect[i];
        f(i,n) f(j,n)
            if(rect[i][j] == '*'){
                stars.pb(i);
                stars.pb(j);
            }
        a = stars[0];
        b = stars[1];
        c = stars[2];
        d = stars[3];
        // same row ff same
        // same col ss same
        if(a == c){
            if(a == 0){
                a++;
                c++;
            }
            else{
                a--;
                c--;
            }
        }
        else if(b == d){
            if(b == 0){
                b++;
                d++;
            }
            else{
                b--;
                d--;
            }
        }
        else
            swap(b,d);
        
        rect[a][b] = '*';
        rect[c][d] = '*';
        f(i,n) cout<<rect[i]<<nl;
    }

    return 0;
}