//51
//abc_141_b_tap_dance
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	bool ok = true;
	rep(i,s.size())
	{
		if(i&1 && s[i] == 'R') ok =false;
		if(i%2==0 && s[i] == 'L') ok = false;
	}
	if(ok) cout << "Yes"<<endl;
	else cout << "No" << endl;
	return 0;
}