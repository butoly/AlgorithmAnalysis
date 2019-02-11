using System;
using System.Threading;
using System.Collections.Concurrent;

namespace lab_05
{
    public class Threading
    {
        int[,] mtr1, mtr2, result;
        int n, m, l;

        public Threading(int n, int m, int l)
        {
            this.n = n;
            this.m = m;
            this.l = l;
            mtr1 = new int[n, m];
            mtr2 = new int[m, l];
            result = new int[n, l];

            Fill_mtr();
        }

        public void Print_res()
        {
            Console.WriteLine("Произведение матриц");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    Console.Write(result[i, j]);
                    Console.Write(' ');
                }
                Console.WriteLine();
            }
        }

        public void Print_mtr1()
        {
            Console.WriteLine("Матрица 1");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    Console.Write(mtr1[i, j]);
                    Console.Write(' ');
                }
                Console.WriteLine();
            }
        }

        public void Print_mtr2()
        {
            Console.WriteLine("Матрица 2");
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    Console.Write(mtr2[i, j]);
                    Console.Write(' ');
                }
                Console.WriteLine();
            }
        }

        public void Dump_res()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < l; j++)
                    result[i, j] = 0;
            }
        }

        void Fill_mtr()
        {
            Random rnd = new Random();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    mtr1[i, j] = rnd.Next(0, 9);

            for (int i = 0; i < m; i++)
                for (int j = 0; j < l; j++)
                    mtr2[i, j] = rnd.Next(0, 9);
        }

        public void Thread_mult(int thread_am)
        {
            int partition = n / thread_am; //  3=6/2
            int start = 0, finish = partition + (n - partition * thread_am);//  3 = 3 + (6 - 3 * 2)
            if (thread_am > n)
            {
                partition = 1;
                finish = 1;
            }
            int count;

            ConcurrentBag<Thread> thread_list = new ConcurrentBag<Thread>();
            ConcurrentBag<Mult> mul_list = new ConcurrentBag<Mult>();

            for (int k = 0; k < thread_am; k++)
            {
                Mult mult = new Mult(n, m, l, mtr1, mtr2);
                mult.Set_bounds(start, finish);
                Thread thread = new Thread(mult.Multiply);
                thread.Start();
                thread_list.Add(thread);
                mul_list.Add(mult);

                count = thread_list.Count;

                for (int i = 0; i < count; i++)
                {
                    thread_list.TryTake(out Thread curr);
                    curr.Join();
                }

                count = mul_list.Count;

                for (int i = 0; i < count; i++)
                {
                    mul_list.TryTake(out Mult mul);
                    mul.Copy(ref result);
                }

                start = finish;
                finish += partition;
                if (finish > n)
                    finish = n;
            }
        }

        public void Thread_vinograd(int thread_am)
        {
            int[] row_fact, col_fact;
            int coef = m / 2;
            int partition = n / thread_am;
            int start = 0, finish = partition + (n - partition * thread_am);
            if (thread_am > n)
            {
                partition = 1;
                finish = partition;
            }

            int count;
            row_fact = new int[n];
            col_fact = new int[l];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < coef; j++)
                    row_fact[i] += mtr1[i, 2 * j + 1] * mtr1[i, 2 * j];
            }

            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < coef; j++)
                    col_fact[i] = col_fact[i] + mtr2[2 * j + 1, i] * mtr2[2 * j, i];
            }

            ConcurrentBag<Thread> thread_list = new ConcurrentBag<Thread>();
            ConcurrentBag<Mult> mul_list = new ConcurrentBag<Mult>();
            for (int k = 0; k < thread_am; k++)
            {
                Mult mult = new Mult(n, m, l, mtr1, mtr2, coef, row_fact, col_fact);
                mult.Set_bounds(start, finish);
                Thread thread = new Thread(mult.Vinograd_mult);
                thread.Start();
                thread_list.Add(thread);
                mul_list.Add(mult);

                count = thread_list.Count;

                for (int i = 0; i < count; i++)
                {
                    thread_list.TryTake(out Thread curr);
                    curr.Join();
                }

                count = mul_list.Count;

                for (int i = 0; i < count; i++)
                {
                    mul_list.TryTake(out Mult mul);
                    mul.Copy(ref result);
                }

                start = finish;
                finish += partition;
                if (finish > n)
                    finish = n;
            }

            if (m % 2 != 0)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < l; j++)
                    {
                        result[i, j] += mtr1[i, m - 1] * mtr2[m - 1, j];
                    }
                }
            }
        }
    }
}
