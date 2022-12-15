from UI.consola import Consola
from repository.repo_atelier import RepoAtelier
from service.service_atelier import ServiceAtelier

repo = RepoAtelier("data/ateliere.txt")
service = ServiceAtelier(repo)

consola = Consola(service)
consola.run()