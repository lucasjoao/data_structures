/**
 *  Copyright [2016] - Lucas Joao Martins
 *  FilaEnc.hpp
 */

#include "ListaEnc.hpp"

template <typename T>
class FilaEnc : ListaEnc<T> {
	public:
		FilaEnc() {}

		FilaEnc<T>() {}

		~FilaEnc() {}

		void inclui(const T &dado) {}

		T retira() {}

		T ultimo() {}

		T primeiro() {}

		bool filaVazia() {}

		void limparFila() {}
};
