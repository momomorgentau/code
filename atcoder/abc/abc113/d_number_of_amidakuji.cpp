//ABC_113_D
//number_of_amidakuji
//1597
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int H = 100;
const int W = 8;
int dp[H+5][W];
const int mod = (1e9)+7;
int main()
{
    int h,w,k;
    cin >> h >> w >> k;
    if(w == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    dp[0][0] = 1;

    rep(i,h)
    {
        rep(j,w)
        {
            rep(bit,1<<(w-1))
            {
                bool ok = true;
                rep(k,w-2)
                {
                    if(((bit>>k)&3)==3) ok = false;
                }
                if(!ok) continue;
            
                int r = j;
                int l = j-1;
                bool isr = false,isl = false;
                if(r<w-1)
                {
                    if(bit&(1<<r)) isr = true;
                }
                if(l>=0)
                {
                    if(bit&(1<<l)) isl = true;
                }
                int nx = j + isr-isl;
                dp[i+1][nx] += dp[i][j];
                dp[i+1][nx] %= mod;
            }
        }
    }
    cout << dp[h][k-1] << endl;
    return 0;
}