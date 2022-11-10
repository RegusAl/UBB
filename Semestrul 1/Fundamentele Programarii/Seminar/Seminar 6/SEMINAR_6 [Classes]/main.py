from domain.entities import Serial
from domain.validators import ShowValidator
from repository.show_repo import InMemoryRepository
from service.show_service import ShowService
from ui.console import Console

repo = InMemoryRepository()
val = ShowValidator()
srv = ShowService(repo, val)
ui = Console(srv)
ui.show_ui()
