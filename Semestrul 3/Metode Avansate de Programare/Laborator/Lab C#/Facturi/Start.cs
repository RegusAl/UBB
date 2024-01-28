using Facturi.Repository;
using Facturi.Service;
using Facturi.UI;

public class Start
{
    public static void Main()
    {
        var documenteRepo = new DocumenteRepo(
            "/home/albert/Documents/UBB/Semestrul 3/Metode Avansate de Programare/Laborator/Lab C#/Facturi/Data/documente.txt");
        
        var facturiRepo = new FacturiRepo(
            "/home/albert/Documents/UBB/Semestrul 3/Metode Avansate de Programare/Laborator/Lab C#/Facturi/Data/facturi.txt", 
            documenteRepo);
        
        var achizitiiRepo = new AchizitiiRepo(
            "/home/albert/Documents/UBB/Semestrul 3/Metode Avansate de Programare/Laborator/Lab C#/Facturi/Data/achizitii.txt", 
            facturiRepo);

        documenteRepo.GetFromFile();
        facturiRepo.GetFromFile();
        achizitiiRepo.GetFromFile();

        Service service = new Service(
            documenteRepo, 
            facturiRepo, 
            achizitiiRepo);
        Ui ui = new Ui(service);
        ui.Main();

    }   
}