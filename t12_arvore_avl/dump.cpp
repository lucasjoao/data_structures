//!< balanceia da net
	fixAltura(arv);
	if (varBalanco(arv) == -2) {
		if (varBalanco(arv->getDireita()) > 0) {
			// return rotacao_dupla_getDireita()(arv);
			arv->setDireita(rotacaoDirSimples(arv->getDireita()));
		}
		arv = rotacaoEsqSimples(arv);
		return arv;
	}
	if (varBalanco(arv) == 2) {
		if (varBalanco(arv->getEsquerda()) < 0) {
			// return rotacao_dupla_esquerda(arv);
			arv->setEsquerda(rotacaoEsqSimples(arv->getEsquerda()));
		}
		arv = rotacaoDirSimples(arv);
		return arv;
	}
	return arv;

//!< inserir com arg nodo pai, principal inserir a chama com pai nullptr
	NoAVL<T> *inserirAVL(const T &dado, NoAVL<T> *arv, NoAVL<T> *arvPai) {
		NoAVL<T> *tmpArv;

		if (checkNullptr(arv)) {
			arv = new NoAVL<T>(dado);
			if (checkNullptr(arv))
				throw "sem espaço na memória!";
		} else {
			if (dado < *arv->getDado()) {
				arv->setEsquerda(inserirAVL(dado, arv->getEsquerda(), arv));
				if (varBalanco(arv) > 1) {
					if (dado < *arv->getEsquerda()->getDado())
						tmpArv = rotacaoEsqSimples(arv);
					else
						tmpArv = rotacaoEsqDupla(arv);

					if (arvPai->getEsquerda() == arv)
						arvPai->setEsquerda(tmpArv);
					else
						arvPai->setDireita(tmpArv);
				} else {
					fixAltura(arv);
				}
			} else {
				if (*arv->getDado() < dado) {
					arv->setDireita(inserirAVL(dado, arv->getDireita(), arv));
					if (alturaNo(arv->getDireita()) - alturaNo(arv->getEsquerda()) > 1) {
						if (dado < *arv->getEsquerda()->getDado())
							tmpArv = rotacaoDirSimples(arv);
						else
							tmpArv = rotacaoDirDupla(arv);

						if (arvPai->getDireita() == arv)
							arvPai->setDireita(tmpArv);
						else
							arvPai->setEsquerda(tmpArv);
					} else {
						fixAltura(arv);
					}
				} else {
					throw "fuck";
				}
			}
		}
		return arv;
	}

//!< inserir estilo bst
	if (dado < *arv->getDado()) {  //!< insere a esquerda
		if (checkNullptr(arv->getEsquerda())) {
			tmpArv = new NoAVL<T>(dado);
			if (checkNullptr(tmpArv))
				throw "sem espaço na memória!";
			else
				arv->setEsquerda(tmpArv);
		} else {
			arv = inserir(dado, arv->getEsquerda());
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
		}
	}


//!< remover do geekforgeeks
	NoAVL<T> *remover(NoAVL<T> *arv, const T &dado) {
		if (checkNullptr(arv))
			return arv;

		if (dado < *arv->getDado()) {
			arv->setEsquerda(remover(arv->getEsquerda(), dado));
		} else if (*arv->getDado() < dado) {
			arv->setDireita(remover(arv->getDireita(), dado));
		} else {
			if (checkNullptr(arv->getEsquerda()) || checkNullptr(arv->getDireita())) {

				NoAVL<T> *tmpArv;

				tmpArv = !checkNullptr(arv->getEsquerda()) ? arv->getEsquerda() : arv->getDireita();

				// if (!checkNullptr(arv->getEsquerda()))
				// 	tmpArv = arv->getEsquerda();
				// else
				// 	tmpArv

				if (checkNullptr(tmpArv)) {
					tmpArv = arv;
					arv = nullptr;
				} else {
					*arv = *tmpArv;
				}

				delete tmpArv;
			} else {
				NoAVL<T> *tmpArv = minimo(arv->getDireita());

				arv->setDado(tmpArv->getDado());

				arv->setDireita(remover(arv->getDireita(), *tmpArv->getDado()));
			}
		}

		if (checkNullptr(arv))
			return arv;

		fixAltura(arv);
		arv = balanceia(dado, arv);
		return arv;
	}

