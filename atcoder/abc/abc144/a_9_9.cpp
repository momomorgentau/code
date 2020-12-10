//15
//abc144_a_9*9
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
	int a, b;
	cin >> a >> b;
	int ans = a * b;
	if (a >= 10 || b >= 10) ans = -1;
	cout << ans << endl;
	return 0;
}