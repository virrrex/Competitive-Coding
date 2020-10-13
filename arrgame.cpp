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

/*Tzuyu gave Nayeon a strip of N cells (numbered 1 through N) for her birthday. This strip is
described by a sequence A1,A2,…,AN, where for each valid i, the i-th cell is blocked if Ai=1 or
free if Ai=0. Tzuyu and Nayeon are going to use it to play a game with the following rules:

-The players alternate turns; Nayeon plays first.
-Initially, both players are outside of the strip. However, note that afterwards during the game,
their positions are always different.
-In each turn, the current player should choose a free cell and move there. Afterwards, this cell
becomes blocked and the players cannot move to it again.
-If it is the current player's first turn, she may move to any free cell.
-Otherwise, she may only move to one of the left and right adjacent cells, i.e. from a cell c,
the current player may only move to the cell c−1 or c+1 (if it is free).
-If a player is unable to move to a free cell during her turn, this player loses the game.

Nayeon and Tzuyu are very smart, so they both play optimally. Since it is Nayeon's birthday, she
wants to know if she can beat Tzuyu. Find out who wins.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi strip(n);
        int ct=0, maxlen=0, smaxlen=0;
        f(i,n)
        {
            cin>>strip[i];
            if(!strip[i])
                ct++;
            else 
            {
                if(maxlen < ct)
                {
                    smaxlen = maxlen;
                    maxlen = ct;
                }
                else if(smaxlen < ct)
                    smaxlen = ct;
                ct = 0;
            }
        }
        if(smaxlen == 0)
        {
            if(maxlen % 2)
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }
        else 
        {
            if((maxlen%2) && (smaxlen < (maxlen+1)/2))
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }

    }
    
    return 0;
}