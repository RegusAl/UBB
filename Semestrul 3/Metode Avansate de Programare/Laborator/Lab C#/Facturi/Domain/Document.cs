namespace Facturi.Domain;

public class Document : Entity<string>
{
    public string Nume { set; get; }
    public DateTime DataEmitere { set; get; }
    
    public Document(Document document)
    {
        this.ID = document.ID;
        this.Nume = document.Nume;
        this.DataEmitere = document.DataEmitere;
    }
    
    public Document(string id, string nume, DateTime dataEmitere)
    {
        this.ID = id;
        this.Nume = nume;
        this.DataEmitere = dataEmitere;
    }

    protected Document(string nume, DateTime dataEmitere)
    {
        this.Nume = nume;
        this.DataEmitere = dataEmitere;
    }

    public override string ToString()
    {
        return $"{base.ToString()} {Nume} {DataEmitere:dd.MM.yyyy}";
    }
}