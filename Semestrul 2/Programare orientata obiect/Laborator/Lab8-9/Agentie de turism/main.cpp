#include "consola.h"
#include "OfertaRepo.h"
#include "AgentieService.h"
#include "Validator.h"
#include "teste.h"


int main() {
    test_all();
    string fileName = "/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Laborator/Lab8-9/Agentie de turism/oferte.txt";
    OfertaRepoFile repo{fileName};

//    OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    Consola ui{service};
    ui.run();
}
