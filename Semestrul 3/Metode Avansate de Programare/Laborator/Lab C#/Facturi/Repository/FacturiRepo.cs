using Facturi.Domain;

namespace Facturi.Repository;

public class FacturiRepo(string file, DocumenteRepo fileRepository) : IFileRepository<string, Factura>
{
    private readonly List<Factura> _facturi = new();
    private DocumenteRepo _documenteRepo = fileRepository;
    

    public IEnumerable<Factura> FindAll()
    {
        return _facturi;
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

                var document = _documenteRepo
                    .FindAll()
                    .Where(x => x.ID.Equals(args[0]))
                    .ToList();
                if(document.Count.Equals(0)) continue;
                
                _facturi.Add(new Factura(
                    document[0],
                    DateTime.Parse(args[1]),
                    Enum.Parse<Factura.Enum>(args[2])
                    )
                {
                    ID = args[0]
                });
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