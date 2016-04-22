/**
 *  Copyright [2016] - Lucas Joao Martins
 *  FilaEnc.hpp
 */

#include "ListaEnc.hpp"

template <typename T>
class FilaEnc : ListaEnc<T> {
	public:
		FilaEnc<T>() : ListaEnc<T>::ListaEnc() {}

		~FilaEnc() {
			limparFila();
		}

		void inclui(const T &dado) {
			Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr);

			if (tmpElemento == nullptr) {
				throw "problema";
			} else {
				if (filaVazia())
					ListaEnc<T>::setHead(tmpElemento);
				else
					ListaEnc<T>::getTail()->setProximo(tmpElemento);

				ListaEnc<T>::setTail(tmpElemento);
				ListaEnc<T>::setSize(ListaEnc<T>::getSize() + 1);
			}
		}

		T retira() {
			if (ListaEnc<T>::getSize() == 1)
				ListaEnc<T>::setTail(nullptr);

			return ListaEnc<T>::retiraDoInicio();
		}

		T ultimo() {
			if (filaVazia())
				throw "problema";
			else
				return ListaEnc<T>::getTail()->getInfo();
		}

		T primeiro() {
			if (filaVazia())
				throw "problema";
			else
				return ListaEnc<T>::getHead()->getInfo();
		}

		bool filaVazia() {
			return ListaEnc<T>::listaVazia();
		}

		void limparFila() {
			ListaEnc<T>::destroiLista();
		}
};
