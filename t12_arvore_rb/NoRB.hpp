#ifndef NO_RB_HPP
#define NO_RB_HPP

#include <vector>

#define RB_RUBRO true
#define RB_NEGRO false

template <typename T>
class NoRB {
	public:
		/*!
		 *  \brief Construtor
		 *	\param referencia ao tipo generico constante dado do nodo
		 *
		 *	Inicializa a arvore, seta o dado do nodo conforme parametro,
		 *		esquerda e direita sao nulos enquanto a altura e zero.
		 */
		explicit NoRB(const T &dado)
			: dado(new T(dado)), esquerda(nullptr), direita(nullptr), altura(0)
			 {}

		/*!
		 *  \brief Destrutor
		 *
		 *	Destrutor virtual.
		 */
		virtual ~NoRB() {
			if (!checkNullptr(getEsquerda()))
				delete esquerda;
			else if (!checkNullptr(getDireita()))
				delete direita;

			delete dado;
		}

		/*!
		 *  \brief Funcao getter getAltura
		 *  \return a altura do nodo.
		 */
		NoRB<T> *getPai() {
			return altura;
		}

		/*!
		 *  \brief Funcao getter getDado
		 *  \return o ponteiro para o dado do nodo.
		 */
		T *getDado() {
			return dado;
		}

		bool getCor(NoRB<T>*) {}

		/*!
		 *  \brief Funcao getter getElementos
		 *  \return o vector de nodos avls elementos.
		 */
		std::vector<NoRB<T>*> getElementos() {
			return elementos;
		}

		/*!
		 *  \brief Funcao getter getEsquerda
		 *  \return o ponteiro para o nodo filho da esquerda.
		 */
		NoRB<T> *getEsquerda() {
			return esquerda;
		}

		/*!
		 *  \brief Funcao getter getDireita
		 *  \return o ponteiro para o nodo filho da direita.
		 */
		NoRB<T> *getDireita() {
			return direita;
		}

		/*!
		 *	\brief Funcao setter setEsquerda
		 *  \param esq passado por nome e um nodo avl.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como filho da esquerda do nodo pai.
		 */
		void setEsquerda(NoRB<T> *esq) {
			esquerda = esq;
		}

