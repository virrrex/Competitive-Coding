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
#define deb2(x, y)      cout<<#x<< "=" <<x<<","<<#y<<"="<<y<<endl
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

const int N = 2e5 + 7;
int dsu[N];

int get(int v)
{
	if (v == dsu[v]) return v;
	else return dsu[v] = get(dsu[v]);
}

void uni(int u, int v)
{
  	dsu[get(u)] = get(v);
}

int calcWeight(vi a, vi b){
    int d = a.size();
    int wt = 0;
    f(i,d){
        wt += abs(a[i] - b[i]);
    }
    return wt;
}

int main()
{
    rex;
    int n, d;
    cin>>n>>d;
    vector<vi> dims(n);
    int weight;
    f(i,n){
        f(j,d){
            cin>>weight;
            dims[i].pb(weight);
        }
	}
	vector<pair<int, pii>> edges;
	f(bit, (1<<d)/2){
		vpii edd;
		f(i,n){
			int sum = 0;
			f(j,d){
				if((bit>>j) & 1)
					sum -= dims[i][j];
				else 
					sum += dims[i][j];
			}
			edd.pb({sum,i});
		}
		int small = min_element(all(edd))->ss;
		int big = max_element(all(edd))->ss;
		f(x,n){
			weight = calcWeight(dims[small], dims[x]);
			edges.pb({weight,{small,x}});
			weight = calcWeight(dims[big], dims[x]);
			edges.pb({weight,{big,x}});
		}
	}
	sort(edges.rbegin(), edges.rend());
	f(i,n) dsu[i] = i;
	ll ans = 0;
	for(auto it : edges){
		int u = it.ss.ff, v = it.ss.ss;
		if(get(u) != get(v)){
			uni(u,v);
			ans += it.ff;
		}
	}
    cout<<ans<<endl;
 
    return 0;
}