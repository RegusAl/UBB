from domain.validare import Validare
from repository.repository import RepositoryEvenimente
from service.service import ServiceEvenimente
from ui.consola import Consola

validare = Validare()
repository = RepositoryEvenimente("./data/evenimente")
service = ServiceEvenimente(repository, validare)

consola = Consola(service)
consola.start()