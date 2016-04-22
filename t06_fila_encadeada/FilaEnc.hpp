/**
 *  Copyright [2016] - Lucas Joao Martins
 *  FilaEnc.hpp
 */

#include "ListaEnc.hpp"

/** Classe FilaEnc
 *  Implementa a estrutura de dados fila encadeada através de template e
 *      heranca da classe que representa a estrutura de dados lista encadeada.
 */

template <typename T>
class FilaEnc : ListaEnc<T> {
	public:
		/**
         *  Construtor
         *  Utiliza template.
         *  Chama o construtor da classe base ListaEnc.
         *  Nao possui parametro.
         */
		FilaEnc<T>() : ListaEnc<T>::ListaEnc() {}

		/**
         *  Destrutor
         *  Chama a funcao limparFila.
         */
		~FilaEnc() {
			limparFila();
		}

		/**
		 *  Funcao inclui
		 *  Istancia um novo Elemento temporario que aponta para um nullptr e
		 *		possui o dado passado como argumento, e, se houver espaco na
		 *		memoria para alocar essa instanciacao, verifica se e uma fila
		 *		vazia ou nao. Se for, entao define o elemento temporario como
		 *		head. Ja se nao for, aponta o atual tail para o elemento
		 *		temporario. Apos isso tudo, define o elemento temporario como
		 *		o novo tail e aumenta o numero que indica o tamanho da fila.
		 *  Verifica a situacao da memoria ao comparar se o novo elemento
		 *		temporario e igual a um nullptr.
		 *	Verifica o status da fila atraves da funcao filaVazia.
		 *  Se houver problema na primeira verificacao, redireciona a execucao
		 *		para lugar nenhum.
 		 *	Parametro dado passado por referencia e um tipo generico constante
		 *		que representa o dado que ficara na ultima posicao da fila.
		 *  Nao possui retorno.
		 */
		void inclui(const T &dado) {
			Elemento<T> *tmpElemento = new Elemento<T>(dado, nullptr);

			if (tmpElemento == nullptr) {
				throw "problema";
			} else {
				if (filaVazia())
					ListaEnc<T>::setHead(tmpElemento);
				else
					ListaEnc<T>::getTail()->setProximo(tmpElemento);

				ListaEnc<T>::setTail(tmpElemento);
				ListaEnc<T>::setSize(ListaEnc<T>::getSize() + 1);
			}
		}

		/**
         *  Funcao retira
         *  Se for uma fila unitaria, entao precisa setar o tail como nullptr.
         *		Apos isso, chama a funcao retiraDoInicio da classe ListaEnc
         *		que fica responsavel pelo processo da retirada do dado.
         *	Verificacao e realizada atraves de uma comparacao do atributo size
         *		da classe ListaEnc com um inteiro 1.
         *  Retorna o tipo generico que representa o dado retirado da pilha.
         *  Nao possui parametro.
         */
		T retira() {
			if (ListaEnc<T>::getSize() == 1)
				ListaEnc<T>::setTail(nullptr);

			return ListaEnc<T>::retiraDoInicio();
		}

		/**
         *  Funcao ultimo
         *  Se a fila nao estiver vazia, entao chama a funcao getTail da
         *      classe ListaEnc que retorna o tail da fila, que corresponde ao
         *      ultimo da fila, e, a partir dele chama a funcao getInfo da
         *      classe Elemento que ira retornar o dado da ultima posicao.
         *  Verifica o status da fila atraves da funcao filaVazia.
         *  Se houver problema na verificao, redireciona a execucao para lugar
         *      nenhum.
         *  Nao possui parametro.
         *  Retorna o tipo generico que representa o ultimo dado da fila.
         */
		T ultimo() {
			if (filaVazia())
				throw "problema";
			else
				return ListaEnc<T>::getTail()->getInfo();
		}

		/**
         *  Funcao primeiro
         *  Se a fila nao estiver vazia, entao chama a funcao getHead da
         *      classe ListaEnc que retorna o head da fila, que corresponde ao
         *      primeiro da fila, e, a partir dele chama a funcao getInfo da
         *      classe Elemento que ira retornar o dado da primeira posicao.
         *  Verifica o status da fila atraves da funcao filaVazia.
         *  Se houver problema na verificao, redireciona a execucao para lugar
         *      nenhum.
         *  Nao possui parametro.
         *  Retorna o tipo generico que representa o primeiro dado da fila.
         */
		T primeiro() {
			if (filaVazia())
				throw "problema";
			else
				return ListaEnc<T>::getHead()->getInfo();
		}

		/**
         *  Funcao filaVazia
         *  Chama a funcao listaVazia da classe ListaEnc que fica
         *      responsavel pelo processo de verificacao do status da fila.
         *  Retorna o valor booleano que resulta da verificacao.
         *  Nao possui parametro.
         */
		bool filaVazia() {
			return ListaEnc<T>::listaVazia();
		}

		/**
         *  Funcao limparFila
         *  Chama a funcao destroiLista da classe ListaEnc que fica
         *      responsavel pelo processo de ~limpeza~ da fila.
         *  Nao possui retorno.
         *  Nao possui parametro.
         */
		void limparFila() {
			ListaEnc<T>::destroiLista();
		}
};
