//----------------------------
// ABC 295 G
// Minimum Reachable City
// 2091
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

template<typename T>
struct UnionFind {
    vector<int> d;
    //�R���X�g���N�^
    UnionFind(int n = 0) : d(n, -1) {}
    //���̒T���ƒ���ւ�
    int find(int x) {
        if (d[x] < 0) return x;
        //���̂͂肩��
        return d[x] = find(d[x]);
    }
    //���̌���
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        //�傫�����ɏ�����������������
        //if (d[x] > d[y]) swap(x, y);
        // ���_�ԍ����������ق��ɂ������܂�
        if (x > y) swap(x, y);
        //�T�C�Y�̍X�V
        d[x] += d[y];
        //����
        d[y] = x;
        return true;
    }
    //�T�C�Y�̎擾
    int size(int x) { return -d[find(x)]; }
    //�����W���ɑ����Ă��邩
    bool same(int x, int y) { return (find(x) == find(y)); }
};


int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    reps(i, 1, n) cin >> p[i];
    rep(i, n) p[i]--;

    UnionFind<int> uf(n);
    int q; cin >> q;
    while (q--)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            u = uf.find(u);
            v = uf.find(v);
            queue<int> q;
            q.emplace(u);
            while (!q.empty())
            {
                int a = q.front();
                q.pop();
                if (v == a)break;
                int t = p[a];
                uf.unite(a, t);
                q.emplace(t);
            }
        }
        if (op == 2)
        {
            int x; cin >> x;
            x--;
            printf("%d\n", uf.find(x) + 1);
        }
    }
    return 0;
}