//----------------------------
// ABC 300 A
// N-choice question
// 8
//----------------------------
nclude<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    rep(i, n)
    {
	int c; cin >> c;
        if (c == a + b)
	{
	    cout << i + 1 << endl;
	    return 0;
	}
    }
    return 0;
}
