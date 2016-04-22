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

		void adicionaNaPosicaoDuplo(const T &dado, int pos) {}

		void adicionaDuplo(const T &dado) {
			if (listaVazia())
				adicionaNoInicioDuplo(dado);
			else
				adicionaNaPosicaoDuplo(dado, size);
		}

		void adicionaEmOrdem(const T &data) {}

		T retiraDoInicioDuplo() {}

		T retiraDaPosicaoDuplo(int pos) {}

		T retiraDuplo() {}

		T retiraEspecificoDuplo(const T &dado) {}

		int posicaoDuplo(const T& dado) const {}

		T* posicaoMemDuplo(const T &dado) const {}

		T mostra(int pos) {}

		int verUltimo() {}

		bool listaVazia() const {
			return size == 0;
		}

		bool contemDuplo(const T &dado) {}

		bool igual(T dado1, T dado2) {}

		bool maior(T dado1, T dado2) {}

		bool menor(T dado1, T dado2) {}

		void destroiListaDuplo() {}

		void eliminaDoInicioDuplo() {}
	private:
		Elemento<T> *head;
		int size;
};