//!< remover do professor
	NoAVL<T> *remover(NoAVL<T> *arv, const T &dado) {
		NoAVL<T> *tmpArv;
		NoAVL<T> *filhoArv;

		if (checkNullptr(arv)){
			return arv;
		} else  {
			if (dado < *arv->getDado()) {
				/* busca do nodo a ser removido */
				arv->setEsquerda(remover(arv->getEsquerda(), dado));
				return arv;
			} else {
				if (*arv->getDado() < dado) {
					/* busca do nodo a ser removido */
					arv->setDireita(remover(arv->getDireita(), dado));
					fixAltura(arv);
					arv = balanceia(dado, arv);
					return arv;
				} else {
					if (!checkNullptr(arv->getEsquerda())
								&& !checkNullptr(arv->getDireita())) {
						/* dois filhos */
						tmpArv = minimo(arv->getDireita());
						arv->setDado(tmpArv->getDado());
						arv->setDireita(remover(arv->getDireita(), *arv->getDado()));
						fixAltura(arv);
						arv = balanceia(dado, arv);
						return arv;
					} else {
						tmpArv = arv;
						if (!checkNullptr(arv->getDireita())) {
							/* filho na direita */
							filhoArv = arv->getDireita();
							// delete tmpArv;
							return filhoArv;
						} else {
							if (!checkNullptr(arv->getEsquerda())) {
								/* filho na esquerda */
								filhoArv = arv->getEsquerda();
								// delete tmpArv;
								return filhoArv;
							} else {
								/* sem filhos */
								delete tmpArv;
								return nullptr;
							}
						}
					}
				}
			}
		}

		// fixAltura(arv);
		// arv = balanceia(dado, arv);
		// return arv;
	}

//!< versao pirata
#ifndef NO_AVL_HPP
#define NO_AVL_HPP

#include <vector>
#include <algorithm>
#include <cmath>

#include <iostream>

template <typename T>
class NoAVL {
	public:
		explicit NoAVL(const T &dado)
			: dado(new T(dado)), esquerda(nullptr), direita(nullptr), altura(0)
			{}

		virtual ~NoAVL() { }

		int getAltura() {
			return altura;
		}

		/*!
		 *  \brief Funcao getter getDado
		 *  \return o ponteiro para o dado do nodo.
		 */
		T *getDado() {
			return dado;
		}

		/*!
		 *  \brief Funcao getter getElementos
		 *  \return o vector de nodos binarios elementos.
		 */
		std::vector<NoAVL<T>*> getElementos() {
			return elementos;
		}

		/*!
		 *  \brief Funcao getter getEsquerda
		 *  \return o ponteiro para o nodo filho da esquerda.
		 */
		NoAVL<T> *getEsquerda() {
			return esquerda;
		}

		/*!
		 *  \brief Funcao getter getDireita
		 *  \return o ponteiro para o nodo filho da direita.
		 */
		NoAVL<T> *getDireita() {
			return direita;
		}

		void setEsquerda(NoAVL<T> *esq) {
			esquerda = esq;
		}

		void setDireita(NoAVL<T> *dir) {
			direita = dir;
		}

		void setAltura(int alt) {
			altura = alt;
		}

		void setDado(T *data) {
			dado = data;
		}

		bool checkNullptr(NoAVL<T> *arv) {
			return arv == nullptr ? true : false;
		}

		int alturaNo(NoAVL<T> *nodo) {
			return nodo == nullptr ? -1 : nodo->getAltura();
		}

		void fixAltura(NoAVL<T> *nodo) {
			nodo->setAltura(std::max(alturaNo(nodo->getEsquerda()),
				alturaNo(nodo->getDireita())) + 1);
		}

		int varBalanco(NoAVL<T> *arv) {
			return alturaNo(arv->getEsquerda()) - alturaNo(arv->getDireita());
		}

		NoAVL<T> *rotacaoEsqSimples(NoAVL<T> *arv) {
			if (!checkNullptr(arv->getEsquerda())) {
				NoAVL<T> *arvTmp = arv->getEsquerda();
				arv->setEsquerda(arvTmp->getDireita());
				arvTmp->setDireita(arv);

				fixAltura(arv);
				fixAltura(arvTmp);

				return arvTmp;
			} else {
				throw "ERRO!";
			}
		}

		NoAVL<T> *rotacaoDirSimples(NoAVL<T> *arv) {
			if (!checkNullptr(arv->getDireita())) {
				NoAVL<T> *arvTmp = arv->getDireita();
				arv->setDireita(arvTmp->getEsquerda());
				arvTmp->setEsquerda(arv);

				fixAltura(arv);
				fixAltura(arvTmp);

				return arvTmp;
			} else {
				throw "ERRO!";
			}
		}

		NoAVL<T> *rotacaoEsqDupla(NoAVL<T> *arv) {
			if (!checkNullptr(arv->getEsquerda()) &&
					!checkNullptr(arv->getEsquerda()->getDireita())) {
				arv->setEsquerda(rotacaoDirSimples(arv->getEsquerda()));
				return rotacaoEsqSimples(arv);
			} else {
				throw "ERRO!";
			}
		}

		NoAVL<T> *rotacaoDirDupla(NoAVL<T> *arv) {
			if (!checkNullptr(arv->getDireita()) &&
					!checkNullptr(arv->getDireita()->getEsquerda())) {
				arv->setDireita(rotacaoEsqSimples(arv->getDireita()));
				return rotacaoDirSimples(arv);
			} else {
				throw "ERRO!";
			}
		}

