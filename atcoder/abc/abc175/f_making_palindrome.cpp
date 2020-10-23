//diff 2716
//abc175 making_plindrome

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pli = pair<ll, int>;

const ll inf = 1e18;

string rev(string str) {
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    //-----�v�f�̏���--------
    //������A�t���̕�����A�ꕶ�������炵���C���f�b�N�X
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> c(n);
    rep(i, n) cin >> s[i] >> c[i];
    rep(i, n) {
        s.emplace_back(rev(s[i]));
        c.emplace_back(c[i]);
    }
    vector<vector<int>> idx(n * 2);
    int cnt = 1; //0�͏I�������ɂ��邽��1����J�n

    rep(i, n * 2) {
        int l = s[i].size();
        rep(j, l) {
            idx[i].emplace_back(cnt);
            ++cnt;
        }
    }

    //�O���t�̐���-----------------------------
    /*v[i][j]�Ƃ����Ƃ���
    i -���݂̃m�[�h
    j - �ړ���̃m�[�h(idx)�Ƃ���ɂ�����R�X�g��pair
    �Ƃ����z����쐬����*/

    vector<vector<Pii>> g(cnt);
    rep(i, n * 2) {
        int l = s[i].size();
        rep(j, l) { //j������v���Ă���ƍl����B
            int v = idx[i][j];
            rep(k, n * 2) { //k�͎��ɂ��镶����i�J�ڐ�j
              //0~n-1�͑O�An~2n-1�͌��ɐڑ�����v�f
              //�O�̂��̂ɂ͌��̂��̂�����B
                if (i / n == k / n) continue;
                int lt = s[k].size(); //�J�ڐ�̕�����
                //�������ƌ��݂̕����̗]��̒������r���ĒZ�������Ƃ�B
                int w = min(lt, l - j);
                //�񕶂̂��߂�w������v����K�v������B
                if (s[i].substr(j, w) != s[k].substr(0, w)) continue;
                int u = 0;
                if (lt > w) { //�J�ڐ�̂ق�������
                    u = idx[k][w];
                }
                else if (l > j + w) { //���̕�����̕�������
                    u = idx[i][j + w];
                }
                else u = 0; //��v���Ă���B
                g[v].emplace_back(u, c[k]);
            }
        }
    }


    vector<ll> d(cnt, inf);
    priority_queue<Pli, vector<Pli>, greater<Pli>> pq;

    //���n�_->������1�����u������Ԃ�S�Ă̕�����queue�ɓ���Ă����B
    rep(i, n)
    {
        d[idx[i][0]] = c[i];
        pq.emplace(c[i], idx[i][0]);
    }
    while (!pq.empty())
    {
        ll c = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        if (d[s] < c) continue;
        for (auto a : g[s])
        {
            int gt = a.first;
            int gc = a.second;
            if (d[gt] <= d[s] + gc) continue;
            d[gt] = d[s] + gc;
            pq.emplace(d[gt], gt);
        }
    }

    ll ans = d[0];
    rep(i, n * 2)
    {
        int l = s[i].size();
        rep(j, l)
        {
            string t = s[i].substr(j);
            if (t == rev(t)) ans = min(ans, d[idx[i][j]]);
        }

    }

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

