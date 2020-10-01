#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using  P = pair<int, int>;
//BIT�̎���
template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    BIT(int n = 0) :n(n), bit(n + 1) {}
    void add(int i, T x = 1) {
        for (i++; i <= n; i += i & -i) {
            bit[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i & -i) {
            x += bit[i];
        }
        return x;
    }
};
int main()
{
    int n, q; cin >> n >> q;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }

    //�N�G�����n�_�̑傫�������Ƃɕ��ׂ�---
    vector<vector<P>> query(n);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        //�ԍ����ێ����Ă���
        query[l].emplace_back(r, i);
    }

    //���̔z�������------------------
    vector<vector<int>> arrow(n);
    //���Ɍ��ꂽ�������i�[����
    vector<int> app(n, -1);

    rep(i, n)
    {
        int num = app[c[i]];
        if (num != -1)
        {
            arrow[num].emplace_back(i);
        }
        app[c[i]] = i;
    }
    //X���Ɋւ��đ������s��-----------------
    vector<int> ans(q);
    BIT<int> bit(n);

    //x���̑傫�����ɒ��ׂ�
    for (int x = n - 1; x >= 0; --x)
    {
        //���̍��W�ƈ�v������Abit��y���W�Ԗڂ�+1
        for (int y : arrow[x]) bit.add(y, 1);
        //�N�G���𒲂ׂ�
        for (P qu : query[x])
        {
            int r = qu.first, i = qu.second;
            //bit��r�܂ł̐����̍��v���d����
            ans[i] = (r - x + 1) - bit.sum(r);
        }
    }
    rep(i, q) cout << ans[i] << endl;

    return 0;
}