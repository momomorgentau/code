//BITとセットで使用します
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
        BIT<T> bit(mx+10);
        // bitに要素を入れます
        for (int i = n-1; i >= 0; i--)
        {
            inversions[i] = bit.sum(v[i]-1);
            bit.add(v[i], 1);
        }
        return inversions;
    }
};
