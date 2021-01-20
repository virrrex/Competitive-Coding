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

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int mx = 0;
        vi num(2*n); f(i,2*n){ cin>>num[i]; if(num[i]>num[mx]) mx=i;}
        int ans = -1;
        f(i,2*n){
            if(i == mx)
                continue;
            int x = num[mx];
            multiset<int> tmp;
            f(j,2*n){
                if(j == mx || j == i) continue;
                tmp.insert(num[j]);
            }
            bool ok = 1;
            while(tmp.size()){
                int a = *tmp.rbegin();
                tmp.erase(tmp.find(a));
                if(tmp.find(x-a) == tmp.end()){
                    ok = 0;
                    break;
                }
                tmp.erase(tmp.find(x-a));
                x = a;
            }
            if(ok == 1)
                ans = i;
        }
        if(ans == -1)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            int x = num[mx] + num[ans];
            cout<<x<<endl;
            multiset<int> tmp;
            f(i,2*n) 
                tmp.insert(num[i]);
            while(tmp.size()){
                int a = *tmp.rbegin();
                tmp.erase(tmp.find(a));
                tmp.erase(tmp.find(x-a));
                cout<<a<<" "<<x-a<<endl;
                x = a;
            }
        }
        
    }

    return 0;
}