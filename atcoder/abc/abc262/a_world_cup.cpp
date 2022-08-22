//----------------------------
//ABC 262 A
//World Cup
//8
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
	int y; cin >> y;
	int t = 0;
	if (y % 4 == 0) t = 2;
	else if (y % 4 == 1) t = 1;
	else if (y % 4 == 3) t = 3;
	cout << y + t << endl;
	return 0;
}