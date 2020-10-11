//diff 2000
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int n2 = n * 2;
    //type[i] = -1,0,1
    //-1:�n�_0�Ȃ�ł�,1:�I�_
    vector<int> type(n2, 0);
    //p[i][j] = -1,0,1
    //-1,�y�A�ɂł��Ȃ��A0�y�Aok, 1�y�A
    vector<vector<int>> p(n2, vector<int>(n2));
    //�����������o�Ă��Ȃ���������
    bool ng = false;

    //�f�[�^�Z�b�g�����---------
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        if (a != -1) --a;
        if (b != -1) --b;

        //���~����L�^���Ă���
        if (a != -1) {
            if (type[a] != 0) ng = true;
            type[a] = -1;
        }
        if (b != -1) {
            if (type[b] != 0) ng = true;
            type[b] = 1;
        }

        //�y�A�ɂȂ��Ă����
        if (a != -1 && b != -1) {
            //a��b�����肦�Ȃ��ꍇ
            if (a >= b) ng = true;
            rep(j, n2) {
                p[a][j] = -1;
                p[j][b] = -1;
            }
            //��X�̂��߂�1�����Ă����܂��B
            p[a][b] = 1;
        }
    }

    if (ng) {
        cout << "No" << endl;
        return 0;
    }

    //�y�A�����邩�ǂ����̔���
    rep(i, n2) {
        if (type[i] == -1) {
            rep(j, n2) {
                if (type[j] == 1) {
                    //��قǃy�A�̂��̂ɂ�1�����Ă����܂���
                    if (p[i][j] == 0) {
                        p[i][j] = -1;
                    }
                }
            }
        }
    }

    //�f�[�^�Z�b�g�m�F�p
    /*
    for (auto v : type) cout << v << " ";
    cout << endl;
    cout << "------------------" << endl;
    for (auto vv : p) {
        for (auto v : vv) cout << v << " ";
        cout << endl;
    }
    cout << "-------------" << endl;
    */

    //dp�񂵂܂�------
    vector<bool> dp(n2 + 1, false);
    dp[0] = true;

    //2����Ԃ����炵�Ĕ�������Ă����B
    for (int i = 0; i < n2; i += 2) {
        if (!dp[i]) continue;
        for (int j = i + 2; j < n2 + 1; j += 2) { //n2�Ԗڂ܂Ŕ��肷�邩��n2+1�Ƃ���
            //�T���̕�w��ŋ�؂��Ƃ���B
            int w = j - i;
            //�y�A�ɂȂ�̂�2���B
            w /= 2;
            //�ق�Ƃ�ok�����肷��i��L�̃f�[�^�Z�b�g�𖞂������j
            bool ok = true;

            //w�K��ō~���B
            //�܂�A0->w, w-1 ->2w-1�ł����
            for (int k = 0; k < w && ok; ++k) {
                int s = i + k; //���K
                int t = i + k + w; // �~���K


                //�y�A���m�肵�Ă�����̂̃`�F�b�N
                if (p[s][t] == -1) ok = false;
                //�n�_�A�I�_���������g���Ă��邩
                if (type[s] == 1 || type[t] == -1) ok = false;
            }
            //�f�o�b�O�p
            //cout << i << " " << j << " " << w*2 << " " << ok <<endl;
            dp[j] = dp[j] || ok; //��xtrue�ɂȂ������̂́Afalse�ɍX�V���Ȃ��B
        }
    }

    string ans = dp[n2] ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}

