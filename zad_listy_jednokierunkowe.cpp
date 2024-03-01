#include <iostream>

using namespace std;

struct elem {
	int dane;
	elem* nast;
};

/**
 * Zadanie 1
 * Zaimplementuj podstawowe operacje na listach:
 * - wstawienie elementu x do listy (a_1, a_2, ... , a_{i−1}, a_{i}, ... , a_{n}) pomiędzy elementy a_{i−1} oraz a_{i};
 * - usunięcię i-tego elementu z listy;
 * - zwrócenie danej i-tego elemntu z listy.
 */
void insert(int x, int i, elem* &head) {
    if(head == NULL || i == 0)            //Jeśli pusty obiekt (NULL) To tworzymy nową liste Lub kiedy tworzymy nowy element na poczatku listy
    {  
        if(i != 0)     //Jesli rozne od zera to tworzymy nowa liste
        {
            head = new elem;         //Nowy obiekt
            head->dane = x;         //Przypisanie wartosc nowemu obiektowi
            head->nast = NULL;      //Nastepny obiekt jeszcze nie istnieje wiec przypisujemy NULL
        }
        else    //Jesli 0 to bedziemy dopisywac element na poczatku listy
        {
            elem* newHead = new elem;     //Nowy obiekt
            newHead->dane = x;          //Przypisanie danej
            newHead->nast = head;       //Jako nastepnik przypisujemy adres obecnie pierwszego elementu
            head = newHead;             //Teraz nowy element staje sie glowa, pierwszym elementem na liscie

        }
    }
    else                        //W przeciwnym wypadku jesli lista istnieje będziemy przedostawać się na jej początek, do najmłodszego obiektu
    {

        elem* current = head;
        for(int j = 0; j < i - 1 && current != NULL; ++j)
            current = current->nast;

        if(current != NULL)
        {
            elem* ptr = new elem;
            ptr->dane = x;
            ptr->nast = current->nast;
            current->nast = ptr;
        }
        else
        {
            cout<<"Lista nie posiada tylu elementow!"<<endl;
        }
    }
		
}
void remove(int i, elem* &head) {
   if (i < 0)
    {
        cout << "Błąd: Nie można usunąć elementu z pozycji ujemnej!" << endl;
        return;
    }

    if (head == NULL)
    {
        cout << "Błąd: Lista jest pusta, nie można usunąć elementu." << endl;
        return;
    }

    elem* current = head;

    if (i == 0)         //Jesli pierwszy element to tworzymy nowa glowe(Element ktory bedzie zawieral pierwszy obiekt listy)
    {
        elem* temp = head;
        head = head->nast;
        delete temp;
        return;
    }
    else
    {
        for(int j = 0; j < i - 1 && current != NULL ;++j)   //Idziemy do elementu ktory jest przed elementem ktory chcemy usunac
            current = current->nast;

        if(current != NULL)     //Jesli obiekt nie jest poza lista
        {
            elem* temp = current->nast;  
            current->nast = current->nast->nast;    //elementowi poprzedzajacemu element ktory chcemy usunac przypisz element nastepny po tym ktory chcemy usunac(W sensie adres)
            delete temp;    //Usun obiekt 
        }
        else
        {
            cout<<"Element o podanym indeksie nie istnieje."<<endl;
        }
    }
	
}
int read(int i, elem* head) {
	for(int j = 0; j < i; ++j)
		head = head->nast;

	return head->dane;
}

/**
 * Zadanie 2
 * Napisz funkcję zwracającą liczbę elementów podanej listy.
 */
int size(elem* head) {
	int counter = 0;
    while (head != NULL)
    {
        head = head->nast;
        counter++;
    }
    
    return counter;
}

/**
 * Zadanie 3
 * Napisz procedurę wypisującą wszystkie elementy listy.
 */
void print(elem* head) {
    cout<<"List: ";
    while (head != NULL)    //Powtarzaj tak dlugo az obiekt nie jest NULL, poniewaz jesli pobierzemy adres nastepnego obiektu z najmlodszego to bedzie NULL, nie mylic z head->link != NULL, bo nie odczytamy ostaniego obiektu
    {
        cout<<head->dane<<", ";
        head = head->nast;
    }
    cout<<endl;
}

