/**
 *  Copyright [2016] - Lucas Joao Martins
 *  ListaDupla.hpp
 */

#include "ElementoDuplo.hpp"

class ListaDupla {
	public:
		ListaDupla() {}

		~ListaDupla() {}

		void adicionaNoInicioDuplo(const T &dado) {}

		T retiraDoInicioDuplo() {}

		void eliminaDoInicioDuplo() {}

		void adicionaNaPosicaoDuplo(const T &dado, int pos) {}

		int posicaoDuplo(const T& dado) const {}

		T* posicaoMemDuplo(const T &dado) const {}

		bool contemDuplo(const T &dado) {}

		T retiraDaPosicaoDuplo(int pos) {}

		void adicionaDuplo(const T &dado) {}

		T retiraDuplo() {}

		T retiraEspecificoDuplo() {}

		T mostra(int pos) {}

		void adicionaEmOrdem(const T &data) {}

		int verUltimo() {}

		bool listaVazia() const {}

		bool igual(T dado1, T dado2) {}

		bool maior(T dado1, T dado2) {}

		bool menor(T dado1, T dado2) {}

		void destroiListaDuplo() {}
};
