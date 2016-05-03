/**
 *  Copyright [2016] - Lucas Joao Martins
 *  Elemento.hpp
 */

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

/**
 *  Classe Elemento
 *	Implementa o elemento/vertice da lista encadeada simples atraves de
 *		template.
 */
template<typename T>
class Elemento {
	public:
		Elemento(Elemento<T> *next) : _next(next) {}

		/**
		 *  Construtor
		 *	Inicializa o vertice ao informar para qual nodo ele aponta e qual
		 *		dado a posicao ira possuir.
		 *	Parametro info passado por referencia e um tipo generico constante
		 *		que representa a informacao que sera adicionada para o vertice.
		 *	Parametro next passado por nome e um elemento que representa a
		 *		posicao para qual o vertice instanciado pelo construtor aponta.
		 */
		Elemento(const T &info, Elemento<T> *next) : info(new T(info)), _next(next) {}

		/**
		 *  Destrutor
		 *	Deleta o tipo generico info.
		 */
		~Elemento() {
			delete info;
		}

		/**
		 *  Funcao getter constante getProximo
		 *  Retorna o ponteiro do vertice para qual o elemento aponta.
		 */
		Elemento<T>* getProximo() const {
			return _next;
		}

		/**
		 *  Funcao getter constante getInfo
		 *  Retorna o valor armazenado no ponteiro que possui os dados do
		 *		vertice.
		 */
		T getInfo() const {
			return *info;
		}

		/**
		 *  Funcao setter setProximo
		 *	Atribui o argumento passado para a variavel que contem o proximo
		 *		vertice.
		 *  Parametro next passado por nome e um elemento que representa o dado
		 *		para qual o vertice deve passar a apontar.
		 * 	Nao possui retorno.
		 */
		void setProximo(Elemento<T> *next) {
			_next = next;
		}

	private:
		T *info;			 //!< tipo generico que possui a info do nodo
		Elemento<T> *_next;  //!< obj que aponta ao proximo elemento do vertice
};

#endif
