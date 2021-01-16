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

    int n; cin>>n;
    int st = -1, en = n; bool flag = true;
    vi arr(n);
    f(i,n) cin>>arr[i];
    fx(i,1,n){
        if(flag && arr[i]<arr[i-1]){
            flag = false;
            st = i-1;
        }
        else if(flag==false && arr[i]>arr[i-1]){
            en = i;
            break;
        }
    }
    if(st != -1){
        reverse(arr.begin()+st, arr.begin()+en);
        fx(i,1,n){
            if(arr[i] < arr[i-1]){
                flag = false;
                break;
            }
            else flag = true;
        }
    }
    if(flag){
        cout<<"yes\n";
        st==-1 ? cout<<"1 1\n": cout<<st+1<<" "<<en<<"\n";
    }
    else cout<<"no\n";

    return 0;
}