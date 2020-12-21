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
        int n, x; cin>>n>>x;
        vi arr(n); f(i,n) cin>>arr[i];
        if(n == 2){
            while(x){
                bool flag = false;
                for(int i=30; i>=0; i--){
                    if((1<<i)&arr[0]){
                        arr[0] ^= (1<<i);
                        arr[1] ^= (1<<i);
                        x--;
                        flag = true;
                        if(x == 0)
                            break;
                    }
                }
                if(flag == false)
                    break;
            }
            if(x&1){
                arr[0] ^= 1;
                arr[1] ^= 1;
            }
            cout<<arr[0]<<" "<<arr[1]<<endl;
        }
        else{
            int store[31];
            memset(store, 0, sizeof(store));
            int save = n-1;
            f(i,n-1){
                save = i;
                for(int bit=30; bit>=0; bit--){
                    if((1<<bit)&arr[i]){
                        if(store[bit] == 1){
                            arr[i] ^= (1<<bit);
                            store[bit] = 0;
                        }
                        else{
                            arr[i] ^= (1<<bit);
                            store[bit] = 1;
                            x--;
                            if(x == 0)
                                break;
                        }
                    }
                }
                if(x == 0)
                   break;
            }
            f(i,31){
                if(store[i] == 1){
                    for(int j=save; j<n-1; j++){
                        if((1<<i) & arr[j]){
                            arr[j] ^= (1<<i);
                            store[i] = 0;
                            break;
                        }
                    }
                }
            }
            f(i,31){
                if(store[i] == 1)
                    arr[n-1] ^= (1<<i);
            }
            f(i,n) cout<<arr[i]<<" ";
            cout<<endl;
        }
    }

    return 0;
}