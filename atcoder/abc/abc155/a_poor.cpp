//14
//abc_155_a_poor
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	string ans = "No";
	if (a == b && b != c) ans = "Yes";
	if (b == c && c != a) ans = "Yes";
	if (c == a && a != b) ans = "Yes";
	cout << ans << endl;
	return 0;
}
