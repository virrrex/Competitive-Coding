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

/*
Chef is playing a card game with his friend Chefu. The rules of the game are as follows:

-There are two piles of cards. One pile belongs to Chef and the other to Chefu. One pile may be empty.
-At any moment, each card used in the game has a positive integer value. Whenever the value of a card
 becomes non-positive, it is removed from the game.
-The game is played in rounds. In each round, each player simultaneously draws one card from the top of
 his pile.
-If one player's pile is empty, this player cannot draw a card and therefore loses the game. (Note that
 it is impossible for both piles to be empty.)
-If the values of the drawn cards are equal, each player simply places the card he drew to the bottom of
 his pile.
-Otherwise, the player whose card has the higher value wins this round. This player places the card he
 drew to the bottom of his pile. Then, the card his opponent drew is transferred to him and he places this
 card to the bottom of his pile (below the card he just drew) as well.
-Whenever a card is transferred from one player to the other, the value of that card decreases by 1.
-When there is no transfer of cards between the players during 10100 consecutive rounds, each player
 calculates the sum of values of the cards that are currently in his pile. If one player has a higher sum,
 this player wins the game. Otherwise, the game ends in a draw.

You are given N cards (numbered 1 through N). For each valid i, the value of the i-th card is Ci. Your
task is to distribute the cards between the players before the start of the game ― assign each card to
one of the players. It is not necessary to distribute the cards equally between the players in any way.
After you distribute the cards, each player arranges the cards in his pile in some order he chooses (not
necessarily good for this player). Once the game starts, they may not rearrange their piles anymore.

Find the number of distributions of cards such that it is impossible for the game to end in a draw,
regardless of how the players form their starting piles. Since this number might be large, compute it
modulo 1,000,000,007. Two distributions of cards are different if there is an integer i (1≤i≤N) such that
the i-th card belongs to Chef in one distribution and to Chefu in the other distribution.
*/

ll pp(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b%2 != 0)
            ans = ans * a % mod;
        b /= 2;
        a = a*a % mod;
    }
    return ans;
}

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        map<ll,ll> card;
        ll res, mx = 0;
        F(i,n)
        {
            ll temp; cin>>temp;
            card[temp]++;
            if(mx < temp)
                mx = temp;
        }
        if(n == 1)
        {
            cout<<2<<endl;
            continue;
        }
        if(card[mx] %2 != 0)
            res = pp(2,n) % mod;
        else
        {
            ll midnum = 1;
            ll k = card[mx]/2;
            F(i,k)
            {
                midnum = (midnum %mod * (card[mx]-i))%mod;
                midnum = (midnum * pp(i+1, mod-2) %mod) % mod;
            }
            res = pp(2,n)%mod - ((pp(2, n-card[mx])%mod) * midnum) % mod;
        }
        if(res < 0)
            res = (res + mod) % mod;
        cout<<res<<endl;
    }
    
    return 0;
}