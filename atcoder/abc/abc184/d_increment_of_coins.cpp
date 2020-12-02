//1276
//abc184_d_increment_of_coins
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using P = pair<int, int>;

const int MAX = 100;
double dp[MAX + 1][MAX + 1][MAX + 1];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = MAX - 1; i >= 0; --i)
    {
        for (int j = MAX - 1; j >= 0; --j)
        {
            for (int k = MAX - 1; k >= 0; --k)
            {
                if (i + j + k == 0) continue;
                dp[i][j][k] += dp[i + 1][j][k] * i;
                dp[i][j][k] += dp[i][j + 1][k] * j;
                dp[i][j][k] += dp[i][j][k + 1] * k;
                dp[i][j][k] /= ((double)i + j + k);
                dp[i][j][k] += 1;
            }
        }
    }
    printf("%.10f\n", dp[a][b][c]);

    return 0;
}