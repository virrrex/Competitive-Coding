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

int fun (int a, int b) {
	return a^b;
}

int main()
{
    rex;
    
    vi a = {1, 2, 5, 4, 6, 8, 9, 2, 1, 4, 5, 8, 9};
    cout << accumulate(a.begin(), a.end(), 0L, fun)<< endl;
    string s = "abbacd";
    vector<char> vc(s.begin(), s.end());
    // cout<<'a'^'b'<<endl;

    string msg = "apple";
    cout<<msg;
    msg.append(" is good.");
    cout<<endl<<msg;

    //      ADAKING

    // int t; cin>>t;
    // while(t--)
    // {
    //     int k;
	//     cin >> k;
	//     f(i,8)
    //     {
	//         f(j,8)
    //         {
	//             if(i==0 && j==0)
    //                 cout<<'O';
	//             else 
    //                 cout<<(k>0 ? '.' : 'X');
	//             k--;
	//         }
    //         cout<<endl;
    //     }
    // }
    
    return 0;
}