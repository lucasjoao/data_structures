/**
 *  Copyright [2016] - Lucas Joao Martins
 *  ListaDupla.hpp
 */

#include "ElementoDuplo.hpp"

template<typename T>
class ListaDupla {
	public:
		ListaDupla() {
			size = 0;
			head = nullptr;
		}

		~ListaDupla() {
			destroiListaDuplo();
		}

		void adicionaNoInicioDuplo(const T &dado) {
			Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr, nullptr);

			if (tmpElemento == nullptr) {
				throw "problema";
			} else {
				tmpElemento->setProximo(head);
				if (head != nullptr)
					head->setBack(tmpElemento);
				head = tmpElemento;
				size += 1;
			}
		}

		void adicionaNaPosicaoDuplo(const T &dado, int pos) {
			if (pos > size) {
				throw "problema";
			} else {
				if (pos == 0) {
					adicionaNoInicioDuplo(dado);
				} else {
					Elemento<T> *tmp = new Elemento<T>(dado, nullptr, nullptr);
					Elemento<T> *antElemento;

					if (tmp == nullptr) {
						throw "problema";
					} else {
						antElemento = head;

						while (--pos != 0)
							antElemento = antElemento->getProximo();

						tmp->setProximo(antElemento->getProximo());

						if (tmp->getProximo() != nullptr)
							tmp->getProximo()->setBack(tmp);

						antElemento->setProximo(tmp);
						tmp->setBack(antElemento);
						size += 1;
					}
				}
			}
		}

		void adicionaDuplo(const T &dado) {
			if (listaVazia())
				adicionaNoInicioDuplo(dado);
			else
				adicionaNaPosicaoDuplo(dado, size);
		}

		void adicionaEmOrdem(const T &data) {
			if (listaVazia()) {
				adicionaNoInicioDuplo(data);
			} else {
				Elemento<T> *tmpElemento = head;

				int i = 0;
				for (; i < size; i++) {
					if (maior(tmpElemento->getInfo(), data) ||
						tmpElemento->getProximo() == nullptr)
							break;

					tmpElemento = tmpElemento->getProximo();
				}

				adicionaNaPosicaoDuplo(data, i);
			}
		}

		T retiraDoInicioDuplo() {
			if (listaVazia()) {
				throw "problema";
			} else {
				Elemento<T> *tmpElemento = head;
				T tmpInfo = head->getInfo();
				head = head->getProximo();

				if (head != nullptr)
					head->setBack(nullptr);

				size -= 1;
				delete tmpElemento;
				return tmpInfo;
			}
		}

		T retiraDaPosicaoDuplo(int pos) {
			if (pos >= size) {
				throw "problema";
			} else {
				if (pos == 0) {
					return retiraDoInicioDuplo();
				} else {
					Elemento<T> *antElemento, *tmpElemento;
					T tmpInfo;

					antElemento = head;

					while (--pos != 0)
						antElemento = antElemento->getProximo();

					tmpElemento = antElemento->getProximo();
					tmpInfo = tmpElemento->getInfo();
					antElemento->setProximo(tmpElemento->getProximo());

					if (tmpElemento->getProximo() != nullptr)
						tmpElemento->getProximo()->setBack(antElemento);

					size -= 1;
					delete tmpElemento;
					return tmpInfo;
				}
			}
		}

		T retiraDuplo() {
			if (listaVazia())
				throw "problema";
			else
				return retiraDaPosicaoDuplo(size-1);
		}

		T retiraEspecificoDuplo(const T &dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				return retiraDaPosicaoDuplo(posicaoDuplo(dado));
			}
		}

		int posicaoDuplo(const T& dado) const {
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

		T* posicaoMemDuplo(const T &dado) const {}

		T mostra(int pos) {}

		int verUltimo() {}

		bool listaVazia() const {
			return size == 0;
		}

		bool contemDuplo(const T &dado) {
			Elemento<T> *tmpElemento = head;

			while (tmpElemento != nullptr) {
				if (igual(tmpElemento->getInfo(), dado))
					return true;

				tmpElemento = tmpElemento->getProximo();
			}

			return false;
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

		void destroiListaDuplo() {
			if (listaVazia()) {
				delete head;
			} else {
				Elemento<T> *tmpElemento = head;

				while (tmpElemento != nullptr) {
					tmpElemento = tmpElemento->getProximo();
					eliminaDoInicioDuplo();
					size -= 1;
				}
			}
		}

		void eliminaDoInicioDuplo() {
			delete head;
			head = head->getProximo();
		}
	private:
		Elemento<T> *head;
		int size;
};
