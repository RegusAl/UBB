
    using sem11.domain;
    using sem11.repository;
    namespace sem11.service;
    class PontajService
    {
        private IRepository<string, Pontaj> repo;

        public PontajService(IRepository<string, Pontaj> repo)
        {
            this.repo = repo;
        }

        public List<Pontaj> FindAllPontaje()
        {
            return repo.FindAll().ToList();
        }



        public List<PontajDTO> Salar(int luna) //4
        {
            //var res = from p in FindAllPontaje()
            //          where p.Date.Month == luna
            //          group p by p.Angajat into g
            //          select new PontajDTO()
            //          {
            //              NumeAngajat = g.Key.Nume,
            //              Nivel = g.Key.Nivel,
            //              Salar = g.Sum(x => x.Sarcina.NrOreEstimate * x.Angajat.VenitPeOra)
            //          };
            //FindAllPontaje().Where(x => x.Date.Month == luna)
            //    .GroupBy(x => x.Angajat)
            //    .Select(g => new PontajDTO()
            //    {
            //        NumeAngajat = g.Key.Nume,
            //        Nivel = g.Key.Nivel,
            //        Salar = g.Sum(x => x.Sarcina.NrOreEstimate * x.Angajat.VenitPeOra)
            //    })
            //    .ToList();
            //return res;

            var res1 = from pontaj in repo.FindAll().ToList()
                where pontaj.Date.Month.Equals(luna)
                group pontaj by pontaj.Angajat
                into g
                select new PontajDTO
                {
                    NumeAngajat = g.Key.Nume,
                    Nivel = g.Key.Nivel,
                    Salar = g.Sum(x => x.Sarcina.NrOreEstimate * x.Angajat.VenitPeOra)
                }
                into pontajDTO
                orderby pontajDTO.Nivel, pontajDTO.Salar
                select pontajDTO;
            return res1.ToList();
        }
    }
