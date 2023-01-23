from repository.repository import Repository
from service.service import Service
from ui.consola import Consola

repository = Repository("data/echipa")
service = Service(repository)

consola = Consola(service)
consola.start()
