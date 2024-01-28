using Facturi.Service;
using Facturi.Domain;

namespace Facturi.UI;

public class Ui(Service.Service service)
{
    private void All()
    {
        Console.WriteLine("\nDocumente: ");

        service
            .FindDocumente()
            .ForEach(Console.WriteLine);
        
        Console.WriteLine("\nFacturi:");
        
        service
            .FindFacturi()
            .ForEach(Console.WriteLine);
        
        Console.WriteLine("\nAchizitii:");
        
        service
            .FindAchizitii()
            .ForEach(Console.WriteLine);
    }

    private bool ParseCommand(string line)
    {
        switch (line)
        {
            case "0":
                All();
                break;
            
            case "1":
                Console.WriteLine("\t\t Documente emise in 2023 \t\t");
                service.DocumenteEmise2023()
                    .ForEach(document => Console.WriteLine(document.Nume + " " + document.DataEmitere));
                break;
            
            case "2":
                Console.WriteLine($"\t\t Facturi scadente in luna {DateTime.Now.Month} si anul {DateTime.Now.Year}\t\t");
                service.FacturiScadenteLunaCurenta()
                    .ForEach(factura => Console.WriteLine(factura.Nume + " " + factura.DataScadenta));
                break;
            
            case "3":
                Console.WriteLine("\t\t Facturi cu trei achizitii");
                service.FacturiCu3Achizitii()
                    .ForEach(factura => Console.WriteLine(factura.Nume + " " + service.NrProduse(factura)));
                break;
            
            case "4":
                Console.WriteLine("\t\tAchizitiile din categoria Utilities");
                service.AchizitiiUtilities()
                    .ForEach(achizitie => Console.WriteLine(achizitie.produs + " " + achizitie.factura.Nume));
                break;
            
            case "5":
                Console.WriteLine("\t\tCategoria cu cheltuiala maxima");
                Console.WriteLine($"\t{service.CategoriaCuCheltuialaMaxima()} ");
                break;
            
            default:
                return true;
        }

        return false;
    }

    private void Meniu()
    {
        Console.WriteLine("\n\t\t Meniu \t\t");
        Console.WriteLine(" 0. Afisare tot");
        Console.WriteLine(" 1. Documente emise in 2023");
        Console.WriteLine(" 2. Facturile scadente in luna curenta");
        Console.WriteLine(" 3. Facturile cu cel putin 3 produse acizitionate");
        Console.WriteLine(" 4. Achizitiile din categoria 'Utilities'");
        Console.WriteLine(" 5. Categoria de facturi care a inregistrat cele mai multe cheltuieli");
    }

    public void Main()
    {
        while (true)
        {
            Meniu();
            Console.WriteLine("\nAlegeti comanda: ");
            if (ParseCommand(Console.ReadLine())) 
                return;
        }

    }

}