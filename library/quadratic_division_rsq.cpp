// ��������RangeSumQuery
template<class T>
class QuadraticDivisionRSQ
{
private:
	T k;
	T q;
	vector<T> a;
	vector<T> b;

public:
	QuadraticDivisionRSQ(T n)
	{
		k = std::sqrt(n); // 1�u���b�N�̗v�f��
		q = (n + k - 1) / k; // ������
		a.resize(n);
		b.resize(q);
	}


	void add(T x, T y)
	{
		a[x] += y;;
		b[x / k] += y;
	}

	T sum(T x, T y)
	{
		T s = 0;
		// [x, y)
		for (; x < y && x % k; s += a[x++]);
		for (; x < y && y % k; s += a[--y]);
		for (; x < y; s += b[(y -= k) / k]);
		return s;
	}
};