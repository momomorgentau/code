//33
//abc144_b_81
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	bool ok = false;
	reps(i, 1, 10)
	{
		if (n % i == 0 && n / i <= 9) ok = true;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
