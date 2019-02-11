using System;
using System.Diagnostics;

namespace lab_05
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Введите размерность матриц");
            Console.WriteLine("Количество строк в первой матрице: ");
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Количество столбцов в первой матрице: ");
            int m = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Количество столбцов во второй матрице: ");
            int l = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Введите количество потоков: ");
            int thread_amount = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Результат работы алгоритмов на потоках");
            Threading threading = new Threading(n, m, l);
            threading.Print_mtr1();
            threading.Print_mtr2();

            threading.Thread_mult(thread_amount);
            threading.Print_res();

            threading.Dump_res();

            threading.Thread_vinograd(thread_amount);
            threading.Print_res();

            Console.WriteLine("Результат работы алгоритмов на основном потоке");
            Mult mult_alg = new Mult(n, m, l);
            mult_alg.Print_mtr1();
            mult_alg.Print_mtr2();

            mult_alg.Standart_alg();
            mult_alg.Print_res();

            mult_alg.Dump_res();

            mult_alg.Standart_vinograd_mult();
            mult_alg.Print_res();

            /*Console.WriteLine("Провести замер времени?(y/n)");
            if (Convert.ToChar(Console.ReadLine()) == 'y')
            {
                Console.WriteLine("Стандартный алгоритм на потоках");
                for (int j = 1; j < Environment.ProcessorCount * 4 + 1; j += 1)
                {
                    int i = 1001;
                    Threading thread_mult = new Threading(i, i, i);

                    var start = Process.GetCurrentProcess().UserProcessorTime;
                    thread_mult.Thread_mult(j);
                    var finish = Process.GetCurrentProcess().UserProcessorTime;

                    var mult_time = (finish - start).Ticks;

                    Console.Write("," + mult_time.ToString());
                }
                Console.WriteLine();
                Console.WriteLine("Алгоритм Винограда на потоках");
                for (int j = 1; j < Environment.ProcessorCount * 4 + 1; j += 1)
                {
                    int i = 1001;

                    Threading thread_mult = new Threading(i, i, i);
                    var start = Process.GetCurrentProcess().UserProcessorTime;
                    thread_mult.Thread_vinograd(j);
                    var finish = Process.GetCurrentProcess().UserProcessorTime;

                    var mult_time = (finish - start).Ticks;

                    Console.Write("," + mult_time.ToString());
                }
                Console.WriteLine();
                Console.WriteLine("Все алгоритмы на потоках (Стандартный, Виноград, Стандартный и Виноград на потоках)");
                for (int i = 101; i < 1012; i += 100)
                {
                    Threading thread_mult = new Threading(i, i, i);
                    Mult mult = new Mult(i, i, i);
                    Console.Write(i.ToString());

                    var start = Process.GetCurrentProcess().UserProcessorTime;
                    mult.Standart_alg();
                    var finish = Process.GetCurrentProcess().UserProcessorTime;

                    var mult_time = (finish - start).Ticks;

                    mult.Fill_mtr();

                    start = Process.GetCurrentProcess().UserProcessorTime;
                    mult.Standart_vinograd_mult();
                    finish = Process.GetCurrentProcess().UserProcessorTime;

                    var vinograd_time = (finish - start).Ticks;

                    mult.Fill_mtr();

                    Console.Write("," + mult_time.ToString() + "," + vinograd_time.ToString());

                    for (int j = 1; j < Environment.ProcessorCount * 4 + 1; j *= 2)
                    {
                        start = Process.GetCurrentProcess().UserProcessorTime;
                        thread_mult.Thread_mult(j);
                        finish = Process.GetCurrentProcess().UserProcessorTime;

                        mult_time = (finish - start).Ticks;

                        mult.Fill_mtr();

                        start = Process.GetCurrentProcess().UserProcessorTime;
                        thread_mult.Thread_vinograd(j);
                        finish = Process.GetCurrentProcess().UserProcessorTime;

                        vinograd_time = (finish - start).Ticks;

                        mult.Fill_mtr();

                        Console.Write("," + mult_time.ToString() + "," + vinograd_time.ToString());
                    }
                    Console.WriteLine();
                }
            }*/
        }
    }
}
