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

/*-The power of a positive integer is the sum of digits of that integer. For example, the power of 13
is 1+3=4.
-Chef and Rick receive randomly generated positive integers. For each player, let's call the integer
he received final power.
-The goal of each player is to generate a positive integer such that its power (defined above) is
equal to his final power.
-The player who generated the integer with fewer digits wins the game. If both have the same number
of digits, then Rick cheats and wins the game.

You are given the final power of Chef PC and the final power of Rick PR. Assuming that both players
play optimally, find the winner of the game and the number of digits of the integer he generates.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int pc, pr, score_pc, score_pr;
        cin>>pc>>pr;
        score_pc = pc%9 == 0 ? pc/9 : pc/9+1;
        score_pr = pr%9 == 0 ? pr/9 : pr/9+1;
        
        if(score_pc < score_pr)
            cout<<0<<" "<<score_pc<<endl;
        else
            cout<<1<<" "<<score_pr<<endl;
    }
    
    return 0;
}