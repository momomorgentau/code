//----------------------------
//ABC_097_A
//Colorful Transceivers
//50
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
	if (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;

}