namespace sem11.domain;

enum KnowledgeLevel
{
    Junior=1, Medium, Senior
}
class Angajat : Entity<string> , ICloneable
{
    public String Nume { get; set; }
    public double VenitPeOra { get; set; }
    public KnowledgeLevel Nivel { get; set; }

    public object Clone()
    {
        throw new NotImplementedException();
    }

    public override string ToString()
    {
        return Id+" "+Nume+" "+VenitPeOra+" "+Nivel;
    }
}