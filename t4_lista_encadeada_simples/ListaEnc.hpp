/**
 *  Copyright [2016] - Lucas João Martins
 *
 */

/**
 *  TODO
 duvidas trabalho
	conceito de destrutor melhor
	definições estranhas no elemento.hpp
	nullptr vs null
	revisar cada função para saber se eu conseguiria explicar e fazer um refactoring
	se tempo permitir, tentar não usar o null
	como se chama um destrutor?
	keyword delete
	implementação de um destroi para o eliminaDoInicio
	entender com calma o for do algoritmo do adicionaNaPosicao
mudar ordem das paradas
comentar que posicao antigo do lista.hpp tem problema
colocar para assistir vídeo aula no lugar daquela aula fuleira do mestrando
add para aprender passagem por valor, por referência e por nome (?). Essa última existe?

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

		~ListaEnc() {
			delete head;
		}

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
					Elemento<T> *novoElemento = new Elemento<T>(dado, NULL);
					Elemento<T> *antElemento;
					//  Elemento<T> *novoElemento, *antElemento;

					if (novoElemento == NULL) {
						throw "problema";
					} else {
						antElemento = head;

						for (int i = 0; i < pos - 2; i++)
							antElemento = antElemento->getProximo();

						//  novoElemento =  new Elemento<T>(dado, antElemento->getProximo());
						novoElemento->setProximo(antElemento->getProximo());
						antElemento->setProximo(novoElemento);
						size += 1;
					}
				}
			}
		}

		int posicao(const T &dado) const {
			Elemento<T> *antElemento = head;
			int i = 0;

			T tmp = dado;

			for (; i <= size; i++) {
				antElemento = antElemento->getProximo();

				if (igual(antElemento->getInfo(), tmp))
					break;
			}

			if (i > size)
				throw "problema";
			else
				return i;

			/*
			if (!contem(dado)) {
				throw "problema";
			} else {
				Elemento<T> *antElemento = head;
				int i = 0;

				for (; i <= size; i++) {
					antElemento = antElemento->getProximo();

					if (igual(antElemento->getInfo(), dado))
						break;
				}

				return i;
			}*/
		}

		T *posicaoMem(const T &dado) const {}

		bool contem(const T &dado) {
			Elemento<T> *antElemento = head;

			for (int i = 0; i <= size; i++) {
				antElemento = antElemento->getProximo();

				if (igual(antElemento->getInfo(), dado))
					return true;
			}

			return false;
		}

		T retiraEspecifico(const T &dado) {}

		T retiraDaPosicao(int pos) {
			if (pos > size) {
				return T(NULL);
			} else {
				if (pos == 1) {
					return retiraDoInicio();
				} else {
					Elemento<T> *antElemento, *elimElemento;
					T volta;

					antElemento = head;

					for (int i = 0; i < pos - 2; i++)
						antElemento = antElemento->getProximo();

					elimElemento = antElemento->getProximo();
					volta = elimElemento->getInfo();
					antElemento->setProximo(elimElemento->getProximo());
					size -= 1;
					delete elimElemento;
					return volta;

				}
			}
		}

		void adiciona(const T &dado) {
			if (listaVazia())
				adicionaNoInicio(dado);
			else
				adicionaNaPosicao(dado, size);
		}

		T retira() {
			if (listaVazia())
				return T(NULL);
			else
				return retiraDaPosicao(size);
		}

		void adicionaEmOrdem(const T &dado) {
			if (listaVazia()) {
				adicionaNoInicio(dado);
			} else {
				Elemento<T> *antElemento = head;

				int i = 0;

				for (; i <= size; i++) {
					antElemento = antElemento->getProximo();

					if (maior(antElemento->getInfo(), dado) ||
						antElemento->getProximo() == NULL)
							break;
				}

				adicionaNaPosicao(dado, i+1);
			}
		}

		bool listaVazia() const {
			return size == 0;
		}

		bool igual(T dado1, T dado2) {
			return dado1 == dado2;
		}

		bool maior(T dado1, T dado2) {
			return dado1 > dado2;
		}

		bool menor(T dado1, T dado2) {
			return dado1 < dado2;
		}

		void destroiLista() {}

	private:
		Elemento<T> *head;
		int size;
};
