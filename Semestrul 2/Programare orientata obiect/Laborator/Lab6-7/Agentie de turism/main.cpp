#include "consola.h"
#include "OfertaRepo.h"
#include "AgentieService.h"
#include "teste.h"


int main() {
    test_all();
    OfertaRepo repo;
    AgentieService service{repo};
    Consola ui{service};
    ui.run();
}