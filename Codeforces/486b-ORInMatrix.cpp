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

    int n,m; cin>>n>>m;
    set<int> row, col, trow, tcol;
    int sum = 0, tsum = 0;
    bool flag = true;
    vector<vi> orr(n,vi(m,1)), mat(n,vi(m)), tran(n,vi(m,0));
    f(i,n)f(j,m){cin>>mat[i][j]; if(mat[i][j]==0){sum++; row.insert(i); col.insert(j);}}
    
    if(sum != 0){
        for(int i: row)
            f(j,m) orr[i][j] = 0;
        for(int j: col)
            f(i,n) orr[i][j] = 0;
    }
    f(i,n)f(j,m){if(orr[i][j]==1){tsum++; trow.insert(i); tcol.insert(j);}}
    if(tsum != 0){
        for(int i: trow)
            f(j,m) tran[i][j] = 1;
        for(int j: tcol)
            f(i,n) tran[i][j] = 1;
    }
    f(i,n)f(j,m) if(tran[i][j] != mat[i][j]){
        flag = false;
        break;
    }

    if(flag){
        cout<<"YES\n";
        f(i,n){f(j,m) cout<<orr[i][j]<<" "; cout<<endl;}
    }
    else cout<<"NO\n";
    return 0;
}