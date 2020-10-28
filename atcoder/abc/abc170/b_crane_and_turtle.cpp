//17
//abc170_crane_and_turtle
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	rep(i, x + 1)
	{
		int s = 2 * i + 4 * (x - i);
		if (s == y)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}