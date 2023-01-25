from UI.consola import Consola
from repository.repository import Repository
from service.service import Service

repository = Repository("./produse")
service = Service(repository)

consola = Consola(service)
consola.start()