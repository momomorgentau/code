//ABC_200_E
//Patisserie_ABC_2
//1955
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> ijk(3*n+1);
	queue<int> q;
	rep(i, n) q.emplace(0);
	int add = 0;
	ll sum = 0;
	bool up = true;
	reps(i,3, n * 3+1)
	{
		int sub = q.front();
		q.pop();
		if (up) add += 1;
		else add -= 1;
		if (add == n) up = false;
		sum += max(0,add) - sub;
		ijk[i] = sum;
		q.emplace(add);
	}
	ll now = 0;
	int x = 2;
	reps(i, 3, n * 3 + 1)
	{
		if (now + ijk[i] < k)
		{
			now += ijk[i];
			x = i;
		}
		else break;
	}
	//合計値がx+1のときにK番目が現れる。
	//xまでにnow個出現している。
	x += 1;
	for (int i = max(x-n*2,1); i <= min(n,x-2); ++i)
	{
		int z = x - i - 1;
		int next = z -  max((z - n), 0) * 2;
		if (now + next < k)
		{
		    now += next;
			continue;
		}
		for (int j = max(x-i-n,1); j <= min(x-i-1,n); ++j)
		{
			int z = x - i - j;
			++now;
			if (now == k)
			{
				cout << i << " " << j << " " << z << endl;
				return 0;
			}
		}
	}


	return 0;
}