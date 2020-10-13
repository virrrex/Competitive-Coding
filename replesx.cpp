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
#define deb(x)          cout<<#x<<" "<<x<<endl
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
        int n, x, p, k;
        cin>>n>>x>>p>>k;
        vi a(n);
        f(i,n) cin>>a[i];
        sort(a.begin(), a.end());
        bool isP = binary_search(a.begin(), a.end(), x);
        int addon = 0;
        if(!isP){
            a[k-1] = x; addon = 1;
            sort(a.begin(), a.end());
        }
        if(x == a[p-1]){
            // if(p == k){
                cout<<0 + addon<<endl;
                continue;
            // }
            // else{
            //     cout<<-1<<endl;
            //     continue;
            // }
        }
        else{
            // int i=k, j=k-2;
            // while(i<n || j>=0){
            //     if(i<n && a[i] == x){
            //         posx = i;
            //         break;
            //     }
            //     if(j>=0 && a[j] == x){
            //         posx = j;
            //         break;
            //     }
            //     i++; j--;
            // }
            int posx = -1 ;
            int mn = INT_MAX;
            f(i,n)
                if(a[i] == x)
                    if(abs(p-i) < mn){
                        mn = abs(p-i);
                        posx = i;
                    }
            // if((posx < k-1 && p>k) || (posx > k-1 && p<k)){
            //     cout<<-1<<endl;
            //     continue;
            // }
            if(x < a[p-1] && p>k ){
                cout<<-1<<endl;
                continue;
            }
            if(x > a[p-1] && p<k){
                cout<<-1<<endl;
                continue;
            }
            int ct = abs((p-1) - posx);
            cout<<ct + addon<<endl;
            continue;
        }
    }
    
    return 0;
}