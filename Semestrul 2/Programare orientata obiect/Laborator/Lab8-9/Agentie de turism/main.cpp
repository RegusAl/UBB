#include "consola.h"
#include "OfertaRepo.h"
#include "AgentieService.h"
#include "Validator.h"
#include "teste.h"


int main() {
    test_all();
    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    Consola ui{service};
    ui.run();
}