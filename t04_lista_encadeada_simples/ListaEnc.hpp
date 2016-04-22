/**
 *  Copyright [2016] - Lucas Joao Martins
 *  ListaEnc.hpp
 */

#include "Elemento.hpp"

/**
 *  Classe ListaEnc
 *	Implementa a estrutura de dados lista encadeada simples atraves de template
 *		e ponteiros.
 */
template<typename T>
class ListaEnc {
	public:
		/**
		 *  Construtor
		 *	Inicializa a lista ao dizer que seu tamanho e zero ao mesmo tempo
		 * 		em que o head (primeiro vertice) aponta para nullptr.
		 */
		ListaEnc() {
			size = 0;
			head = nullptr;
		}

		/**
		 *  Destrutor
		 *	Chama a funcao destroiLista.
		 */
		~ListaEnc() {
			destroiLista();
		}

		/**
		 *  Funcao adiciona
		 *  Se a lista estiver vazia, entao chama a funcao adicionaNoInicio
		 * 		para realizar o processo de adicao do dado recebido como
		 *		argumento. Caso contrario, entao chama a funcao
		 *		adicionaNaPosicao para realizar o processo de adicao do dado
		 *		recebido como argumento na posicao correspondente ao atual
		 *		tamanho da lista.
		 *	Verifica o status da lista atraves da funcao listaVazia.
		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado a ser adicionado na lista.
		 *	Nao possui retorno.
		 */
		void adiciona(const T &dado) {
			if (listaVazia())
				adicionaNoInicio(dado);
			else
				adicionaNaPosicao(dado, size);
		}

		/**
		 *  Funcao adicionaNoInicio
		 *  Istancia um novo Elemento temporario que aponta para um nullptr e
		 *		possui o dado passado como argumento, e, se houver espaco na
		 *		memoria para alocar essa instanciacao, entao aponta o elemento
		 *		temporario para o head atual, define o elemento temporario
		 *		como head e aumenta o numero que indica o tamanho da lista.
		 *  Verifica a situacao da memoria ao comparar se o novo elemento
		 *		temporario e igual a um nullptr.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
 		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que ficara na primeira posicao da lista.
		 *  Nao possui retorno.
		 */
		void adicionaNoInicio(const T &dado) {
			Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr);

