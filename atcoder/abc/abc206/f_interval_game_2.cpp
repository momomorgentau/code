//ABC_206_F
//Interval_Game_2
//2221
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int M = 100;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> dp(M + 5, vector<int>(M + 5));

        vector<int> L(n), R(n);
        rep(i, n) cin >> L[i] >> R[i];
        rep(i, n) --L[i];
        rep(i, n) --R[i];
        for (int w = 1; w <= M; ++w)
        {
            for (int l = 0; l < M; ++l)
            {
                int r = l + w;
                if (r > M) break;
                vector<int> s(M + 5);
                rep(i, n)
                {
                    if (l <= L[i] && R[i] <= r)
                    {
                        s[dp[l][L[i]] ^ dp[R[i]][r]] = 1;
                    }
                }
                rep(g, M + 5)
                {
                    if (s[g] == 1) continue;
                    dp[l][r] = g;
                    break;
                }
            }

        }

        if (dp[0][M-1] == 0) cout << "Bob" << endl;
        else cout << "Alice" << endl;

    }

    return 0;
}