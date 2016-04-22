/**
 *  Copyright [2016] - Lucas Joao Martins
 *  PilhaEnc.hpp
 */

#include "ListaEnc.hpp"

/** Classe PilhaEnc
 *  Implementa a estrutura de dados pilha encadeada através de template e
 *      heranca da classe que representa a estrutura de dados lista encadeada.
 */
template<typename T>
class PilhaEnc : ListaEnc<T> {
	public:
		/**
         *  Construtor
         *  Chama o construtor da classe base ListaEnc.
         *  Nao possui parametro.
         */
        PilhaEnc() : ListaEnc<T>::ListaEnc() {}

		/**
         *  Destrutor
         *  Chama a funcao limparPilha.
         */
        ~PilhaEnc() {
			limparPilha();
		}

        /**
         *  Funcao empilha
         *  Chama a funcao adicionaNoInicio da classe ListaEnc que fica
         *      responsavel pelo processo de adicao do dado no topo da pilha.
         *  Nao possui retorno
         *  Parametro dado passado por referencia e um tipo generico constante
         *      que representa o dado a ser adicionado no topo da pilha.
         */
		void empilha(const T &dado) {
			ListaEnc<T>::adicionaNoInicio(dado);
		}

        /**
         *  Funcao desempilha
         *  Chama a funcao retiraDoInicio da classe ListaEnc que fica
         *      responsavel pelo processo da retirada do dado.
         *  Retorna o tipo generico que representa o dado retirado da pilha.
         *  Nao possui parametro.
         */
    	T desempilha() {
    		return ListaEnc<T>::retiraDoInicio();
    	}

        /**
         *  Funcao topo
         *  Se a pilha nao estiver vazia, entao chama a funcao getHead da
         *      classe ListaEnc que retorna o head da pilha, que corresponde ao
         *      topo da pilha, e, a partir dele chama a funcao getInfo da
         *      classe Elemento que ira retornar o dado da posicao topo.
         *  Verifica o status da pilha atraves da funcao PilhaVazia.
         *  Se houver problema na verificao, redireciona a execucao para lugar
         *      nenhum.
         *  Nao possui parametro.
         *  Retorna o tipo generico que representa o dado no topo da pilha.
         */
    	T topo() {
    		if (PilhaVazia())
    			throw "problema";
    		else
    			return ListaEnc<T>::getHead()->getInfo();
    	}

        /**
         *  Funcao limparPilha
         *  Chama a funcao destroiLista da classe ListaEnc que fica
         *      responsavel pelo processo de ~limpeza~ da pilha.
         *  Nao possui retorno.
         *  Nao possui parametro.
         */
    	void limparPilha() {
    		ListaEnc<T>::destroiLista();
    	}

        /**
         *  Funcao PilhaVazia
         *  Chama a funcao listaVazia da classe ListaEnc que fica
         *      responsavel pelo processo de verificacao do status da pilha.
         *  Retorna o valor booleano que resulta da verificacao.
         *  Nao possui parametro.
         */
    	bool PilhaVazia() {
    		return ListaEnc<T>::listaVazia();
    	}
};
