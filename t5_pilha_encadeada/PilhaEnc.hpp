/**
 *  Copyright [2016] - Lucas Joao Martins
 *  PilhaEnc.hpp
 */

#include "ListaEnc.hpp"

template<typename T>
class PilhaEnc : public ListaEnc<T>{
    public:
        PilhaEnc() : ListaEnc<T>::ListaEnc() {}

        ~PilhaEnc() {
            limparPilha();
        }

        void empilha(const T& dado) {
            ListaEnc<T>::adicionaNoInicio(dado);
        }

        T desempilha() {
            return ListaEnc<T>::retiraDoInicio();
        }

    	T topo() {
            if (PilhaVazia()) {
                throw "problema";
            } else {
                Elemento<T> *tmpElemento = ListaEnc<T>::getHead();

                /*for (int i = 0; i < ListaEnc<T>::getSize(); i++)
                    tmpElemento = tmpElemento->getProximo();*/

                /*while (tmpElemento != nullptr) {
                    if (tmpElemento->getProximo() == nullptr)
                        return tmpElemento->getInfo();

                    tmpElemento = tmpElemento->getProximo();
                }*/

                // return tmpElemento->getInfo();

                // return T(NULL);
            }
        }

    	void limparPilha() {
            ListaEnc<T>::destroiLista();
        }

     	bool PilhaVazia() {
            return ListaEnc<T>::listaVazia();
        }
};
