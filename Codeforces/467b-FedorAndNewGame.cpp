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

string to_bi(int x, int n)
{
    string ans = "";
    while(x >= 1) {
        if(x % 2)
            ans += '1';
        else
            ans += '0';
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() < n) {
        ans = "0" + ans;
    }
    return ans;
}

int main()
{
    rex;

    int n,m,k; cin>>n>>m>>k;
    vi player(m); f(i,m) cin>>player[i];
    int cnt = 0, me;
	cin>>me;
	string x = to_bi(me, n), s[m];
	f(i,m)
		s[i] = to_bi(player[i], n);
	f(i,m) {
		int tmp = 0;
		f(j,n)
			if (s[i][j] != x[j])
				tmp++;
		if (tmp <= k)
			cnt++;
	}
 
	cout << cnt;

    return 0;
}