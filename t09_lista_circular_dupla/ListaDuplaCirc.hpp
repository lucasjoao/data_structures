/*!
 *  \brief ListaDuplaCirc.hpp
 *	\copyright Copyright [2016], Lucas Joao Martins
 *  \author Lucas Joao Martins
 *
 *	Implementa a estrutura lista duplamente circular atraves de template.
 */

#include "ElementoDuplo.hpp"

template<typename T>
class ListaDuplaCirc {
	public:
		/*!
		 *  \brief Construtor
		 *
		 *	Inicializa a lista com tamanho zero, head aponta para nullptr e
		 *		sentinela aponta para head.
		 */
		ListaDuplaCirc() {
			size = 0;
			head = nullptr;
			sentinel = new Elemento<T>(0, nullptr, head);
		}

		/*!
		 *  \brief Destrutor
		 *	\sa destroiListaDuplo()
		 */
		~ListaDuplaCirc() {
			destroiListaDuplo();
		}

		/*!
		 *  \brief Funcao adicionaDuplo
		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado a ser adicionado na lista.
		 *	\return nao possui retorno
		 *	\sa listaVazia(), adicionaNoInicioDuplo(...) e
		 *		adicionaNaPosicaoDuplo(...)
		 *
		 *  Se a lista estiver vazia, entao adiciona no inicio. Caso contrario
		 *		adiciona no fim (ultima posicao que corresponde ao size).
		 */
		void adicionaDuplo(const T &dado) {
			if (listaVazia())
				adicionaNoInicioDuplo(dado);
			else
				adicionaNaPosicaoDuplo(dado, size);
		}

