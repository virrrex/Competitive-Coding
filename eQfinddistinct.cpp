#include <iostream>
#include <vector>
#include <map>
using namespace std;
//#define MAX 100000
int main()
{
    long long m, n, temp, res=0;
    cin>>m>>n;
    vector <long long> ar1(m), ar2(n);
    //vector <long long> count(MAX, 0);       //vector count of size MAX, all elements set to 0
    map <long long, long long> count;
    for(long long i=0; i<m; i++)
    {
        cin>>ar1[i];
        temp = ar1[i];
        count[temp]++;
    }

    for(long long i=0; i<n; i++)
    {
        cin>>ar2[i];
        temp = ar2[i];
        count[temp]++;
    }

    for(auto itr: count /*long long i=0; i<count.size(); i++*/)
    {
        if(itr.second==1)
            res++;
    }

    cout<<res<<endl;

    return 0;
}