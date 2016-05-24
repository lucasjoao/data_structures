#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

/*!
 *  \brief NoBinario.hpp
 *	\copyright Copyright [2016], Lucas Joao Martins
 *  \author Lucas Joao Martins
 *
 *	Implementa arvore binaria de busca com percurso (bst) atraves de template.
 */

#include <cstdlib>
#include <vector>

template<typename T>
class NoBinario {
	public:
		/*!
		 *  \brief Construtor
		 *	\param referencia ao tipo generico constante dado do nodo
		 *
		 *	Inicializa a arvore, seta o dado do nodo conforme parametro e
		 *		esquerda e direita sao nulos.
		 */
		NoBinario<T>(const T &dado)
			: dado(new T(dado)), esquerda(nullptr), direita(nullptr) {}

		/*!
		 *  \brief Destrutor
		 *
		 *	Destrutor virtual.
		 */
		virtual ~NoBinario() {}

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
		std::vector<NoBinario<T>*> getElementos() {
			return elementos;
		}

		/*!
		 *  \brief Funcao getter getEsquerda
		 *  \return o ponteiro para o nodo filho da esquerda.
		 */
		NoBinario<T> *getEsquerda() {
			return esquerda;
		}

		/*!
		 *  \brief Funcao getter getDireita
		 *  \return o ponteiro para o nodo filho da direita.
		 */
		NoBinario<T> *getDireita() {
			return direita;
		}

		/*!
		 *  \brief Funcao setter setEsquerda
		 *  \param esq passado por nome e um nodo binario.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como filho da esquerda do nodo pai.
		 */
		void setEsquerda(NoBinario<T> *esq) {
			esquerda = esq;
		}

		/*!
		 *  \brief Funcao setter setDireita
		 *  \param dir passado por nome e um nodo binario.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como filho da direita do nodo pai.
		 */
		void setDireita(NoBinario<T> *dir) {
			direita = dir;
		}

		/*!
		 *  \brief Funcao setter setDado
		 *  \param data passado por nome e um tipo generico que representa a
		 *		info do nodo.
		 * 	\return nao possui.
		 *
		 *	Atribui a info passada como a nova informacao do nodo.
		 */
		void setDado(T *data) {
			dado = data;
		}

		/*!
		 *  \brief Funcao checkNullptr
		 *  \param arv passado por nome e um nodo binario
		 *  \return valor booleano resultante da comparacao
		 *
		 *  Checa se o nodo passado e um nullptr.
		 */
		bool checkNullptr(NoBinario<T> *arv) {
			return arv == nullptr ? true : false;
		}

