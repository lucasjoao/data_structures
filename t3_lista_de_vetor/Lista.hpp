/**
 *  Copyright [2016] - Lucas João Martins
 *  Lista.hpp
 */

template<typename T>  // nao sei se entra, ja que n esta no vpl
class Lista {
	private:
		T *dados;
		int ultimo;
		int maxLista;

	public:
		Lista() { }

		explicit Lista(int tam) {
			maxLista = tam;
			ultimo = -1;
			dados = new T[tam];
		}

		void adiciona(T dado) {
			if (listaCheia()) {
				throw "problema";
			} else {
				ultimo += 1;
				dados[ultimo] = dado;
			}
		}

		void adicionaNoInicio(T dado) {
			if (listaCheia()) {
				throw "problema";
			} else {
				ultimo += 1;

				/**
				 *  PORQUE ESSE MODO PODE NAO FUNCIONAR?
				 *  na fila coloquei para a frente, aqui coloco para tras, essa e a diff. Trocar para for
				 */
				/*
				for (int i = 0; i < maxLista; i++)  // duvida no funcionamento desse for --- BOTAR NO PAPEL PARA MELHOR ENTENDIMENTO
					dados[i+1] = dados[i];
				*/

				int i = ultimo;

				while (i > 0) {
					dados[i] = dados[i-1];
					i--;
				}

				dados[0] = dado;
			}
		}

		void adicionaNaPosicao(T dado, int posicao) {
			bool maiorZero = 0 < posicao;
			bool menorMax = posicao < maxLista;

			if (listaCheia() || (maiorZero && menorMax)) {
				throw "problema";
			} else {
				ultimo += 1;

				for (int i = posicao+1; i < maxLista; i++)
					dados[i] = dados[i-1];

				dados[posicao] = dado;
			}
		}

		void adicionaEmOrdem(T dado) {
			if (listaCheia()) {
				throw "problema";
			} else {
				int i = 0;
				for (; i <= ultimo; i++) {
					if (dados[i] > dado)
						break;
				}

				adicionaNaPosicao(dado, i);
			}
		}

		T retira() {
			if (listaVazia()) {
				throw "problema";
			} else {
				ultimo -= 1;
				return dados[ultimo + 1];
			}
		}

		T retiraDoInicio() {
			if (listaVazia()) {
				throw "problema";
			} else {
				ultimo -= 1;
				T tmp = dados[0];

				for (int i = 1; i < maxLista; i++)
					dados[i-1] = dados[i];

				return tmp;
			}
		}

		T retiraDaPosicao(int posicao) {
			bool maiorZero = 0 < posicao;
			bool menorMax = posicao < maxLista;

			if (listaVazia() || (maiorZero && menorMax)) {
				throw "problema";
			} else {
				ultimo -= 1;
				T tmp = dados[posicao];

				for (int i = posicao+1; i < maxLista; i++)
					dados[i-1] = dados[i];

				return tmp;
			}
		}

		T retiraEspecifico(T dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				int posicao = posicao(dado);

				if (posicao < 0)
					throw "problema";
				else
					return retiraDaPosicao(posicao);
			}
		}

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

		bool contem(T dado) {
			for (int i = 0; i <= ultimo; i++)
				if (igual(dado, dados[i]))
					return true;

			return false;
		}

		bool igual(T dado1, T dado2) {
			return dado1 == dado2;
		}

		bool maior(T dado1, T dado2) {
			return dado1 > dado2;
		}

		bool menor(T dado1, T dado2) {
			return dado1 < dado2;
		}

		bool listaCheia() {
			return ultimo == maxLista - 1;
		}

		bool listaVazia() {
			return ultimo == -1;
		}

		void destroiLista() {
			ultimo = -1;
		}
};
