/**
 *  Copyright [2016] - Lucas João Martins
 *
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
			destroiLista();
		}

		void adiciona(const T &dado) {
			if (listaVazia())
				adicionaNoInicio(dado);
			else
				adicionaNaPosicao(dado, size);
		}

		void adicionaNoInicio(const T &dado) {
			Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr);

			if (tmpElemento == nullptr) {
				throw "problema";
			} else {
				tmpElemento->setProximo(head);
				head = tmpElemento;
				size += 1;
			}
		}

		void adicionaNaPosicao(const T &dado, int pos) {
			if (pos > size) {
				throw "problema";
			} else {
				if (pos == 0) {
					adicionaNoInicio(dado);
				} else {
					Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr);
					Elemento<T> *antElemento;

					if (tmpElemento == nullptr) {
						throw "problema";
					} else {
						antElemento = head;

						while (--pos != 0)
							antElemento = antElemento->getProximo();

						tmpElemento->setProximo(antElemento->getProximo());
						antElemento->setProximo(tmpElemento);

						size += 1;
					}
				}
			}
		}

		void adicionaEmOrdem(const T &dado) {
			if (listaVazia()) {
				adicionaNoInicio(dado);
			} else {
				Elemento<T> *tmpElemento = head;

				int i = 0;
				for (; i < size; i++) {
					if (maior(tmpElemento->getInfo(), dado) ||
						tmpElemento->getProximo() == nullptr)
							break;

					tmpElemento = tmpElemento->getProximo();
				}

				adicionaNaPosicao(dado, i);
			}
		}

		T retira() {
			if (listaVazia())
				throw "problema";
			else
				return retiraDaPosicao(size-1);
		}

		T retiraDoInicio() {
			if (listaVazia()) {
				throw "problema";
			} else {
				Elemento<T> *tmpElemento = head;
				T tmpInfo = head->getInfo();
				head = head->getProximo();
				size -= 1;
				delete tmpElemento;
				return tmpInfo;
			}
		}

		T retiraDaPosicao(int pos) {
			if (pos >= size) {
				throw "problema";
			} else {
				if (pos == 0) {
					return retiraDoInicio();
				} else {
					Elemento<T> *antElemento, *tmpElemento;
					T tmpInfo;

					antElemento = head;

					while (--pos != 0)
						antElemento = antElemento->getProximo();

					tmpElemento = antElemento->getProximo();
					tmpInfo = tmpElemento->getInfo();
					antElemento->setProximo(tmpElemento->getProximo());
					size -= 1;
					delete tmpElemento;
					return tmpInfo;
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
			delete head;
			head = head->getProximo();
		}

		void destroiLista() {
			if (listaVazia()) {
				delete head;
			} else {
				Elemento<T> *tmpElemento = head;

				while (tmpElemento != nullptr) {
					tmpElemento = tmpElemento->getProximo();
					eliminaDoInicio();
					size -= 1;
				}
			}
		}

		int posicao(const T &dado) const {
			Elemento<T> *tmpElemento = head;

			int i = 0;

			for (; i < size; i++) {
				if (tmpElemento->getInfo() == dado)
					break;

				tmpElemento = tmpElemento->getProximo();
			}

			if (i == size)
				throw "problema";
			else
				return i;
		}

		T *posicaoMem(const T &dado) const {
			Elemento<T> *tmpElemento = head;

			int i = 0;
			for (; i < size; i++) {
				if (tmpElemento->getInfo() == dado)
					break;

				 tmpElemento = tmpElemento->getProximo();
			}

			if (i > size)
				throw "problema";
			else
				return &tmpElemento;
		}

		bool contem(const T &dado) {
			Elemento<T> *tmpElemento = head;

			while (tmpElemento != nullptr) {
				if (tmpElemento->getInfo() == dado)
					return true;

				tmpElemento = tmpElemento->getProximo();
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
