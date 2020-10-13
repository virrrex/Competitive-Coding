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
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

/*
There are N athletes (numbered 1 through N) in a line. For each valid i, the i-th athlete starts at the
position i and his speed is Vi, i.e. for any real number t≥0, the position of the i-th athlete at the
time t is i+Vi⋅t.

Unfortunately, one of the athletes is infected with a virus at the time t=0. This virus only spreads from
an infected athlete to another whenever their positions are the same at the same time. A newly infected
athlete may then infect others as well.

We do not know which athlete is infected initially. However, if we wait long enough, a specific set of
athletes (depending on the athlete that was infected initially) will become infected. Your task is to find
the size of this set, i.e. the final number of infected people, in the best and worst possible scenario.
*/

float time(int a, int b, int va, int vb)
{
    return (float)(a-b)/(float)(vb-va);
}

void sol2(int n)
{
    vector<float>velocity(n);
    f(i,n)
        cin>>velocity[i];
    ll mn=n+1,mx=1;
    vector<vector<float>>infected (n,vector<float>(n));
    f(i,n){
        f(j,n){
            if(velocity[i] == velocity[j])
                infected[i][j]=0;
            else if(i>j)
                infected[i][j]= time(i,j, velocity[i], velocity[j]);
            else
                infected[i][j] = time(j,i, velocity[j], velocity[i]);
        }
    }

    ll res=1;
    f(i,n)
    {   
        res = 1LL;
        f(j,n)
        {
            float tt = time(i,j,velocity[i], velocity[j]);
            if(infected[i][j]>0)
                res++;
            else if(i!=j)
            {
                f(k,n)
                    if(infected[j][k]>0 && infected[i][k]>0)
                        if(infected[j][k] > infected[i][k])
                        {
                            res++;
                            break;
                        }
            }
            else
                infected[i][j] += tt - time(i,j, velocity[i], velocity[j]);
        }
        mx=max(mx,res);
        mn=min(mn,res);
    }
    cout<<mn<<" "<<mx<<"\n";
}

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        if(n>3)
        {
            sol2(n);
            continue;
        }
        vi velocity(n);
        f(i,n)
            cin>>velocity[i];
        map<pii, vector<pair<pii, float>>> infected;
        f(i,n)
        {
            fx(j, i+1, n)
            {
                int a = i, b = j, va = velocity[i], vb = velocity[j];
                float tt = -1;
                if(va != vb)
                    tt = time(a,b,va,vb);
                if(tt >= 0)
                    infected[make_pair(velocity[i], i)].pb(make_pair(make_pair(velocity[j], j), tt));
            }
            for(int j=i-1; j>=0; j--)
            {
                int a = i, b = j, va = velocity[i], vb = velocity[j];
                float tt = -1;
                if(va != vb)
                    tt = time(a,b,va,vb);
                if(tt >= 0)
                    infected[make_pair(velocity[i], i)].pb(make_pair(make_pair(velocity[j], j), tt));
            }
        }
        // for(auto itr : infected)
        //     {cout<<itr.ff.ff<<"("<<itr.ff.ss<<")"<<" || "; for(auto i:itr.ss) cout<<"("<<i.ff.ff<<"-"<<i.ff.ss<<", "<<i.ss<<")"; cout<<endl;}

        map<pii,int> res;
        f(i,n)
            res[make_pair(velocity[i], i)] = 1;
        
        f(i,n)
        {
            res[make_pair(velocity[i], i)] += infected[make_pair(velocity[i],i)].size();
            if(res[make_pair(velocity[i], i)] == n) continue;

            for(auto j: infected[make_pair(velocity[i], i)])
            {
                for(auto k: infected[make_pair(j.ff.ff, j.ff.ss)])
                {
                    if(res[make_pair(velocity[i], i)] == n) break;
                    if(k.ff.ss != i && k.ss > j.ss)
                    {
                        // cout<<"checking: "<<velocity[i]<<"("<<i<<") isPresent:"<<k.ff.ff<<"-"<<k.ff.ss<<", "<<k.ss;
                        bool isP = binary_search(infected[make_pair(velocity[i],i)].begin(),
                        infected[make_pair(velocity[i],i)].end(),
                        make_pair(make_pair(k.ff.ff, k.ff.ss), k.ss));
                        if(!isP)//{
                            res[make_pair(velocity[i], i)]++; //cout<<"no";} else cout<<"yes"; cout<<endl;
                    }
                }
            }
        }

        int mn=n+1, mx=1;
        for(auto it : res)
        {
            mn = min(it.ss, mn);
            mx = max(it.ss, mx);
        }
        cout<<mn<<" "<<mx<<endl;
    }
    
    return 0;
}