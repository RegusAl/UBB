from repository.workshop_repo import WorkShopRepo
from service.workshop_controller import WorkshopController
from ui.console import Console

repo = WorkShopRepo("data/ateliere.txt")
ctrl = WorkshopController(repo)
console = Console(ctrl)

console.run()