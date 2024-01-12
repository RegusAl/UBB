namespace sem11.domain;

class EntityToFileMapping
{
    public static Angajat CreateAngajat(string line)
    {
        string[] fields = line.Split(','); // new char[] { ',' } 
        Angajat angajat = new Angajat()
        {

            Id = fields[0],
            Nume = fields[1],
            VenitPeOra = Double.Parse(fields[2]),
            Nivel = (KnowledgeLevel)Enum.Parse(typeof(KnowledgeLevel), fields[3])
        };
        return angajat;
    }



    public static Sarcina CreateSarcina(string line)
    {
        string[] fields = line.Split(','); // new char[] { ',' } 
        Sarcina sarcina = new Sarcina()
        {

            Id = fields[0],
            TipDificultate = (Dificultate)Enum.Parse(typeof(Dificultate), fields[1]),
            NrOreEstimate = Int32.Parse(fields[2])
        };
        return sarcina;
    }
}