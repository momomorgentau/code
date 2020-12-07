//-
//abc150_a_500yen_coins
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int k, x;
	cin >> k >> x;
	string ans;
	if (k * 500 >= x) ans = "Yes";
	else ans = "No";

	cout << ans << endl;

	return 0;
}