/**
 * Zadanie 4
 * Napisz procedurę usuwającą wszystkie elementy listy.
 */
void destroy(elem* &head) {

	while (head != NULL)
        remove(0, head);

}

/**
 * Zadanie 5
 * Napisz funkcję zwracającą wskaźnik do elementu listy zawierającego w polu dane wartość x.
 */
elem* search(int x, elem* head) {
    while (head != NULL){
        if(head->dane == x)
            return head;
        
        head = head->nast;
    }
    
    cout<<"Takiego elementu nie ma na liscie"<<endl;
	return NULL;
}

/**
 * Zadanie 6
 * Treść zadania jest pod linkiem: https://uniwersytetslaski-my.sharepoint.com/:i:/g/personal/arkadiusz_nowakowski_o365_us_edu_pl/EamNW4wqCO9AqAnFSxlxDSYBvlnbuAL2k34Ehgfl7V_5mw?e=TOidLD
 */
struct poly_elem {
	int expo, coef;
	poly_elem* nast;
};
void poly_insert(int expo, int coef, int i, poly_elem* &head) {
   if(head == NULL || i == 0)            //Jeśli pusty obiekt (NULL) To tworzymy nową liste Lub kiedy tworzymy nowy element na poczatku listy
    {  
        if(i != 0)     //Jesli rozne od zera to tworzymy nowa liste
        {
            head = new poly_elem;         //Nowy obiekt
            head->expo =  expo;         //Przypisanie wartosc nowemu obiektowi
            head->coef = coef;
            head->nast = NULL;      //Nastepny obiekt jeszcze nie istnieje wiec przypisujemy NULL
        }
        else    //Jesli 0 to bedziemy dopisywac element na poczatku listy
        {
            poly_elem* newHead = new poly_elem;     //Nowy obiekt
            newHead->expo = expo;          //Przypisanie danej
            newHead->coef = coef;
            newHead->nast = head;       //Jako nastepnik przypisujemy adres obecnie pierwszego elementu
            head = newHead;             //Teraz nowy element staje sie glowa, pierwszym elementem na liscie

        }
    }
    else                        //W przeciwnym wypadku jesli lista istnieje będziemy przedostawać się na jej początek, do najmłodszego obiektu
    {

        poly_elem* current = head;
        for(int j = 0; j < i - 1 && current != NULL && current->expo < expo; ++j)
            current = current->nast;

        if(current != NULL && current->expo != expo)
        {
            poly_elem* ptr = new poly_elem;
            ptr->expo = expo;
            ptr->coef = coef;
            ptr->nast = current->nast;
            current->nast = ptr;
        }
        else if(current != NULL && current->expo == expo)
        {
            current->coef += coef;
        }
        else
        {
            cout<<"Lista nie posiada tylu elementow!"<<endl;
        }
    }
    
}

void poly_print(poly_elem* head) {
    while (head != NULL)
    {
        cout<<"("<<head->coef<<"x^"<<head->expo<<")";
        if(head->nast != NULL)
            cout<<"+";
        head = head->nast;
    }
    
    cout<<endl;
}
poly_elem* polyadd(poly_elem* l1, poly_elem* l2) {

    poly_elem* sum = NULL;

    int length = 0;
    while (l1 != NULL)
    {
        poly_insert(l1->expo, l1->coef, length, sum);
        length++;
        l1 = l1->nast;
    }
    while (l2 != NULL)
    {
        poly_insert(l2->expo, l2->coef, length, sum);
        length++;
        l2 = l2->nast;
    }

    poly_elem* sortedHead = NULL;
    poly_elem* head = sum;

    while (head != NULL) {
        poly_elem* nextNode = head->nast;

        if (sortedHead == NULL || sortedHead->expo < head->expo) {
            // Wstaw na początek listy sortedHead
            head->nast = sortedHead;
            sortedHead = head;
        } else {
            // Wstaw w odpowiednie miejsce wewnątrz posortowanej listy
            poly_elem* sortedCurrent = sortedHead;
            while (sortedCurrent->nast != NULL && sortedCurrent->nast->expo > head->expo) {
                sortedCurrent = sortedCurrent->nast;
            }

            head->nast = sortedCurrent->nast;
            sortedCurrent->nast = head;
        }

        head = nextNode;
    }

    return sortedHead;
}

