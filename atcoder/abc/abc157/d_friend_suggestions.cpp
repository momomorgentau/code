//----------------------------
// ABC 157 D
// Friend Suggestions
// 1208
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
		if (d[x] > d[y]) swap(x, y);
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
	int n, m, k;
	cin >> n >> m >> k;
	UnionFind<int> uf(n);
	vector<vector<int>> block(n);
	vector<int> f(n);
	rep(i, m)
	{
		int u, v; cin >> u >> v;
		--u, --v;
		f[u]++;
		f[v]++;
		uf.unite(u, v);
	}
	rep(i, k)
	{
		int u, v; cin >> u >> v;
		--u, --v;
		block[u].emplace_back(v);
		block[v].emplace_back(u);
	}
	rep(i, n)
	{
		ll now = uf.size(i) - 1;
		now -= f[i];
		for (const auto& b : block[i])
		{
			now -= uf.same(i, b);
		}
		printf("%d ", now);
	}

	return 0;
}