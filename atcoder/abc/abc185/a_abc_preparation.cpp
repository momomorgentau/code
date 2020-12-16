//7
//abc185_a_abc_preparation
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	int ans = min({ a1,a2,a3,a4 });
	cout << ans << endl;

	return 0;
}