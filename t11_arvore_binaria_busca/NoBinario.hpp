#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>
#include <iostream>

template<typename T>
class NoBinario {
	public:
		NoBinario<T>(const T &dado) :										dado(new T(dado)), esquerda(nullptr), direita(nullptr) {}

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

		NoBinario<T> *setEsquerda(NoBinario<T> *esq) {
			esquerda = esq;
		}

		NoBinario<T> *setDireita(NoBinario<T> *dir) {
			direita = dir;
		}

		T *busca(const T &dado, NoBinario<T> *arv) {
			while (arv != nullptr && dado != *arv->getDado()) {
				if (*arv->getDado() < dado)
					arv = arv->getDireita();
				else
					arv = arv->getEsquerda();
			}

			// if ()
			return arv->getDado();
		}

		NoBinario<T> *inserir(const T &dado, NoBinario<T> *arv) {
			NoBinario<T> *tmpArv;

			if (dado < *arv->getDado()) {  //!< insere a esquerda
				if (arv->getEsquerda() == nullptr) {
					tmpArv = new NoBinario<T>(dado);
					arv->setEsquerda(tmpArv);
				} else {
					arv = inserir(dado, arv->getEsquerda());
				}
			} else {                     //!< insere a direita
				if (arv->getDireita() == nullptr) {
					tmpArv = new NoBinario<T>(dado);
					arv->setDireita(tmpArv);
				} else {
					arv = inserir(dado, arv->getDireita());
				}
			}
		}

		NoBinario<T> *remover(NoBinario<T> *arv, const T &dado) {}

		NoBinario<T> *minimo(NoBinario<T> *nodo) {}

		void preOrdem(NoBinario<T> *nodo) {
			if (nodo != nullptr) {
				// printf("a");
			}
		}

		void emOrdem(NoBinario<T> *nodo) {}

		void posOrdem(NoBinario<T> *nodo) {}

	protected:
		T *dado;
		NoBinario<T> *esquerda;
		NoBinario<T> *direita;
		std::vector<NoBinario<T>*> elementos;  //!< elementos acessados durante
											  // o percurso realizado
};
#endif