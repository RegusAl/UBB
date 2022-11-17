from domain.validators import ShowValidator
from repository.show_repo import InMemoryRepository, InMemoryRepoDict
from service.show_service import ShowService
from ui.console import Console

repo = InMemoryRepository()
# repo = InMemoryRepoDict()
val = ShowValidator()
srv = ShowService(repo, val)
ui = Console(srv)
ui.show_ui()
