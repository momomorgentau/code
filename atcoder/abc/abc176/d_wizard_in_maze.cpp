#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w, sh, sw, th, tw;
    cin >> h >> w >> sh >> sw >> th >> tw;
    --sh; --sw; --th; --tw;
    vector<string> s(h);
    //���͂�h�s��string 
    rep(i, h) cin >> s[i];

    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));

    deque<P> q;

    vector<int> mx = { 0, 0, -1, 1 };
    vector<int> my = { 1, -1, 0, 0 };

    dist[sh][sw] = 0;
    q.emplace_back(sh, sw);
    while (!q.empty()) {
        int i = q[0].first;
        int j = q[0].second;
        int d = dist[i][j];
        q.pop_front();
        //�����ł̈ړ�
        rep(k, 4) {
            int ni = i + mx[k];
            int nj = j + my[k];
            //�g�O�ɔ�яo���Ȃ����̔���
            if (ni < 0 || h - 1 < ni || nj < 0 || w - 1 < nj) continue;
            //�ǂ��̔���
            if (s[ni][nj] == '#') continue;
            //�X�V�\�A���B�ς݂��̔���
            if (dist[ni][nj] <= d) continue;
            dist[ni][nj] = d;
            q.emplace_front(ni, nj);
        }
        //���@�ł̈ړ�
        for (int wx = -2; wx <= 2; ++wx) {
            for (int wy = -2; wy <= 2; ++wy) {
                int ni = i + wx;
                int nj = j + wy;
                //�g�O�ɔ�яo���Ȃ����̔���
                if (ni < 0 || h - 1 < ni || nj < 0 || w - 1 < nj) continue;
                //�ǂ��̔���
                if (s[ni][nj] == '#') continue;
                //�X�V�\�A���B�ς݂��̔���
                if (dist[ni][nj] <= d + 1) continue;
                dist[ni][nj] = d + 1;
                q.emplace_back(ni, nj);
            }
        }
    }

    int ans = dist[th][tw];
    if (ans == INT_MAX) ans = -1;

    cout << ans << endl;

    return 0;
}