//ABC_111_A
//AtCoder_Beginner_Contest_999
//31
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	string s;
	cin >> s;
	for (auto c : s)
	{
		if (c == '1') cout << '9';
		else if (c == '9') cout << '1';
		else cout << c;
	}
	cout << endl;

	return 0;
}