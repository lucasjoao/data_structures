/**
 *  Copyright [2016] - Lucas Joao Martins
 *  ListaDupla.hpp
 */

#include "ElementoDuplo.hpp"

/**
 *  Classe ListaDupla
 *	Implementa a estrutura de dados lista duplamente encadeada atraves de
 *		template e ponteiros.
 */
template<typename T>
class ListaDuplaCirc {
	public:
		/**
		 *  Construtor
		 *	Inicializa a lista ao dizer que seu tamanho e zero ao mesmo tempo
		 * 		em que o head (primeiro vertice) aponta para nullptr.
		 */
		ListaDuplaCirc() {
			size = 0;
			head = nullptr;
			sentinel = new Elemento<T>(0, nullptr, head);
		}

		/**
		 *  Destrutor
		 *	Chama a funcao destroiListaDuplo.
		 */
		~ListaDuplaCirc() {
			destroiListaDuplo();
		}

		/**
		 *  Funcao adicionaNoInicioDuplo
		 *  Istancia um novo Elemento temporario que aponta para um nullptr e
		 *		possui o dado passado como argumento, e, se houver espaco na
		 *		memoria para alocar essa instanciacao, entao aponta o elemento
		 *		temporario para o head atual e se o head existir, ou seja, nao
		 *		for nulo, entao aponta o anterior do head para o elemento
		 *		temporario. Por fim, define o elemento temporario como head e
		 *		aumenta o numero que indica o tamanho da lista.
		 *  Verifica a situacao da memoria ao comparar se o novo elemento
		 *		temporario e igual a um nullptr.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
 		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que ficara na primeira posicao da lista.
		 *  Nao possui retorno.
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

		/**
		 *  Funcao adicionaNaPosicao
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
		 *	Verifica se e uma posicao valida ao comparar a posicao desejada
		 *		com o atual tamanho da lista, ja que a posicao deve ser menor
		 *		que o tamanho da lista.
		 *  Verifica a situacao da memoria ao comparar se o novo elemento
		 *		temporario e igual a um nullptr.
		 *  Se houver problema em alguma das duas verificacoes, redireciona a
		 *		execucao para lugar nenhum.
 		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que ficara na primeira posicao da lista.
 		 *	Parametro pos e um inteiro que indica a posicao em que deve-se
		 *		tentar adicionar o dado.
		 *  Nao possui retorno.
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

		/**
		 *  Funcao adicionaDuplo
		 *  Se a lista estiver vazia, entao chama funcao adicionaNoInicioDuplo
		 * 		para realizar o processo de adicao do dado recebido como
		 *		argumento. Caso contrario, entao chama a funcao
		 *		adicionaNaPosicaoDuplo para realizar a adicao do dado
		 *		recebido como argumento na posicao correspondente ao atual
		 *		tamanho da lista.
		 *	Verifica o status da lista atraves da funcao listaVazia.
		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado a ser adicionado na lista.
		 *	Nao possui retorno.
		 */
		void adicionaDuplo(const T &dado) {
			if (listaVazia())
				adicionaNoInicioDuplo(dado);
			else
				adicionaNaPosicaoDuplo(dado, size);
		}

		/**
		 *  Funcao adicionaEmOrdem
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
		 *  Verifica o status da lista atraves da funcao listaVazia.
  		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que entrara na lista.
		 *  Nao possui retorno.
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

		/**
		 * 	Funcao retiraDoInicioDuplo
		 *  Se a lista nao estiver vazia, entao salva temporariamente o dado
		 *		que sera retirado com o auxilio de um vertice temporario,
		 *		define o novo head como o elemento para qual o head que sera
		 *		deletado apontava e se o head existir, ou seja, nao
		 *		for nulo, entao aponta o anterior do head para o elemento
		 *		temporario. Por fim, diminui o tamanho da estrutura e deleta o
		 *		nodo temporario.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *  Nao possui parametro.
		 *  Retorna o tipo generico que representa o dado retirado da lista, o
		 *  	que foi salvo temporariamente durante o processo.
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

		/**
		 *  Funcao retiraDaPosicaoDuplo
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
		 *	Verifica se e uma posicao valida ao comparar a posicao desejada
		 *		com o atual tamanho da lista, ja que a posicao deve ser menor
		 *		ao tamanho da lista.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *	Parametro posicao e um inteiro que indica a posicao em que deve-se
		 *		tentar retirar o dado.
		 *  Retorna o tipo generico que representa o dado retirado da lista, o
		 *		que foi salvo temporariamente durante o processo.
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

		/**
		 *	Funcao retiraDuplo
		 *  Se a lista nao estiver vazia, entao retorna uma chamada para a
		 *		funcao retiraDaPosicaoDuplo realizar o processo de remocao na
		 *		posicao tamanho - 1.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *  Nao possui parametro.
		 *  Retorna o tipo generico que representa o dado retirado da lista.
		 */
		T retiraDuplo() {
			if (listaVazia())
				throw "problema";
			else
				return retiraDaPosicaoDuplo(size-1);
		}

