//diff 1466
//abc170e_smart_infants

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int, int>;
const int mx = 2 * 1e5 + 5;
const int inf = 1e9;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<multiset<int>> la(mx);
    vector<int> a(n);
    vector<int> b(n);
    multiset<int> ga;

    rep(i, n)
    {
        int ta, tb; cin >> ta >> tb;
        --tb;
        la[tb].emplace(ta);
        a[i] = ta;
        b[i] = tb;
    }
    rep(i, mx)
    {
        if (la[i].empty()) continue;
        ga.emplace(*--la[i].end());
    }
    rep(i, q)
    {
        int c, d;
        cin >> c >> d;
        --c; --d;
        int ta = a[c];
        int tb = b[c];
        //�O���[�o���������
        //�O
        ga.erase(ga.find(*--la[tb].end()));
        //��
        if (!la[d].empty()) ga.erase(ga.find(*--la[d].end()));

        //���[�J���̈����z��
        la[tb].erase(la[tb].find(ta));
        la[d].emplace(ta);
        b[c] = d;

        //�O���[�o���֒ǉ�
        if (!la[tb].empty())
        {
            int nba = *--la[tb].end();
            ga.emplace(nba);
        }
        int naa = *--la[d].end();
        ga.emplace(naa);

        int ans = *ga.begin();
        cout << ans << endl;
    }
}