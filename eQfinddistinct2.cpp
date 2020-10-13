#include <iostream>
// #include <vector>
#include <map>
using namespace std;
// #define MAX 100000000
int main()
{
    long long m, n, temp, res=0;
    cin>>m>>n;
    //vector <long long> ar1(m), ar2(n);        --> NOT NEEDED
    //vector <long long> count(MAX, 0);       //vector count of size MAX, all elements set to 0
    map <long long, long long> count;
    for(long long i=0; i<m; i++)
    {
        cin>>temp;
        count[temp]++;
        if(count[temp] == 1)
            res++;
        else if(count[temp] == 2)
            res--;
    }

    for(long long i=0; i<n; i++)
    {
        cin>>temp;
        count[temp]++;
        if(count[temp] == 1)
            res++;
        else if(count[temp] == 2)
            res--;
    }

    cout<<res<<endl;

    return 0;
}