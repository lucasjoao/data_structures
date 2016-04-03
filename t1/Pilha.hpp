// Copyright [2016] - Lucas João Martins

template<typename T>
class Pilha {
	private:
		T *dados;
		int numeroTopo;
		int maxPilha;

	public:
		Pilha() {}

		Pilha<T>(int t) {
			maxPilha = t;
			numeroTopo = -1;
			dados = new T[t];
		}

		void empilha(T dado) {
			if (PilhaCheia()) {
				throw "problema";
			} else {
				numeroTopo += 1;
				dados[numeroTopo] = dado;
			}
		}

		T desempilha() {
			if (PilhaVazia()) {
				throw "problema";
			} else {
				numeroTopo -= 1;
				return dados[numeroTopo + 1];
			}
		}

		T topo() {
			if (PilhaVazia())
				throw "problema";
			else
				return dados[numeroTopo];
		}

		int getPosTopo() {
			if (PilhaVazia())
				throw "problema";
			else
				return numeroTopo;
		}

		void limparPilha() {
			numeroTopo = -1;
		}

		bool PilhaVazia() {
			return numeroTopo == -1;
		}

		bool PilhaCheia() {
			return numeroTopo == maxPilha - 1;
		}
};
