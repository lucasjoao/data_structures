/**
 *  Copyright [2016] - Lucas Joao Martins
 *  Lista.hpp
 */

/**
 *  Classe Lista
 *  Implementa a estrutura de dados lista de vetor atraves de template.
 */
template<typename T>
class Lista {
	private:
		T *dados;      //!< vetor que armazena os dados da estrutura
		int ultimo;    //!< indica a posicao do ultimo elemento na lista
		int maxLista;  //!< indica o tamanho do vetor

	public:
		/**
		 *  Construtor
		 *  Default e vazio.
		 */
		Lista() {}

		/**
		 *  Construtor
		 *  Utiliza um tipo explicito para evitar que o compilador o utilize
		 *  	com uma conversao implicita.
		 *  Inicializa a lista através do atributo ultimo.
		 *  Instancia um vetor para o atributo dados.
		 *  Parametro tam e um inteiro que indica o tamanho do vetor.
		 */
		explicit Lista(int tam) {
			maxLista = tam;
			ultimo = -1;
			dados = new T[tam];
		}

		/**
		 *  Funcao adiciona
		 *  Se a lista nao estiver cheia, entao aumenta o numero que indica a
		 *  	a posicao do ultimo e coloca um elemento nessa nova posicao.
		 *  Verifica o status da lista atraves da funcao listaCheia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *  Parametro dado e um tipo generico que representa o dado que ficara
		 *  	na ultima posicao da lista.
		 *  Nao possui retorno.
		 */
		void adiciona(T dado) {
			if (listaCheia()) {
				throw "problema";
			} else {
				ultimo += 1;
				dados[ultimo] = dado;
			}
		}

		/**
		 *  Funcao adicionaNoInicio
		 *  Se a lista nao estiver cheia, entao aumenta o numero que indica a
		 *  	a posicao do ultimo, empurra todos os dados para uma
		 *		posicao atras e coloca um elemento na primeira posicao.
		 *  Verifica o status da lista atraves da funcao listaCheia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *  Parametro dado e um tipo generico que representa o dado que ficara
		 *  	na primeira posicao da lista.
		 *  Nao possui retorno.
		 */
		void adicionaNoInicio(T dado) {
			if (listaCheia()) {
				throw "problema";
			} else {
				ultimo += 1;

				for (int i = ultimo; i > 0; i--)
					dados[i] = dados[i-1];

				dados[0] = dado;
			}
		}

		/**
		 *  Funcao adicionaNaPosicao
		 *  Se a lista nao estiver cheia e a posicao ser valida, entao aumenta
		 * 	 	o numero que indica a posicao do ultimo, empurra os dados, que
		 * 		estao entre o final e a posicao que sera adicionada, para uma
		 *		posicao atras e coloca um elemento na posicao indicada.
		 *  Verifica o status da lista atraves da funcao listaCheia.
		 * 	Verifica se e uma posicao valida atraves de duas variaveis bool
		 *		locais que armazenam o resultado das comparacoes adequadas.
		 *  Se houver problema em alguma verificacao, redireciona a execucao
		 *  	para lugar nenhum.
		 *  Parametro dado e um tipo generico que representa o dado que ficara
		 *  	na primeira posicao da lista.
		 *	Parametro posicao e um inteiro que indica a posicao em que deve-se
		 *		tentar adicionar o dado.
		 *  Nao possui retorno.
		 */
		void adicionaNaPosicao(T dado, int posicao) {
			bool menorZero = posicao < 0;
			bool maiorUlt = ultimo + 1 < posicao;

			if (listaCheia() || menorZero || maiorUlt) {
				throw "problema";
			} else {
				ultimo += 1;

				for (int i = ultimo; i > posicao; i--)
					dados[i] = dados[i-1];

				dados[posicao] = dado;
			}
		}

		/**
		 *  Funcao adicionaEmOrdem
		 *  Se a lista nao estiver cheia, entao percorre toda a estrutura e
		 *		para cada elemento dela compara o elemento e o dado que sera
		 * 		adicionado atraves da funcao maior. Assim, ira adicionar o dado
		 * 		uma posicao antes de um elemento maior que ele, ou, no
		 *		fim da lista, caso o dado a ser inserido for maior que todos
		 *		os outros elementos. O processo de adicao fica por conta da
		 *		funcao adicionaNaPosicao.
		 *  Verifica o status da lista atraves da funcao listaCheia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *  Parametro dado e um tipo generico que representa o dado que entrara
		 *  	na lista.
		 *  Nao possui retorno.
		 */
		void adicionaEmOrdem(T dado) {
			if (listaCheia()) {
				throw "problema";
			} else {
				int i = 0;
				for (; i <= ultimo; i++) {
					if (maior(dados[i], dado))
						break;
				}

				adicionaNaPosicao(dado, i);
			}
		}

		/**
		 *	Funcao retira
		 *  Se a lista nao estiver vazia, entao diminui o numero que indica a
		 *		posicao do ultimo elemento na estrutura.
		 *	Nao ha o processo de apagar o dado retirado da lista.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 *  Nao possui parametro.
		 *  Retorna o tipo generico que representa o dado retirado da lista.
		 */
		T retira() {
			if (listaVazia()) {
				throw "problema";
			} else {
				ultimo -= 1;
				return dados[ultimo + 1];
			}
		}

