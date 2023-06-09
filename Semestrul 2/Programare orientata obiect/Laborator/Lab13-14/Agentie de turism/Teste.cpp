#include "Teste.h"
#include "oferta.h"
#include "Repo.h"
#include "Validator.h"
#include "Service.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

void test_domain()
{
	Oferta o{ "A", "B", "Altele", 100 };
	assert(o.getDenumire() == "A");
	assert(o.getDestinatie() == "B");
	assert(o.getTip() == "Altele");
	assert(o.getPret() == 100);

	o.setDenumire("X");
	o.setDestinatie("Y");
	o.setTip("Croaziere");
	o.setPret(5);

	assert(o.getDenumire() == "X");
	assert(o.getDestinatie() == "Y");
	assert(o.getTip() == "Croaziere");
	assert(o.getPret() == 5);
}

void test_add_repo() {
	OfertaRepo repo;
	Oferta o1{ "A", "d", "Altele", 10 };
	repo.store(o1);
	assert(repo.getAllOferte().size() == 1);
	try {
		repo.store(o1);
		assert(false);
	}
	catch (RepoException) {
		assert(true);
	}
}

void test_delete_repo() {
	Oferta o1{ "A", "d", "Altele", 10 };
	Oferta o2{ "F", "dAS", "Altele", 410 };
	Oferta o3{ "PO", "SVS", "Altele", 63 };
	OfertaRepo repo;
	repo.store(o1);
	repo.store(o2);
	repo.store(o3);
	try {
		repo.delete_of("Fvsd"); 
		assert(false);
	}
	catch (RepoException) {
		assert(true);
	}
	repo.delete_of("A");
	auto list = repo.getAllOferte();
	assert(list.size() == 2);
	assert(list.at(0).getDenumire() == "F");
	assert(list.at(1).getDenumire() == "PO");
}

void test_modify_repo() {
	OfertaRepo repo;
	Oferta o1{ "A", "d", "Altele", 10 };
	Oferta o2{ "A", "dAS", "Altele", 410 };
	Oferta o3{ "PO", "SVS", "Altele", 63 };
	repo.store(o1);
	repo.modify_of(o2);
	auto list = repo.getAllOferte();
	assert(list.size() == 1);
	assert(list.at(0).getPret() == 410);
	assert(list.at(0).getDestinatie() == "dAS");
	try {
		repo.modify_of(o3); 
		assert(false);
	}
	catch (RepoException) {
		assert(true);
	}
}

void test_find_repo() {
	Oferta o1{ "A", "d", "Altele", 10 };
	Oferta o2{ "F", "dAS", "Altele", 410 };
	Oferta o3{ "PO", "SVS", "Altele", 63 };
	OfertaRepo repo;
	repo.store(o1);
	assert(repo.exists(o1));
	assert(!repo.exists(o2));
	repo.store(o2);
	repo.store(o3);
	assert(repo.find("F").getDenumire() == o2.getDenumire());
	try {
		repo.find("szs"); assert(false);
	}
	catch (RepoException) {
		assert(true);
	}
}

void test_validator() {
	Validator validator;
	Oferta o{ "a", "b", "Altele", 10 };
	Oferta o2{ "", "", "", -8 };
	validator.validateOferta(o);
	try {
		validator.validateOferta(o2);
		assert(false);
	}
	catch (ValidationException) {
		assert(true);
	}
}

void test_add_service() {
	OfertaRepo repo;
	Validator valid;
	OfertaStore service{ repo, valid };

	service.addOferta("a", "b", "Altele", 10);
	service.addOferta("f", "b", "Altele", 10);
	assert(service.getAllOferte().size() == 2);
	try {
		service.addOferta("a", "svb", "Altele", 10);
		assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}
	try {
		service.addOferta("", "", "", 10); 
		assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}
}

void test_modify_service() {
	OfertaRepo repo;
	Validator valid;
	OfertaStore service{ repo, valid };

	service.addOferta("f", "b", "Altele", 10);
	service.addOferta("gd", "bsv", "Altele", 30);
	service.modifyOferta("f", "abc", "Altele", 65);
	assert(service.getAllOferte().at(0).getPret() == 65);
	try {
		service.modifyOferta("a", "b", "Altele", 10);
		assert(false);
	}
	catch (RepoException& ) {
		assert(true);
	}
	try {
		service.modifyOferta("f", "abc", "ABC", -65);
		assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}
}

void test_delete_service() {
	OfertaRepo repo;
	Validator valid;
	OfertaStore service{ repo, valid };
	service.addOferta("f", "b", "Altele", 10);
	service.addOferta("p", "bedb", "Altele", 100);
	service.addOferta("i", "bedgmb", "Altele", 80);
	service.deleteOferta("p");
	assert(service.getAllOferte().size() == 2);
	try {
		service.deleteOferta("111");
		assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}
	try {
		service.deleteOferta("A");
		assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}
}

void test_filter_service() {
	OfertaRepo repo;
	Validator valid;
	OfertaStore service{ repo, valid };
	service.addOferta("a", "b", "Altele", 10);
	service.addOferta("aac", "ccb", "Altele", 50);
	service.addOferta("t", "b", "Altele", 66);
	service.addOferta("ty", "gr", "Altele", 50);

	vector<Oferta> oferte_cu_dest_b = service.filtrareDest("b");
	assert(oferte_cu_dest_b.size() == 2);
	vector<Oferta> oferte_cu_dest_null = service.filtrareDest("gdd");
	assert(oferte_cu_dest_null.size() == 0);

	vector<Oferta> oferte_cu_pret_50 = service.filtrarePret(50);
	assert(oferte_cu_pret_50.size() == 2);
	vector<Oferta> oferte_cu_pret_null = service.filtrarePret(80);
	assert(oferte_cu_pret_null.size() == 0);
}

