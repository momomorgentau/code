//----------------------------
// ABC 319 B 
// Measure
// 70
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
	cin >> n;
	string ans = "";
	rep(i,n+1)
	{
	    char c = '-';
	    reps(j,1,10)
		{
		    if(n % j != 0) continue;
		    if((i * j) % n != 0) continue;
			c = j + '0';
			break;
		}
		ans += c;
	}
	cout << ans << endl;
    return 0;
}

