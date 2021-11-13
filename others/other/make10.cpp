//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

//map<vector<int>, string> memo;

map<string, vector<string>> answer;

typedef class frac
{
public:

    frac()
    {
        _den = 0;
        _num = 1;
    };

    frac(int a, int b)
    {
        set(a, b);
    }


    int getden()
    {
        return this->_den;
    }

    int getnum()
    {
        return this->_num;
    }

    void set(int a, int b)
    {
        _den = a;
        _num = b;
        if (_num == 0)
        {
            cout << "�����0�ɂł��܂���" << endl;
        }
        reduction();
    }

    frac operator+(frac obj)
    {
        frac res = *this;
        res._den = res._den * obj._num + obj._den * res._num;
        res._num *= obj._num;
        return reduction(res);
    }
    frac operator-(frac obj)
    {
        frac res = *this;
        res._den = res._den * obj._num - obj._den * res._num;
        res._num *= obj._num;
        return reduction(res);
    }
    frac operator*(frac obj) {
        frac res = *this;
        res._den *= obj._den;
        res._num *= obj._num;
        return reduction(res);
    }
    frac operator/(frac obj) {
        if (obj._den == 0)
        {
            cout << "0���Z���������܂���" << endl;
        }

        frac res = *this;
        res._den *= obj._num;
        res._num *= obj._den;
        return reduction(res);
    }


private:

    int _den; //���q
    int _num; //����

    frac reduction(frac obj)
    {
        obj.reduction();
        return obj;
    }

    //�������g��񕪂���
    void reduction()
    {
        int g = gcd(this->_den, this->_num);
        if (g != 1)
        {
            this->_den /= g;
            this->_num /= g;
        }
        if (this->_num < 0)
        {
            this->_den *= -1;
            this->_num *= -1;
        }
    }
};
void dfs(vector<frac> v, string tmp, string q)
{
    int cnt = v.size();
    if (cnt == 1)
    {
        if (v[0].getden() == 10 && v[0].getnum() == 1)
        {
            answer[q].emplace_back(tmp);
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
                if (f2.getden() != 0)
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

        dfs(add, tmp + " + " + to_string(index) + " " + to_string(index + 1), q);
        dfs(sub, tmp + " - " + to_string(index) + " " + to_string(index + 1), q);
        dfs(mul, tmp + " * " + to_string(index) + " " + to_string(index + 1), q);
        if (div.size() == mul.size())
        {
            dfs(div, tmp + " / " + to_string(index) + " " + to_string(index + 1), q);
        }
    }
}

int main()
{
    bool _isPrm = true;

    while (1)
    {
        cout << "���s���iyes:1,no:0�j : ";
        int input_prm; cin >> input_prm;
        if (input_prm == 0)
        {
            _isPrm = true;
            break;
        }
        else if (input_prm == 1)
        {
            _isPrm = false;
            break;
        }
        else
        {
            cout << "�s���Ȓl�ł��B" << endl;
        }
    }

    int d = 0;
    while (1)
    {
        cout << "�v�Z���鐔���̌�����͂��Ă�������" << endl;
        cout << "�i���s���F5�A�����F7�܂ł͌v�Z�ł��܂��j�F  ";
        cin >> d;
        if (1 <= d)
        {
            break;
        }
        else
        {
            cout << "�s���ȓ��͂ł�" << endl;
        }
    }
    vector<frac> inputs(d);

    while (1)
    {
        cout << "0�`9�܂ł̐�������͂��Ă������� : ";
        vector<int> digits(d);
        for (auto& e : digits) cin >> e;
        if (*max_element(digits.begin(), digits.end()) <= 9 && *min_element(digits.begin(), digits.end()) >= 0)
        {
            for (int idx = 0; idx < d; ++idx)
            {
                inputs[idx].set(digits[idx], 1);
            }
            break;
        }
        else
        {
            cout << "�s���ȓ��͂ł��B������x���͂��Ă�������" << endl;
        }
    }

    if (_isPrm)
    {
        string q = "";
        for (auto e : inputs)
        {
            q += to_string(e.getden()) + " ";
        }
        dfs(inputs, "", q);
    }
    else
    {
        vector<int> prm;
        for (int idx = 0; idx < d; ++idx) prm.emplace_back(idx);
        map<string, int> used;
        do
        {
            string q = "";
            vector<frac> tmp_inputs;
            for (auto const& e : prm)
            {
                q += to_string(inputs[e].getden()) + " ";
                tmp_inputs.emplace_back(inputs[e]);
            }
            if (used[q] == -1)
            {
                continue;
            }
            used[q] = -1;
            dfs(tmp_inputs, "", q);
        } while (next_permutation(prm.begin(), prm.end()));
    }




    cout << "----------------------" << endl;
    if (answer.empty())
    {
        cout << "���͂���܂���" << endl;
    }
    else
    {
        for (auto const& q : answer)
        {
            cout << q.first << endl;
            cout << endl;
            for (auto const& a : q.second)
            {
                cout << "    " << a << endl;

            }
            cout << endl;
        }
    }
    cout << "----------------------" << endl;

    cout << endl;
    cout << "�v�Z���@" << endl;
    cout << "�����猩�Ă����u+ 0 1�v�Ȃ� �u0�Ԗ� + 1�Ԗځv�����č��ɋl�߂܂�" << endl;
    cout << "��G�u1 2 3 4�v�u+ 1 2 + 0 1 + 0 1�v" << endl;
    cout << "�@�@�� {[1+(2+3)]+4}" << endl;


    return 0;
}