		/*!
		 *  \brief Funcao adicionaNoInicioDuplo
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
		void adicionaNoInicioDuplo(const T &dado) {
			Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr, nullptr);

			if (tmpElemento == nullptr) {
				throw "problema";
			} else {
				sentinel->setProximo(tmpElemento);
				tmpElemento->setBack(sentinel);

			    if (size != 0) {
					tmpElemento->setProximo(head);
					head->setBack(tmpElemento);
					head = tmpElemento;
			    } else {
					head = tmpElemento;
					head->setProximo(sentinel);
					sentinel->setBack(head);
			    }

			    size += 1;
			}
		}

		/*!
		 *  \brief Funcao adicionaNaPosicaoDuplo
		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que ficara na primeira posicao da lista.
 		 *	\param pos e um inteiro que indica a posicao em que deve-se
		 *		tentar adicionar o dado.
		 *  \return nao possui.
		 *	\sa adicionaNoInicioDuplo(...)
		 *
		 *  Se a posicao for valida e ser a zero, chama a funcao
		 *		adicionaNoInicioDuplo para realizar o processo de adicao com o
		 *		dado recebido como argumento. Se a posicao nao for a zero,
		 * 		entao istancia um novo Elemento temporario que aponta para um
		 *		nullptr e possui o dado passado como argumento, e, se houver
		 *		espaco na memoria para alocar essa instanciacao, entao caminha
		 *		ate o vertice anterior ao da posicao em que se pretende
		 *		adicionar o dado com outro elemento temporario. Ao chegar
		 *		nessa posicao, aponta o vertice anterior ao primeiro elemento
		 *		temporario criado e aponta esse ultimo para o vertice seguinte
		 *		ao da posicao anterior. Tambem aponta o anterior do elemento
		 *		temporario para o elemento anterior e se o proximo elemento
		 *		apos o temporario existir, ou seja, for diferente de um
		 *		nullptr, aponta o anterior dele para o elemento temporario.
		 *		Por fim, aumenta o numero que indica o tamanho da lista.
		 */
		void adicionaNaPosicaoDuplo(const T &dado, int pos) {
			if (pos > size) {
				throw "problema";
			} else {
				if (pos == 0) {
					adicionaNoInicioDuplo(dado);
				} else {
					Elemento<T> *tmp = new Elemento<T>(dado, nullptr, nullptr);
					Elemento<T> *antElemento;

					if (tmp == nullptr) {
						throw "problema";
					} else {
						antElemento = head;

						while (--pos != 0)
							antElemento = antElemento->getProximo();

						tmp->setProximo(antElemento->getProximo());

						if (tmp->getProximo() != nullptr)
							tmp->getProximo()->setBack(tmp);

						antElemento->setProximo(tmp);
						tmp->setBack(antElemento);
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
		 *	\sa listaVazia(), adicionaNoInicioDuplo(...), maior(...), e
		 *		adicionaNaPosicaoDuplo(...)
		 *
		 *  Se a lista estiver vazia, entao chama funcao adicionaNoInicioDuplo
		 * 		para realizar o processo de adicao do dado recebido como
		 *		argumento. Caso contrario, entao caminha por todos vertices da
		 *		estrutura e para cada um deles compara se a informacao do
		 *		vertice e maior do que o dado passado como argumento atraves
		 *		da funcao maior, e, tambem verifica se o proximo vertice
		 *		existe. Se alguma dessas possibilidade forem verdadeiras,
		 *		entao o laco e parado e ira adicionar o dado uma posicao antes
		 *		de um elemento maior que ele, ou, no fim da lista, caso o dado
		 *		a ser inserido for maior que todos os outros elementos. A
		 *	 	adicao fica por conta da funcao adicionaNaPosicaoDuplo que e
		 *		chamada por ultimo.
		 */
		void adicionaEmOrdem(const T &data) {
			if (listaVazia()) {
				adicionaNoInicioDuplo(data);
			} else {
				Elemento<T> *tmpElemento = head;

				int i = 0;
				for (; i < size; i++) {
					if (maior(tmpElemento->getInfo(), data) ||
						tmpElemento->getProximo() == nullptr)
							break;

					tmpElemento = tmpElemento->getProximo();
				}

				adicionaNaPosicaoDuplo(data, i);
			}
		}

		/*!
		 *	\brief Funcao retiraDuplo
		 *  \param nao possui.
		 *  \return o tipo generico que representa o dado retirado da lista.
		 *	\sa listaVazia(), retiraDaPosicaoDuplo(...)
		 *
		 *  Se a lista nao estiver vazia, entao \return uma chamada para a
		 *		funcao retiraDaPosicao realizar o processo de remocao na
		 *		posicao tamanho - 1.
		 */
		T retiraDuplo() {
			if (listaVazia())
				throw "problema";
			else
				return retiraDaPosicaoDuplo(size-1);
		}

		/*!
		 * 	\brief Funcao retiraDoInicioDuplo
		 *  \param nao possui.
		 *  \return o tipo generico que representa o dado retirado da lista, o
		 *  	que foi salvo temporariamente durante o processo.
		 *	\sa listaVazia()
		 *
		 *  Se a lista nao estiver vazia, entao salva temporariamente o dado
		 *		que sera retirado com o auxilio de um vertice temporario,
		 *		define o novo head como o elemento para qual o head que sera
		 *		deletado apontava e se o head existir, ou seja, nao
		 *		for nulo, entao aponta o anterior do head para o elemento
		 *		temporario. Por fim, diminui o tamanho da estrutura e deleta o
		 *		nodo temporario.
		 */
		T retiraDoInicioDuplo() {
			if (listaVazia()) {
				throw "problema";
			} else {
				Elemento<T> *tmpElemento = head;
				T tmpInfo = head->getInfo();

				head = head->getProximo();
				sentinel->setProximo(head);
				if (head != nullptr)
					head->setBack(sentinel);

				size -= 1;
				delete tmpElemento;
				return tmpInfo;
			}
		}

		/*!
		 *  \brief Funcao retiraDaPosicaoDuplo
		 *	\param posicao e um inteiro que indica a posicao em que deve-se
		 *		tentar retirar o dado.
		 *  \return o tipo generico que representa o dado retirado da lista, o
		 *		que foi salvo temporariamente durante o processo.
		 *	\sa retiraDoInicioDuplo()
		 *
		 *  Se a posicao for valida e ser a zero, chama a funcao
		 *		retiraDoInicioDuplo para realizar o processo de remocao do
		 *		dado. Se a posicao nao for a zero, entao caminha ate o vertice
		 *		anterior ao da posicao em que se pretende deletar com outro
		 *		elemento temporario. Ao chegar nessa posicao, salva
		 *		temporariamente o dado e o vertice que serao deletados, aponta
		 *		o vertice, anterior ao nodo que sera deletado, para o vertice
		 *		seguinte, ao que sera deletado. Se o proximo vertice existir,
		 *		ou seja, for diferente de um nullptr, entao aponta o anterior
		 *		dele para o vertice anterior ao da posicao que sera deletada.
		 *		Por fim, diminui o numero que indica o tamanho da lista e
		 *		deleta o vertice.
		 */
		T retiraDaPosicaoDuplo(int pos) {
			if (pos >= size) {
				throw "problema";
			} else {
				if (pos == 0) {
					return retiraDoInicioDuplo();
				} else {
					Elemento<T> *antElemento, *tmpElemento;
					T tmpInfo;

					antElemento = head;

					while (--pos != 0)
						antElemento = antElemento->getProximo();

					tmpElemento = antElemento->getProximo();
					tmpInfo = tmpElemento->getInfo();
					antElemento->setProximo(tmpElemento->getProximo());

					if (tmpElemento->getProximo() != nullptr)
						tmpElemento->getProximo()->setBack(antElemento);

					size -= 1;
					delete tmpElemento;
					return tmpInfo;
				}
			}
		}

		/*!
		 *  \brief Funcao retiraEspecificoDuplo
		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser retirado da lista.
		 *	\return uma chamada para a funcao retiraDaPosicao.
		 *	\sa listaVazia(), posicaoDuplo(...), retiraDaPosicaoDuplo(...)
		 *
		 *  Se a lista nao estiver vazia, entao chama a funcao posicaoDuplo
		 *		para ter o local do dado passado como argumento e passa esse
		 *		local para a funcao retiraDaPosicaoDuplo que fara o processo
		 *		de retirada do dado.
		 */
		T retiraEspecificoDuplo(const T &dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				return retiraDaPosicaoDuplo(posicaoDuplo(dado));
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
		void eliminaDoInicioDuplo() {
			delete head;
			head = head->getProximo();
			sentinel->setProximo(head);
		}

		/*!
		 *	\brief Funcao destroiLista
		 *	\param nao possui.
		 *  \return nao possui.
		 *	\sa eliminaDoInicioDuplo(), listaVazia()
		 *
		 *  Se a lista estiver vazia, entao deleta o head. Caso contrario,
		 *		entao caminha por todos os elementos nao nulos da estrutura com
		 *		o auxilio de um vertice temporario e para cada um deles
		 *		diminui o tamanho atual da lista e chama a funcao
		 *		eliminaDoInicio() que e responsavel por deletar o nodo.
		 */
		void destroiListaDuplo() {
			if (listaVazia()) {
				delete head;
			} else {
				Elemento<T> *tmpElemento = head;

				while (size != 0) {
					tmpElemento = tmpElemento->getProximo();
					sentinel->setProximo(tmpElemento);
					eliminaDoInicioDuplo();
					size -= 1;
				}
			}
		}

		/*!
		 *  \brief Funcao constante posicaoDuplo
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
		int posicaoDuplo(const T& dado) const {
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
		 *  \brief Funcao constante posicaoMemDuplo
		 *	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser procurado na lista.
		 *	\return um pointer inteiro que possui a posicao na memoria do valor
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
		T* posicaoMemDuplo(const T &dado) const {
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
		 *  \brief Funcao contemDuplo
		 * 	\param dado passado por referencia e um tipo generico constante
		 *		que representa o dado que sera procurado na lista.
		 *	\return um valor booleano que indica se a lista possui ou nao o
		 *		valor passado.
		 *	\sa igual(...)
		 *
		 * 	Caminha por todos vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento atraves
		 *		da funcao igual. Se houver igualdade, entao o laco e parado.
		 */
		bool contemDuplo(const T &dado) {
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
		Elemento<T> *head;  	//!< objeto cabeca da lista
		Elemento<T> *sentinel;  //!< objeto sentinela da lista
		int size;				//!< indica o atual tamanho da lista
};
