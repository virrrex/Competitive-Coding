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

int getIndex(vi v, int k){
    auto it = find(all(v),k);
    if(it != v.end()){
        int index = it-v.begin();
        return index;
    }
    else 
        return -1;
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi w(n), l(n), idx(n);
        f(i,n){cin>>w[i]; idx[i]=i;}
        f(i,n) cin>>l[i];
        vi sortedw = w; sortall(sortedw);
        int steps = 0;
        fx(i,1,n){
            auto it1 = find(all(w), sortedw[i-1]);
            auto it2 = find(all(w), sortedw[i]);
            int one = idx[it1-w.begin()];
            int two = it2 - w.begin();
            int j = two;
            while(two <= one){
                two += l[j];
                idx[j] = two;
                steps++;
            }
        }
        cout<<steps<<endl;
    }

    return 0;
}