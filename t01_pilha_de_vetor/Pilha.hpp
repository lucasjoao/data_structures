/**
 *  Copyright [2016] - Lucas João Martins
 *  Pilha.hpp
 */

/** Classe Pilha
 *  Implementa a estrutura de dados pilha de vetor através de template.
 */
template<typename T>
class Pilha {
	private:
		T *dados;        //!< vetor que armazena os dados da estrutura
		int numeroTopo;  //!< indica a posição do elemento no topo da pilha
		int maxPilha;    //!< indica o tamanho do vetor

	public:
		/** Construtor
		 *  Default e vazio.
		 */
		Pilha() {}

		/** Construtor
		 *  Utiliza template.
		 *  Inicializa a pilha através do atributo numeroTopo
		 *  Instancia um vetor para o atributo dados.
		 *  Parâmetro t é um inteiro que indica o tamanho do vetor.
		 */
		Pilha<T>(int t) {
			maxPilha = t;
			numeroTopo = -1;
			dados = new T[t];
		}

		/** Função empilha
		 *  Se a pilha não estiver cheia, então aumenta o número do topo e
		 *  	coloca um elemento no novo topo.
		 *  Verifica o status da pilha através da função PilhaCheia.
		 *  Se houver problema na verificação, redireciona a execução para
		 *  	lugar nenhum.
		 *  Parâmetro dado é um tipo genérico que representa o dado que ficará
		 *  	no topo da pilha.
		 *  Não possui retorno.
		 */
		void empilha(T dado) {
			if (PilhaCheia()) {
				throw "problema";
			} else {
				numeroTopo += 1;
				dados[numeroTopo] = dado;
			}
		}

		/** Função desempilha
		 *  Se a pilha não estiver vazia, então diminui o número do topo.
		 *	Não há o processo de apagar o dado desempilhado da pilha.
		 *  Verifica o status da pilha através da função PilhaVazia.
		 *  Se houver problema na verificação, redireciona a execução para
		 *  	lugar nenhum.
		 *  Não possui parâmetro.
		 *  Retorna o tipo genérico que representa o dado retirado da pilha.
		 */
		T desempilha() {
			if (PilhaVazia()) {
				throw "problema";
			} else {
				numeroTopo -= 1;
				return dados[numeroTopo + 1];
			}
		}

		/** Função topo
		 *  Se a pilha não estiver vazia, retorna o tipo genérico que
		 *  	representa o dado no topo da pilha.
		 *  Verifica o status da pilha através da função PilhaVazia.
		 *  Se houver problema na verificação, redireciona a execução para
		 *  	lugar nenhum.
		 *  Não possui parâmetro.
		 */
		T topo() {
			if (PilhaVazia())
				throw "problema";
			else
				return dados[numeroTopo];
		}

		/** Função getter para a posição do topo
		 *  Se a pilha não estiver vazia, retorna a posição do elemento no topo
		 *  	da pilha.
		 *  Verifica o status da pilha através da função PilhaVazia.
		 *  Se houver problema na verificação, redireciona a execução para
		 *  	lugar nenhum.
		 *  Não possui parâmetro.
		 */
		int getPosTopo() {
			if (PilhaVazia())
				throw "problema";
			else
				return numeroTopo;
		}

		/** Função limparPilha
		 *  Limpa / inicializa a pilha através do atributo numeroTopo.
		 *	Não há o processo de apagar os dados limpados da pilha, os mesmos
		 * 		serão sobrescritos pela função empilha.
		 *  Não possui parâmetro.
		 *  Não possui retorno.
		 */
		void limparPilha() {
			numeroTopo = -1;
		}

		/** Função PilhaVazia
		 *  Verifica se a pilha está vazia através de uma comparação entre o
		 * 		atributo numeroTopo e a constante -1.
		 *  Não possui parâmetro.
		 *  Retorna o valor booleano que resulta da comparação.
		 */
		bool PilhaVazia() {
			return numeroTopo == -1;
		}

		/** Função PilhaCheia
		 *  Verifica se a pilha está cheia através de uma comparação entre o
		 * 		atributo numeroTopo e o atributo maxPilha - 1.
		 *  Não possui parâmetro.
		 *  Retorna o valor booleano que resulta da comparação.
		 */
		bool PilhaCheia() {
			return numeroTopo == maxPilha - 1;
		}
};