/**
 * Zadanie 7
 * Treść zadania jest pod linkiem: https://uniwersytetslaski-my.sharepoint.com/:i:/g/personal/arkadiusz_nowakowski_o365_us_edu_pl/ETlZwgdaIARIoeGKepwQZwMB6SSRuEJRvF03pOjU4NTdNg?e=tgoEhR
 */
struct farey_elem {
	int coun, deno;
    farey_elem* nast;
};
void farey_print(farey_elem* head) {
    cout<<"(";
    while (head != NULL)
    {
        cout<<head->coun<<"/"<<head->deno<<", ";
        head = head->nast;
    }
    cout<<")";
	
}
farey_elem* farey(int n) 
{
	farey_elem* head = new farey_elem;
    head->coun = 0;
    head->deno = 1;
    farey_elem* last = new farey_elem;
    last->coun = 1;
    last->deno = 1;
    last->nast = NULL;
    head->nast = last; 

    for(int i = 2; i<=n; ++i)
    {
        farey_elem* first = head;
        farey_elem* secound = head->nast;

        //first = head;
        //secound = head->nast;

        while (secound != NULL)
        {
            if(first->deno + secound->deno == i) 
            {
                farey_elem* temp = new farey_elem;
                temp->coun = first->coun + secound->coun;
                temp->deno = first->deno + secound->deno;
                first->nast = temp;
                temp->nast = secound;
            }
            first = secound;
            secound = secound->nast;
        }
        
    }
    return head;
}

int main()
{
    // [Odblokuj jak ukończysz zadanie 1.]
    elem* lista = NULL;
	insert(2, 0, lista);
	insert(1, 0, lista);
    insert(3, 2, lista);
	insert(4, 3, lista);
	insert(5, 4, lista);
	remove(0, lista);
	cout << "Pierwszy element: " << read(0, lista) << endl; // Oczekiwany wynik to 2.
	
	// [Odblokuj jak ukończysz zadanie 2.]
	cout << "Liczba elementow: " << size(lista) << endl; // Oczekiwany wynik to 4.
	
	// [Odblokuj jak ukończysz zadanie 3.]
	print(lista); // Oczekiwany wynik to 2, 3, 4, 5
	
	// [Odblokuj jak ukończysz zadanie 4.]
	destroy(lista);
	print(lista); // Oczekiwany wynik jest pusty
	
	// [Odblokuj jak ukończysz zadanie 5.]
	insert(1, 0, lista);
	insert(2, 1, lista);
	elem* t = search(2, lista);
	cout << "Znaleziony element: " << t->dane << endl;
	
	// [Odblokuj jak ukończysz zadanie 6.]
	poly_elem* w1 = NULL;
	poly_elem* w2 = NULL;
	poly_insert(2, 2, 0, w1);
	poly_insert(1, 3, 1, w1);
	poly_print(w1); // Oczekiwany wynik to (2x^2) + (3x^1)
	poly_insert(3, 1, 0, w2);
	poly_insert(2, 3, 1, w2);
	poly_print(w2); // Oczekiwany wynik to (1x^3) + (3x^2)
	poly_elem* o = polyadd(w1, w2);
    poly_print(o); // Oczekiwany wynik to (1x^3) + (5x^2) + (3x^1)
    
    // [Odkomentuj jak ukończysz zadanie 7.]
    farey_elem* farey3 = farey(3);
    farey_print(farey3); // Oczekiwane wyjście: (0/1, 1/3, 1/2, 2/3, 1/1)
    
    return 0;
}
