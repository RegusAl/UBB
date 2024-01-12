// See https://aka.ms/new-console-template for more information

using System.Threading.Channels;
using sem11.domain;
using sem11.domain.validators;
using sem11.repository;
using sem11.service;

//List<int> l = new List<int>() { 1,2,3,4,5,6,7,8,9,10};          
//var res=l.Where(x => x % 2 == 0);
//res.ToList().ForEach(Console.WriteLine);


// 0. afisati doar angajatii care au nivelul junior - extension methods "Where"
//var newList = list.Where(x => x.Nivel == KnowledgeLevel.Junior);
//newList.ToList().ForEach(Console.WriteLine);


Console.WriteLine("Cerinta 1..............");
//1 - cerinta 1 din pdf sem11 - 12  sql like
Task1();

Console.WriteLine("Cerinta 2..............");
//2 cate ore dureaza in medie fiecare tip de sarcina
Task2();

Console.WriteLine("Cerinta 3..............");
//3 primii doi cei mai harnici angajati
//Task3();


Console.WriteLine("Cerinta 4..............");
//Task4();
//TaskCurs();


static void TaskCurs()
{
    //1. Determinati cuvintele dintr-un text care sunt scrise cu litere mari. (String.Equals)
    String text = "ACESTA Este UN Text MARE";
    Console.WriteLine("Cerinta extensions methods -------------------");
    //text.Split(" ")
    //    .ToList()
    //    .Where(x => x.ToUpper().Equals(x))
    //    .ToList()
    //    .ForEach(x => Console.WriteLine(x));

    //Console.WriteLine("Cerinta 1 sql like sintax-------------------");
    //var res = from c in text.Split(" ")
    //          where c.ToUpper().Equals(c)
    //          select c;
    //res.ToList().ForEach(x => Console.WriteLine(x));

    Console.WriteLine("Cerinta 2-------------------");
    //2.Afisati numerele si frecventele lor de apartitie dintr - un sir de numere.
    int[] numbers = { 1, 2, 3, 5, 2, 1, 2, 3, 6, 2, 2, 4, 1, 2, 1, 4, 6, 2, 4, 1, 2, 5, 7 };
    //numbers.ToList()
    //    .GroupBy(x => x)
    //    .Select(x =>
    //    {
    //        return new { value = x.Key, frecv = x.Count() };
    //    })
    //    .ToList()
    //    .ForEach(x => Console.WriteLine(x.value + " apare de:" + x.frecv));
    var res = from n in numbers.ToList()
        group n by n
        into g
        select new { value = g.Key, frecv = g.Count() };
    res.ToList().ForEach(x => Console.WriteLine(x.value + " apare de:" + x.frecv));
}

static void Task1()
{
    List<Angajat> list = GetAngajatService().FindAllAngajati();
    //1 - cerinta 1 din pdf sem11 - 12  extension methods
    list.OrderBy(x => x.Nivel).ThenBy(x => x.VenitPeOra)
        .ToList()
        .ForEach(Console.WriteLine);

    //1 - cerinta 1 din pdf sem11 - 12  sql like
    //var result =
    //    from a in list
    //    orderby a.Nivel ascending, a.VenitPeOra descending
    //    select a;
    //result.ToList().ForEach(Console.WriteLine);
}


static void Task2()
{
    //2 cate ore dureaza in medie fiecare tip de sarcina
    List<Sarcina> sarcini = GetSarcinaService().FindAllSarcini();
    sarcini.ForEach(Console.WriteLine);

    sarcini.GroupBy(sarcina => sarcina.TipDificultate)
        .Select(group => new { Dificultate = group.Key, Media = group.Average(sarcina => sarcina.NrOreEstimate) })
        .ToList()
        .ForEach(Console.WriteLine);
    
    var result = from sarcina in sarcini
        group sarcina by sarcina.TipDificultate
        into g
        select new { Dificultate = g.Key, Media = g.Average(sarcina => sarcina.NrOreEstimate) };

}

static void Task3()
{
    //3
    List<Pontaj> pontaje = GetPontajService().FindAllPontaje();
    pontaje.GroupBy(x => x.Angajat)
        .Select(g => new { Nume = g.Key.Nume, Salar = g.Sum(x => x.Sarcina.NrOreEstimate * x.Angajat.VenitPeOra) })
        .OrderByDescending(x => x.Salar)
        .ToList()
        .Take(2)
        .ToList()
        .ForEach(Console.WriteLine);
}

static void Task4()
{

    //4 
    GetPontajService().Salar(3).ForEach(x => Console.WriteLine(x));

}

static AngajatService GetAngajatService()
{
    //string fileName2 = ConfigurationManager.AppSettings["angajatiFileName"];
    string fileName = "..\\..\\..\\data\\angajati.txt";

    IValidator<Angajat> vali = new AngajatValidator();

    IRepository<string, Angajat> repo1 = new AngajatInFileRepository(vali, fileName);
    AngajatService service = new AngajatService(repo1);
    return service;
}

static SarcinaService GetSarcinaService()
{
    //string fileName2 = ConfigurationManager.AppSettings["sarciniFileName"];
    string fileName2 = "..\\..\\..\\data\\sarcini.txt";
    
    IValidator<Sarcina> vali = new SarcinaValidator();

    IRepository<string, Sarcina> repo1 = new SarcinaInFileRepository(vali, fileName2);
    SarcinaService service = new SarcinaService(repo1);
    return service;
}

static PontajService GetPontajService()
{
    //string fileName2 = ConfigurationManager.AppSettings["pontajeFileName"];
    string fileName2 = "..\\..\\..\\data\\pontaje.txt";
    IValidator<Pontaj> vali = new PontajValidator();

    IRepository<string, Pontaj> repo1 = new PontajInFileRepository(vali, fileName2);
    PontajService service = new PontajService(repo1);
    return service;
}





