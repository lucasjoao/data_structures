// Copyright [2016] - Lucas João Martins

template<typename T>
class Fila {
	private:
		T *dados;
		int numeroUltimo;
		int maxFila;

	public:
		Fila() {}

		Fila<T>(int tam) {
			maxFila = tam;
			numeroUltimo = -1;
			dados = new T[tam];
		}

		void inclui(T dado) {
			if (filaCheia()) {
				throw "problema";
			} else {
				numeroUltimo += 1;
				dados[numeroUltimo] = dado;
			}
		}

		T retira() {
			if (filaVazia()) {
				throw "problema";
			} else {
				numeroUltimo -= 1;
				T tmp = dados[0];

				for (int i = 1; i < maxFila; i++)
					dados[i-1] = dados[i];

				return tmp;
			}
		}

		T ultimo() {
			if (filaVazia())
				throw "problema";
			else
				return dados[numeroUltimo];
		}

		int getUltimo() {
			if (filaVazia())
				throw "problema";
			else
				return numeroUltimo;
		}

		bool filaCheia() {
			return numeroUltimo == maxFila - 1;
		}

		bool filaVazia() {
			return numeroUltimo == -1;
		}

		void inicializaFila() {
			numeroUltimo = -1;
		}
};