		/**
		 * 	Funcao retiraDoInicio
		 *  Se a lista nao estiver vazia, entao salva temporariamente o dado
		 *		que sera retirado, empura todos os outros dados para uma
		 * 		posicao a frente atraves de um laco e diminui o numero que
		 *		indica a posicao do ultimo.
		 *	Nao ha o processo de apagar o ultimo dado da lista, mas o dado
		 *		retirado e sobrescrito.
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
				T tmp = dados[0];

				for (int i = 0; i < ultimo; i ++)
					dados[i] = dados[i+1];

				ultimo -=1;

				return tmp;
			}
		}

		/**
		 *  Funcao retiraDaPosicao
		 *  Se a lista nao estiver vazia e a posicao ser valida, entao salva
		 * 	 	salva temporariamente o dado que sera retirado, empurra os
		 *		dados, que estao entre o final e a posicao que sera retirada,
		 *  	para uma posicao a frente e diminui o numero que indica a
		 * 		posicao do ultimo.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 * 	Verifica se e uma posicao valida atraves de duas variaveis bool
		 *		locais que armazenam o resultado das comparacoes adequadas.
		 *  Se houver problema em alguma verificacao, redireciona a execucao
		 *  	para lugar nenhum.
		 *	Nao ha o processo de apagar o ultimo dado da lista, mas o dado
		 *		retirado e sobrescrito.
		 *	Parametro posicao e um inteiro que indica a posicao em que deve-se
		 *		tentar retirar o dado.
		 *  Retorna o tipo generico que representa o dado retirado da lista, o
		 *		que foi salvo temporariamente durante o processo.
		 */
		T retiraDaPosicao(int posicao) {
			bool menorZero = posicao < 0;
			bool maiorUlt = ultimo < posicao;

			if (listaVazia() || menorZero || maiorUlt) {
				throw "problema";
			} else {
				T tmp = dados[posicao];

				for (int i = posicao; i < ultimo; i++)
					dados[i] = dados[i+1];

				ultimo -= 1;

				return tmp;
			}
		}

		/**
		 *  Funcao retiraEspecifico
		 *  Se a lista nao estiver vazia, entao chama a funcao posicao para ter
		 *		o local do dado passado como argumento e passa esse local para
		 *		a funcao retiraEspecifico que fara o processo de retirada do
		 *		dado.
		 *	O dado retirado e sobrescrito no processo realizado pela funcao
		 *		retiraDaPosicao.
		 *  Verifica o status da lista atraves da funcao listaVazia.
		 *  Se houver problema na verificacao, redireciona a execucao para
		 *  	lugar nenhum.
		 * 	Parametro dado e um tipo generico que representa o dado que deve
		 *		 ser retirado da lista.
		 *	Retorna uma chamada para a funcao retiraDaPosicao.
		 */
		T retiraEspecifico(T dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				return retiraDaPosicao(posicao(dado));
			}
		}

		/**
		 *  Funcao posicao
		 *	Percorre toda a estrutura e para cada elemento dela compara o
		 *		elemento com o dado passado como argumento atraves da funcao
		 *		igual. Se houver igualdade, entao o laco e parado, e, a posicao
		 *		onde houve igualdade e armazenada para um futuro retorno. Ja
		 *		se nao houver igualdade, o valor da posicao fica maior que a
		 *		variavel ultimo e entao a execucao sera redirecionada para
		 *		lugar nenhum.
		 *	Parametro dado e um tipo generico que representa o dado que tera a
		 *		sua posicao procurada na lista.
		 *	Retorna um inteiro que possui a posicao do valor passado como
		 *		argumento.
		 */
		int posicao(T dado) {
			int i = 0;

			for (; i <= ultimo; i++) {
				if (igual(dado, dados[i]))
					break;
			}

			if (i > ultimo)
				throw "problema";
			else
				return i;
		}

		/**
		 *  Funcao contem
		 * 	Percorre toda a estrutura e para cada elemento dela compara o
		 *		elemento com o dado passado como argumento atraves da funcao
		 *		igual. Se houver igualdade, entao o laco e parado.
		 *	Parametro dado e um tipo generico que representa o dado que sera
		 * 		procurado na lista.
		 *	Retorna um valor booleano que indica se a lista possui ou nao o
		 *		valor passado.
		 */
		bool contem(T dado) {
			for (int i = 0; i <= ultimo; i++)
				if (igual(dado, dados[i]))
					return true;

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
		 *  Funcao listaCheia
		 *	Verifica se a lista esta cheia atraves de uma comparacao entre o
		 * 		atributo ultimo e o atributo maxLista - 1.
		 *  Nao possui parametro.
		 *  Retorna o valor booleano que resulta da comparacao.
		 */
		bool listaCheia() {
			return ultimo == maxLista - 1;
		}

		/**
		 *  Funcao listaVazia
		 * 	Verifica se a lista esta vazia atraves de uma comparacao entre o
		 * 		atributo ultimo e a constante -1.
		 *  Nao possui parametro.
		 *  Retorna o valor booleano que resulta da comparacao.
		 */
		bool listaVazia() {
			return ultimo == -1;
		}

		/**
		 *  Funcao destroiLista
		 * 	Limpa / inicializa / destroi a lista atraves do atributo ultimo.
		 *	Nao ha o processo de apagar os dados limpados da lista, os mesmos
		 * 		serao sobrescritos por alguma funcao adiciona*.
		 *  Nao possui parametro.
		 *  Nao possui retorno.
		 */
		void destroiLista() {
			ultimo = -1;
		}
};
