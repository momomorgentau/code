//066
//Various_Array
//*5

using System;
using System.Collections.Generic;

namespace atcoder_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var L = new List<int>();
            var R = new List<int>();
            for (int i = 0; i < n; ++i)
            {
                string[] str = Console.ReadLine().Split(' ');
                L.Add(int.Parse(str[0]));
                R.Add(int.Parse(str[1]));
            }
            double ans = 0;
            for(int ni = 0; ni<n;++ni)
            {

                for (int i = L[ni]; i <= R[ni]; ++i)
                {
                    for (int j = ni+1; j < n; ++j)
                    {
                        double m = Math.Max(i - L[j], 0) - Math.Max(i - R[j] - 1, 0);
                        ans += m / (double)(R[j] - L[j] + 1) / (double)(R[ni]-L[ni]+1);
                    }
                }
            }


            Console.WriteLine(ans);
        }
    }
}

