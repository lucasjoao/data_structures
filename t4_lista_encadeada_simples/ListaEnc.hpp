#include "Elemento.hpp"

template<typename T>
class ListaEnc {
	public:
		/**
		 *  se head e nulo, quer dizer que nao houve espaco na memoria
		 */
		ListaEnc() {
			/*
			head = new Elemento<T>(T *info, Elemento<T> *next);
			if (head != NULL) {
				size = 0;
				head = NULL;
			}
			*/
			ListaEnc *a = new ListaEnc();
			if (a != NULL) {
				a->size = 0;
				a->head = NULL;
			}
		}

		~ListaEnc() {

		}

		// inicio
		void adicionaNoInicio(const T &dado) {

		}

		T retiraDoInicio() {

		}

		void eliminaDoInicio() {

		}

		//posicao
		void adicionaNaPosicao(const T &dado, int pos) {

		}

		int posicao(const T &dado) const {

		}

		T *posicaoMem(const T &dado) const {

		}

		bool contem(const T &dado) {

		}

		T retiraDaPosicao(int pos) {

		}

		//fim
		void adiciona(const T &dado) {

		}

		T retira() {

		}

		//especifico
		T retiraEspecifico(const T &dado) {

		}

		void adicionaEmOrdem(const T &data) {

		}

		bool listaVazia() const {

		}

		bool igual(T dado1, T dado2) {

		}

		bool maior(T dado1, T dado2) {

		}

		bool menor(T dado1, T dado2) {

		}

		void destroiLista() {

		}

	private:
		Elemento<T> *head;
		int size;
};