from consola.consola import Consola
from domain.contact import Validator
from repository.repository import ContactRepository
from service.service import AgendaService


validator = Validator()
repository = ContactRepository("./data/agenda")
service = AgendaService(repository, validator)

consola = Consola(service)
consola.start()