//----------------------------
//ABC_235_E
//MST +1
//1304
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

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
	int n, m, q;
	cin >> n >> m >> q;

	vector<tuple<int, int, int, bool, int>> node;
	map<int, int> mp;
	rep(i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		node.emplace_back(c, a, b, false, -1);
	}
	rep(i, q)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		node.emplace_back(w, u, v, true, i);

	}
	sort(node.begin(), node.end());
	UnionFind<int> UF(n);
	vector<int> ans(q);
	for (const auto& [x, a, b, p, qi] : node)
	{
		if (p)
		{
			if (!UF.same(a, b))
			{
				ans[qi] = 1;
			}
			else
			{
				ans[qi] = 0;
			}
		}
		else
		{
			if (!UF.same(a, b))
			{
				UF.unite(a, b);
			}
		}
	}
	for (const auto& a : ans)
	{
		if (a)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}