namespace Facturi.Domain;

public class Entity<TypeID>
{
    public TypeID ID { get; set; }

    public override string ToString()
    {
        return $"{ID}";
    }
}