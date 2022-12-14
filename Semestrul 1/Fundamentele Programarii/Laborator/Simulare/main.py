from repository.repo import Repo
from service.service import Service
from ui.ui import Consola

repo = Repo("data/prognoza.txt")
service = Service(repo)

ui = Consola(service)
ui.run()