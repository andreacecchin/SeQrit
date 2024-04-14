#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array {
    private:
        T* memoria;
        unsigned int capacita;
        unsigned int size;
    public:
        Array();
        ~Array();
        typedef T* iterator;

        void aggiungi(const T&);
        void cancella(const unsigned int&);
        int cercapos(const T&) const;
        iterator begin() const;
        iterator end() const;

        T& operator[](const unsigned int&) const;
};

template<class T>
Array<T>::Array(): memoria(nullptr), capacita(0), size(0){}

template<class T>
void Array<T>::aggiungi(const T& aggiunta) {
    if(size >= capacita) {
        if (capacita == 0) capacita = 1;
        else capacita = capacita*2;
        T* memoriatmp = new T[capacita];
        for(unsigned int i = 0; i < size; ++i) {
            memoriatmp[i] = memoria[i];
        }
        delete[] memoria;
        memoria = memoriatmp;
    }
    memoria[size] = aggiunta;
    size++;
}

template<class T>
void Array<T>::cancella(const unsigned int &pos) {
    unsigned int newpos = 0;
    T* memoriatmp = new T[capacita];
    for(unsigned int i = 0; i < size; ++i) {
        if(i != pos) {
            memoriatmp[newpos] = memoria[i];
            ++newpos;
        }
    }
    size--;
    delete[] memoria;
    memoria = memoriatmp;
}

template<class T>
typename Array<T>::iterator Array<T>::begin() const {
    return memoria;
}

template<class T>
typename Array<T>::iterator Array<T>::end() const {
    return memoria+size;
}

template<class T>
T& Array<T>::operator[](const unsigned int& pos) const {
    return memoria[pos];
}

template<class T>
int Array<T>::cercapos(const T& ricercato) const {
    for(unsigned int i = 0; i < size; ++i) {
        if(memoria[i] == ricercato) {
            return i;
        }
    }
    return -1;
}

template<class T>
Array<T>::~Array() {
    if(memoria) {
        delete[] memoria;
    }
}

#endif