		/*!
		 *  \brief Funcao setter setDireita
		 *  \param dir passado por nome e um nodo avl.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como filho da direita do nodo pai.
		 */
		void setDireita(NoRB<T> *dir) {
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
		void setDado(const T &data) {
			*dado = data;
		}

		/*!
		 *  \brief Funcao checkNullptr
		 *  \param arv passado por nome e um nodo avl
		 *  \return valor booleano resultante da comparacao
		 *
		 *  Checa se o nodo passado e um nullptr.
		 */
		bool checkNullptr(NoRB<T> *arv) {
			return arv == nullptr ? true : false;
		}

		/*!
		 *  \brief Funcao busca
		 *  \param referencia ao tipo generico constante dado do nodo
		 *  \param arv passado por nome e um nodo avl que vai ser procurado
		 *  \return um tipo generico que representa o dado do nodo encontrado
		 *  \sa getDireita(), getEsquerda(), getDado(), checkNullptr(...)
		 *
		 *  Caminha pela arvore a procura do nodo, se ele nao for encontrado,
		 *		entao lanca uma excecao.
		 */
		T *busca(const T &dado, NoRB<T> *arv) {
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
		 *  \param arv passado por nome e um nodo avl que vai ser inserido
		 *  \return o ponteiro para o nodo avl
		 *  \sa getDado(), checkNullptr(...), getEsquerda(), getDireita(),
		 *		setEsquerda(...), setDireita(...), fixAltura(...),
		 *		balanceia(...)
		 *
		 *  Busca de forma recursiva o local correto para inserir o nodo e
		 *		so realiza o processo de adicao se houver espaco na memoria.
		 *		Apos isso balanceia, se necessario, os nodos que estao acima
		 *		da arv inserida.
		 */
		NoRB<T> *inserir(const T &dado, NoRB<T> *arv) {
			if (checkNullptr(arv)) {
				arv = new NoRB<T>(dado);
				if (checkNullptr(arv))
					throw "sem espaço na memória!";
			} else if (dado < *arv->getDado()) {  //!< insere a esquerda
				arv->setEsquerda(inserir(dado, arv->getEsquerda()));
			} else {                              //!< insere a direita
				arv->setDireita(inserir(dado, arv->getDireita()));
			}

			fixAltura(arv);
			return balanceia(dado, arv);
		}

		/*!
		 *  \brief Funcao remover
		 *  \param referencia ao tipo generico constante dado do nodo
		 *  \param arv passado por nome e um nodo avl que vai ser removido
		 *  \return o ponteiro para o nodo avl
		 *  \sa getDado(), checkNullptr(...), getEsquerda(), getDireita(),
		 *		setEsquerda(...), setDireita(...), setDado(...), minimo(...),
		 *		fixAltura(...), balanceia(...)
		 *
		 *  Busca de forma recursiva o nodo a ser deletado e entao o deleta.
		 *		Apos isso balanceia, se necessario, os nodos que estao acima
		 *		da arv deletada.
		 */
		NoRB<T> *remover(NoRB<T> *arv, const T &dado) {
			NoRB<T> *tmpArv = arv;

			if (dado < *arv->getDado()) {
				/* busca do nodo a ser removido */
				arv->setEsquerda(remover(arv->getEsquerda(), dado));
				arv = balanceia(dado, arv);
			} else if (*arv->getDado() < dado) {
				/* busca do nodo a ser removido */
				arv->setDireita(remover(arv->getDireita(), dado));
				arv = balanceia(dado, arv);
			} else if (!checkNullptr(arv->getEsquerda())
						&& !checkNullptr(arv->getDireita())) {
				/* dois filhos */
				tmpArv = minimo(arv->getDireita());
				arv->setDado(*tmpArv->getDado());
				arv->setDireita(remover(arv->getDireita(), *arv->getDado()));
				arv = balanceia(dado, arv);
			} else if (!checkNullptr(arv->getDireita())) {
				/* filho na direita */
				arv = arv->getDireita();
			} else if (!checkNullptr(arv->getEsquerda())) {
				/* filho na esquerda */
				arv = arv->getEsquerda();
			} else {
				/* sem filhos */
				delete tmpArv;
				return nullptr;
			}

			fixAltura(arv);
			return arv;
		}

		/*!
		 *  \brief Funcao minimo
		 *  \param ponteiro ao nodo avl que deve ser procurado
		 *  \return o ponteiro para o nodo minimo da arvore
		 *  \sa getEsquerda(), checkNullptr(...)
		 *
		 *  Percorre a arvore em busca do nodo com o menor dado de forma
		 *		recursiva.
		 */
		NoRB<T> *minimo(NoRB<T> *nodo) {
			if (checkNullptr(nodo->getEsquerda()))
				return nodo;
			else
				return minimo(nodo->getEsquerda());
		}

		/*!
		 *  \brief Funcao preOrdem
		 *  \param parametro ao nodo avl que sera utilizado como base.
		 *  \return nao possui.
		 *  \sa checkNullptr(...), getDireita(), getEsquerda(),
		 * 		vector::push_back(...)
		 *
		 *  Adiciona os nodos da arvore no vector elementos ao percorre-la em
		 *		preordem.
		 */
		void preOrdem(NoRB<T> *nodo) {
			if (!checkNullptr(nodo)) {
				elementos.push_back(nodo);
				preOrdem(nodo->getEsquerda());
				preOrdem(nodo->getDireita());
			}
		}

		/*!
		 *  \brief Funcao emOrdem
		 *  \param parametro ao nodo avl que sera utilizado como base.
		 *  \return nao possui.
		 *  \sa checkNullptr(...), getDireita(), getEsquerda(),
		 * 		vector::push_back(...)
		 *
		 *  Adiciona os nodos da arvore no vector elementos ao percorre-la em
		 *		emordem.
		 */
		void emOrdem(NoRB<T> *nodo) {
			if (!checkNullptr(nodo)) {
				emOrdem(nodo->getEsquerda());
				elementos.push_back(nodo);
				emOrdem(nodo->getDireita());
			}
		}

		/*!
		 *  \brief Funcao posOrdem
		 *  \param parametro ao nodo avl que sera utilizado como base.
		 *  \return nao possui.
		 *  \sa checkNullptr(...), getDireita(), getEsquerda(),
		 * 		vector::push_back(...)
		 *
		 *  Adiciona os nodos da arvore no vector elementos ao percorre-la em
		 *		posordem.
		 */
		void posOrdem(NoRB<T> *nodo) {
			if (!checkNullptr(nodo)) {
				posOrdem(nodo->getEsquerda());
				posOrdem(nodo->getDireita());
				elementos.push_back(nodo);
			}
		}

	private:
		T *dado;						   //!< informacao generica do nodo
		NoRB<T> *esquerda;				   //!< nodo filho da esquerda
		NoRB<T> *direita;                  //!< nodo filho da direita
		NoRB<T> *pai;
		bool cor;
		std::vector<NoRB<T>*> elementos;   //!< elementos acessados durante
										   // o percurso realizado

};

#endif