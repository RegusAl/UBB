using Facturi.Domain;

namespace Facturi.Repository;

public class DocumenteRepo(string file) : IFileRepository<string, Document>
{
    private readonly List<Document> _documents = new();
    
    public IEnumerable<Document> FindAll()
    {
        return _documents;
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
                
                var args = line.Split(',').ToList();
                
                if (args.Count >= 3 && DateTime.TryParse(args[2], out var date))
                {
                    _documents.Add(new Document(args[0], args[1], date));
                }
                else
                {
                    Console.WriteLine("Invalid data format: " + line);
                }
            }
        }
        catch (IOException e)
        {
            Console.WriteLine(e.Message);
        }

    }
}