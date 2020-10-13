#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s;
    cout<<"Input string: ";
    // cin>>s;
    getline(cin,s);     //vishal rex
    for(int i=0; i<s.length();i++)
        cout<<s[i];
    if(s[6]==' ')       //using " " gives error
        cout<<"\ns[6] is space"<<endl;

    stringstream st(s);
    string o;
    while(st>>o)
        cout<<o<<endl;
    long long val = LONG_MAX;
    cout<<val;
    return 0;
}