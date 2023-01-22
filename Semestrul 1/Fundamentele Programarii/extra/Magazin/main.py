from repository.repository import RepoMagazin
from service.service import ServiceMagazin
from ui.consola import Consola

repository = RepoMagazin("./data/produse.txt")
service = ServiceMagazin(repository)
consola = Consola(service)

consola.start()