//081
//Friendly Group
//*5

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int M = 5005;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ab(M, vector<int>(M));
    rep(i, n)
    {
        int a, b; cin >> a >> b;
        ++ab[a][b];
    }
    rep(i, M - 1)rep(j, M - 1) ab[i][j + 1] += ab[i][j];
    rep(i, M - 1)rep(j, M - 1) ab[j + 1][i] += ab[j][i];
    int ans = 0;
    reps(al, 1, M)reps(bl, 1, M)
    {
        int ar = min(al + k, M - 1);
        int br = min(bl + k, M - 1);

        int now = ab[ar][br] - ab[al - 1][br] - ab[ar][bl - 1] + ab[al - 1][bl - 1];
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}
