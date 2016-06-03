#ifndef NO_AVL_HPP
#define NO_AVL_HPP

#include <vector>
#include <algorithm>
#include "../t11_arvore_binaria_busca/NoBinario.hpp"

template <typename T>
class NoAVL : private NoBinario<T> {
	public:
		explicit NoAVL(const T &dado)
			: NoBinario<T>::NoBinario<T>(dado), altura(0) {}

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
			return (NoAVL<T> *) NoBinario<T>::getEsquerda();
		}

		/*!
		 *  \brief Funcao getter getDireita
		 *  \return o ponteiro para o nodo filho da direita.
		 */
		NoAVL<T> *getDireita() {
			return (NoAVL<T> *) NoBinario<T>::getDireita();
		}

		void setEsquerda(NoAVL<T> *esq) {
			NoBinario<T>::setEsquerda(esq);
		}

		void setDireita(NoAVL<T> *dir) {
			NoBinario<T>::setDireita(dir);
		}

		void setAltura(int alt) {
			altura = alt;
		}

		int alturaNo(NoAVL<T> *nodo) {
			return nodo == nullptr ? -1 : nodo->getAltura();
		}

		T *busca(const T &dado, NoAVL<T> *arv) {
			return NoBinario<T>::busca(dado, arv);
		}

		NoAVL<T> *inserir(const T &dado, NoAVL<T> *arv) { }

		NoAVL<T> *remover(NoAVL<T> *arv, const T &dado) { }

		NoAVL<T> *minimo(NoAVL<T> *nodo) {
			return (NoAVL<T> *) NoBinario<T>::minimo(nodo);
		}

		void preOrdem(NoAVL<T> *nodo) {
			NoBinario<T>::preOrdem(nodo);
		}

		void emOrdem(NoAVL<T> *nodo) {
			NoBinario<T>::emOrdem(nodo);
		}

		void posOrdem(NoAVL<T> *nodo) {
			NoBinario<T>::preordem(nodo);
		}

		NoAVL<T> *rotacaoEsqSimples(NoAVL<T> *arv) {
			if (arv->getEsquerda() != nullptr) {
				NoAVL<T> *arvTmp = arv->getEsquerda();
				arv->setEsquerda(arvTmp->getDireita());
				arvTmp->setDireita(arv);

				//
				// DA DE QUEBRAR ESSAS LINHAS?
				//
				arv->setAltura(max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);
				arvTmp->setAltura(max(alturaNo(arvTmp->getEsquerda()), alturaNo(arvTmp->getDireita())) + 1);

				return arvTmp;
			} else {
				throw "ERRO!";
			}
		}

		NoAVL<T> *rotacaoDirSimples(NoAVL<T> *arv) {
			if (arv->getDireita() != nullptr) {
				NoAVL<T> *arvTmp = arv->getDireita();
				arv->setDireita(arvTmp->getEsquerda());
				arvTmp->setEsquerda(arv);

				//
				// DA DE QUEBRAR ESSAS LINHAS?
				//
				arv->setAltura(max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);
				arvTmp->setAltura(max(alturaNo(arvTmp->getEsquerda()), alturaNo(arvTmp->getDireita())) + 1);

				return arvTmp;
			} else {
				throw "ERRO!";
			}
		}

	private:
		int altura; //!< representa a altura do no avl
};
#endif