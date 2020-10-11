//diff 410
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ls = s.length();
	vector<int> a(ls + 1, 0);
	vector<int> t(ls + 1, 0);
	vector<int> g(ls + 1, 0);
	vector<int> c(ls + 1, 0);

	int suma = 0;
	int sumt = 0;
	int sumc = 0;
	int sumg = 0;


	rep(i, ls) {
		char ch = s[i];

		if (ch == 'A') ++suma;
		else if (ch == 'T') ++sumt;
		else if (ch == 'C') ++sumc;
		else ++sumg;

		a[i + 1] = suma;
		t[i + 1] = sumt;
		c[i + 1] = sumc;
		g[i + 1] = sumg;

	}

	int ans = 0;
	for (int li = 1; li < ls + 1; ++li) {
		for (int j = 1; j <= ls - li + 1; ++j) {
			int e = j + li - 1;
			if (a[e] - a[j - 1] != t[e] - t[j - 1]) continue;
			if (c[e] - c[j - 1] != g[e] - g[j - 1]) continue;
			++ans;

		}
	}
	cout << ans << endl;
	return 0;

}