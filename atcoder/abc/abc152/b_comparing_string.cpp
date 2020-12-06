//25
//abc152_b_comparing_strings

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
	string sa, sb;
	rep(i, a) sa += b + '0';
	rep(i, b) sb += a + '0';
	if (sa > sb) swap(sa, sb);
	cout << sa << endl;
	return 0;
}