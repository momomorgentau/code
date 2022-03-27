//----------------------------
//ABC 245 A
//Good morning
//25
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a * 60 + b < c * 60 + d + 1) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;

	return 0;
}
