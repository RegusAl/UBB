from validare.validator_filme import ValidatorFilme
from validare.validator_clienti import ValidatorClienti
from validare.validator_inchiriere import ValidatorInchiriere
from infrastructura.repo_filme import RepoFilmeFile
from infrastructura.repo_clienti import RepoClientiFile
from infrastructura.repo_inchiriere import RepoInchiriereFile
from services.service_filme import ServiceFilme
from services.service_clienti import ServiceClienti
from services.service_inchiriere import ServiceInchiriere
from prezentare.consola import ui

# validator
validator_filme = ValidatorFilme()
validator_clienti = ValidatorClienti()
validator_inchiriere = ValidatorInchiriere()

# repository
repo_filme = RepoFilmeFile('data/filme')
repo_clienti = RepoClientiFile('data/clienti')
repo_inchiriere = RepoInchiriereFile('data/inchirieri')

# services
service_filme = ServiceFilme(validator_filme, repo_filme, repo_inchiriere)
service_clienti = ServiceClienti(validator_clienti, repo_clienti, repo_inchiriere)
service_inchiriere = ServiceInchiriere(validator_clienti, validator_filme, repo_clienti, repo_filme, repo_inchiriere, service_clienti, service_filme)

# consola
consola = ui(service_filme, service_clienti, service_inchiriere)
consola.run()