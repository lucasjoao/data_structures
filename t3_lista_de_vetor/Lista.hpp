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
			ultimo = -1
			dados = new T[tam];
		}

		void adiciona(T dado) {
			if (PilhaCheia()) {
				throw "problema";
			} else {
				ultimo += 1;
				dados[ultimo] = dado;
			}
		}

		void adicionaNoInicio(T dado) {

		}

		void adicionaNaPosicao(T dado, int posicao) {

		}

		void adicionaEmOrdem(T dado) {

		}

		T retira() {

		}

		T retiraDoInicio() {

		}

		T retiraDaPosicao(int posicao) {

		}

		int posicao(T dado) {

		}

		bool contem(T dado) {

		}

		bool igual(T dado1, T dado2) {

		}

		bool maior(T dado1, T dado2) {

		}

		bool menor(T dado1, T dado2) {

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