using System;
namespace lab_05
{
    public class Mult
    {
        int[,] mtr1, mtr2;
        int[,] result;
        int n, m, l;
        int start, finish;
        int[] row_fact, col_fact;
        int coef;
        public Mult(int n, int m, int l)
        {
            this.n = n;
            this.m = m;
            this.l = l;
            mtr1 = new int[n, m];
            mtr2 = new int[m, l];
            row_fact = new int[n];
            col_fact = new int[l];
            result = new int[n, l];
            coef = m / 2;
            result = new int[n, l];

            Fill_mtr();
        }
        public Mult(int n, int m, int l, int[,] mtr1, int[,] mtr2)
        {
            this.n = n;
            this.m = m;
            this.l = l;
            this.mtr1 = mtr1;
            this.mtr2 = mtr2;
            result = new int[n, l];
        }

        public Mult(int n, int m, int l, int[,] mtr1, int[,] mtr2, int coef, int[] row_fact, int[] col_fact)
        {
            this.n = n;
            this.m = m;
            this.l = l;
            this.mtr1 = mtr1;
            this.mtr2 = mtr2;
            this.row_fact = row_fact;
            this.col_fact = col_fact;
            result = new int[n, l];
            this.coef = coef;
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

        public void Fill_mtr()
        {
            Random rnd = new Random();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    mtr1[i, j] = rnd.Next(0, 9);

            for (int i = 0; i < m; i++)
                for (int j = 0; j < l; j++)
                    mtr2[i, j] = rnd.Next(0, 9);
        }

        public void Fill_factors()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < coef; j++)
                    row_fact[i] += mtr1[i, 2 * j + 1] * mtr1[i, 2 * j];
            }

            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < coef; j++)
                    col_fact[i] += mtr2[2 * j + 1, i] * mtr2[2 * j, i];
            }
        }

        public void Multiply()
        {
            for (int i = start; i < finish; i++)
                for (int j = 0; j < l; j++)
                {
                    result[i, j] = 0;
                    for (int k = 0; k < m; k++)
                        result[i, j] += mtr1[i, k] * mtr2[k, j];
                }
        }

        public void Standart_alg()
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < l; j++)
                {
                    result[i, j] = 0;
                    for (int k = 0; k < m; k++)
                        result[i, j] += mtr1[i, k] * mtr2[k, j];
                }
        }

        public void Vinograd_mult()
        {
            for (int i = start; i < finish; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    result[i, j] = -row_fact[i] - col_fact[j];
                    for (int r = 0; r < coef; r++)
                    {
                        result[i, j] = result[i, j] + (mtr1[i, 2 * r] + mtr2[2 * r + 1, j]) * (mtr1[i, 2 * r + 1] + mtr2[2 * r, j]);
                    }
                }
            }
        }

        public void Standart_vinograd_mult()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < coef; j++)
                    row_fact[i] += mtr1[i, 2 * j + 1] * mtr1[i, 2 * j];
            }

            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < coef; j++)
                    col_fact[i] += mtr2[2 * j + 1, i] * mtr2[2 * j, i];
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    result[i, j] = -row_fact[i] - col_fact[j];
                    for (int r = 0; r < coef; r++)
                    {
                        result[i, j] = result[i, j] + (mtr1[i, 2 * r] + mtr2[2 * r + 1, j]) * (mtr1[i, 2 * r + 1] + mtr2[2 * r, j]);
                    }
                }
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

        public void Set_bounds(int start, int finish)
        {
            this.start = start;
            this.finish = finish;
        }

        public void Copy(ref int[,] res)
        {
            for (int i = start; i < finish; i++)
                for (int j = 0; j < l; j++)
                    res[i, j] = result[i, j];
        }

        public void Dump_res()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < l; j++)
                    result[i, j] = 0;
            }
        }

    }
}
