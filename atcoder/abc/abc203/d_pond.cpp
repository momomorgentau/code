//ABC_203_D
//Pond
//1622
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() 
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> A(n, vector<int> (n));
    rep(i, n)rep(j, n)cin >> A[i][j];
    int ac = 1e9 + 5;
    int wa = -1;
    while (ac - wa > 1)
    {
        int wj = (ac + wa) / 2;
        vector<vector<int>> S(n+1, vector<int>(n+1));
        int judge = 0;
        rep(i, n)rep(j, n)
        {
            if (A[i][j] <= wj) S[i][j+1] = S[i][j] + 1;
            else S[i][j+1] = S[i][j];
        }
        for (int j = 0; j < n - k + 1; ++j)
        {
            int now = 0;
            rep(p, k)
            {
                now += S[p][j + k] - S[p][j];
            }
            judge = max(judge, now);

            for (int i = 0; i < n - k; ++i)
            {
                now -= S[i][j + k] - S[i][j];
                now += S[i+k][j + k] - S[i + k][j];

                judge = max(judge, now);

            }
        }
        if (judge >= (k*k + 1) / 2) ac = wj;
        else wa = wj;

    }
    cout << ac << endl;
    return 0;
}

