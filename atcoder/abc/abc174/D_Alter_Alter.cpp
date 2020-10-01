#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	int stoneNum;
	string stones;
	cin >> stoneNum >> stones;

	int iterW, iterR;
	int cntR = 0;
	int ans = 0;

	rep(i, stoneNum)
	{
		if (stones[i] == 'R') ++cntR;
	}
	rep(i, cntR)
	{
		if (stones[i] == 'W') ++ans;
	}
	cout << ans << endl;
	return 0;
}