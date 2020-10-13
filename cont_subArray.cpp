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
/*
4
5
1 2 3 4 5
0 0 0 0 0
5
1 2 3 4 5
0 0 1 0 0
5
5 4 3 2 1
1 1 1 1 1
5
5 4 3 2 1
0 0 0 0 0


*/
long long GoodSubArray(vector<int> arr, vector<bool> is_bad)
{
    int n = arr.size();
    long long count = 0;
    int start;
    for(int i = 0; i<n; i++)
    {
        start = arr[i];
        if(is_bad[i]==0)
        {
            count++;
            for(int j=i+1; j<n; j++)
            {
                if(arr[j] > start)
                {
                    start = arr[j];
                    count++;
                }
                
            }
        }
        
    }
    return count;
}

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> arr(n); vector<bool> is_bad(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        for(int j=0; j<n; j++)
            {
                bool temp;
                cin>>temp;
                is_bad[j] = temp;
            }
        // cout<<"ok";
        cout<<GoodSubArray(arr, is_bad)<<endl;
    }
    
    return 0;
}

/*
from itertools import combinations 
arr = int(input()) 
seq=[] 
for a in range(arr): 
    seq.append(int(input()))
sets=combinations(seq,2) 
b=[] 
for i in sets: 
    seq.append(abs(i[0]-i[1]))
print(len(set(seq)))

===================================

from itertools import combinations 
a=int(input()) 
h=[] 
for i in range(a): 
      h.append(int(input()))
p=combinations(h,2) 
b=[] 
for i in p: 
      h.append(abs(i[0]-i[1]))
print(len(set(h)))
*/ 