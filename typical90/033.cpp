#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int h, w;
	cin >> h >> w;
	if (h == 1 || w == 1)
	{
		cout << h + w << endl;
		return 0;
	}
	h = (h + 1) / 2;
	w = (w + 1) / 2;
	cout << h * w << endl;
	return 0;
}