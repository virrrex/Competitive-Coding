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

void sol1(){
    set<int> fib; fib.insert(0); fib.insert(1);
    int a = 0;
    for(int i=1, b=1; b<1e9; i++){
        fib.insert(a+b);
        a += b;
        swap(a,b);
    }
    int n; cin>>n;
    if(n == 0) {
		cout << 0 << " " << 0 << " " << 0 << "\n";
		return;
	}
	if(n == 1) {
		cout << "0 0 1" << "\n";
		return;
	}
	if(n == 2) {
		cout << "0 1 1" << "\n";
		return;
	}
	if(n == 3) {
		cout << "0 1 2" << "\n";
		return;
	} 
	if(n == 5) {
		cout << "1 1 3" << "\n";
		return;
	}
    auto it = fib.find(n);
    --it;
    cout<<*it<<" ";
    --it; --it;
    cout<<*it<<" ";
    --it;
    cout<<*it<<nl;
}

void sol2(){
    int n; cin>>n;
    cout<<n<<" 0 0\n";
}

int main()
{
    rex;

    // sol1();
    sol2();

    return 0;
}