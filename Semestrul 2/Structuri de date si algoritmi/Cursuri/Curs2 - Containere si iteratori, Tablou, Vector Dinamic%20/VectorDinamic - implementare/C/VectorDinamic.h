//tip de data generic (pentru moment este intreg)
typedef struct {

//iterator
	//iteratorul contine pointer catre container
	//varianta 2
} Iterator;

//constructor
//destructor
//dimensiunea vectorului (numar de elemente)
//elementul al i-lea (1 <= i <= numar de elemente)
//adaugare la sfarsit
//alte operatii specifice
//returneaza un iterator pe vector

//constructor
void prim(Iterator* v);
void urmator(Iterator* i);
TElem elementI(Iterator* i);
int valid(Iterator* i);
void distrugeI(Iterator* i);