from validare.validator_filme import ValidatorFilme
from validare.validator_clienti import ValidatorClienti
from validare.validator_inchiriere import ValidatorInchiriere
from infrastructura.repo_filme import RepoFilme
from infrastructura.repo_clienti import RepoClienti
from infrastructura.repo_inchiriere import RepoInchiriere
from services.service_filme import ServiceFilme
from services.service_clienti import ServiceClienti
from services.service_inchiriere import ServiceInchiriere
from prezentare.consola import ui

validator_filme = ValidatorFilme()
validator_clienti = ValidatorClienti()
validator_inchiriere = ValidatorInchiriere()

repo_filme = RepoFilme()
repo_clienti = RepoClienti()
repo_inchiriere = RepoInchiriere()

service_filme = ServiceFilme(validator_filme, repo_filme)
service_clienti = ServiceClienti(validator_clienti, repo_clienti)
service_inchiriere = ServiceInchiriere(validator_inchiriere, repo_inchiriere)

consola = ui(service_filme, service_clienti, service_inchiriere)
consola.run()