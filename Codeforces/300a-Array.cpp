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
    vi a(n); f(i,n) cin>>a[i];
    vi visited(n,0);
    vi s1, s2, s3;
    f(i,n)
        if(a[i] < 0){
            visited[i] = 1;
            s1.pb(a[i]);
            break;
        }
    f(i,n)
        if(a[i] > 0){
            visited[i] = 1;
            s2.pb(a[i]);
            break;
        }
    if(!s2.size()){
        int cnt = 2;
        f(i,n){
            if(a[i] < 0 and visited[i] == 0){
                s2.pb(a[i]);
                visited[i] = 1;
                cnt--;
            }
            if(cnt == 0)
                break;
        }
    }
    f(i,n)
        if(visited[i] == 0) s3.pb(a[i]);
    cout<<s1.size()<<" "; f(i,s1.size()) cout<<s1[i]<<" "; cout<<endl;
    cout<<s2.size()<<" "; f(i,s2.size()) cout<<s2[i]<<" "; cout<<endl;
    cout<<s3.size()<<" "; f(i,s3.size()) cout<<s3[i]<<" "; cout<<endl;

    return 0;
}