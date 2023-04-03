//----------------------------
// ABC 296 F
// Silmultaneous Swap
// 1811
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    BIT(int n = 0) :n(n), bit(n + 1) {}
    void add(int i, T x = 1) {
        for (i++; i <= n; i += i & -i) {
            bit[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i & -i) {
            x += bit[i];
        }
        return x;
    }
};

template<class T>
class InversionNumber
{
private:
    T mx;

public:
    InversionNumber(T _mx)
    {
        mx = _mx;
    }

    vector<T> GetInversions(const vector<T>& v)
    {
        int n = v.size();
        vector<T> inversions(n);
        BIT<T> bit(mx + 10);
        // bit‚É—v‘f‚ð“ü‚ê‚Ü‚·
        for (int i = n - 1; i >= 0; i--)
        {
            inversions[i] = bit.sum(v[i] - 1);
            bit.add(v[i], 1);
        }
        return inversions;
    }
};
int main()
{
    const int N = 2e5 + 10;
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> da(N), db(N);
    rep(i, n) da[a[i]]++;
    rep(i, n) db[b[i]]++;
    rep(i, N)
    {
        if (da[i] == db[i]) continue;
        cout << "No" << endl;
        return 0;
    }
    rep(i, N)
    {
        if (da[i] < 2) continue;
        cout << "Yes" << endl;
        return 0;
    }
    InversionNumber<int> in(N);

    auto va = in.GetInversions(a);
    auto vb = in.GetInversions(b);
    int ca = 0, cb = 0;
    for (const auto& e : va) ca += e;
    for (const auto& e : vb) cb += e;
    if ((ca & 1) == (cb & 1))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}