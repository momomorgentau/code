//----------------------------
//ABC_094_A
//Cats and Dogs
//48
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
	int a, b, x;
	cin >> a >> b >> x;
	if (a <= x && x <= a + b)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}