void test_sort_service() {
	OfertaRepo repo;
	Validator valid;
	OfertaStore service{ repo, valid };
	service.addOferta("a", "b", "Altele", 100);
	service.addOferta("sa", "a", "Altele", 50);
	service.addOferta("t", "y", "Croaziere", 63);
	service.addOferta("o", "xc", "AllInclusive", 100);

	vector<Oferta>sortedByDenumire = service.sortByDenumire();
	vector<Oferta>sortedByDest = service.sortByDestinatie();
	vector<Oferta>sortedByTipSiPret = service.sortByTipSiPret();

	assert(sortedByDenumire.size() == 4);
	assert(sortedByDenumire.at(0).getDenumire() == "a");
	assert(sortedByDenumire.at(3).getDenumire() == "t");

	assert(sortedByDest.size() == 4);
	assert(sortedByDest.at(1).getDenumire() == "a");
	assert(sortedByDest.at(2).getDenumire() == "o");

	assert(sortedByTipSiPret.size() == 4);
	assert(sortedByTipSiPret.at(0).getDenumire() == "o");
	assert(sortedByTipSiPret.at(1).getDenumire() == "sa");
}

void test_cos()
{
	OfertaRepo repo;
	Validator valid;
	OfertaStore service{ repo, valid };
	service.addOferta("a", "b", "Altele", 100);
	service.addOferta("sa", "a", "Altele", 50);
	service.addOferta("t", "y", "Altele", 63);
	service.addOferta("o", "xc", "Altele", 100);

	service.addToCos("a");
	assert(service.getAllOferteCos().size() == 1);

	service.addRandomToCos(2);
	assert(service.getAllOferteCos().size() == 2);

	service.emptyCos();
	assert(service.getAllOferteCos().size() == 0);
}

void test_count() {
	OfertaRepo repo;
	Validator valid;
	OfertaStore service{ repo, valid };
	service.addOferta("a", "b", "Altele", 100);
	service.addOferta("sa", "a", "Altele", 50);
	service.addOferta("t", "a", "Altele", 63);
	service.addOferta("o", "A", "Altele", 100);
	assert(service.count_oferte("a") == 2);
	assert(service.count_oferte("A") == 1);
	assert(service.count_oferte("x") == 0);
}

void test_export() {
	OfertaRepo repo;
	Validator valid;
	OfertaStore service{ repo, valid };
	service.addOferta("a", "b", "Altele", 100);
	service.addOferta("sa", "a", "Altele", 50);
	service.addOferta("t", "y", "Altele", 63);
	service.addOferta("o", "xc", "Altele", 100);

	service.addToCos("a");
	service.addToCos("sa");
	service.addToCos("t");
	assert(service.getAllOferteCos().size() == 3);

	service.export_fisier("test");

	string den, dest, tip, pr, line;
	int cnt = 0;
	std::ifstream fin("test");
	while (std::getline(fin, line)) {
		//	std::vector < string > v;
		//	string delimitator = " | ";
		//	string token = line.substr(0, line.find(delimitator));
		//	size_t pos = 0;
		//	int atr = 0;
		//	while ((pos = line.find(" | ")) != string::npos) {
		//		token = line.substr(0, pos);
		//		if (atr == 0)
		//			assert(token == service.getAllOferteCos().at(cnt).getDenumire());
		//		if (atr == 1)
		//			assert(token == service.getAllOferteCos().at(cnt).getDestinatie());
		//		if (atr == 2)
		//			assert(token == service.getAllOferteCos().at(cnt).getTip());
		//		if (atr == 3) assert(stoi(token) == service.getAllOferteCos().at(cnt).getPret());
		//		v.push_back(token);
		//		line.erase(0, pos + delimitator.length());
		//		atr++;
		//	}
		cnt++;
	}
	assert(cnt == 3);
}

void test_repo_file() {
	std::ofstream ofs;
	ofs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
	ofs << "A,Ankara,Altele,100\n";
	ofs << "B,Berlin,Altele,700\n";
	ofs << "C,Cairo,Altele,800\n";
	ofs << "D,Dubai,Altele,160\n";
	ofs.close();
	try {
		OfertaRepoFile testRepoF{ "test2.txt" };
		assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}
	OfertaRepoFile testRepoF{ "test.txt" };
	assert(testRepoF.getAllOferte().size() == 4);


	auto foundof = testRepoF.find("C");
	assert(foundof.getDestinatie() == "Cairo");
	assert(foundof.getTip() == "Altele");
	assert(foundof.getPret() == 800);

	Oferta of1{ "E", "Edinburgh", "ee", 500};

	testRepoF.store(of1);
	assert(testRepoF.getAllOferte().size() == 5);
	Oferta found = testRepoF.find("E");
	assert(found.getPret() == 500);
}

void test_all() {
	test_domain();
	test_add_repo();
	test_delete_repo();
	test_modify_repo();
	test_find_repo();
	test_validator();
	test_add_service();
	test_modify_service();
	test_delete_service();
	test_filter_service();
	test_sort_service();
	test_cos();
	test_count();
	test_export();
	test_repo_file();
}
