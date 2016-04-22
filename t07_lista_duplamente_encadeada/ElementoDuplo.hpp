/**
 *  Copyright [2016] - Lucas Joao Martins
 *  ElementoDuplo.hpp
 */

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

/**
 *  Classe Elemento
 *	Implementa o elemento/vertice da lista duplamente encadeada atraves de
 *		template.
 */
template<typename T>
class Elemento {
	public:
		/**
		 *  Construtor
		 *	Inicializa o vertice ao informar para qual nodo ele aponta para
		 *		frente e para tras e qual dado a posicao ira possuir.
		 *	Parametro info passado por referencia e um tipo generico constante
		 *		que representa a informacao que sera adicionada para o vertice.
		 *	Parametro back passado por nome e um elemento que representa a
		 *		posicao atras para qual o vertice instanciado pelo construtor
		 *		aponta.
		 *	Parametro next passado por nome e um elemento que representa a
		 *		posicao para qual o vertice instanciado pelo construtor aponta.
		 */
		Elemento(const T &info, Elemento<T> *back, Elemento<T> *next) {
			_info = new T(info);
			_back = back;
			_next = next;
		}

		/**
		 *  Destrutor
		 *	Deleta o tipo generico info.
		 */
		~Elemento() {
			delete _info;
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
			return *_info;
		}

		/**
		 *  Funcao getter constante getBack
		 *  Retorna o ponteiro do vertice anterior para qual o elemento aponta.
		 */
		Elemento<T>* getBack() const {
			return _back;
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

		/**
		 *  Funcao setter setBack
		 *	Atribui o argumento passado para a variavel que contem o vertice
		 *		anterior.
		 *  Parametro back passado por nome e um elemento que representa o dado
		 *		para qual o vertice deve passar a apontar para tras.
		 * 	Nao possui retorno.
		 */
		void setBack(Elemento<T> *back) {
			_back = back;
		}

	private:
		T *_info;			 //!< tipo generico que possui a info do nodo
		Elemento<T> *_next;  //!< obj que aponta ao proximo elemento do vertice
		Elemento<T> *_back;  //!< obj que aponta ao vertice anterior
};

#endif