			if (tmpElemento == nullptr) {
				throw "problema";
			} else {
				tmpElemento->setProximo(head);
				head = tmpElemento;
				size += 1;
			}
		}

		/**
		 *  Funcao adicionaNaPosicao
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

		/**
		 *  Funcao adicionaEmOrdem
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
		 *  Verifica o status da lista atraves da funcao listaVazia.
  		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que entrara na lista.
		 *  Nao possui retorno.
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

		/**
		 *	Funcao retira
		 *  Se a lista nao estiver vazia, entao retorna uma chamada para a
		 *		funcao retiraDaPosicao realizar o processo de remocao na
		 *		posicao tamanho - 1.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *  Nao possui parametro.
		 *  Retorna o tipo generico que representa o dado retirado da lista.
		 */
		T retira() {
			if (listaVazia())
				throw "problema";
			else
				return retiraDaPosicao(size-1);
		}

		/**
		 * 	Funcao retiraDoInicio
		 *  Se a lista nao estiver vazia, entao salva temporariamente o dado
		 *		que sera retirado com o auxilio de um vertice temporario,
		 *		define o novo head como o elemento para qual o head que sera
		 *		deletado apontava, diminui o tamanho da estrutura e deleta o
		 *		nodo temporario.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *  Nao possui parametro.
		 *  Retorna o tipo generico que representa o dado retirado da lista, o
		 *  	que foi salvo temporariamente durante o processo.
		 */
		T retiraDoInicio() {
			if (listaVazia()) {
				throw "problema";
			} else {
				Elemento<T> *tmpElemento = head;
				T tmpInfo = head->getInfo();
				head = head->getProximo();
				size -= 1;
				delete tmpElemento;
				return tmpInfo;
			}
		}

		/**
		 *  Funcao retiraDaPosicao
		 *  Se a posicao for valida e ser a zero, chama a funcao
		 *		retiraDoInicio para realizar o processo de remocao do dado. Se
		 *		a posicao nao for a zero, entao caminha ate o vertice anterior
		 *		ao da posicao em que se pretende deletar com outro elemento
		 *		temporario. Ao chegar nessa posicao, salva temporariamente o
		 *		dado e o vertice que serao deletados, aponta o vertice,
		 *		anterior ao nodo que sera deletado, para o vertice seguinte,
		 *		ao que sera deletado. Por fim, diminui o numero que indica o
		 *		tamanho da lista e deleta o vertice.
		 *	Verifica se e uma posicao valida ao comparar a posicao desejada
		 *		com o atual tamanho da lista, ja que a posicao deve ser menor
		 *		ou igual ao tamanho da lista.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *	Parametro posicao e um inteiro que indica a posicao em que deve-se
		 *		tentar retirar o dado.
		 *  Retorna o tipo generico que representa o dado retirado da lista, o
		 *		que foi salvo temporariamente durante o processo.
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

		/**
		 *  Funcao retiraEspecifico
		 *  Se a lista nao estiver vazia, entao chama a funcao posicao para ter
		 *		o local do dado passado como argumento e passa esse local para
		 *		a funcao retiraEspecifico que fara o processo de retirada do
		 *		dado.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
  		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser retirado da lista.
		 *	Retorna uma chamada para a funcao retiraDaPosicao.
		 */
		T retiraEspecifico(const T &dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				return retiraDaPosicao(posicao(dado));
			}
		}

		/**
		 *  Funcao eliminaDoInicio
		 *	Deleta o head e diz que o atual head e o elemento que o antigo
		 *		head apontava.
		 *	Nao possui argumento.
		 *  Nao possui retorno.
		 */
		void eliminaDoInicio() {
			delete head;
			head = head->getProximo();
		}

		/**
		 *	Funcao destroiLista
		 *  Se a lista estiver vazia, entao deleta o head. Caso contrario,
		 *		entao caminha por todos os elementos não nulos da estrutura com
		 *		o auxilio de um vertice temporario e para cada um deles
		 *		diminui o tamanho atual da lista e chama a funcao
		 *		eliminaDoInicio que e responsavel por deletar o nodo.
		 *	Verifica o status da lista atraves da funcao listaVazia.
		 *	Nao possui argumento.
		 *  Nao possui retorno.
		 */
		void destroiLista() {
			if (listaVazia()) {
				delete head;
			} else {
				Elemento<T> *tmpElemento = head;

				while (tmpElemento != nullptr) {
					tmpElemento = tmpElemento->getProximo();
					eliminaDoInicio();
					size -= 1;
				}
			}
		}

		/**
		 *  Funcao constante posicao
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

		/**
		 *  Funcao ponteiro constante posicaoMem
		 *	Caminha por todos os vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento. Se
		 *		houver igualdade, entao o laco e parado, e, a posicao
		 *		onde houve igualdade e armazenada para um futuro retorno. Ja
		 *		se nao houver igualdade, o valor da posicao fica igua a
		 *		variavel size e entao a execucao sera redirecionada para
		 *		lugar nenhum.
  		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que deve ser procurado na lista.
		 *	Retorna um inteiro que possui a posicao na memoria do valor
		 *		passado como argumento.
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

		/**
		 *  Funcao contem
		 * 	Caminha por todos vertices da estrutura e para cada um deles
		 *		compara o elemento com o dado passado como argumento atraves
		 *		da funcao igual. Se houver igualdade, entao o laco e parado.
		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que sera procurado na lista.
		 *	Retorna um valor booleano que indica se a lista possui ou nao o
		 *		valor passado.
		 */
		bool contem(const T &dado) {
			Elemento<T> *tmpElemento = head;

			while (tmpElemento != nullptr) {
				if (igual(tmpElemento->getInfo(), dado))
					return true;

				tmpElemento = tmpElemento->getProximo();
			}

			return false;
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

	private:
		Elemento<T> *head;  //!< objeto cabeca da lista, ocupa a primeira pos
		int size;			//!< indica o atual tamanho da lista
};
