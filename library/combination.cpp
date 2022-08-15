template<class T>
class Comb
{
private:
    vector<T> v;
public:
    // 0indexed
    T aCbCalc(int a, int b)
    {
        if (b > a)
        {
            cout << "error" << endl;
        }
        b = min({ b, a - b, 0 });
        T res = 1;
        for (int i = 0; i < b; ++i)
        {
            res *= a - i;
            res /= i + 1;
        }
        return res;
    }

    // mintの場合を想定してテーブルを事前に用意します
    T aCb(int a, int b)
    {
        return v[a] / v[b] / v[a - b];
    }
    //***********************
    // a - 種類数
    // b - 総数
    //***********************
    T aHb(int a, int b)
    {
        if (a <= 0)
        {
            cout << "error" << endl;
        }
        return v[a - 1 + b] / v[a - 1] / v[b];
    }

    void Set(int n)
    {
        v.resize(n + 1);
        v[0] = 1;
        for (int i = 1; i < n + 1; ++i)
        {
            v[i] = (T)i * v[i - 1];
        }
    }

};