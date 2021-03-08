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

int arr[10];
int h, m; 

bool isValidReflection(int hh, int mm)
{
    int rhh, rmm;
    if(arr[hh/10]==-1 || arr[hh%10]==-1 || arr[mm/10]==-1 || arr[mm%10]==-1)
        return false;
    rhh = arr[mm%10]*10 + arr[mm/10];
    rmm = arr[hh%10]*10 + arr[hh/10];
    if(rhh < h && rmm < m)
        return true;
    else 
        return false;
}

int main()
{
    // rex;

    mem1(arr);
    arr[0]=0; arr[1]=1; arr[2]=5; arr[5]=2; arr[8]=8;
    int t; cin>>t;
    while(t--)
    {
        cin>>h>>m;
        string s; cin>>s;
        int hh = (s[0]-'0')*10 + (s[1]-'0');
        int mm = (s[3]-'0')*10 + (s[4]-'0');
        bool flag = false, start = true;
        fx(i,hh,h){
            // fx(j,mm,m){                          //WRONG
            f(j,m){                                 //CORRECTION
                if(start){ j=mm; start=false;}      //CORRECTION
                if(isValidReflection(i,j)){
                    flag = true;
                    printf("%02d:", i);
                    printf("%02d\n", j);
                    break;
                }
            }
            if(flag) break;
        }
        if(flag==false)
            cout<<"00:00"<<nl;
        //          ALTERNATE CORRECT CODE
        // while(!isValidReflection(hh,mm)){
        //     mm++;
        //     if(mm == m) hh++;
        //     mm %= m;
        //     hh %= h;
        // }
        // printf("%02d:",hh);
        // printf("%02d\n",mm);
    }

    return 0;
}