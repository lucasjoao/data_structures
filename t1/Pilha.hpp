// Copyright [2016] - Lucas João Martins

template<typename T>
class Pilha {

	private:
		T* dados;
		int topo;

	public:

		Pilha() {}

		Pilha<T>(int t);

		void empilha(T dado); // slide 11

		T desempilha(); // slide 12

		T topo(); // slide 13

		int getPosTopo();

		void limparPilha(); // slide 8

		bool PilhaVazia(); // slide 10

		bool PilhaCheia(); // slide 9
};
