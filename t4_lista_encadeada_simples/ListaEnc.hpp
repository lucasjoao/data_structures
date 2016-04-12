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
			Elemento<T> *novo = new Elemento<T>(dado, NULL);

			if (novo == NULL) {
				throw "problema";
			} else {
				novo->setProximo(head);
				head = novo;
				size += 1;
			}
		}

		T retiraDoInicio() {
			T *volta;
			// Elemento<T> *saiu;

			if (listaVazia()) {
				return T(NULL);
			} else {
				/*
				saiu = head;
				*volta = saiu->getInfo();
				head = saiu->getProximo();
				size -= 1;
				saiu->~Elemento();
				return *volta;
				*/
				// CONSIGO MELHORAR ISSO PARA SO UMA VAR???
				*volta = head->getInfo();
				head = head->getProximo();
				size -= 1;
				saiu->~Elemento();
				return *volta;
			}
		}

		void eliminaDoInicio() {}

		//posicao
		void adicionaNaPosicao(const T &dado, int pos) {}

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
