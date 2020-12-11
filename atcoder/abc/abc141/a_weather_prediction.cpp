//16
//abc_141_a_weather_prediction
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

string st[] ={"Sunny", "Cloudy", "Rainy"};
int main()
{
	string s;
	cin >> s;
	string ans;
	if(s == st[0]) ans = st[1];
	if(s == st[1]) ans = st[2];
	if(s == st[2]) ans = st[0];
	cout << ans << endl;		
	return 0;
}