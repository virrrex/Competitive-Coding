#include<bits/stdc++.h>
using namespace std;

string findNextPalinDate (string input) {
   // Write your code here      DD:MM, D:M, D:MM, DD:M
   int d1, d2, m1, m2;
   if(input[2] == ':')
   {
       d1 = input[0] - '0'; d2 = input[1] - '0';
       if(input.length()==4)
            { m1 = 0; m2 = input[3] - '0';}
        else
        { m1 = input[3] - '0'; m2 = input[4] - '0'; }
   }
   else if(input[1] == ':')
   {
       d1 = 0; d2 = input[0] - '0';
       if(input.length()==3)
       { m1 = 0; m2 = input[2] - '0';}
       else
       { m1 = input[2] - '0'; m2 = input[3] - '0'; }
   }
   while(1)
   {
        if(d1 == 6 && d2 == 0 && m1 == 3 && m2 == 0)
        {
            d1 = 0; d2 = 1; m1 = 0; m2 = 1;
        }
        else
        {
            if(d2 == 0 && d1 == 6)
            {
                d1 = 0; d2 = 1;
                if(m2 == 9)
                {
                    m2 = 0;
                    m1++;
                }
                else
                    m2++;
            }
            if(d2 == 9)
            {
                d2 = 0;
                d1++;
            }
            else
                d2++;
        }
        if(d1 == m2 && d2 == m1)
            break;
   }
   char a = '0' + d1, b = '0' + d2, c = '0' + m1, d = '0' + m2, x = ':';
   string ans = ""; cout<<a<<b<<":"<<c<<d;
   //string a1(1,a), b1(1,b), c1(1,c), dd(1,d), x1(1,x);
   //strcat(ans,a1); strcat(ans,b1); strcat(ans,x1); strcat(ans,c1); strcat(ans,dd);
   //ans.append(a); ans.append(b); ans.append(':'); ans.append(c); ans.append(d);
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    getline(cin, input);

    string out_;
    out_ = findNextPalinDate(input);
    cout << out_;
}