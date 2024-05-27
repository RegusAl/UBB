using System.Data.SqlClient;

namespace Deadlock
{
    class Program
    {
        private static SqlConnection connection;
        static string conectionString = @"Server=ALBERT;Database=MagazinSportiv;
        Integrated Security=true;TrustServerCertificate=true;";

        static void Main(string[] args)
        {
            Thread thread1 = new Thread(new ThreadStart(runThread1));
            Thread thread2 = new Thread(new ThreadStart(runThread2));

            thread1.Start();
            thread2.Start();
        }

        private static void runThread1()
        {
            int nrIncercari = 0;
            while (!thr1_run())
            {
                nrIncercari++;
                if (nrIncercari > 2)
                    break;
            }
            if (nrIncercari == 2)
                Console.WriteLine("First transaction aborted");
        }

        static bool thr1_run()
        {
            bool succes = false;

            Console.WriteLine("First transaction started");
            using (SqlConnection con = new SqlConnection(conectionString))
            {
                SqlCommand command = con.CreateCommand();
                try
                {
                    con.Open();
                    command.Connection = con;
                    command.CommandText = "EXECUTE run_thread1";
                    command.ExecuteNonQuery();
                    succes = true;
                    Console.WriteLine("First transaction completed");
                }
                catch (SqlException ex)
                {
                    Console.WriteLine(ex.Message);
                    if (ex.Number == 1205)
                    {
                        Console.WriteLine("Deadlock in thread1");
                    }
                    else
                    {
                        Console.WriteLine("Error in database");
                    }
                }
            }
            return succes;
        }

        private static void runThread2()
        {
            int nrIncercari = 0;
            while (!thr2_run())
            {
                nrIncercari++;
                if (nrIncercari > 2)
                    break;
            }
            if (nrIncercari == 2)
                Console.WriteLine("Second transaction aborted");
        }

        private static bool thr2_run()
        {
            bool succes = false;

            Console.WriteLine("Second transaction started");
            using (SqlConnection con = new SqlConnection(conectionString))
            {
                SqlCommand command = con.CreateCommand();
                try
                {
                    con.Open();
                    command.Connection = con;
                    command.CommandText = "EXECUTE run_thread2";
                    command.ExecuteNonQuery();
                    succes = true;
                    Console.WriteLine("Second transaction completed");
                }
                catch (SqlException ex)
                {
                    if (ex.Number == 1205)
                    {
                        Console.WriteLine("Deadlock in thread2");
                    }
                    else
                    {
                        Console.WriteLine("Error in database");
                    }
                }
            }
            return succes;
        }
    }
}