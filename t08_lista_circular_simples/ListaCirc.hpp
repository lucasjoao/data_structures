/*!
 *  \brief ListaCirc.hpp
 *	\copyright Copyright [2016], Lucas Joao Martins
 *  \author Lucas Joao Martins
 *
 *	Implementa a estrutura de dados lista circular atraves de template.
 */

#include "Elemento.hpp"

template <typename T>
class ListaCirc {
	public:
		/*!
		 *  \brief Construtor
		 *
		 *	Inicializa a lista com tamanho zero, head aponta para nullptr e
		 *		sentinela aponta para head.
		 */
		ListaCirc() {
			size = 0;
			head = nullptr;
			sentinel = new Elemento<T>(0, head);
		}

		/*!
		 *  \brief Destrutor
		 *	\sa destroiLista()
		 */
		~ListaCirc() {
			destroiLista();
		}

		/*!
		 *  \brief Funcao adiciona
		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado a ser adicionado na lista.
		 *	\return nao possui retorno
		 *	\sa listaVazia(), adicionaNoInicio(...) e adicionaNaPosicao(...)
		 *
		 *  Se a lista estiver vazia, entao adiciona no inicio. Caso contrario
		 *		adiciona no fim (ultima posicao que corresponde ao size).
		 */
		void adiciona(const T &dado) {
			if (listaVazia())
				adicionaNoInicio(dado);
			else
				adicionaNaPosicao(dado, size);
		}

		/*!
		 *  \brief Funcao adicionaNoInicio
 		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que ficara na primeira posicao da lista.
		 *  \return nao possui.
		 *
		 *  Istancia um elemento tmp que aponta para um nullptr e
		 *		possui o dado passado como argumento, e, se houver espaco na
		 *		memoria para alocar essa instanciacao, entao faz o processo de
		 *		adicao conforme o atual tamanho da lista. Verifica a situacao
		 *		da memoria ao comparar se o novo elemento temporario e igual a
		 *		um nullptr.
		 */
		void adicionaNoInicio(const T &dado) {
			Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr);

