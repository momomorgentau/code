//2
//abc168_a_therefore
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	int d = n % 10;
	string ans;
	if (d == 2 || d == 4 || d == 5 || d == 7 || d == 9) 
	{
		ans = "hon";
	}
	else if (d == 3) ans = "bon";
	else ans = "pon";
	cout << ans << endl;

	return 0;
}