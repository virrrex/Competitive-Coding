#include<bits/stdc++.h>
using namespace std;

string to_string(int n){
    ostringstream ss;
    ss << n;
    return ss.str();
}
int stoi(string s){
    int i;
    istringstream(s)>>i;
    return i;
}

int main()
{
    /* For each query you have to print "Yes" (without the quotes) if the number is present
    and at which index(1-based) it is present separated by a space.
    If the number is not present you have to print "No" (without the quotes) followed by
    the index of the next smallest number just greater than that number. */ 
    
    int n = 8; //cin>>n;
    vector<int> a = {1,1,2,2,6,9,9,15};
    // for(int i=0; i<n; i++) cin>>a[i];
    int q = 4; //cin>>q;
    vector<int> qq = {1, 4, 9, 15};
    // for(int i=0; i<q; i++) cin>>qq[i];  
    for(int i=0; i<q; i++){
        auto low = lower_bound(a.begin(), a.end(), qq[i]);
        if(a[low - a.begin()] == qq[i])
            cout<<"Yes "<<(low-a.begin()+1)<<endl;
        else
            cout<<"No "<<(low-a.begin()+1)<<endl;
    }

    // get whole sentence as input in a string
    string input;
    getline(cin, input);

    // remove all occurences of a char in a string
    string test = "remove spaces from this string.";
    char c = ' ';
    test.erase(remove(test.begin(), test.end(), c), test.end());
    cout<<test<<"\n";

    return 0;
}