		NoAVL<T> *balanceia(const T &dado, NoAVL<T> *arv) {
			fixAltura(arv);
			if (varBalanco(arv) == -2) {
				if (varBalanco(arv->getDireita()) > 0) {
					// return rotacao_dupla_getDireita()(arv);
					arv->setDireita(rotacaoDirSimples(arv->getDireita()));
				}
				arv = rotacaoEsqSimples(arv);
				return arv;
			}
			if (varBalanco(arv) == 2) {
				if (varBalanco(arv->getEsquerda()) < 0) {
					// return rotacao_dupla_esquerda(arv);
					arv->setEsquerda(rotacaoEsqSimples(arv->getEsquerda()));
				}
				arv = rotacaoDirSimples(arv);
				return arv;
			}
			return arv;
		}

		T *busca(const T &dado, NoAVL<T> *arv) {
			while (!checkNullptr(arv) && dado != *arv->getDado()) {
				if (*arv->getDado() < dado)
					arv = arv->getDireita();
				else
					arv = arv->getEsquerda();
			}

			if (checkNullptr(arv))
				throw "nodo não encontrado!";
			else
				return arv->getDado();
		}

		NoAVL<T> *inserir(const T &dado, NoAVL<T> *arv) {
			if (checkNullptr(arv)) {
				arv = new NoAVL<T>(dado);
				if (checkNullptr(arv))
					throw "sem espaço na memória!";
			} else if (dado < *arv->getDado()) {
				arv->setEsquerda(inserir(dado, arv->getEsquerda()));
			} else {
				arv->setDireita(inserir(dado, arv->getDireita()));
			}

			fixAltura(arv);
			return balanceia(dado, arv);
		}

	NoAVL<T> *remover(NoAVL<T> *arv, const T &dado) {
		NoAVL<T> *tmpArv;
		NoAVL<T> *filhoArv;

		if (checkNullptr(arv)){
			return arv;
		} else  {
			if (dado < *arv->getDado()) {
				/* busca do nodo a ser removido */
				arv->setEsquerda(remover(arv->getEsquerda(), dado));
				return arv;
			} else {
				if (*arv->getDado() < dado) {
					/* busca do nodo a ser removido */
					arv->setDireita(remover(arv->getDireita(), dado));
					fixAltura(arv);
					arv = balanceia(dado, arv);
					return arv;
				} else {
					if (!checkNullptr(arv->getEsquerda())
								&& !checkNullptr(arv->getDireita())) {
						/* dois filhos */
						tmpArv = minimo(arv->getDireita());
						arv->setDado(tmpArv->getDado());
						arv->setDireita(remover(arv->getDireita(), *arv->getDado()));
						fixAltura(arv);
						arv = balanceia(dado, arv);
						return arv;
					} else {
						tmpArv = arv;
						if (!checkNullptr(arv->getDireita())) {
							/* filho na direita */
							filhoArv = arv->getDireita();
							// delete tmpArv;
							return filhoArv;
						} else {
							if (!checkNullptr(arv->getEsquerda())) {
								/* filho na esquerda */
								filhoArv = arv->getEsquerda();
								// delete tmpArv;
								return filhoArv;
							} else {
								/* sem filhos */
								delete tmpArv;
								return nullptr;
							}
						}
					}
				}
			}
		}

		// fixAltura(arv);
		// arv = balanceia(dado, arv);
		// return arv;
	}

		NoAVL<T> *minimo(NoAVL<T> *nodo) {
			if (checkNullptr(nodo->getEsquerda()))
				return nodo;
			else
				return minimo(nodo->getEsquerda());
		}

		void preOrdem(NoAVL<T> *nodo) {
			if (!checkNullptr(nodo)) {
				elementos.push_back(nodo);
				// std::cout << *nodo->getDado() << " ";
				preOrdem(nodo->getEsquerda());
				preOrdem(nodo->getDireita());
			}
		}

		void emOrdem(NoAVL<T> *nodo) {
			if (!checkNullptr(nodo)) {
				emOrdem(nodo->getEsquerda());
				elementos.push_back(nodo);
				// std::cout << *nodo->getDado() << " ";
				emOrdem(nodo->getDireita());
			}
		}

		void posOrdem(NoAVL<T> *nodo) {
			if (!checkNullptr(nodo)) {
				posOrdem(nodo->getEsquerda());
				posOrdem(nodo->getDireita());
				elementos.push_back(nodo);
			}
		}

	private:
		T *dado;						   //!< informacao generica do nodo
		NoAVL<T> *esquerda;				   //!< nodo filho da esquerda
		NoAVL<T> *direita;                 //!< nodo filho da direita
		int altura; 					   //!< representa a altura do no avl
		std::vector<NoAVL<T>*> elementos;  //!< elementos acessados durante
										   // o percurso realizado
};
#endif
