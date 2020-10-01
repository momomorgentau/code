#include <bits/stdc++.h> #define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
//UnionFind
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
		if (x < y) swap(x, y);
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
	int n, m;
	cin >> n >> m;
	UnionFind uf(n);

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		uf.unite(a, b);
	}

	int ans = 0;
	rep(i, n) ans = max(ans, uf.size(i));

	cout << ans << endl;
	return 0;
}