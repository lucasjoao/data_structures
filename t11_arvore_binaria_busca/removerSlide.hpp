/* delecao em uma bst implementado conforme o slide */

NoBinario<T> *remover(NoBinario<T> *arv, const T &dado) {
	NoBinario<T> *tmpArv;
	NoBinario<T> *filhoArv;

	if (checkNullptr(arv)) {
		return arv;
	} else {
		if (dado < *arv->getDado()) {
			arv->setEsquerda(remover(arv->getEsquerda(), dado));
			return arv;
		} else {
			if (*arv->getDado() < dado) {
				arv->setDireita(remover(arv->getDireita(), dado));
				return arv;
			} else { // dois filhos
				if (!checkNullptr(arv->getEsquerda())							&& !checkNullptr(arv->getDireita())) {

					tmpArv = minimo(arv->getDireita());
					arv->setDado(tmpArv->getDado());
					arv->setDireita(remover(arv->getDireita(), *arv->getDado()));
					return arv;
				} else { // um filho na direita
					tmpArv = arv;
					if (!checkNullptr(arv->getDireita())) {
						filhoArv = arv->getDireita();
						delete tmpArv;
						return filhoArv;
					} else { // um filho na esquerda
						if (!checkNullptr(arv->getEsquerda())) {
							filhoArv = arv->getEsquerda();
							delete tmpArv;
							return filhoArv;
						} else { // sem filhos
							delete tmpArv;
							return nullptr;
						}
					}
				}
			}
		}
	}
}
