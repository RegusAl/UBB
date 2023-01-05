from repository.repo_emisiune import RepoEmisiune
from service.service_emisiune import ServiceEmisiune
from ui.consola import Consola

repo = RepoEmisiune("data/emisiuni.txt")
service = ServiceEmisiune(repo)

consola = Consola(service, repo)
consola.run()