#include <iostream>

using namespace std;

struct elem {
    int dane;
    elem * nast;
};

/**
 * Zadanie 1
 * Zaimplementuj podstawowe operacje stosowe:
 * - położenie elementu na wierzchołku stosu;
 * - pobranie ostatnio odłożonego elementu i zwrócenie go jako wartości funkcji;
 * - zwrócenie elementu znajdującego się na wierzchołku stosu bez jego usuwania;
 * - sprawdzenie, czy stos jest pusty.
 */
void push(elem* &stos, int x) {
    if(stos == NULL){
        stos = new elem();
        stos->dane = x;
        stos->nast = NULL;
        return;
    }
    
    elem* newTop = new elem;
    newTop->dane = x;
    newTop->nast = stos;
    stos = newTop;
	
}
int pop(elem* &stos) {
    elem* temp = stos;
    int dane = temp->dane;
    stos = stos->nast;
    delete temp;
    return dane;

}
int topEl(elem* stos) {
    return stos->dane;
}
bool isEmpty(elem* stos) {
    return false;
}

/**
 * Zadanie 2
 * Zaimplementuj podstawowe operacje wykonywane na kolejce:
 * - dodanie elementu do kolejki;
 * - pobranie pierwszego elementu kolejki (czyli najwcześniej dodanego) i zwrócenie go jako wartości funkcji;
 * - zwrócenie elementu znajdującego się na początku kolejki bez jego usuwania.
 */
void add(elem* &pocz_kolejki, elem* &kon_kolejki, int x) {
	elem* newElem = new elem;
	newElem->dane = x;
	newElem->nast = NULL;

	if(pocz_kolejki == NULL){
		pocz_kolejki = newElem;
		kon_kolejki = pocz_kolejki;
	}
	else{
		kon_kolejki->nast = newElem;
		kon_kolejki = newElem;
	}
	
}
int next(elem* &pocz_kolejki, elem* &kon_kolejki) {
	int value = pocz_kolejki->dane;

	elem* temp = pocz_kolejki;
	pocz_kolejki = pocz_kolejki->nast;

	if(pocz_kolejki == NULL){
		kon_kolejki = NULL;
	}

	delete temp;

    return value;
}
int firstEl(elem* pocz_kolejki) {
    return pocz_kolejki->dane;
}

/**
 * Zadanie 3
 * W następującym ciągu litera oznacza operację umieszczenia, a gwiazdka operację pobrania elementu ze stosu:
 * EAS*Y*QUE***ST***IO*N***
 * Napisz funkcję, która wypisze ciąg wartości zwracanych przez operację pobrania elementu ze stosu.
 */
void decodeAsStack(string text) {

	elem* zad3 = NULL;
	for(char znak : text){
		if(znak == '*'){
			cout<<char(zad3->dane);
			pop(zad3);
		}
		
		else{
			int x = int(znak);
			push(zad3, x);
		}
	}

}

/**
 * Zadanie 4
 * Napisz funkcję, która działa jak w zadaniu 3, ale tym razem wykorzystaj kolejkę.
 */
void decodeAsQueue(string text) {
    elem* pocz = NULL;
	elem* koni = NULL;
	for(char znak : text){
		if(znak == '*'){
			int x = next(pocz, koni);
			cout<<char(x);
		}
		else{
			add(pocz, koni, int(znak));
		}
	}
}

/**
 * Zadanie 5
 * Zaimplementuj kolejkę za pomocą dwóch stosów.
 */
void queueAsStacksAdd(elem* &stos1, elem* &stos2, int x) {
	push(stos1, x);
}
int queueAsStackNext(elem* &stos1, elem* &stos2) {
	
	while (stos1 != NULL)
	{
		push(stos2, pop(stos1));
	}
	

    return pop(stos2);
}

/**
 * Zadanie 6
 * Odwróć porządek elementów na stosie korzystając z:
 * - jednego dodatkowego stosu;
 * - jednej dodatkowej kolejki.
 */
