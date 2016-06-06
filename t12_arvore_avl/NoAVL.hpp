#ifndef NO_AVL_HPP
#define NO_AVL_HPP

#include <vector>
#include <algorithm>
#include <cmath>
#include "../t11_arvore_binaria_busca/NoBinario.hpp"

template <typename T>
class NoAVL : private NoBinario<T> {
	public:
		explicit NoAVL(const T &dado)
			: NoBinario<T>::NoBinario(dado), altura(0) {}

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

		// VERIFICAR ISSO AQUI
		void getElementos() {
			NoBinario<T>::getElementos();
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

		T *busca(const T &dado, NoAVL<T> *arv) {
			return NoBinario<T>::busca(dado, arv);
		}

		bool checkNullptr(NoBinario<T> *arv) {
			return arv == nullptr ? true : false;
		}

		NoAVL<T> *inserir(const T &dado, NoAVL<T> *arv) {
			NoAVL<T> *tmpArv;

			if (dado < *arv->getDado()) {  //!< insere a esquerda
				if (checkNullptr(arv->getEsquerda())) {
					tmpArv = new NoAVL<T>(dado);
					if (checkNullptr(tmpArv))
						throw "sem espaço na memória!";
					else
						arv->setEsquerda(tmpArv);
				} else {
					arv = inserir(dado, arv->getEsquerda());

					if (abs((alturaNo(arv->getEsquerda()) - alturaNo(arv->getDireita()))) > 1) {
						if (arv->getEsquerda()->getEsquerda() == nullptr)
							arv = rotacaoEsqDupla(arv);
						else
							arv = rotacaoEsqSimples(arv);
					} // else {
						// arv->setAltura(std::max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);
					// }
					// MELHORAR ESSA PARTE!!!
				}
			} else {                       //!< insere a direita
				if (checkNullptr(arv->getDireita())) {
					tmpArv = new NoAVL<T>(dado);
					if (checkNullptr(tmpArv))
						throw "sem espaço na memória!";
					else
						arv->setDireita(tmpArv);
				} else {
					arv = inserir(dado, arv->getDireita());

					if (abs((alturaNo(arv->getEsquerda()) - alturaNo(arv->getDireita()))) > 1) {
						if (arv->getDireita()->getDireita() == nullptr)
							arv = rotacaoDirDupla(arv);
						else
							arv = rotacaoDirSimples(arv);
					} // else {
						// arv->setAltura(std::max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);
					// }
					// MELHORAR ESSA PARTE!!!
				}
			}

			// MELHORAR ESSA PARTE!!!
			arv->setAltura(std::max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);
			return arv;
		}

		NoAVL<T> *remover(NoAVL<T> *arv, const T &dado) {
			NoAVL<T> *tmpArv = arv;
			NoAVL<T> *filhoArv;

			if (dado < *arv->getDado()) {
				/* busca do nodo a ser removido */
				arv->setEsquerda(remover(arv->getEsquerda(), dado));
			} else if (*arv->getDado() < dado) {
				/* busca do nodo a ser removido */
				arv->setDireita(remover(arv->getDireita(), dado));
			} else if (!checkNullptr(arv->getEsquerda())
						&& !checkNullptr(arv->getDireita())) {
				/* dois filhos */
				tmpArv = minimo(arv->getDireita());
				arv->setDado(tmpArv->getDado());
				arv->setDireita(remover(arv->getDireita(), *arv->getDado()));
			} else if (!checkNullptr(arv->getDireita())) {
				/* filho na direita */
				filhoArv = arv->getDireita();
				delete tmpArv;
				return filhoArv;
			} else if (!checkNullptr(arv->getEsquerda())) {
				/* filho na esquerda */
				filhoArv = arv->getEsquerda();
				delete tmpArv;
				return filhoArv;
			} else {
				/* sem filhos */
				delete tmpArv;
				return nullptr;
			}

			// arv->setAltura(std::max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);

			// errado, não serve para todos -- arrumar!
			if (abs((alturaNo(arv->getEsquerda()) - alturaNo(arv->getDireita()))) > 1) {
				if (arv->getDireita() == nullptr) {
					if (arv->getEsquerda()->getEsquerda() == nullptr)
						arv = rotacaoEsqDupla(arv);
					else
						arv = rotacaoEsqSimples(arv);
				} else if (arv->getEsquerda() == nullptr) {
					if (arv->getDireita()->getDireita() == nullptr)
						arv = rotacaoDirDupla(arv);
					else
						arv = rotacaoDirSimples(arv);
				}
			}

			arv->setAltura(std::max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);

			return arv;
		}

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
			NoBinario<T>::preOrdem(nodo);
		}

		int alturaNo(NoAVL<T> *nodo) {
			return nodo == nullptr ? -1 : nodo->getAltura();
		}

		NoAVL<T> *rotacaoEsqSimples(NoAVL<T> *arv) {
			if (arv->getEsquerda() != nullptr) {
				NoAVL<T> *arvTmp = arv->getEsquerda();
				arv->setEsquerda(arvTmp->getDireita());
				arvTmp->setDireita(arv);

				//
				// DA DE QUEBRAR ESSAS LINHAS?
				//
				arv->setAltura(std::max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);
				arvTmp->setAltura(std::max(alturaNo(arvTmp->getEsquerda()), alturaNo(arvTmp->getDireita())) + 1);

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
				arv->setAltura(std::max(alturaNo(arv->getEsquerda()), alturaNo(arv->getDireita())) + 1);
				arvTmp->setAltura(std::max(alturaNo(arvTmp->getEsquerda()), alturaNo(arvTmp->getDireita())) + 1);

				return arvTmp;
			} else {
				throw "ERRO!";
			}
		}

		NoAVL<T> *rotacaoEsqDupla(NoAVL<T> *arv) {
			//
			// DA DE QUEBRAR ESSAS LINHAS?
			//
			if (arv->getEsquerda() != nullptr && arv->getEsquerda()->getDireita() != nullptr) {
				arv->setEsquerda(rotacaoDirSimples(arv->getEsquerda()));
				return rotacaoEsqSimples(arv);
			} else {
				throw "ERRO!";
			}
		}

		NoAVL<T> *rotacaoDirDupla(NoAVL<T> *arv) {
			//
			// DA DE QUEBRAR ESSAS LINHAS?
			//
			if (arv->getDireita() != nullptr && arv->getDireita()->getEsquerda() != nullptr) {
				arv->setDireita(rotacaoEsqSimples(arv->getDireita()));
				return rotacaoDirSimples(arv);
			} else {
				throw "ERRO!";
			}
		}

	private:
		int altura; //!< representa a altura do no avl
};
#endif