			if (tmpElemento == nullptr) {
				throw "problema";
			} else {
				sentinel->setProximo(tmpElemento);

			    if (size != 0) {
					tmpElemento->setProximo(head);
					head = tmpElemento;
			    } else {
					head = tmpElemento;
					head->setProximo(sentinel);
			    }

			    size += 1;
			}
		}

		/*!
		 *  \brief Funcao adicionaNaPosicao
 		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que ficara na primeira posicao da lista.
 		 *	\param pos e um inteiro que indica a posicao em que deve-se
		 *		tentar adicionar o dado.
		 *  \return nao possui.
		 *	\sa adicionaNoInicio(...)
		 *
		 *  Se a posicao for valida e ser a zero, chama a funcao
		 *		adicionaNoInicio para realizar o processo de adicao com o dado
		 *		recebido como argumento. Se a posicao nao for a zero, entao
		 *		istancia um novo Elemento temporario que aponta para um
		 *		nullptr e possui o dado passado como argumento, e, se houver
		 *		espaco na memoria para alocar essa instanciacao, entao caminha
		 *		ate o vertice anterior ao da posicao em que se pretende
		 *		adicionar o dado com outro elemento temporario. Ao chegar
		 *		nessa posicao, aponta o vertice anterior ao primeiro elemento
		 *		temporario criado e aponta esse ultimo para o vertice seguinte
		 *		ao da posicao anterior. Por fim, aumenta o numero que indica o
		 *		tamanho da lista.
		 */
		void adicionaNaPosicao(const T &dado, int pos) {
			if (pos > size) {
				throw "problema";
			} else {
				if (pos == 0) {
					adicionaNoInicio(dado);
				} else {
					Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr);
					Elemento<T> *antElemento;

					if (tmpElemento == nullptr) {
						throw "problema";
					} else {
						antElemento = head;

						while (--pos != 0)
							antElemento = antElemento->getProximo();

						tmpElemento->setProximo(antElemento->getProximo());
						antElemento->setProximo(tmpElemento);

						size += 1;
					}
				}
			}
		}

		/*!
		 *  \brief Funcao adicionaEmOrdem
  		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que entrara na lista.
		 *  \return nao possui.
		 *	\sa listaVazia(), adicionaNoInicio(...), maior(...), e
		 *		adicionaNaPosicao(...)
		 *
		 *  Se a lista estiver vazia, entao chama a funcao adicionaNoInicio
		 * 		para realizar o processo de adicao do dado recebido como
		 *		argumento. Caso contrario, entao caminha por todos vertices da
		 *		estrutura e para cada um deles compara se a informacao do
		 *		vertice e maior do que o dado passado como argumento atraves
		 *		da funcao maior, e, tambem verifica se o proximo vertice
		 *		existe. Se alguma dessas possibilidade forem verdadeiras,
		 *		entao o laco e parado e ira adicionar o dado uma posicao antes
		 *		de um elemento maior que ele, ou, no fim da lista, caso o dado
		 *		a ser inserido for maior que todos os outros elementos. O
		 *	 	processo de adicao fica por conta da funcao adicionaNaPosicao
		 *		que e chamada por ultimo.
		 */
		void adicionaEmOrdem(const T &dado) {
			if (listaVazia()) {
				adicionaNoInicio(dado);
			} else {
				Elemento<T> *tmpElemento = head;

				int i = 0;
				for (; i < size; i++) {
					if (maior(tmpElemento->getInfo(), dado) ||
						tmpElemento->getProximo() == nullptr)
							break;

					tmpElemento = tmpElemento->getProximo();
				}

				adicionaNaPosicao(dado, i);
			}
		}

		/*!
		 *	\brief Funcao retira
		 *  \param nao possui.
		 *  \return o tipo generico que representa o dado retirado da lista.
		 *	\sa listaVazia(), retiraDaPosicao(...)
		 *
		 *  Se a lista nao estiver vazia, entao \return uma chamada para a
		 *		funcao retiraDaPosicao realizar o processo de remocao na
		 *		posicao tamanho - 1.
		 */
		T retira() {
			if (listaVazia())
				throw "problema";
			else
				return retiraDaPosicao(size-1);
		}

		/*!
		 * 	\brief Funcao retiraDoInicio
		 *  \param nao possui.
		 *  \return o tipo generico que representa o dado retirado da lista, o
		 *  	que foi salvo temporariamente durante o processo.
		 *	\sa listaVazia()
		 *
		 *  Se a lista nao estiver vazia, entao salva temporariamente o dado
		 *		que sera retirado com o auxilio de um vertice temporario,
		 *		define o novo head como o elemento para qual o head que sera
		 *		deletado apontava, arruma o sentinela, diminui o tamanho da
		 *		estrutura e deleta o nodo temporario.
		 */
		T retiraDoInicio() {
			if (listaVazia()) {
				throw "problema";
			} else {
				Elemento<T> *tmpElemento = head;
				T tmpInfo = head->getInfo();

				head = head->getProximo();
				sentinel->setProximo(head);
				size -= 1;

				delete tmpElemento;
				return tmpInfo;
			}
		}

		/*!
		 *  \brief Funcao retiraDaPosicao
		 *	\param posicao e um inteiro que indica a posicao em que deve-se
		 *		tentar retirar o dado.
		 *  \return o tipo generico que representa o dado retirado da lista, o
		 *		que foi salvo temporariamente durante o processo.
		 *	\sa retiraDoInicio()
		 *
		 *  Se a posicao for valida e ser a zero, chama a funcao
		 *		retiraDoInicio para realizar o processo de remocao do dado. Se
		 *		a posicao nao for a zero, entao caminha ate o vertice anterior
		 *		ao da posicao em que se pretende deletar com outro elemento
		 *		temporario. Ao chegar nessa posicao, salva temporariamente o
		 *		dado e o vertice que serao deletados, aponta o vertice,
		 *		anterior ao nodo que sera deletado, para o vertice seguinte,
		 *		ao que sera deletado. Por fim, diminui o numero que indica o
		 *		tamanho da lista e deleta o vertice.
		 */
		T retiraDaPosicao(int pos) {
			if (pos >= size) {
				throw "problema";
			} else {
				if (pos == 0) {
					return retiraDoInicio();
				} else {
					Elemento<T> *antElemento, *tmpElemento;
					T tmpInfo;

					antElemento = head;

					while (--pos != 0)
						antElemento = antElemento->getProximo();

					tmpElemento = antElemento->getProximo();
					tmpInfo = tmpElemento->getInfo();
					antElemento->setProximo(tmpElemento->getProximo());
					size -= 1;
					delete tmpElemento;
					return tmpInfo;
				}
			}
		}

		/*!
		 *  \brief Funcao retiraEspecifico
  		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser retirado da lista.
		 *	\return uma chamada para a funcao retiraDaPosicao.
		 *	\sa listaVazia(), posicao(...), retiraDaPosicao(...)
		 *
		 *  Se a lista nao estiver vazia, entao chama a funcao posicao para ter
		 *		o local do dado passado como argumento e passa esse local para
		 *		a funcao retiraEspecifico que fara o processo de retirada do
		 *		dado.
		 */
		T retiraEspecifico(const T &dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				return retiraDaPosicao(posicao(dado));
			}
		}

		/*!
		 *  \brief Funcao eliminaDoInicio
		 *  \param nao possui.
		 *	\return nao possui.
		 *
		 *	Deleta o head, diz que o atual head e o elemento que o antigo
		 *		head apontava e aponta o sentinela para o novo head.
		 */
		void eliminaDoInicio() {
			delete head;
			head = head->getProximo();
			sentinel->setProximo(head);
		}

		/*!
		 *	\brief Funcao destroiLista
		 *	\param nao possui.
		 *  \return nao possui.
		 *	\sa eliminaDoInicio(), listaVazia()
		 *
		 *  Se a lista estiver vazia, entao deleta o head. Caso contrario,
		 *		entao caminha por todos os elementos nao nulos da estrutura com
		 *		o auxilio de um vertice temporario e para cada um deles
		 *		diminui o tamanho atual da lista e chama a funcao
		 *		eliminaDoInicio() que e responsavel por deletar o nodo.
		 */
		void destroiLista() {
			if (listaVazia()) {
				delete head;
			} else {
				Elemento<T> *tmpElemento = head;

				while (size != 0) {
					tmpElemento = tmpElemento->getProximo();
					sentinel->setProximo(tmpElemento);
					eliminaDoInicio();
					size -= 1;
				}
			}
		}

		/*!
		 *  \brief Funcao constante posicao
  		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser procurado na lista.
		 *	\return um inteiro que possui a posicao do valor passado como
		 *		argumento.
		 *
		 *	Caminha por todos os vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento. Se
		 *		houver igualdade, entao o laco e parado, e, a posicao
		 *		onde houve igualdade e armazenada para um futuro retorno. Ja
		 *		se nao houver igualdade, o valor da posicao fica igua a
		 *		variavel size e entao a execucao sera redirecionada para
		 *		lugar nenhum.
		 */
		int posicao(const T &dado) const {
			Elemento<T> *tmpElemento = head;

			int i = 0;

			for (; i < size; i++) {
				if (tmpElemento->getInfo() == dado)
					break;

				tmpElemento = tmpElemento->getProximo();
			}

			if (i == size)
				throw "problema";
			else
				return i;
		}

		/*!
		 *  \brief Funcao ponteiro constante posicaoMem
  		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser procurado na lista.
		 *	\return um inteiro que possui a posicao na memoria do valor
		 *		passado como argumento.
		 *
		 *	Caminha por todos os vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento. Se
		 *		houver igualdade, entao o laco e parado, e, a posicao
		 *		onde houve igualdade e armazenada para um futuro retorno. Ja
		 *		se nao houver igualdade, o valor da posicao fica igua a
		 *		variavel size e entao a execucao sera redirecionada para
		 *		lugar nenhum.
		 */
		T *posicaoMem(const T &dado) const {
			Elemento<T> *tmpElemento = head;

			int i = 0;
			for (; i < size; i++) {
				if (tmpElemento->getInfo() == dado)
					break;

				 tmpElemento = tmpElemento->getProximo();
			}

			if (i == size)
				throw "problema";
			else
				return &tmpElemento;
		}

		/*!
		 *  \brief Funcao mostra
		 *	\param pos e o inteiro que indica a posicao que deve mostrar a
		 *		info que ela possui.
		 *	\return um tipo generico que representa o dado na posicao.
		 *
		 *  Se for uma posicao valida, entao caminha ate o vertice da posicao
		 *		desejada com o auxilio de um ponteiro temporario e retorna a
		 *		informacao que o elemento dessa posicao contem. Posicao deve
		 *		ser menor que o tamanho da lista.
		 */
		T mostra(int pos) {
			if (pos >= size) {
				throw "problema";
			} else {
				Elemento<T> *tmpElemento = head;

				while (pos-- != 0)
					tmpElemento = tmpElemento->getProximo();

				return tmpElemento->getInfo();
			}
		}

		/*!
		 *  \brief Funcao verUltimo
		 *  \param nao possui.
		 *  \return a posicao do ultimo elemento na lista.
		 */
		int verUltimo() {
			return size - 1;
		}

		/*!
		 *  \brief Funcao contem
		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que sera procurado na lista.
		 *	\return um valor booleano que indica se a lista possui ou nao o
		 *		valor passado.
		 *	\sa igual(...)
		 *
		 * 	Caminha por todos vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento atraves
		 *		da funcao igual. Se houver igualdade, entao o laco e parado.
		 */
		bool contem(const T &dado) {
			Elemento<T> *tmpElemento = head;

			while (size != 0) {
				if (igual(tmpElemento->getInfo(), dado))
					return true;

				tmpElemento = tmpElemento->getProximo();
				size -= 1;
			}

			if (size != 0)
				delete tmpElemento;

			return false;
		}

		/*!
		 *  \brief Funcao constante listaVazia
		 *  \param nao possui.
		 *  \return o valor booleano que resulta da comparacao.
		 *
		 * 	Verifica se a lista esta vazia ao checar se o atributo size e igual
		 *		a zero.
		 */
		bool listaVazia() const {
			return size == 0;
		}

		/*!
		 *	\brief Funcao igual
		 *  \param dado1 e um tipo generico que representa o primeiro dado.
		 *	\param dado2 e um tipo generico que representa o segundo dado.
		 *  \return o valor booleano que resulta da comparacao.
		 *
		 *  Verifica se o primeiro dado e igual ao segundo dado.
		 */
		bool igual(T dado1, T dado2) {
			return dado1 == dado2;
		}

		/*!
		 *	\brief Funcao maior
		 *  \param dado1 e um tipo generico que representa o primeiro dado.
		 *	\param dado2 e um tipo generico que representa o segundo dado.
		 *  \return o valor booleano que resulta da comparacao.
		 *
		 * 	Verifica se o primeiro dado e maior que o segundo dado.
		 */
		bool maior(T dado1, T dado2) {
			return dado1 > dado2;
		}

		/*!
		 *  \brief Funcao menor
		 *  \param dado1 e um tipo generico que representa o primeiro dado.
		 *	\param dado2 e um tipo generico que representa o segundo dado.
		 *  \return o valor booleano que resulta da comparacao.
		 *
		 *	Verifica se o primeiro dado e menor que o segundo dado.
		 */
		bool menor(T dado1, T dado2) {
			return dado1 < dado2;
		}

	private:
		Elemento<T> *head;      //!< objeto cabeca da lista
		Elemento<T> *sentinel;  //!< objeto sentinela da lista
		int size;				//!< indica o atual tamanho da lista
};
