#ifndef NO_AVL_HPP
#define NO_AVL_HPP

#include <vector>
#include "../t11_arvore_binaria_busca/NoBinario.hpp"

template <typename T>
class NoAVL : private NoBinario<T> {
	public:
		explicit NoAVL(const T &dado) { }
		virtual ~NoAVL() { }

		int getAltura() {
			return altura;
		}

		/*!
		 *  \brief Funcao getter getDado
		 *  \return o ponteiro para o dado do nodo.
		 */
		T *getDado() {
			return NoBinario<T>::getDado();
		}

		/*!
		 *  \brief Funcao getter getElementos
		 *  \return o vector de nodos binarios elementos.
		 */
		std::vector<NoAVL<T>*> getElementos() {
			return NoBinario<T>::getElementos();
		}

		/*!
		 *  \brief Funcao getter getEsquerda
		 *  \return o ponteiro para o nodo filho da esquerda.
		 */
		NoAVL<T> *getEsquerda() {
			return NoBinario<T>::getEsquerda();
		}

		/*!
		 *  \brief Funcao getter getDireita
		 *  \return o ponteiro para o nodo filho da direita.
		 */
		NoAVL<T> *getDireita() {
			return NoBinario<T>::getDireita();
		}

		T *busca(const T &dado, NoAVL<T> *arv) { }

		NoAVL<T> *inserir(const T &dado, NoAVL<T> *arv) { }

		NoAVL<T> *remover(NoAVL<T> *arv, const T &dado) { }

		NoAVL<T> *minimo(NoAVL<T> *nodo) { }

		void preOrdem(NoAVL<T> *nodo) {
			NoBinario<T>::preOrdem(nodo);
		}

		void emOrdem(NoAVL<T> *nodo) {
			NoBinario<T>::emOrdem(nodo);
		}

		void posOrdem(NoAVL<T> *nodo) {
			NoBinario<T>::preordem(nodo);
		}

	private:
		int altura; //!< representa a altura do no avl
};
#endif