#ifndef NO_AVL_HPP
#define NO_AVL_HPP

/*!
 *  \brief NoAVL.hpp
 *	\copyright Copyright [2016], Lucas Joao Martins
 *  \author Lucas Joao Martins
 *
 *	Implementa arvore avl atraves de template.
 */

#include <vector>
#include <algorithm>
#include <cmath>

template <typename T>
class NoAVL {
	public:
		/*!
		 *  \brief Construtor
		 *	\param referencia ao tipo generico constante dado do nodo
		 *
		 *	Inicializa a arvore, seta o dado do nodo conforme parametro,
		 *		esquerda e direita sao nulos enquanto a altura e zero.
		 */
		explicit NoAVL(const T &dado)
			: dado(new T(dado)), esquerda(nullptr), direita(nullptr), altura(0)
			 {}

		/*!
		 *  \brief Destrutor
		 *
		 *	Destrutor virtual.
		 */
		virtual ~NoAVL() {
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
		 *  \return o vector de nodos avls elementos.
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

		/*!
		 *	\brief Funcao setter setEsquerda
		 *  \param esq passado por nome e um nodo avl.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como filho da esquerda do nodo pai.
		 */
		void setEsquerda(NoAVL<T> *esq) {
			esquerda = esq;
		}

		/*!
		 *  \brief Funcao setter setDireita
		 *  \param dir passado por nome e um nodo avl.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como filho da direita do nodo pai.
		 */
		void setDireita(NoAVL<T> *dir) {
			direita = dir;
		}

		/*!
		 *  \brief Funcao setter setAltura
		 *  \param alt e a nova altura
		 * 	\return nao possui.
		 *
		 *	Atribui o inteiro passado como nova altura do nodo.
		 */
		void setAltura(int alt) {
			altura = alt;
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
		bool checkNullptr(NoAVL<T> *arv) {
			return arv == nullptr ? true : false;
		}

		/*!
		 *  \brief Funcao alturaNo
		 *  \param nodo passado por nome e um nodo avl
		 *  \return inteiro que representa a altura do nodo
		 *	\sa getAltura(), checkNullptr(...)
		 *
		 *  Retorna a altura do nodo, necessaria para casos em que o nodo e um
		 *		nullptr.
		 */
		int alturaNo(NoAVL<T> *nodo) {
			return checkNullptr(nodo) ? -1 : nodo->getAltura();
		}

		/*!
		 *  \brief Funcao fixAltura
		 *  \param nodo passado por nome e um nodo avl
		 *  \return nao possui
		 *  \sa setAltura(...), std::max(...), alturaNo(...), getEsquerda(),
		 *		getDireita()
		 *
		 *  Atualiza a altura do nodo.
		 */
		void fixAltura(NoAVL<T> *nodo) {
			nodo->setAltura(std::max(alturaNo(nodo->getEsquerda()),
				alturaNo(nodo->getDireita())) + 1);
		}

		/*!
		 *  \brief Funcao varBalanco
		 *  \param arv passado por nome e um nodo avl
		 *  \return inteiro que representa o fator de balanceamento do nodo
		 *  \sa alturaNo(...), getEsquerda(), getDireita()
		 *
		 *  Calcula o fator de balanceamento de um nodo.
		 */
		int varBalanco(NoAVL<T> *arv) {
			if (checkNullptr(arv))
				return 0;

			return alturaNo(arv->getEsquerda()) - alturaNo(arv->getDireita());
		}

		/*!
		 *  \brief Funcao rotacaoEsqSimples
		 *  \param arv passado por nome e um nodo avl
		 *  \return a arv rotacionada a esquerda
		 *  \sa checkNullptr(...), getEsquerda(), setEsquerda(...),
		 * 		setDireita(...), fixAltura(...)
		 *
		 *  Se possivel, realiza a rotacao esquerda simples.
		 */
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

		/*!
		 *  \brief Funcao rotacaoDirSimples
		 *  \param arv passado por nome e um nodo avl
		 *  \return a arv rotacionada a direita
		 *  \sa checkNullptr(...), getDireita(), setEsquerda(...),
		 * 		setDireita(...), fixAltura(...)
		 *
		 *  Se possivel, realiza a rotacao direita simples.
		 */
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

		/*!
		 *  \brief Funcao rotacaoEsqDupla
		 *  \param arv passado por nome e um nodo avl
		 *  \return a arv rotacionada duplamente a esquerda
		 *  \sa checkNullptr(...), getDireita(), getEsquerda(),
		 *		setEsquerda(...), rotacaoDirSimples(...), rotacaoEsqSimples(..)
		 *
		 *  Se possivel, realiza a rotacao esquerda dupla.
		 */
		NoAVL<T> *rotacaoEsqDupla(NoAVL<T> *arv) {
			if (!checkNullptr(arv->getEsquerda()) &&
					!checkNullptr(arv->getEsquerda()->getDireita())) {
				arv->setEsquerda(rotacaoDirSimples(arv->getEsquerda()));
				return rotacaoEsqSimples(arv);
			} else {
				throw "ERRO!";
			}
		}

		/*!
		 *  \brief Funcao rotacaoDirDupla
		 *  \param arv passado por nome e um nodo avl
		 *  \return a arv rotacionada duplamente a direita
		 *  \sa checkNullptr(...), getDireita(), getEsquerda(),
		 *		setDireita(...), rotacaoDirSimples(...), rotacaoEsqSimples(..)
		 *
		 *  Se possivel, realiza a rotacao direita dupla.
		 */
		NoAVL<T> *rotacaoDirDupla(NoAVL<T> *arv) {
			if (!checkNullptr(arv->getDireita()) &&
					!checkNullptr(arv->getDireita()->getEsquerda())) {
				arv->setDireita(rotacaoEsqSimples(arv->getDireita()));
				return rotacaoDirSimples(arv);
			} else {
				throw "ERRO!";
			}
		}

		/*!
		 *  \brief Funcao balanceia
		 *  \param referencia ao tipo generico constante dado do nodo
		 *  \param arv passado por nome e um nodo avl que vai ser balanceado
		 *  \return arv avl balanceada
		 *  \sa varBalanco(...), getEsquerda(), getDado(), getDireita(),
		 *		rotacaoEsqSimples(...), rotacaoEsqDupla(...),
		 *		rotacaoDirDupla(...), rotacaoDirSimples(...)
		 *
		 *  Balanceia a arvore com rotacoes conforme o caso de
		 *		desbanlaceamento.
		 */
		NoAVL<T> *balanceia(const T &dado, NoAVL<T> *arv) {
			if (1 < varBalanco(arv)) {
				if (0 <= varBalanco(arv->getEsquerda()))  //!< left left
					arv = rotacaoEsqSimples(arv);
				else                                      //!< left right
					arv = rotacaoEsqDupla(arv);
			} else if (varBalanco(arv) < -1) {
				if (varBalanco(arv->getDireita()) <= 0)  //!< right right
					arv = rotacaoDirSimples(arv);
				else                                     //!< right left
					arv = rotacaoDirDupla(arv);
			}

			return arv;
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
		NoAVL<T> *inserir(const T &dado, NoAVL<T> *arv) {
			if (checkNullptr(arv)) {
				arv = new NoAVL<T>(dado);
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
		NoAVL<T> *remover(NoAVL<T> *arv, const T &dado) {
			NoAVL<T> *tmpArv = arv;

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
		NoAVL<T> *minimo(NoAVL<T> *nodo) {
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
		void preOrdem(NoAVL<T> *nodo) {
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
		void emOrdem(NoAVL<T> *nodo) {
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