		/*!
		 *  \brief Funcao busca
		 *  \param referencia ao tipo generico constante dado do nodo
		 *  \param arv passado por nome e um nodo binario que vai ser procurado
		 *  \return um tipo generico que representa o dado do nodo encontrado
		 *  \sa getDireita(), getEsquerda(), getDado(), checkNullptr(...)
		 *
		 *  Caminha pela arvore a procura do nodo, se ele nao for encontrado,
		 *		entao lanca uma excecao.
		 */
		T *busca(const T &dado, NoBinario<T> *arv) {
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

		/*!
		 *  \brief Funcao inserir
		 *  \param referencia ao tipo generico constante dado do nodo
		 *  \param arv passado por nome e um nodo binario que vai ser inserido
		 *  \return o ponteiro para o nodo binario
		 *  \sa getDado(), checkNullptr(...), getEsquerda(), getDireita(),
		 *		setEsquerda(...), setDireita(...)
		 *
		 *  Busca de forma recursiva o local correto para inserir o nodo e
		 *		so realiza o processo de adicao se houver espaco na memoria.
		 */
		NoBinario<T> *inserir(const T &dado, NoBinario<T> *arv) {
			NoBinario<T> *tmpArv;

			if (dado < *arv->getDado()) {  //!< insere a esquerda
				if (checkNullptr(arv->getEsquerda())) {
					tmpArv = new NoBinario<T>(dado);
					if (checkNullptr(tmpArv))
						throw "sem espaço na memória!";
					else
						arv->setEsquerda(tmpArv);
				} else {
					arv = inserir(dado, arv->getEsquerda());
				}
			} else {                       //!< insere a direita
				if (checkNullptr(arv->getDireita())) {
					tmpArv = new NoBinario<T>(dado);
					if (checkNullptr(tmpArv))
						throw "sem espaço na memória!";
					else
						arv->setDireita(tmpArv);
				} else {
					arv = inserir(dado, arv->getDireita());
				}
			}

			return arv;
		}

		/*!
		 *  \brief Funcao remover
		 *  \param referencia ao tipo generico constante dado do nodo
		 *  \param arv passado por nome e um nodo binario que vai ser removido
		 *  \return o ponteiro para o nodo binario
		 *  \sa getDado(), checkNullptr(...), getEsquerda(), getDireita(),
		 *		setEsquerda(...), setDireita(...), setDado(...), minimo(...)
		 *
		 *  Busca de forma recursiva o nodo a ser deletado e entao o deleta.
		 */
		NoBinario<T> *remover(NoBinario<T> *arv, const T &dado) {
			NoBinario<T> *tmpArv = arv;
			NoBinario<T> *filhoArv;

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

			return arv;
		}

		/*!
		 *  \brief Funcao minimo
		 *  \param ponteiro ao nodo binario que deve ser procurado
		 *  \return o ponteiro para o nodo minimo da arvore
		 *  \sa getEsquerda(), checkNullptr(...)
		 *
		 *  Percorre a arvore em busca do nodo com o menor dado de forma
		 *		recursiva.
		 */
		NoBinario<T> *minimo(NoBinario<T> *nodo) {
			if (checkNullptr(nodo->getEsquerda()))
				return nodo;
			else
				return minimo(nodo->getEsquerda());
		}

		/*!
		 *  \brief Funcao preOrdem
		 *  \param parametro ao nodo binario que sera utilizado como base.
		 *  \return nao possui.
		 *  \sa checkNullptr(...), getDireita(), getEsquerda(),
		 * 		vector::push_back(...)
		 *
		 *  Adiciona os nodos da arvore no vector elementos ao percorre-la em
		 *		preordem.
		 */
		void preOrdem(NoBinario<T> *nodo) {
			if (!checkNullptr(nodo)) {
				elementos.push_back(nodo);
				preOrdem(nodo->getEsquerda());
				preOrdem(nodo->getDireita());
			}
		}

		/*!
		 *  \brief Funcao emOrdem
		 *  \param parametro ao nodo binario que sera utilizado como base.
		 *  \return nao possui.
		 *  \sa checkNullptr(...), getDireita(), getEsquerda(),
		 * 		vector::push_back(...)
		 *
		 *  Adiciona os nodos da arvore no vector elementos ao percorre-la em
		 *		emordem.
		 */
		void emOrdem(NoBinario<T> *nodo) {
			if (!checkNullptr(nodo)) {
				emOrdem(nodo->getEsquerda());
				elementos.push_back(nodo);
				emOrdem(nodo->getDireita());
			}
		}

		/*!
		 *  \brief Funcao posOrdem
		 *  \param parametro ao nodo binario que sera utilizado como base.
		 *  \return nao possui.
		 *  \sa checkNullptr(...), getDireita(), getEsquerda(),
		 * 		vector::push_back(...)
		 *
		 *  Adiciona os nodos da arvore no vector elementos ao percorre-la em
		 *		posordem.
		 */
		void posOrdem(NoBinario<T> *nodo) {
			if (!checkNullptr(nodo)) {
				posOrdem(nodo->getEsquerda());
				posOrdem(nodo->getDireita());
				elementos.push_back(nodo);
			}
		}

	protected:
		T *dado;							   //!< informacao generica do nodo
		NoBinario<T> *esquerda;				   //!< nodo filho da esquerda
		NoBinario<T> *direita;                 //!< nodo filho da direita
		std::vector<NoBinario<T>*> elementos;  //!< elementos acessados durante
											   // o percurso realizado
};
#endif
