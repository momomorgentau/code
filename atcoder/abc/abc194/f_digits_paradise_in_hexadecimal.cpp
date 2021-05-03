//ABC194F_Digits_Paradise_in_Hexadecimal
//2197
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

const int mod = (1e9)+7;
class mint
{
public:
	long long x;
	mint(long long x = 0) :x((x% mod + mod) % mod) {}
	mint operator -() const { return mint(-x); }
	mint& operator +=(const mint a)
	{
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator -=(const mint a)
	{
		if ((x += -a.x + mod) >= mod) x -= mod;
		return *this;
	}
	mint& operator *=(const mint a)
	{
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a)
	{
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a)
	{
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a)
	{
		mint res(*this);
		return res *= a;
	}
	mint pow(long long t) const
	{
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}
	//for only prime number
	//Fermat's little theorem
	mint inv() const
	{
		return pow(mod - 2);
	}
	mint& operator/=(const mint a)
	{
		return (*this) *= a.inv();
	}
	mint operator/(const mint a)
	{
		mint res(*this);
		return res /= a;
	}
};

const int N = 2e5;
mint dp[N+10][16];

int main()
{
	string n;
	int k;
	cin >> n >> k;

	int l = n.size();

	/*
	各桁において
	[1]0~15に変換した数字
	[2]それまでに使用した数字の種類数(該当桁も含む)
	[3]それまでに使用した数字の種類数のうちi+1桁目より小さいもの
	(次桁の数-[3]により i 桁目まで一致していた時に i+1 に遷移しうる数が求まる)
	の配列を用意する。
	*/
	vector<int> n16(l);		//[1]
	vector<int> used(l);	//[2]
	vector<int> used2(l);	//[3]
	set<int> s;
	rep(i, l)
	{
		char c = n[i];
		int d = -1;
		if (c - '0' <= 9) d = c - '0';
		else d = c - 'A' + 10;
		
		if(i != 0) used2[i-1] = distance(s.begin(),s.lower_bound(d));
		
		s.insert(d); 
		n16[i] = d;
		used[i] = s.size();
	}

	//1 ~ 1桁目の数（含まない）が該当する
	dp[0][1] = n16[0] - 1;

	rep(i, l-1)
	{
		for(int j = 1; j <= 16; ++j)
		{
			//含まれない数
			dp[i + 1][j+1] += dp[i][j] * (16-j);
			//含まれる数
			dp[i + 1][j] += dp[i][j] * j;
		}		
		//0が続くものからの遷移
		//0000→00001 ~ 0000Fまでの15通り
		dp[i + 1][1] += 15;

		//i桁目までNと一致している場合からの遷移
		//i+1桁目がNのそれよりも小さいものに遷移させる。
		//含まれない数
		dp[i + 1][used[i] + 1] += max(0, n16[i+1] - used2[i]);
		//含まれる数
		dp[i + 1][used[i]] += used2[i];
	}
	int ans = dp[l - 1][k].x;
	//nが条件を満たしていたら足してあげる
	if (used[l - 1] == k) ++ans;
	cout << ans << endl;
	return 0;
}