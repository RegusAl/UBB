#include "consola.h"
#include "OfertaRepo.h"
#include "AgentieService.h"


int main() {
    OfertaRepo repo;
    AgentieService service{repo};
    Consola ui{service};
    ui.run();
}