from domain.validators import ShowValidator, ClientValidator, RatingValidator
from repository.client_repo import ClientFileRepo
from repository.rating_repo import RatingRepoFile
from repository.show_repo import ShowFileRepo
from service.client_service import ClientService
from service.rating_service import RatingService

from service.show_service import ShowService
from ui.console import Console

repo_file_show = ShowFileRepo('data/shows.txt')
val_show = ShowValidator()
srv_show = ShowService(repo_file_show, val_show)

# repo_client = ClientInMemoryRepo()
repo_file_client = ClientFileRepo('data/clients.txt')
val_client = ClientValidator()
srv_client = ClientService(repo_file_client, val_client)

repo_ratings = RatingRepoFile('data/ratings.txt')
repo_validator = RatingValidator()
srv_ratings = RatingService(repo_ratings, repo_validator, repo_file_show, repo_file_client)

ui = Console(srv_show, srv_client, srv_ratings)
ui.show_ui()