		/**
		 *  Funcao retiraEspecificoDuplo
		 *  Se a lista nao estiver vazia, entao chama a funcao posicaoDuplo
		 *		para ter o local do dado passado como argumento e passa esse
		 *		local para a funcao retiraDaPosicaoDuplo que fara o processo
		 *		de retirada do dado.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
  		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser retirado da lista.
		 *	Retorna uma chamada para a funcao retiraDaPosicaoDuplo.
		 */
		T retiraEspecificoDuplo(const T &dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				return retiraDaPosicaoDuplo(posicaoDuplo(dado));
			}
		}


		/**
		 *  Funcao constante posicaoDuplo
		 *	Caminha por todos os vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento. Se
		 *		houver igualdade, entao o laco e parado, e, a posicao
		 *		onde houve igualdade e armazenada para um futuro retorno. Ja
		 *		se nao houver igualdade, o valor da posicao fica igua a
		 *		variavel size e entao a execucao sera redirecionada para
		 *		lugar nenhum.
  		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser procurado na lista.
		 *	Retorna um inteiro que possui a posicao do valor passado como
		 *		argumento.
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

		/**
		 *  Funcao constante posicaoMemDuplo
		 *	Caminha por todos os vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento. Se
		 *		houver igualdade, entao o laco e parado, e, a posicao
		 *		onde houve igualdade e armazenada para um futuro retorno. Ja
		 *		se nao houver igualdade, o valor da posicao fica igua a
		 *		variavel size e entao a execucao sera redirecionada para
		 *		lugar nenhum.
  		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser procurado na lista.
		 *	Retorna um ponteiro que possui a posicao na memoria do valor
		 *		passado como argumento.
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

		/**
		 *  Funcao mostra
		 *  Se for uma posicao valida, entao caminha ate o vertice da posicao
		 *		desejada com o auxilio de um ponteiro temporario e retorna a
		 *		informacao que o elemento dessa posicao contem.
		 *  Verifica se e uma posicao valida ao comparar a posicao desejada
		 *		com o atual tamanho da lista, ja que a posicao deve ser menor
		 *		que o tamanho da lista.
		 *	Se houver problema na verificacao, redireciona a execucao para
		 *		lugar nenhum.
		 *	Retorna um tipo generico que representa o dado na posicao.
		 *	Parametro pos e o inteiro que indica a posicao que deve mostrar a
		 *		info que ela possui.
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

		/**
		 *  Funcao verUltimo
		 *  Retorna a posicao do ultimo elemento na lista.
		 *  Nao possui parametro.
		 */
		int verUltimo() {
			return size - 1;
		}

		/**
		 *  Funcao constante listaVazia
		 * 	Verifica se a lista esta vazia ao checar se o atributo size e igual
		 *		a zero.
		 *  Nao possui parametro.
		 *  Retorna o valor booleano que resulta da comparacao.
		 */
		bool listaVazia() const {
			return size == 0;
		}

		/**
		 *  Funcao contemDuplo
		 * 	Caminha por todos vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento atraves
		 *		da funcao igual. Se houver igualdade, entao o laco e parado.
		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que sera procurado na lista.
		 *	Retorna um valor booleano que indica se a lista possui ou nao o
		 *		valor passado.
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

		/**
		 *	Funcao igual
		 *  Verifica se o primeiro dado e igual ao segundo dado.
		 *  Parametro dado1 e um tipo generico que representa o primeiro dado.
		 *	Parametro dado2 e um tipo generico que representa o segundo dado.
		 *  Retorna o valor booleano que resulta da comparacao.
		 */
		bool igual(T dado1, T dado2) {
			return dado1 == dado2;
		}

		/**
		 *	Funcao maior
		 * 	Verifica se o primeiro dado e maior que o segundo dado.
		 *  Parametro dado1 e um tipo generico que representa o primeiro dado.
		 *	Parametro dado2 e um tipo generico que representa o segundo dado.
		 *  Retorna o valor booleano que resulta da comparacao.
		 */
		bool maior(T dado1, T dado2) {
			return dado1 > dado2;
		}

		/**
		 *  Funcao menor
		 *	Verifica se o primeiro dado e menor que o segundo dado.
		 *  Parametro dado1 e um tipo generico que representa o primeiro dado.
		 *	Parametro dado2 e um tipo generico que representa o segundo dado.
		 *  Retorna o valor booleano que resulta da comparacao.
		 */
		bool menor(T dado1, T dado2) {
			return dado1 < dado2;
		}

		/**
		 *	Funcao destroiListaDuplo
		 *  Se a lista estiver vazia, entao deleta o head. Caso contrario,
		 *		entao caminha por todos os elementos não nulos da estrutura com
		 *		o auxilio de um vertice temporario e para cada um deles
		 *		diminui o tamanho atual da lista e chama a funcao
		 *		eliminaDoInicioDuplo que e responsavel por deletar o nodo.
		 *	Verifica o status da lista atraves da funcao listaVazia.
		 *	Nao possui argumento.
		 *  Nao possui retorno.
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

		/**
		 *  Funcao eliminaDoInicioDuplo
		 *	Deleta o head e diz que o atual head e o elemento que o antigo
		 *		head apontava.
		 *	Nao possui argumento.
		 *  Nao possui retorno.
		 */
		void eliminaDoInicioDuplo() {
			delete head;
			head = head->getProximo();
			sentinel->setProximo(head);
		}

	private:
		Elemento<T> *head;  	//!< objeto cabeca da lista
		Elemento<T> *sentinel;  //!< objeto sentinela da lista
		int size;				//!< indica o atual tamanho da lista
};
