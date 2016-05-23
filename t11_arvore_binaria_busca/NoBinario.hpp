#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>

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

		void setEsquerda(NoBinario<T> *esq) {
			esquerda = esq;
		}

		void setDireita(NoBinario<T> *dir) {
			direita = dir;
		}

		void setDado(T *data) {
			dado = data;
		}

		T *busca(const T &dado, NoBinario<T> *arv) {
			while (arv != nullptr && dado != *arv->getDado()) {
				if (*arv->getDado() < dado)
					arv = arv->getDireita();
				else
					arv = arv->getEsquerda();
			}

			if (arv == nullptr)
				throw "nodo não encontrado!";
			else
				return arv->getDado();
		}

		NoBinario<T> *inserir(const T &dado, NoBinario<T> *arv) {
			NoBinario<T> *tmpArv;

			if (dado < *arv->getDado()) {  //!< insere a esquerda
				if (arv->getEsquerda() == nullptr) {
					tmpArv = new NoBinario<T>(dado);
					if (semEspaco(tmpArv))
						throw "sem espaço na memória!";
					else
						arv->setEsquerda(tmpArv);
				} else {
					arv = inserir(dado, arv->getEsquerda());
				}
			} else {                     //!< insere a direita
				if (arv->getDireita() == nullptr) {
					tmpArv = new NoBinario<T>(dado);
					if (semEspaco(tmpArv))
						throw "sem espaço na memória!";
					else
						arv->setDireita(tmpArv);
				} else {
					arv = inserir(dado, arv->getDireita());
				}
			}
		}

		bool semEspaco(NoBinario<T> *arv) {
			return arv == nullptr ? true : false;
		}

		NoBinario<T> *remover(NoBinario<T> *arv, const T &dado) {
			NoBinario<T> *tmpArv;
			NoBinario<T> *filhoArv;

			if (arv == nullptr) {
				return arv;
			} else {
				if (dado < *arv->getDado()) {
					arv->setEsquerda(remover(arv->getEsquerda(), dado));
					return arv;
				} else {
					if (*arv->getDado() < dado) {
						arv->setDireita(remover(arv->getEsquerda(), dado));
						return arv;
					} else {
						if (arv->getEsquerda() != nullptr							&& arv->getDireita() != nullptr) {

							tmpArv = minimo(arv->getDireita());
							arv->setDado(tmpArv->getDado());
							arv->setDireita(remover(						arv->getDireita(), *arv->getDado()));
							return arv;
						} else {
							tmpArv = arv;
							if (arv->getDireita() != nullptr) {
								filhoArv = arv->getDireita();
								return filhoArv;
							} else {
								if (arv->getEsquerda() != nullptr) {
									filhoArv = arv->getEsquerda();
									return filhoArv;
								} else {
									delete arv;
									return nullptr;
								}
							}
						}
					}
				}
			}
		}

		NoBinario<T> *minimo(NoBinario<T> *nodo) {
			bool esquerdaNull = nodo->getEsquerda() == nullptr;
			bool direitaNull = nodo->getDireita() == nullptr;

			//*************************** versao que pega o nodo com menor dado
			if (esquerdaNull)
				return nodo;
			else
				return minimo(nodo->getEsquerda());

			/**************************** versao que pega o nodo de maior nivel
			if (esquerdaNull && direitaNull) {
				return nodo;
			} else {
				if (esquerdaNull)
					return minimo(nodo->getDireita());
				else
					return minimo(nodo->getEsquerda());
			}
			******************************************************************/
		}

		void preOrdem(NoBinario<T> *nodo) {
			if (nodo != nullptr) {
				elementos.push_back(nodo);
				preOrdem(nodo->getEsquerda());
				preOrdem(nodo->getDireita());
			}
		}

		void emOrdem(NoBinario<T> *nodo) {
			if (nodo != nullptr) {
				emOrdem(nodo->getEsquerda());
				elementos.push_back(nodo);
				emOrdem(nodo->getDireita());
			}
		}

		void posOrdem(NoBinario<T> *nodo) {
			if (nodo != nullptr) {
				posOrdem(nodo->getEsquerda());
				posOrdem(nodo->getDireita());
				elementos.push_back(nodo);
			}
		}

	protected:
		T *dado;
		NoBinario<T> *esquerda;
		NoBinario<T> *direita;
		std::vector<NoBinario<T>*> elementos;  //!< elementos acessados durante
											  // o percurso realizado
};
#endif