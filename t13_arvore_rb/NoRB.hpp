#ifndef NO_RB_HPP
#define NO_RB_HPP

#define RB_RUBRO true
#define RB_NEGRO false

/*!
 *  \brief NoRB.hpp
 *	\copyright Copyright [2016] <Lucas Joao Martins>
 *  \author Lucas Joao Martins
 *
 *	Implementa arvore rb atraves de template.
 *  WARNING: NAO FUNCIONA CORRETAMENTE, NOS TESTES DO PROFESSOR FICOU 7/10
 *			 NAO TEM VERIFICACAO DE DESBALANCEAMENTO PARA REMOCAO
 *			 NAO FOI REALIZADO TESTES PROPRIOS
 *			 POSSIVELMENTE BALANCEAMENTO APOS INSERCAO ESTA INCORRETO
 */

#include <vector>

template <typename T>
class NoRB {
	public:
		/*!
		 *  \brief Construtor
		 *	\param referencia ao tipo generico constante dado do nodo
		 *
		 *	Inicializa a arvore, seta o dado do nodo conforme parametro,
		 *		esquerda, direita e pai sao nulos enquanto a cor e negra.
		 */
		explicit NoRB(const T &dado)
			: dado(new T(dado)), esquerda(nullptr), direita(nullptr),
			  pai(nullptr), cor(RB_NEGRO) {}

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
		 *  \brief Funcao getter getPai
		 *  \return o pai do nodo.
		 */
		NoRB<T> *getPai() {
			return pai;
		}

		/*!
		 *  \brief Funcao getter getDado
		 *  \return o ponteiro para o dado do nodo.
		 */
		T *getDado() {
			return dado;
		}

		/*!
		 *  \brief Funcao getter getCor
		 *  \return a cor do nodo.
		 */
		bool getCor(NoRB<T> *nodo) {
			return cor;
		}

		/*!
		 *  \brief Funcao getter getElementos
		 *  \return o vector de nodos rbs elementos.
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
		 *  \param esq passado por nome e um nodo rb.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como filho da esquerda do nodo pai.
		 */
		void setEsquerda(NoRB<T> *esq) {
			esquerda = esq;
		}

		/*!
		 *  \brief Funcao setter setDireita
		 *  \param dir passado por nome e um nodo rb.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como filho da direita do nodo pai.
		 */
		void setDireita(NoRB<T> *dir) {
			direita = dir;
		}

		/*!
		 *  \brief Funcao setter setPai
		 *  \param _pai passado por nome e um nodo rb.
		 * 	\return nao possui.
		 *
		 *	Atribui o nodo passado como pai do nodo.
		 */
		void setPai(NoRB<T> *_pai) {
			pai = _pai;
		}

