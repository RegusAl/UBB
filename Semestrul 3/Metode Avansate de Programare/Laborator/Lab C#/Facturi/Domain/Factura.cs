namespace Facturi.Domain;

public class Factura : Document
{
    public enum Enum 
    {
        Utilities, 
        Groceries, 
        Fashion, 
        Entertainment, 
        Electronics
    }
    
    public DateTime DataScadenta { set; get; }
    public List<Achizitie> achizitii { set; get; } = [];
    public Enum Categorie { set; get; }
    
    public Factura(Document document, DateTime dataScadenta, Enum categorie)
        : base(document)
    {
        this.DataScadenta = dataScadenta;
        this.Categorie = categorie;
    }

    public override string ToString()
    {
        return $"{base.ToString()} {DataScadenta:dd.MM.yyyy} {Categorie}";
    }
}