#include <iostream>
#include <algorithm>
using namespace std;

void goodSegment(vector<int> badNumbers, int l, int r) {
    sort(badNumbers.begin(), badNumbers.end());
    for(int i=0; i<badNumbers.size(); i++) cout<<badNumbers[i]<<" ";
    cout<<endl;
    vector <pair<int,int>> range;
    int low=l, high=r;
    for(int i=0; i<badNumbers.size(); i++)
    {
        if(badNumbers[i]>low && badNumbers[i]<high){
            range.push_back(make_pair(low,badNumbers[i]-1));
            low = badNumbers[i]+1;
        }
    }
    int n = badNumbers.size();
    if(badNumbers[n-1]>high)
        range.push_back(make_pair(low+1,high));
    else 
        range.push_back(make_pair(low,high));

    int max=0, diff;
    for(int i=0; i<range.size(); i++)
    {
        diff = range[i].second - range[i].first;
        if(diff>max)
            max = diff;
        cout<<"{"<<range[i].first<<" "<<range[i].second<<"} ";
    }
    max++;
    cout<<endl<<max;
}

int main() 
{
    vector<int> bd = {8,6,20,12};
    goodSegment(bd,1,30);

    return 0;
}