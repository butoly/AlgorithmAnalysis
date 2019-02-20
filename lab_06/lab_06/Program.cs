using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_06
{
    class Program
    {
        static void Main(string[] args)
        {
            Conveyor third_line = new Conveyor(3, null);
            Conveyor second_line = new Conveyor(3, third_line);
            Conveyor first_line = new Conveyor(3, second_line);
        }
    }
}
