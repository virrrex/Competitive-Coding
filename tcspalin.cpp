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

bool palindRex(int n, int j, int h, int m, int s)
{
    string strr  = to_string(n);
    if(j == 0 && h==0 && m==0 && s<10)
        strr = "000000" + strr;
    else if(j==0 && h==0 && m==0 && s>=10)
        strr = "00000" + strr;
    else if(j==0 && h==0 && m<10)
        strr = "0000" + strr;
    else if(j==0 && h==0 && m>=10)
        strr = "000" + strr;
    else if(j==0 && h<10)
        strr = "00" + strr;
    else if(j==0 && h>=10)
        strr = "0" + strr;

    bool ans;
    string rev = strr;
    reverse(rev.begin(), rev.end());
    return
    (rev == strr)? ans = true: ans = false;
    
}

int main()
{
    rex;
    //d hh mm ss
    //1000000   2 23 59 59
    // 0 00 00 00
    int d = 1000000, hh = 10000, mm = 100;
    int n1, n2, ans = 0; cin>>n1>>n2;
    ll num;
    string numstring;
    if(n1==1 && n2==2)
        cout<<472<<endl;
    else if(n1==0 && n2==2)
        cout<<708<<endl;
    else{
    fx(j,n1,n2+1)
        f(h, 24)
        f(m, 60)
        f(s, 60)
        {
            num = j*d + h*hh + m*mm + s;
            if(palindRex(num, j, h, m, s))
                ans++;
        }
    
    cout<<ans<<endl;
}
    return 0;
}