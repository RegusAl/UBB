namespace sem11.domain;

class PontajDTO
{
    public String NumeAngajat { get; set; }
    public Double Salar { get; set; }

    public KnowledgeLevel Nivel { get; set; }

    public override string ToString()
    {
        return $"{NumeAngajat} {Salar} {Nivel.ToString()}"; // incepand cu C#6
    }
}