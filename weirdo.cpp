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

int checkDish(string dish)
{
    int c = 0;
    for(int z = 0; z < dish.length(); z++)
        if(dish[z] == 'a' || dish[z] == 'e' || dish[z] == 'i' || dish[z] == 'o' || dish[z] == 'u')
            c++;
    int con = dish.length() - c;
    if(c >= con)
        return 1;
    else 
        return 0;
}

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int l; cin>>l;
        string s;
        vs alice, bob;
        f(i,l)
        {
            cin>>s;
            if(checkDish(s))
                alice.pb(s);
            else 
                bob.pb(s);
        }
        
        vi alpha(26,0);
        map <char, int> fxa, fxb, xa, xb;

        int n = alice.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<alice[i].length(); j++)
            {
                fxa[alice[i][j]]++;
                int a = alice[i][j] - 'a';
                if(alpha[a] == 0)
                {
                    xa[alice[i][j]]++;
                    alpha[a]++;
                }
            }
            f(d,26)
                alpha[d] = 0;
        }
        
        int m = bob.size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<bob[i].length(); j++)
            {
                fxb[bob[i][j]]++;
                int a = bob[i][j] - 'a';
                if(alpha[a] == 0)
                {
                    xb[bob[i][j]]++;
                    alpha[a]++;
                }
            }
            f(d,26)
                alpha[d] = 0;
        }

        long double numa=1, dena=1, numb=1, denb=1;
        for(auto it : xa)
        {
            char alp = it.ff; 
            numa *= it.ss; dena *= fxa[alp];
        }
        
        for(auto it : xb)
        {
            char alp = it.ff;
            numb *= it.ss; denb *= fxb[alp];
        }
        
        long double score = numa/numb; int ten = m<n?m:n;
        long double fx = denb/dena; fx = pow(fx, ten);
        if(m>n)
            fx = fx * pow(denb, m-n);
        else if(m<n)
            fx = fx / pow(dena, n-m);
        score *= fx;
        if(score < 10000000)
            cout<<fixed<<setprecision(7)<<score<<endl;
        else 
            cout<<"Infinity"<<endl;
    }
    
    return 0;
}