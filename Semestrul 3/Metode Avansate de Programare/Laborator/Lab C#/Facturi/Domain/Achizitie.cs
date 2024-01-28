namespace Facturi.Domain;

public class Achizitie : Entity<string>
{
    public string produs { set; get; }
    public int cantitate { set; get; }
    public double pretProdus { set; get; }
    public Factura factura { set; get; }

    public Achizitie(string produs, int cantitate, double pretProdus, Factura factura)
    {
        this.produs = produs;
        this.cantitate = cantitate;
        this.pretProdus = pretProdus;
        this.factura = factura;
    }

    public override string ToString()
    {
        return $"{base.ToString()} {produs} {cantitate} {pretProdus} {factura}";
    }
}