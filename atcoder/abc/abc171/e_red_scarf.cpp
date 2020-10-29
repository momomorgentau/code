//734
//abc171_e_Red scarf

/*
与えられた数字を2進数変換する。
各桁の1の数を数えて
奇数であれば、それらを反転、
偶数であれば、そのまま
これが答えとなる。
ex.)
20 : 10100
11 : 01011
9  : 01001
24 : 11000

even or odd
e o o o e

26 : 11010
5  : 00101
7  : 00111
22 : 10110
*/



#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    int mx = *max_element(x.begin(), x.end());

    vector<int> a(n);
    int d = 0;
    while (mx > 0)
    {
        bool ds = false;
        vector<bool> tx(n, 0);
        rep(i, n)
        {
            tx[i] = x[i] & (1 << d);
            ds ^= tx[i];
        }

        if (ds) rep(i, n) tx[i] = !tx[i];

        rep(i, n) a[i] += tx[i] << d;

        ++d;
        mx /= 2;
    }
    for (int i : a) cout << i << " ";
    cout << endl;
    return 0;
}