		/*!
		 *  \brief Funcao setter setCor
		 *  \param valor booleano _cor.
		 * 	\return nao possui.
		 *
		 *	Atribui a cor passada como nova cor do nodo.
		 */
		void setCor(bool _cor) {
			cor = _cor;
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
		 *  \param arv passado por nome e um nodo rb
		 *  \return valor booleano resultante da comparacao
		 *
		 *  Checa se o nodo passado e um nullptr.
		 */
		bool checkNullptr(NoRB<T> *arv) {
			return arv == nullptr ? true : false;
		}

		/*!
		 *  \brief Funcao rotacaoEsq
		 *  \param arv passado por nome e um nodo rb
		 *  \return a arv rotacionada
		 *  \sa checkNullptr(...), getDireita(), setEsquerda(...),
		 * 		setDireita(...), getEsquerda(), getPai(), setPai(...)
		 *
		 *  Se possivel, realiza a rotacao esquerda.
		 */
		NoRB<T> *rotacaoEsq(NoRB<T> *arv) {
			if (!checkNullptr(arv->getPai())) {
				NoRB<T> *paiTmp = arv->getPai();
				NoRB<T> *arvTmp = arv->getDireita();

				arvTmp->setPai(paiTmp);
				arv->setDireita(arvTmp->getEsquerda());
				arv->getDireita()->setPai(arv);
				arvTmp->setEsquerda(arv);
				arvTmp->getEsquerda()->setPai(arvTmp);

				if (paiTmp->getEsquerda() == arv)
					paiTmp->setEsquerda(arvTmp);
				else if (paiTmp->getDireita() == arv)
					paiTmp->setDireita(arvTmp);

				return arvTmp;
			} else {
				throw "ERRO!";
			}
		}

		/*!
		 *  \brief Funcao rotacaoDir
		 *  \param arv passado por nome e um nodo rb
		 *  \return a arv rotacionada
		 *  \sa checkNullptr(...), getDireita(), setEsquerda(...),
		 * 		setDireita(...), getEsquerda(), getPai(), setPai(...)
		 *
		 *  Se possivel, realiza a rotacao direita.
		 */
		NoRB<T> *rotacaoDir(NoRB<T> *arv) {
			if (!checkNullptr(arv->getPai())) {
				NoRB<T> *paiTmp = arv->getPai();
				NoRB<T> *arvTmp = arv->getEsquerda();

				arvTmp->setPai(paiTmp);
				arv->setEsquerda(arvTmp->getDireita());
				arv->getEsquerda()->setPai(arv);
				arvTmp->setDireita(arv);
				arvTmp->getDireita()->setPai(arvTmp);

				if (paiTmp->getEsquerda() == arv)
					paiTmp->setEsquerda(arvTmp);
				else if (paiTmp->getDireita() == arv)
					paiTmp->setDireita(arvTmp);

				return arvTmp;
			} else {
				throw "ERRO!";
			}
		}

		/*!
		 *  \brief Funcao ceEsq
		 *  \param arv passado por nome e um nodo rb
		 *  \param arv passado por nome e um nodo rb que representa o pai
		 *  \param arv passado por nome e um nodo rb que representa o avo
		 *  \return a arv "balanceada"
		 *  \sa getDireita(), getCor(...), setCor(...), rotacaoEsq(...),
		 * 		getEsquerda(), rotacaoDir(...)
		 *
		 *  Realiza a correcao ou elevacao da arvore para que ela fique
		 *		"balanceada".
		 */
		NoRB<T> *ceEsq(NoRB<T> *arv, NoRB<T> *pai, NoRB<T> *avo) {
			NoRB<T> *tio = avo->getDireita();
			if (getCor(tio)) {
				pai->setCor(RB_NEGRO);
				avo->setCor(RB_RUBRO);
				tio->setCor(RB_NEGRO);
				arv = avo;
			} else {
				if (pai->getDireita() == arv) {
					pai = rotacaoEsq(pai);
					arv = arv->getEsquerda();
				}
				pai->setCor(RB_NEGRO);
				avo->setCor(RB_RUBRO);
				avo = rotacaoDir(avo);
			}
			return arv;
		}

		/*!
		 *  \brief Funcao ceDir
		 *  \param arv passado por nome e um nodo rb
		 *  \param arv passado por nome e um nodo rb que representa o pai
		 *  \param arv passado por nome e um nodo rb que representa o avo
		 *  \return a arv "balanceada"
		 *  \sa getDireita(), getCor(...), setCor(...), rotacaoEsq(...),
		 * 		getEsquerda(), rotacaoDir(...)
		 *
		 *  Realiza a correcao ou elevacao da arvore para que ela fique
		 *		"balanceada".
		 */
		NoRB<T> *ceDir(NoRB<T> *arv, NoRB<T> *pai, NoRB<T> *avo) {
			NoRB<T> *tio = avo->getEsquerda();
			if (getCor(tio)) {
				pai->setCor(RB_NEGRO);
				avo->setCor(RB_RUBRO);
				tio->setCor(RB_NEGRO);
				arv = avo;
			} else {
				if (pai->getEsquerda() == arv) {
					pai = rotacaoDir(pai);
					arv = arv->getDireita();
				}
				pai->setCor(RB_NEGRO);
				avo->setCor(RB_RUBRO);
				avo = rotacaoEsq(avo);
			}
			return arv;
		}

		/*!
		 *  \brief Funcao busca
		 *  \param referencia ao tipo generico constante dado do nodo
		 *  \param arv passado por nome e um nodo rb que vai ser procurado
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
		 *  \param arv passado por nome e um nodo rb que vai ser inserido
		 *  \return o ponteiro para o nodo rb
		 *  \sa getDado(), checkNullptr(...), getEsquerda(), getDireita(),
		 *		setEsquerda(...), setDireita(...), setCor(...), setPai(...),
		 *		getPai(), getCor(), ceEsq(...), ceDir(...)
		 *
		 *  Busca de forma recursiva o local correto para inserir o nodo e
		 *		so realiza o processo de adicao se houver espaco na memoria.
		 *		Apos isso "balanceia", se necessario, os nodos que estao acima
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

			arv->setPai(arv->getPai());
			arv->setCor(RB_RUBRO);

			NoRB<T> *arvTmp = arv;
			NoRB<T> *pai = arvTmp->getPai();
			NoRB<T> *avo;

			while (getCor(arvTmp) && !checkNullptr(pai) && getCor(pai)) {
				avo = pai->getPai();

				if (!checkNullptr(avo) && avo->getEsquerda() == pai)
					arvTmp = ceEsq(arvTmp, pai, avo);
				else
					arvTmp = ceDir(arvTmp, pai, avo);
			}

			arv = arvTmp;
			while (!checkNullptr(arv->getPai()))
				arv = arv->getPai();

			arv->setCor(RB_NEGRO);
			return arv;
		}

		/*!
		 *  \brief Funcao remover
		 *  \param referencia ao tipo generico constante dado do nodo
		 *  \param arv passado por nome e um nodo rb que vai ser removido
		 *  \return o ponteiro para o nodo rb
		 *  \sa getDado(), checkNullptr(...), getEsquerda(), getDireita(),
		 *		setEsquerda(...), setDireita(...), setDado(...), minimo(...)
		 *
		 *  Busca de forma recursiva o nodo a ser deletado e entao o deleta.
		 */
		NoRB<T> *remover(NoRB<T> *arv, const T &dado) {
			NoRB<T> *tmpArv = arv;

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
				arv->setDado(*tmpArv->getDado());
				arv->setDireita(remover(arv->getDireita(), *arv->getDado()));
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

			return arv;
		}

		/*!
		 *  \brief Funcao minimo
		 *  \param ponteiro ao nodo rb que deve ser procurado
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
		 *  \param parametro ao nodo rb que sera utilizado como base.
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
		 *  \param parametro ao nodo rb que sera utilizado como base.
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
		 *  \param parametro ao nodo rb que sera utilizado como base.
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
		NoRB<T> *pai;                      //!< nodo ascendente (pai)
		bool cor;	                       //!< cor do nodo
		std::vector<NoRB<T>*> elementos;   //!< elementos acessados durante
										   // o percurso realizado
};

#endif
