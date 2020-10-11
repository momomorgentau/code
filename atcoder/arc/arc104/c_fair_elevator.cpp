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
    //-1:始点0なんでも,1:終点
    vector<int> type(n2, 0);
    //p[i][j] = -1,0,1
    //-1,ペアにできない、0ペアok, 1ペア
    vector<vector<int>> p(n2, vector<int>(n2));
    //同じ数字が出てこないか見張る
    bool ng = false;

    //データセットを作る---------
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        if (a != -1) --a;
        if (b != -1) --b;

        //乗り降りを記録していく
        if (a != -1) {
            if (type[a] != 0) ng = true;
            type[a] = -1;
        }
        if (b != -1) {
            if (type[b] != 0) ng = true;
            type[b] = 1;
        }

        //ペアになってるもの
        if (a != -1 && b != -1) {
            //aとbがありえない場合
            if (a >= b) ng = true;
            rep(j, n2) {
                p[a][j] = -1;
                p[j][b] = -1;
            }
            //後々のために1を入れておきます。
            p[a][b] = 1;
        }
    }

    if (ng) {
        cout << "No" << endl;
        return 0;
    }

    //ペアが作れるかどうかの判定
    rep(i, n2) {
        if (type[i] == -1) {
            rep(j, n2) {
                if (type[j] == 1) {
                    //先ほどペアのものには1を入れておきました
                    if (p[i][j] == 0) {
                        p[i][j] = -1;
                    }
                }
            }
        }
    }

    //データセット確認用
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

    //dp回します------
    vector<bool> dp(n2 + 1, false);
    dp[0] = true;

    //2つずつ区間をずらして判定をしていく。
    for (int i = 0; i < n2; i += 2) {
        if (!dp[i]) continue;
        for (int j = i + 2; j < n2 + 1; j += 2) { //n2番目まで判定するからn2+1とする
            //探索の幅w先で区切れるとする。
            int w = j - i;
            //ペアになるので2わる。
            w /= 2;
            //ほんとにokか判定する（上記のデータセットを満たすか）
            bool ok = true;

            //w階先で降りる。
            //つまり、0->w, w-1 ->2w-1でおりる
            for (int k = 0; k < w && ok; ++k) {
                int s = i + k; //乗る階
                int t = i + k + w; // 降りる階


                //ペアが確定しているもののチェック
                if (p[s][t] == -1) ok = false;
                //始点、終点が正しく使われているか
                if (type[s] == 1 || type[t] == -1) ok = false;
            }
            //デバッグ用
            //cout << i << " " << j << " " << w*2 << " " << ok <<endl;
            dp[j] = dp[j] || ok; //一度trueになったものは、falseに更新しない。
        }
    }

    string ans = dp[n2] ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}

