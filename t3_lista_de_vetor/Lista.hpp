/**
 *  Copyright [2016] - Lucas João Martins
 *  Lista.hpp
 */

template<typename T>
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

				for (int i = ultimo; i > 0; i--)
					dados[i] = dados[i-1];

				dados[0] = dado;
			}
		}

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
				T tmp = dados[0];

				for (int i = 0; i < ultimo; i ++)
					dados[i] = dados[i+1];

				ultimo -=1;

				return tmp;
			}
		}

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

		T retiraEspecifico(T dado) {
			if (listaVazia()) {
				throw "problema";
			} else {
				int local = posicao(dado);

				if (local < 0)
					throw "problema";
				else
					return retiraDaPosicao(local);
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
