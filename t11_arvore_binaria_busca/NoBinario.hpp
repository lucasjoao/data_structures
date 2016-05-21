#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>

template<typename T>
class NoBinario {
	public:
		NoBinario<T>(const T &dado) {}

		virtual ~NoBinario() {}

		T *getDado() {
			return dado;
		}

		std::vector<NoBinario<T>*> getElementos() {
			return elementos;
		}

		NoBinario<T> *getEsquerda() {
			return esquerda;
		}

		NoBinario<T> *getDireita() {
			return direita;
		}

		T *busca(const T &dado, NoBinario<T> *arv) {}

		NoBinario<T> *inserir(const T &dado, NoBinario<T> *arv) {}

		NoBinario<T> *remover(NoBinario<T> *arv, const T &dado) {}

		NoBinario<T> *minimo(NoBinario<T> *nodo) {}

		void preOrdem(NoBinario<T> *nodo) {}

		void emOrdem(NoBinario<T> *nodo) {}

		void posOrdem(NoBinario<T> *nodo) {}
	protected:
		T *dado;
		NoBinario<T> *esquerda;
		NoBinario<T> *direita;
		std::vector<NoBinario<T>*> elementos  //!< elementos acessados durante
											  // o percurso realizado
};