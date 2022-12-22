from repository.repo_pantofi import RepoPantofi
from service.service_pantofi import ServicePantofi
from ui.consola import Consola
from validator.validator import Validator

repo = RepoPantofi("data/pantof.txt")
validator = Validator()
service = ServicePantofi(repo, validator)

ui = Consola(service)
ui.run()