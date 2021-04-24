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
#define all(x)          (x).begin(), (x).end()
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

//      GAP ALGORITHM
//  Intuition is shell sort

void merge(vi &arr1, vi &arr2, int n, int m){
    int gap = (((n+m)/2) + ((n+m)%2));
    int i, j;
    while(gap > 0){
        for(i=0, j=gap; j<m+n; i++, j++){
            if(i<n && j<n){
                if(arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);
            }
            else if(i<n && j>=n){
                if(arr1[i] > arr2[j-n])
                    swap(arr1[i], arr2[j-n]);
            }
            else if(i>=n && j>=n){
                if(arr2[i-n] > arr2[j-n])
                    swap(arr2[i-n], arr2[j-n]);
            } 
        }
        if(gap == 1) break;
        gap = ((gap/2) + (gap%2));
    }
}

int main()
{
    rex;

    int n, m; cin>>n>>m; 
    vi a(n), b(m); f(i,n) cin>>a[i]; f(i,m) cin>>b[i];
    merge(a,b, n,m);
    f(i,n) cout<<a[i]<<" "; f(i,m) cout<<b[i]<<" ";

    return 0;
}