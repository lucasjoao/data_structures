/**
 *  Copyright [2016] - Lucas João Martins
 *
 */

#include "Elemento.hpp"

template<typename T>
class ListaEnc {
	public:
		/**
		 *  se head e nulo, quer dizer que nao houve espaco na memoria
		 */
		ListaEnc() {
			ListaEnc *list = new ListaEnc();
			if (list != NULL) {
				list->size = 0;
				list->head = NULL;
			}
		}

		~ListaEnc() {}

		void adicionaNoInicio(const T &dado) {
			Elemento<T> *novoElemento = new Elemento<T>(dado, NULL);

			if (novoElemento == NULL) {
				throw "problema";
			} else {
				novoElemento->setProximo(head);
				head = novoElemento;
				size += 1;
			}
		}

		T retiraDoInicio() {
			//  Elemento<T> *saiu;

			if (listaVazia()) {
				return T(NULL);
			} else {
				T *tmpInfo;
				/*
				saiu = head;
				*tmpInfo = saiu->getInfo();
				head = saiu->getProximo();
				size -= 1;
				saiu->~Elemento();
				return *tmpInfo;
				*/

				*tmpInfo = head->getInfo();
				head = head->getProximo();
				size -= 1;
				return *tmpInfo;
			}
		}

		void eliminaDoInicio() {
			//  Elemento<T> *tmpElemento;

			if (listaVazia()) {
				throw "problema";
			} else {
				/*
				tmpElemento = head;
				head = tmpElemento->getProximo();
				size -= 1;
				delete tmpElemento->getInfo();
				delete tmpElemento;
				return size;
				*/

				delete head->getInfo();
				head = head->getProximo();
				size -= 1;
				return size;
			}
		}

		void adicionaNaPosicao(const T &dado, int pos) {
			if (pos > size + 1) {
				throw "problema";
			} else {
				if (pos == 1) {
					adicionaNoInicio(dado);
				} else {
					//  Elemento<T> *novoElemento = new Elemento<T>(dado, NULL);
					//  Elemento <T> *antElemento;
					Elemento<T> *novoElemento, *antElemento;

					if (novoElemento == NULL) {
						throw "problema";
					} else {
						antElemento = head;

						for (int i = 0; i <= pos - 2; i++)
							antElemento = antElemento->getProximo();

						novoElemento =  new Elemento<T>(dado, antElemento->getProximo());
						antElemento->setProximo(novoElemento);
						size += 1;
					}
				}
			}
		}

		int posicao(const T &dado) const {}

		T *posicaoMem(const T &dado) const {}

		bool contem(const T &dado) {}

		T retiraDaPosicao(int pos) {}

		//fim
		void adiciona(const T &dado) {}

		T retira() {}

		//especifico
		T retiraEspecifico(const T &dado) {}

		void adicionaEmOrdem(const T &data) {}

		bool listaVazia() const {
			return size == 0;
		}

		bool igual(T dado1, T dado2) {}

		bool maior(T dado1, T dado2) {}

		bool menor(T dado1, T dado2) {}

		void destroiLista() {}

	private:
		Elemento<T> *head;
		int size;
};
