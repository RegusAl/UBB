namespace sem11.domain;

enum Dificultate { Usoara, Medie, Grea }
class Sarcina : Entity<string>
{
    public Dificultate TipDificultate { get; set; }
    public int NrOreEstimate { get; set; }
    public override string ToString()
    {
        return Id + " " + TipDificultate + " " + NrOreEstimate;
    }
}