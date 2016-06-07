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
