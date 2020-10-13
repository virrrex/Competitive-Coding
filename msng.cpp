#include <bits/stdc++.h>
using namespace std;

#define pb      push_back
#define ff      first
#define ss      second
#define ll      long long
#define f(i,n)  for(int i = 0; i < n; i++)
#define F(i,n)  for(ll i = 0; i < n; i++)
#define endl    '\n'
#define mod     1000000007
#define rex     ios_base::sync_with_stdio(0);cin.tie(0)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

/*For example:

-1 10001
3 2110
-1 18565

John is wondering if all these pairs of numbers could represent a single common number ― that is,
if it is possible to choose some number X in decimal representation (in base 10) and fill in
all missing bases in such a way that the second numbers in all pairs written on the walls,
when converted from their bases to base 10, are equal to X. For each pair with a missing base (−1,Y),
we may choose any integer base B such that 2≤B≤36 and Y is a valid number in base B.*/
char s[23333];
ll convert(int b) 
{
    ll ans = 0;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - '0';
        if (s[i] >= 'A' && s[i] <= 'Z')
            c = s[i] - 'A' + 10;
        if (c >= b)
            return -1;
        ans = ans * b + c;
        if (ans > 1000000000000ll)
            return -1;
    }
    return ans;
}

int main()
{   
    rex;

    int t; cin>>t;
    while (t--)
    {
        int n, a, len; cin>>n; 
        set<ll> num[123];
        set<ll> empty;
        for(int i=1; i<=n; i++) num[i] = empty;
        for(int i=1; i<=n; i++)
        {
            cin>>a>>s;
            for(int b=2; b<=36; b++)
            {
                if(a==-1 || a==b)
                {
                    ll c = convert(b);
                    if(c != -1)
                        num[i].insert(c);
                }
            }
        }
        bool flag = true;
        for(auto it = num[1].begin(); it != num[1].end(); it++)
        {
            int j;
            for(j=2; j<=n; j++)
                if(num[j].find(*it) == num[j].end())
                    break;
            if(j > n)
            {
                cout<<(*it)<<endl;
                flag = false;
                break;
            }
        }
        if(flag)
                cout<<-1<<endl;
        
    }
    
    return 0;
}