/**
 *  Copyright [2016] - Lucas Joao Martins
 *  PilhaEnc.hpp
 */

#include "ListaEnc.hpp"

template<typename T>
class PilhaEnc : ListaEnc<T> {
	public:
		PilhaEnc() : ListaEnc<T>::ListaEnc() {}

		~PilhaEnc() {
			limparPilha();
		}

		void empilha(const T &dado) {
			ListaEnc<T>::adicionaNoInicio(dado);
		}

	T desempilha() {
		return ListaEnc<T>::retiraDoInicio();
	}

	T topo() {
		if (PilhaVazia())
			throw "problema";
		else
			return ListaEnc<T>::getHead()->getInfo();
	}

	void limparPilha() {
		ListaEnc<T>::destroiLista();
	}

	bool PilhaVazia() {
		return ListaEnc<T>::listaVazia();
	}
};
