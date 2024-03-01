// Main function of the C++ program.

#include <iostream>

using namespace std;
 
struct elem {
	int dane;
	elem * nast;
	elem * poprz;
};
 
/**
 * Zadanie 1
 * Zaimplementuj podstawowe operacje na listach dwukierunkowych:
 * - wstawienie elementu x do listy (a_1, a_2, ... , a_{i−1}, a_i, ... , a_n) pomiędzy elementy a_{i−1} oraz a_i;
 * - usunięcie pierwszego elementu listy;
 * - usunięcie wskazanego elementu listy;
 * - wyświetlenie listy.
 */
void wstaw(int dane, int i, elem* &head) {
    if (head == NULL || i == 0) {
        elem* newHead = new elem;
        newHead->dane = dane;
        newHead->nast = head;
        newHead->poprz = NULL;

        if (head != NULL) {
            head->poprz = newHead;
        }

        head = newHead;
        return;
    }

    elem* current = head;
    for (int j = 0; j < i - 1 && current != NULL; ++j) {
        current = current->nast;
    }

    if (current != NULL) {
        elem* ptr = new elem;
        ptr->dane = dane;
        ptr->nast = current->nast;
        ptr->poprz = current;
        
        if (current->nast != NULL) {
            current->nast->poprz = ptr;
        }

        current->nast = ptr;
    } else {
        cout << "Lista nie posiada tylu elementow!" << endl;
    }
}
void usunPierwszy(elem* &head) {
    if (head == NULL) {
        cout << "Pusta lista." << endl;
        return;
    }

    elem* temp = head;

    if (head->nast != NULL) {
        head->nast->poprz = NULL;
    }

    head = head->nast;

    delete temp;
}
void usun(int i, elem* &head){
    if (head == NULL) {
        cout << "Pusta lista." << endl;
        return;
    }

    if (i == 0) {
        elem* temp = head;
        head = head->nast;

        if (head != NULL) {
            head->poprz = NULL;
        }

        delete temp;
        return;
    }

    elem* current = head;
    for (int j = 0; j < i && current != NULL; ++j) {
        current = current->nast;
    }

    if (current == NULL) {
        cout << "Lista nie posiada wystarczajacej liczby elementow." << endl;
        return;
    }

    if (current->nast != NULL) {
        current->nast->poprz = current->poprz;
    }

    if (current->poprz != NULL) {
        current->poprz->nast = current->nast;
    } else {
        head = current->nast;
    }

    delete current;
}


void wyswietl(elem* head) {
    cout << endl;
    while (head != NULL) {
        cout << head->dane << " ";
        head = head->nast;
    }
    cout << endl;
}

/**
 * Zadanie 2
 * Lista dwukierunkowa może zostać „odwrócona” na dwa sposoby. Można pozmieniać 
 * wskaźniki we wszystkich elementach tak, aby dostać odwrotny porządek lub można
 * pozostawić strukturę listy bez zmian i parami pozamieniać dane elementów listy.
 * Zaimplementuj jeden ze sposobów.
 */
void odwroc(elem* &wsk) {
    {
    elem* temp = NULL;
    elem* current = wsk;

    while (current != NULL) {
        temp = current->poprz;
        current->poprz = current->nast;
        current->nast = temp;

        current = current->poprz;
    }

    if (temp != NULL) {
        // Nowy wskaznik na poczatek listy
        wsk = temp->poprz;
    }
}
}
 
int main() {
    // [Odblokuj jak ukończysz zadanie 1.]
	elem* lista = NULL;
	wstaw(97, 0, lista);
	wstaw(98, 1, lista);
	wstaw(99, 2, lista);
	wyswietl(lista); // Oczekiwany wynik 97, 98, 99
	wstaw(4, 0, lista);
	wstaw(2, 0, lista);
	wstaw(1, 0, lista);
	wyswietl(lista); // Oczekiwany wynik 1, 2, 4, 97, 98, 99
	wstaw(3, 2, lista);
	wyswietl(lista); // Oczekiwany wynik 1, 2, 3, 4, 97, 98, 99
	usunPierwszy(lista);
	wyswietl(lista); // Oczekiwany wynik 2, 3, 4, 97, 98, 99
	usun(4, lista);
	wyswietl(lista); // Oczekiwany wynik 2, 3, 4, 97, 99
	usun(3, lista);
	usun(3, lista);
	wyswietl(lista); // Oczekiwany wynik 2, 3, 4
	
	// [Odblokuj jak ukończysz zadanie 2.]
	odwroc(lista);
	wyswietl(lista); // Oczekiwany wynik 4, 3, 2
	odwroc(lista);
	wyswietl(lista); // Oczekiwany wynik 2, 3, 4
	
	return 0;
}
