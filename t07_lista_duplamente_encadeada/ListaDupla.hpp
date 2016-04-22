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

		~ListaDupla() {}

		void adicionaNoInicioDuplo(const T &dado) {}

		void adicionaNaPosicaoDuplo(const T &dado, int pos) {}

		void adicionaDuplo(const T &dado) {}

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
