//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

//map<vector<int>, string> memo;

vector<string> answer;

typedef class frac
{
public:
    int den;
    int num;
    frac()
    {
        den = 0;
        num = 1;
    };
    frac(int a, int b)
    {
        den = a;
        num = b;
    }
    frac operator+(frac obj)
    {
        frac res = *this;
        res.den = res.den * obj.num + obj.den * res.num;
        res.num *= obj.num;
        return make_gcd(res);
    }
    frac operator-(frac obj)
    {
        frac res = *this;
        res.den = res.den * obj.num - obj.den * res.num;
        res.num *= obj.num;
        return make_gcd(res);
    }
    frac operator*(frac obj) {
        frac res = *this;
        res.den *= obj.den;
        res.num *= obj.num;
        return make_gcd(res);
    }
    frac operator/(frac obj) {
        if (obj.den == 0)
        {
            cout << "0除算が発生しました" << endl;
        }

        frac res = *this;
        res.den *= obj.num;
        res.num *= obj.den;
        return make_gcd(res);
    }

    frac make_gcd(frac obj)
    {
        int g = gcd(obj.den, obj.num);
        if (g != 1)
        {
            obj.den /= g;
            obj.num /= g;
        }
        return obj;
    }
};
void dfs(vector<frac> v, string tmp)
{
    int cnt = v.size();
    if (cnt == 1)
    {
        if (v[0].den == 10 && v[0].num == 1)
        {
            answer.emplace_back(tmp);
        }
        return;
    }

    for (int index = 0; index < cnt - 1; ++index)
    {

        frac f1 = v[index];
        frac f2 = v[index + 1];

        vector<frac> add, sub, mul, div;

        for (int idx = 0; idx < cnt; ++idx)
        {
            if (idx == index)
            {
                add.emplace_back(f1 + f2);
                sub.emplace_back(f1 - f2);
                mul.emplace_back(f1 * f2);
                if (f2.den != 0)
                {
                    div.emplace_back(f1 / f2);
                }
            }
            else if (idx != index + 1)
            {
                add.emplace_back(v[idx]);
                sub.emplace_back(v[idx]);
                mul.emplace_back(v[idx]);
                div.emplace_back(v[idx]);
            }
        }

        dfs(add, tmp + " + " + to_string(index) + " " + to_string(index + 1));
        dfs(sub, tmp + " - " + to_string(index) + " " + to_string(index + 1));
        dfs(mul, tmp + " * " + to_string(index) + " " + to_string(index + 1));
        if (div.size() == mul.size())
        {
            dfs(div, tmp + " / " + to_string(index) + " " + to_string(index + 1));
        }
    }
}

int main()
{
    cout << gcd(-1, -10) << endl;
    return -1;
    int d = 0;
    while (1)
    {
        cout << "計算する数字の個数を入力してください" << endl;
        cout << "（7まではギリギリ計算できます）：  ";
        cin >> d;
        if (1 <= d)
        {
            break;
        }
        else
        {
            cout << "不正な入力です" << endl;
        }
    }
    vector<frac> input(d);

    while (1)
    {
        cout << "0～9までの整数を入力してください : ";
        for (auto& e : input) cin >> e.den;
        for (auto& e : input) e.num = 1;

        bool ok = true;
        for (auto const& e : input)
        {
            if (e.den < 0 || 9 < e.den)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            break;
        }
        else
        {
            cout << "不正な入力です。もう一度入力してください" << endl;
        }
    }

    dfs(input, "");

    cout << "----------------------" << endl;
    if (answer.empty())
    {
        cout << "解はありません" << endl;
    }
    else
    {
        for (auto const& a : answer)
        {
            cout << a << endl;
        }
    }
    cout << "----------------------" << endl;

    cout << endl;
    cout << "計算方法" << endl;
    cout << "左から見ていき「+ 0 1」なら 「0番目 + 1番目」をして左に詰めます" << endl;
    cout << "例；「1 2 3 4」「+ 1 2 + 0 1 + 0 1」" << endl;
    cout << "　　→ {[1+(2+3)]+4}" << endl;

    return 0;
}