void reverseStackWithStack(elem* &stos) {
    elem* dodatkowy_stos = NULL;
	while (stos != NULL)
	{
		push(dodatkowy_stos,pop(stos));
	}
	stos = dodatkowy_stos;
	
    
}
void reverseStackWithQueue(elem* &stos) {
    elem* pocz_kolejki = NULL;
    elem* kon_kolejki = NULL;
	
	while (stos != NULL)
	{
		add(pocz_kolejki, kon_kolejki, pop(stos));
	}
	
    stos = kon_kolejki;
}

/**
 * Zadanie 7
 * Uporządkuj elementy na stosie według rosnących wartości (najmniejsza wartość jest pierwszym elementem), korzystając z jednego dodatkowego stosu i kilku innych zmiennych lokalnych.
 */
void sortStack(elem* &stos) {
    elem* dodatkowy_stos = NULL;
    
  while (stos != nullptr) {
        // Pobieramy element ze stosu głównego.
        int temp = pop(stos);

        // Przenosimy elementy większe od temp na stos pomocniczy.
        while (dodatkowy_stos != nullptr && temp > dodatkowy_stos->dane) {
            push(stos, dodatkowy_stos->dane);
            pop(dodatkowy_stos);
        }

        // Umieszczamy temp na stosie pomocniczym.
        push(dodatkowy_stos, temp);
    }

	stos = dodatkowy_stos;
}

int main()
{
    // [Odblokuj jak ukończysz zadanie 1.]
    elem* stos = NULL;
	push(stos, 1);
	push(stos, 2);
	push(stos, 3);
	push(stos, 4);
	cout << topEl(stos) << endl; // Oczekiwany wynik to 4.
	cout << pop(stos) << endl; // Oczekiwany wynik to 4.
	cout << topEl(stos) << endl; // Oczekiwany wynik to 3.
	
	// [Odblokuj jak ukończysz zadanie 2.]
	cout<<"\nZAD2"<<endl;
	elem* pocz_kolejki = NULL;
	elem* kon_kolejki = NULL;
	add(pocz_kolejki, kon_kolejki, 1);
	add(pocz_kolejki, kon_kolejki, 2);
	add(pocz_kolejki, kon_kolejki, 3);
	add(pocz_kolejki, kon_kolejki, 4);
	cout << firstEl(pocz_kolejki) << endl; // Oczekiwany wynik to 1.
	cout << next(pocz_kolejki, kon_kolejki) << endl; // Oczekiwany wynik to 1.
	cout << firstEl(pocz_kolejki) << endl; // Oczekiwany wynik to 2.
	
	// [Odblokuj jak ukończysz zadanie 3.]
	cout<<"\nZAD3"<<endl;
	decodeAsStack("EAS*Y*QUE***ST***IO*N***");
	
	// [Odblokuj jak ukończysz zadanie 4.]
	cout<<"\nZAD4"<<endl;
	decodeAsQueue("EAS*Y*QUE***ST***IO*N***");
	
	// [Odblokuj jak ukończysz zadanie 5.]
	cout<<"\nZAD5"<<endl;
	elem* stos1 = NULL;
	elem* stos2 = NULL;
	queueAsStacksAdd(stos1, stos2, 1);
	queueAsStacksAdd(stos1, stos2, 2);
	cout << queueAsStackNext(stos1, stos2) << endl; // Oczekiwany wynik to 1.
	cout << queueAsStackNext(stos1, stos2) << endl; // Oczekiwany wynik to 2.

	
	// [Odblokuj jak ukończysz zadanie 6.]
	cout<<"\nZAD6"<<endl;
	reverseStackWithStack(stos);
	cout << topEl(stos) << endl; // Oczekiwany wynik to 1.
	reverseStackWithQueue(stos);
	cout << topEl(stos) << endl; // Oczekiwany wynik to 3.
	
	// [Odblokuj jak ukończysz zadanie 7.]
	cout<<"\nZAD7"<<endl;
	sortStack(stos);
	cout << topEl(stos) << endl; // Oczekiwany wynik to 1.
    
    return 0;
}
