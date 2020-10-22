//diff 2367
//abc180_f_unbranched
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;

int f(int n, int m, int l)
{
	//��ސ��̌v�Z
	vector<int> path(l + 1, 0), cycle(l + 1, 0);
	path[1] = 1;

	if (l >= 2) path[2] = 1; // l=1�̂Ƃ��΍�
	reps(i, 3, l + 1) path[i] = ((ll)path[i - 1] * i) % mod;
	reps(i, 2, l + 1) cycle[i] = path[i - 1];

	//���_�̑I�ѕ��̌v�Z
	//�p�X�J���̎O�p�`��p����
	vector<vector<int>> p(n + 1, vector<int>(n + 1));
	p[0][0] = 1;
	rep(i, n)rep(j, i + 1)
	{
		p[i + 1][j] += p[i][j];
		p[i + 1][j] %= mod;

		p[i + 1][j + 1] += p[i][j];
		p[i + 1][j + 1] %= mod;
	}
	//dp�e�[�u��
	//dp[i][j]: i���_���g�����Bj�ӂ��g�����B
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	dp[0][0] = 1;
	//dp����
	rep(i, n)rep(j, m + 1)
		//�ǉ��� j ��0�ł��A���_�����ǉ��ł���̂�j��m�܂ŁA
	{
		//path�̒ǉ�
		reps(k, 1, l + 1)
		{
			int ni = k + i;
			int nj = k + j - 1;
			if (ni > n || nj > m) break;
			/*
			��C�Ɋ|����ƃI�[�o�t���[����̂œs�xmod�����
			����Ă��邱�Ƃ�
			dp[ni][nj] += dp[i][j] * cycle[k]* p[n - i - 1][k - 1] % mod;
			dp[ni][nj] %= mod;
			*/
			ll add = ((ll)path[k] * p[n - i - 1][k - 1]) % mod;
			add = (add * dp[i][j]) % mod;
			dp[ni][nj] = (dp[ni][nj] + add) % mod;

		}
		//cycle�̒ǉ�
		reps(k, 2, l + 1)
		{
			int ni = k + i;
			int nj = k + j;
			if (ni > n || nj > m) break;
			/*
			��C�Ɋ|����ƃI�[�o�t���[����̂œs�xmod�����
			����Ă��邱�Ƃ�
			dp[ni][nj] += dp[i][j] * path[k]* p[n - i - 1][k - 1] % mod;
			dp[ni][nj] %= mod;
			*/
			ll add = ((ll)cycle[k] * p[n - i - 1][k - 1]) % mod;
			add = (add * dp[i][j]) % mod;
			dp[ni][nj] = (dp[ni][nj] + add) % mod;
		}
	}
	return dp[n][m];
}

int main()
{
	int n, m, l;
	cin >> n >> m >> l;

	int ans = f(n, m, l) - f(n, m, l - 1);
	if (ans < 0) ans += mod;
	else ans %= mod;
	cout << ans << endl;

	return 0;
}