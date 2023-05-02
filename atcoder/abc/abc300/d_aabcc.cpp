//----------------------------
// ABC D 300 
// AABCC
// 908
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<bool> Eratosthenes(int N) {
	// �e�[�u��
	vector<bool> isprime(N + 1, true);

	// 0, 1 �͗\�߂ӂ邢���Ƃ��Ă���
	isprime[0] = isprime[1] = false;

	// �ӂ邢
	for (int p = 2; p <= N; ++p) {
		// ���łɍ������ł�����̂̓X�L�b�v����
		if (!isprime[p]) continue;

		// p �ȊO�� p �̔{������f�����x���𔍒D
		for (int q = p * 2; q <= N; q += p) {
			isprime[q] = false;
		}
	}

	// 1 �ȏ� N �ȉ��̐������f�����ǂ���
	return isprime;
}


int main()
{
	ll n;
	cin >> n;
	ll m = sqrt(n) + 1;
	vector<bool> isprime = Eratosthenes(m);
	vector<ll> p;
	rep(i, m+1) if (isprime[i]) p.emplace_back(i);

	int size = p.size();
	ll ans = 0;
	for (int i = 0; i < size-2; i++)
	{
		ll a = p[i];
		{
			ll tmp = 1;
			bool ok = true;
			rep(i, 5)
			{
				tmp *= a;
				if (tmp > n)
				{
					ok = false;
					break;
				}
			}
			if (!ok) break;
		}


		for (int j = i + 1; j < size - 1; j++)
		{
			ll b = p[j];
			{
				ll tmp = a*a;
				bool ok = true;
				rep(i, 3)
				{
					tmp *= b;
					if (tmp > n)
					{
						ok = false;
						break;
					}
				}
				if (!ok) break;
			}
			for (int k = j + 1; k < size; k++)
			{
				ll c = p[k];
				{
					ll tmp = a * a * b;
					bool ok = true;
					rep(i, 2)
					{
						tmp *= c;
						if (tmp > n)
						{
							ok = false;
							break;
						}
					}
					if (!ok) break;
				}
				ans++;
			}
		}
	}
	cout << ans << endl;
	/*
	for (ll i = 2; i * i <= n; i++)
	{
		bool ok = true;
		for (const auto& q : p)
		{
			if (i % q == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok) p.emplace_back(i);
	}
	*/

	return 0;
}
