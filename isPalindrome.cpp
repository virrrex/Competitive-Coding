#include <iostream>
#include <algorithm>
using namespace std;

bool isNumPalin(int n)
{
    int t = n, rev = 0;
    while(t != 0)
    {
        rev *= 10;
        rev += t%10;
        t /= 10;
    }
    if (n == rev)
        return true;
    else 
        return false;
}

bool isStrPalin(string s)
{
    bool ans;
    string rev = s;
    reverse(rev.begin(), rev.end());
    return
    (rev == s)? ans = true: ans = false;
}

int main() {
    if(isNumPalin(9019))
        cout<<"Palindrome";
    else 
        cout<<"Not a palindrome";
    cout<<endl;

    if(isStrPalin("naman"))
        cout<<"Palindrome";
    else 
        cout<<"Not a palindrome";

    return 0;
}