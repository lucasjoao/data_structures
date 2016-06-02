#ifndef NO_AVL_HPP
#define NO_AVL_HPP

#include <vector>

template <typename T>
class NoAVL {
	public:
		explicit NoAVL(const T &dado) { }
		virtual ~NoAVL() { }
		int getAltura() { }
		std::vector<NoAVL<T>*> getElementos() { }
		NoAVL<T> *getEsquerda() { }
		NoAVL<T> *getDireita() { }
		T *getDado() { }
		T *busca(const T &dado, NoAVL<T> *arv) { }
		NoAVL<T> *inserir(const T &dado, NoAVL<T> *arv) { }
		NoAVL<T> *remover(NoAVL<T> *arv, const T &dado) { }
		NoAVL<T> *minimo(NoAVL<T> *nodo) { }
		void preOrdem(NoAVL<T> *nodo) { }
		void emOrdem(NoAVL<T> *nodo) { }
		void posOrdem(NoAVL<T> *nodo) { }

	private:
		int altura; //!< representa a altura do no avl
		T *dado;
		NoAVL<T> *esquerda;
		NoAVL<T> *direita;
		std::vector<NoAVL<T>*> elementos;
};
#endif