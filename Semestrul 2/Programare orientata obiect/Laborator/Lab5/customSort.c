#include "customSort.h"

/*
* Sorteaza o lista data
* @param l: lista care se sorteaza
* @param cmpF: functia (relatia) dupa care se sorteaza
*
* post: lista l este sortata
*/
void sort(MyList* l, CompareFct cmpF) {
	int i, j;
	for (i = 0; i < size(l); i++) {
		for (j = i + 1; j < size(l); j++) {
			void* p1 = get(l, i);
			void* p2 = get(l, j);
			if (cmpF(p1, p2) > 0) {
				set(l, i, p2);
				set(l, j, p1);
			}
		}
	}
}
