#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;

    public:
        LList() { // Esto no va a compilar
			start = NULL;
		};

		T front() {
			if (start == NULL) throw 'Lista Vac�a';
			else start->data;
		};

		T back() {
			if (start == NULL) throw 'Lista Vac�a';
			else start->prev->data;
		};
		void push_front(T value) {
			Node <T>* temp = new Node <T>;
			temp->data = value;
			temp->next = start;
			if (start == NULL) {
				temp->prev = temp->next = temp;
			}
			else {
				temp->prev = start->prev;
				temp->prev->next = temp;
				start->prev = temp;
			}
			start = temp;
		};
		void push_back(T value) {
			Node <T>* temp = new Node <T>;
			temp->data = value;
			temp->next = start;
			if (start == NULL) {
				temp->prev = temp->next = temp;
			}
			else {
				temp->prev = start->prev;
				temp->prev->next = temp;
				start->prev = temp;
			}
		};
		void pop_front() {
			Node <T>* temp = start; // Te falta controlar casos
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			start = temp->next;
			delete temp;

		};
		void pop_back() {
			Node <T>* temp = start->prev; // Te falta controlar casos
			temp->prev->next = start;
			start->prev = temp->prev;
			delete temp;
		};
		T get(int position) {
			if (position >= size()) position = position % size();
			if (position < 0) throw "Error en la posici�n";
			else {
				Node <T>* temp = start;
				for (int i = 0; i < position; i++) {
					temp = temp->next;
				}
				return temp->data;
			}

		};

		void concat(List<T> &other) { // Falta implementar
		};

		bool empty() {
			return(start == NULL);
		};
		int size() {
			int i = 1;
			Node <T>* temp = start;
			if (start == NULL) return 0;
			else {
				while (temp->next != start) {
					i++;
					temp = temp->next;
				}
				return (i);
			}
		};
		void clear() {
			start->killSelf(); // Esto no funciona en una lista circular
			start = NULL;
		};
		Iterator<T> begin() {
			return Iterator<T>(start);
		};
		Iterator<T> end() {
			return Iterator<T>(start->prev);
		};

		~List() {
			clear(); // No va a funcionar en la manera que lo implementaste
		};
};

#endif