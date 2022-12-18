from repository.repository_piese import Repository_Piese
from service.service_piese import Service_Piese
from ui.consola import Consola
from validare.validator_piese import Validator

validator = Validator()
repo = Repository_Piese("data/piese.txt")
service = Service_Piese(repo, validator)

ui = Consola(service)
ui.run()