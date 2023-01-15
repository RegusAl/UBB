from erori.erori import Validator
from repository.repository import Repository
from service.service import Service
from teste.test_repository import TestRepo
from ui.consola import Consola

validator = Validator()
repo = Repository("data/melodii")
service = Service(repo, validator)

ui = Consola(service, repo)
ui.run()