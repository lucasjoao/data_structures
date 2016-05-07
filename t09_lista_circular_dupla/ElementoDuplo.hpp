/*!
 *  \brief ElementoDuplo.hpp
 *	\copyright Copyright [2016], Lucas Joao Martins
 *  \author Lucas Joao Martins
 *
 *	Implementa um vertice atraves de template.
 */

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>
class Elemento {
	public:
		/*!
		 *  \brief Construtor
		 *	\param info passado por referencia e um tipo generico constante
		 *		que representa a informacao que sera adicionada para o vertice.
		 *	\param back passado por nome e um elemento que representa a
		 *		posicao atras para qual o vertice instanciado pelo construtor
		 *		aponta.
		 *	\param next passado por nome e um elemento que representa a
		 *		posicao para qual o vertice instanciado pelo construtor aponta.
		 *
		 *	Inicializa o vertice ao informar para qual nodo ele aponta para
		 *		frente e para tras e qual dado a posicao ira possuir.
		 */
		Elemento(const T &info, Elemento<T> *back, Elemento<T> *next) {
			_info = new T(info);
			_back = back;
			_next = next;
		}

		/*!
		 *  \brief Destrutor
		 *
		 *	Deleta o tipo generico info.
		 */
		~Elemento() {
			delete _info;
		}

		/*!
		 *  \brief Funcao getter constante getProximo
		 *  \return o ponteiro do vertice para qual o elemento aponta.
		 */
		Elemento<T>* getProximo() const {
			return _next;
		}

		/*!
		 *  \brief Funcao getter constante getInfo
		 *  \return o valor armazenado no ponteiro que possui os dados do
		 *		vertice.
		 */
		T getInfo() const {
			return *_info;
		}

		/*!
		 *  \brief Funcao getter constante getBack
		 *  \return o ponteiro do vertice anterior para qual o elemento aponta.
		 */
		Elemento<T>* getBack() const {
			return _back;
		}

		/*!
		 *  \brief Funcao setter setProximo
		 *  \param next passado por nome e um elemento que representa o dado
		 *		para qual o vertice deve passar a apontar.
		 * 	\return nao possui.
		 *
		 *	Atribui o argumento passado para a variavel que contem o proximo
		 *		vertice.
		 */
		void setProximo(Elemento<T> *next) {
			_next = next;
		}

		/*!
		 *  \brief Funcao setter setBack
		 *  \param back passado por nome e um elemento que representa o dado
		 *		para qual o vertice deve passar a apontar para tras.
		 * 	\return nao possui.
		 *
		 *	Atribui o argumento passado para a variavel que contem o vertice
		 *		anterior.
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
