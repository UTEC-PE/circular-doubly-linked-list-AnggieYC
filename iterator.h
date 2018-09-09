#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;
    
    public:
		Iterator() {
			current = NULL;
		};
		Iterator(Node<T>* node) {
			current = node;
		};

		Iterator<T> operator=(Iterator<T> node) { // return current? Esto no va a compilar
			current = node.current;
			return *current;
		};
		bool operator!=(Iterator<T> cmp) {
			return(current != cmp.current);
		};
		Iterator<T> operator++() {
			current = current->next;
			return *current; // return current? Esto no va a compilar
		};
		Iterator<T> operator--() {
			current = current->prev;
			return *current; // return current? Esto no va a compilar
		};
		T operator*() {
			return (current->data;)
		};
};

#endif