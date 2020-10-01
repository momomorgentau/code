#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int a[6010];
int dp[2010][2010];
int maxa[2010]; //�v�f��i�����ꍇ�̍ő�l
int const inf = 1e9;

int main() {
    int n;
    cin >> n;
    int n3 = n * 3;

    rep(i, n3) cin >> a[i], --a[i];
    rep(i, n)rep(j, n) dp[i][j] = -inf;
    rep(i, n) maxa[i] = -inf;

    dp[a[0]][a[1]] = 0;
    dp[a[1]][a[0]] = 0;
    maxa[a[0]] = maxa[a[1]] = 0;
    int maxab = 0; //���̎��_�ł̍ő�l
    int ex = 0;

    for (int i = 2; i < n3 - 2; i += 3) {
        int x = a[i];
        int y = a[i + 1];
        int z = a[i + 2];

        //�V����3������v���Ă����Ƃ�
        if (x == y && y == z) {
            ++ex;
            continue;
        }

        vector<T> upd;
        rep(j, 3) {
            //�Â�2���ƐV����1��
            //�Â��̂�2���̂Ă邩�炻�̎��_�̍ő�lmaxab�Ɣ�r�B
            int m = max(maxab, dp[z][z] + 1);
            upd.emplace_back(x, y, m);

            //�Â�1���ƐV����2��
            //�Â����̂�1���̂Ă邩��A�̂ĂȂ��ق����܂ލő�lmaxa[k]�Ɣ�r�B
            rep(k, n) {
                int m = maxa[k];
                if (x == y) m = max(m, dp[x][k] + 1);
                upd.emplace_back(z, k, m);
            }
            swap(x, y); swap(y, z);

        }
        for (auto t : upd) {
            int na, nb, s;
            tie(na, nb, s) = t;

            dp[na][nb] = max(dp[na][nb], s);
            dp[nb][na] = max(dp[nb][na], s);
            //na,nb���܂ރe�[�u���̍ő�l���X�V
            maxa[na] = max(maxa[na], s);
            maxa[nb] = max(maxa[nb], s);
            maxab = max(maxab, s);
        }
    }

    int ans = maxab;
    //�Ō�̗v�f����v
    int al = a[n3 - 1];
    ans = max(ans, dp[al][al] + 1);
    //����1�𖞂�������
    ans += ex;
    cout << ans << endl;
    return 0;
}