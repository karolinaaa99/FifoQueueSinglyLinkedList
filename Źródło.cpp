#include<iostream>

using namespace std;

class Elem 
{
private:
	int v; //key, data
	Elem* next_elem; //wskaznik na nastepny element
public:
	Elem(int x, Elem* n); //konstruktor, tworzy element przechowujacy x i posiadajacy wskaznik na nastepny element
	int value(); //zwraca key
	Elem* next(); //zwraca next_elem
	void setNext(Elem* p); //ustawia next_elem
};

Elem::Elem(int x, Elem* n)
{
	v = x;
	next_elem = n;
}

int Elem::value()
{
	return v;
}

Elem* Elem::next()
{
	return next_elem;
}

void Elem::setNext(Elem* p)
{
	next_elem = p;
}

class LFIFO 
{
private:
	Elem* head; //wskaznik na poczatek kolejki
	Elem* tail; //wskaznik na koniec kolejki
public:
	LFIFO(); //konstruktor, tworzy pusta kolejke
	bool empty(); //zwraca true, jesli kolejka jest pusta, false w przeciwnym razie
	void enqueue(int x); //dodaje element na koniec kolejki
	int dequeue();		//usuwa i zwraca daną z kolejki (usuwa z poczatku kolejki)
	void clear();       //usuwa cala kolejke
	friend ostream& operator<<(ostream& out, LFIFO& q); //wyswietla kolejke na ekranie konsoli
};

LFIFO::LFIFO()
{
	head = tail = NULL;
}

bool LFIFO::empty()
{
	if (head == NULL)
		return true;
	return false;
}

void LFIFO::enqueue(int x)
{
	if (empty())
	{
		Elem* p = new Elem(x, NULL);
		head = tail = p;
	}
	else
	{
		Elem* p = new Elem(x, NULL);
		tail->setNext(p);
		tail = p;
	}
}

int LFIFO::dequeue()
{
	if (empty())
		return NULL;
	else
	{
		Elem* p = head;
		int wartosc = head->value();
		head = head->next();
		delete p;
		return wartosc;
	}
}

void LFIFO::clear()
{
	int a = dequeue();
	while (a != NULL)
	{
		dequeue();
		a = dequeue();
	}
}

ostream& operator<<(ostream& out, LFIFO& q)
{
	Elem* temp = q.head;
	while (temp != NULL)
	{
		out << temp->value() << " ";
		temp = temp->next();
	}
	return out;
}

int main()
{
	LFIFO kolejka = LFIFO();

	kolejka.enqueue(1);
	kolejka.enqueue(2);
	kolejka.enqueue(3);
	kolejka.enqueue(4);
	kolejka.enqueue(5);
	kolejka.enqueue(6);
	cout << kolejka << endl;

	kolejka.dequeue();
	cout << kolejka << endl;

	kolejka.clear();
	cout << kolejka;

	return 0;
}