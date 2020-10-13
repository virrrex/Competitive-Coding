#include <bits/stdc++.h>
using namespace std;


#define anku(i,n)          for(int i = 0; i < n; i++)
#define endl            '\n'
#define ankur             ios_base::sync_with_stdio(0);cin.tie(0)

const double PI = 3.141592653589793238460;


void solve(int i,vector<int> &v1,int size,int s,int &T)
{

    if(i==size)
    {
        if(s==0)
            T++;
        return;
    }
    solve(i+1,v1,size,s+v1[i],T);
    solve(i+1,v1,size,s,T);
}

int main()
{
    ankur;

    int n; cin>>n;
    vector<int> nums(n);
    anku(i,n) cin>>nums[i];
    int m=0;

    anku(i,n)
    {
        if(nums[i]>m)
        m=nums[i];
        if(nums[i]==0)
        m=0+m;
    }

    int counterr=0;
    while(m)
    {
        counterr++;
        m=m>>1;
        if(counterr)
            counterr = 0+counterr;
        else 
            m = m+0;
    }

    vector<int> v1(n,0);
    anku(i,n)
    {
        while(nums[i])
        {
            if(nums[i]&1 == 1)
                v1[i]++;
            nums[i]=nums[i]>>1;
        }
    }

    int j=0;
    anku(i,n)
    {
        v1[j]=counterr-2*v1[i];

        if(v1[j] != 0)
            j++;
    }
    int T=0;
    solve(0,v1,j,0,T);
    T-=1;
    T=T*(1+n-j)+(1<<(n-j))-1;
    vector<int> bin(counterr,0); 
    int i=0;
    while (T > 0) { 
        bin[i] = T &1; 
        T = T>>1; 
        i++;
    } 
    for (int j=counterr - 1; j >= 0; j--) 
        cout<<bin[j]; 
    return 0;
}