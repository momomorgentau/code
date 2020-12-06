//655
//arc110_b_many_110

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int init1 = 0;
    int end1 = 0;
    ll p = pow(10, 10);
    if (s[0] == '0' && n == 1)
    {
        cout << p << endl;
        return 0;
    }
    if (s[0] == '1' && n == 1)
    {
        cout << 2 * p << endl;
        return 0;

    }
    if (s[0] == '0' && s[1] == '1' && n == 2)
    {
        cout << p - 1 << endl;
        return 0;

    }
    if (s[0] == '1' && s[1] == '0' && n == 2)
    {
        cout << p << endl;
        return 0;

    }
    if (s[0] == '1' && s[1] == '1' && n == 2)
    {
        cout << p << endl;
        return 0;
    }
    if (s[0] == '0' && s[1] == '0' && n == 2)
    {
        cout << 0 << endl;
        return 0;
    }

    if (s[0] == '1' && s[1] == '1' && s[2] == '0')
    {
        init1 = 0;
        end1 = 0 + n;
    }
    else if (s[0] == '1' && s[1] == '0' && s[2] == '1')
    {
        init1 = 1;
        end1 = 1 + n;

    }
    else if (s[0] == '0' && s[1] == '1' && s[2] == '1')
    {
        init1 = 2;
        end1 = 2 + n;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }
    //ƒ‹[ƒv‚Å‚«‚Ä‚¢‚é‚©”»’è
    rep(i, n)
    {
        int num = i + init1;
        char c;
        if (num % 3 == 2) c = '0';
        else c = '1';
        if (s[i] != c)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    ll X = 3 * p;
    ll ans = X - init1 - n;
    ans = ans / 3 + 1;
    cout << ans << endl;


    return 0;
}