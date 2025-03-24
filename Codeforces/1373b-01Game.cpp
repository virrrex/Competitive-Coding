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
        string s; cin>>s;
        int n = s.size();
        int count0 = 0; f(i,n) if(s[i] == '0') count0++;
        int count1 = n-count0;
        n = min(count0, count1);
        if(n % 2 == 0)
            cout<<"NET"<<nl;
        else 
            cout<<"DA"<<nl;
    }

    return 0;
}

// 1011001 -> 11001 -> 101 -> 1 -> da
//            10101 -> 
// 000111 -> 0011 -> 01 -> da
// 1000111 -> 00111 -> 011 -> 01 -> net
// 1100111 -> 10111 -> 111 -> da
//            11011 -> 111


// 00001111 -> 000111 -> 0011 -> 01 -> net
// 00011101 -> 001101 -> 0101 -> 01 -> net

// 0000001111 -> 00000111 -> 000011 -> 0001 -> net

// 01 -> alice, 0011 -> bob, 000111 -> alice, 00001111 -> bob

// 10101010 // 0101010 // 1111100000


// 0101010101