/**
 *  Copyright [2016] - Lucas João Martins
 *
 */

/**
 *  TODO
 duvidas trabalho
	conceito de destrutor melhor
	definições estranhas no elemento.hpp
	nullptr vs NULL
	revisar cada função para saber se eu conseguiria explicar e fazer um refactoring
	se tempo permitir, tentar não usar o nullptr
	como se chama um destrutor?
	keyword delete
	implementação de um destroi para o eliminaDoInicio
	entender com calma o for do algoritmo do adicionaNaPosicao
const_cast
entender função ponteiro
http://stackoverflow.com/questions/2346806/what-is-segmentation-fault
comentar que posicao antigo do lista.hpp tem problema
colocar para assistir vídeo aula no lugar daquela aula fuleira do mestrando
add para aprender passagem por valor, por referência e por nome (?). Essa última existe?

 */

#include "Elemento.hpp"

template<typename T>
class ListaEnc {
	public:
		ListaEnc() {
			size = 0;
			head = nullptr;
		}

		~ListaEnc() {
			// if (listaVazia())
				delete head;
			// else
				// destroiLista();
		}

		void adiciona(const T &dado) {
			if (listaVazia())
				adicionaNoInicio(dado);
			else
				adicionaNaPosicao(dado, size);
		}

		void adicionaNoInicio(const T &dado) {
			Elemento<T> *novoElemento = new Elemento<T>(dado, nullptr);

			if (novoElemento == nullptr) {
				throw "problema";
			} else {
				novoElemento->setProximo(head);
				head = novoElemento;
				size += 1;
			}
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
						antElemento->getProximo() == nullptr)
							break;
				}

				adicionaNaPosicao(dado, i+1);
			}
		}

		void adicionaNaPosicao(const T &dado, int pos) {
			if (pos > size + 1) {
				throw "problema";
			} else {
				if (pos == 1) {
					adicionaNoInicio(dado);
				} else {
					Elemento<T> *novoElemento = new Elemento<T>(dado, nullptr);
					Elemento<T> *antElemento;
					//  Elemento<T> *novoElemento, *antElemento;

					if (novoElemento == nullptr) {
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

		T retira() {
			if (listaVazia())
				throw "problema";
			else
				return retiraDaPosicao(size);
		}

		T retiraDoInicio() {
			//  Elemento<T> *saiu;
			T tmpInfo;

			if (listaVazia()) {
				throw "problema";
			} else {
				/*
				saiu = head;
				*tmpInfo = saiu->getInfo();
				head = saiu->getProximo();
				size -= 1;
				saiu->~Elemento();
				return *tmpInfo;
				*/

				tmpInfo = head->getInfo();
				head = head->getProximo();
				size -= 1;
				return tmpInfo;
			}
		}

		T retiraDaPosicao(int pos) {
			if (pos > size) {
				throw "problema";
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

		T retiraEspecifico(const T &dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				return retiraDaPosicao(posicao(dado));
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

		void destroiLista() {
			if (listaVazia()) {
				delete head;
			} else {
				Elemento<T> *atualElemento, *antElemento = head;

				while (atualElemento != nullptr) {
					antElemento = atualElemento;
					atualElemento = atualElemento->getProximo();
					antElemento->~Elemento();
					delete antElemento;
				}

				delete head;
			}
		}

		int posicao(const T &dado) const {
			Elemento<T> *antElemento = head;
			int i = 0;

			for (; i <= size; i++) {
				antElemento = antElemento->getProximo();

				/*
				if (const_cast<ListaEnc *>(this)->igual(antElemento->getInfo(), tmp))
					break;
				*/
				if (antElemento->getInfo() == dado)
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

		T *posicaoMem(const T &dado) const {
			Elemento<T> *antElemento = head;
			//  T &pos;
			int i = 0;

			for (; i <= size; i++) {
				antElemento = antElemento->getProximo();

				/*
				if (const_cast<ListaEnc *>(this)->igual(antElemento->getInfo(), tmp))
					break;
				*/
				if (antElemento->getInfo() == dado)
					break;
			}

			if (i > size)
				throw "problema";
			else
				return &antElemento;
		}

		bool contem(const T &dado) {
			Elemento<T> *antElemento = head;

			for (int i = 0; i <= size; i++) {
				antElemento = antElemento->getProximo();

				if (antElemento->getInfo() == dado)
					return true;
			}

			return false;
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

	private:
		Elemento<T> *head;
		int size;
};
