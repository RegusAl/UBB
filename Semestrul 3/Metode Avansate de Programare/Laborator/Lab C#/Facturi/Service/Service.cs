using Facturi.Domain;
using Facturi.Repository;

namespace Facturi.Service;

public class Service(
    IRepository<string, Document> documentsRepository, 
    IRepository<string, Factura> facturiRepository, 
    IRepository<string, Achizitie> achizitiiRepository)
{
    public List<Document> DocumenteEmise2023()
    {
        return documentsRepository
            .FindAll()
            .Where(x => x.DataEmitere.Year.Equals(2023))
            .ToList();
    }
    
    public List<Factura> FacturiScadenteLunaCurenta()
    {
        return facturiRepository
            .FindAll()
            .Where(x => x.DataScadenta.Month.Equals(DateTime.Now.Month))
            .ToList();
    }
    
    public List<Factura> FacturiCu3Achizitii()
    {
        return facturiRepository
            .FindAll()
            .Where(x => x.achizitii.ConvertAll(achizitie => achizitie.cantitate).Sum() >= 3)
            .ToList();
    }
    
    public int NrProduse(Factura factura)
    {
        return factura
            .achizitii
            .ConvertAll(achizitie => achizitie.cantitate)
            .Sum();
    }
    
    public List<Achizitie> AchizitiiUtilities()
    {
        return achizitiiRepository
            .FindAll()
            .Where(x => x.factura.Categorie.Equals(Factura.Enum.Utilities))
            .ToList();
    }
    
    public Factura.Enum CategoriaCuCheltuialaMaxima()
    {
        return facturiRepository
            .FindAll()
            .ToList()
            .MaxBy(x =>
                x.achizitii
                    .ConvertAll(achizitie =>
                        achizitie.cantitate * achizitie.pretProdus)
                    .Sum())!
            .Categorie;
    }
    
    public List<Document> FindDocumente()
    {
        return documentsRepository
            .FindAll()
            .ToList();
    }
    
    public List<Factura> FindFacturi()
    {
        return facturiRepository
            .FindAll()
            .ToList();
    }
    
    public List<Achizitie> FindAchizitii()
    {
        return achizitiiRepository
            .FindAll()
            .ToList();
    }
} 