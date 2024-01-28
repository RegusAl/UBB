using System.Globalization;
using Facturi.Domain;

namespace Facturi.Repository;

public class AchizitiiRepo(string file, FacturiRepo repo) : IFileRepository<string, Achizitie>
{
    private readonly List<Achizitie> _achizitii = new();
    private FacturiRepo _facturiRepo = repo;
    
    public IEnumerable<Achizitie> FindAll()
    {
        return _achizitii;
    }

    public string file { get; set; } = file;
    

    public void GetFromFile()
    {
        try
        {
            using StreamReader fromFile = new StreamReader(file);
            while (!fromFile.EndOfStream)
            {
                var line = fromFile.ReadLine();
                if (line == null) continue;
                var args = line
                    .Split(',')
                    .ToList();

                var facturi = _facturiRepo
                    .FindAll()
                    .Where(x => x.ID.Equals(args[4]))
                    .ToList();
                
                if(facturi.Count.Equals(0)) continue;

                Achizitie achizitie = new Achizitie(
                    args[1],
                    int.Parse(args[2]),
                    double.Parse(args[3].Replace('.', ',')),
                    facturi[0]
                )
                {
                    ID = args[0],
                };
                    
                facturi[0].achizitii.Add(achizitie);
                
                _achizitii.Add(achizitie);
            }
        }
        catch (IOException e)
        {
            Console.WriteLine(e.Message);
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }

    }
}