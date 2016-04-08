/**
 *  Copyright [2016] - Lucas João Martins
 *  Fila.hpp
 */

/** Classe Fila
 *  Implementa a estrutura de dados fila de vetor através de template.
 */
template<typename T>
class Fila {
	private:
		T *dados;          //!< vetor que armazena os dados da estrutura
		int numeroUltimo;  //!< indica a posição do último elemento na fila
		int maxFila;       //!< indica o tamanho do vetor

	public:
		/** Construtor
		 *  Default e vazio.
		 */
		Fila() {}

		/** Construtor
		 *  Utiliza template.
		 *  Inicializa a fila através do atributo numeroUltimo.
		 *  Instancia um vetor para o atributo dados.
		 *  Parâmetro tam é um inteiro que indica o tamanho do vetor.
		 */
		Fila<T>(int tam) {
			maxFila = tam;
			numeroUltimo = -1;
			dados = new T[tam];
		}

		/** Função inclui
		 *  Se a fila não estiver cheia, então aumenta o número que indica a
		 *  	a posição do último e coloca um elemento nessa nova posição.
		 *  Verifica o status da fila através da função filaCheia.
		 *  Se houver problema na verificação, redireciona a execução para
		 *  	lugar nenhum.
		 *  Parâmetro dado é um tipo genérico que representa o dado que ficará
		 *  	na última posição da fila.
		 *  Não possui retorno.
		 */
		void inclui(T dado) {
			if (filaCheia()) {
				throw "problema";
			} else {
				numeroUltimo += 1;
				dados[numeroUltimo] = dado;
			}
		}

		/** Função retira
		 *  Se a fila não estiver vazia, então salva temporariamente o dado
		 * 		que será retirado, empurra todos os outros dados para uma
		 *		posição	à frente através de um laço e diminui o número que
		 *		indica a posição do último.
		 *	Não há o processo de apagar o último dado da fila.
		 *  Verifica o status da fila através da função filaVazia.
		 *  Se houver problema na verificação, redireciona a execução para
		 *  	lugar nenhum.
		 *  Não possui parâmetro.
		 *  Retorna o tipo genérico que representa o dado retirado da fila, o
		 *  	que foi salvo temporariamente durante o processo.
		 */
		T retira() {
			if (filaVazia()) {
				throw "problema";
			} else {
				T tmp = dados[0];

				for (int i = 0; i < numeroUltimo; i++)
					dados[i] = dados[i+1];

				numeroUltimo -= 1;

				return tmp;
			}
		}

		/** Função último
		 *  Se a fila não estiver vazia, retorna o tipo genérico que
		 *  	representa o dado na última posição da fila.
		 *  Verifica o status da fila através da função filaVazia.
		 *  Se houver problema na verificação, redireciona a execução para
		 *  	lugar nenhum.
		 *  Não possui parâmetro.
		 */
		T ultimo() {
			if (filaVazia())
				throw "problema";
			else
				return dados[numeroUltimo];
		}

		/** Função getter para a posição do último elemento
		 *  Se a fila não estiver vazia, retorna a posição do último elemento
		 *  	da fila.
		 *  Verifica o status da fila através da função filaVazia.
		 *  Se houver problema na verificação, redireciona a execução para
		 *  	lugar nenhum.
		 *  Não possui parâmetro.
		 */
		int getUltimo() {
			if (filaVazia())
				throw "problema";
			else
				return numeroUltimo;
		}

		/** Função filaCheia
		 *  Verifica se a fila está cheia através de uma comparação entre o
		 * 		atributo numeroUltimo e o atributo maxFila - 1.
		 *  Não possui parâmetro.
		 *  Retorna o valor booleano que resulta da comparação.
		 */
		bool filaCheia() {
			return numeroUltimo == maxFila - 1;
		}

		/** Função filaVazia
		 *  Verifica se a fila está vazia através de uma comparação entre o
		 * 		atributo numeroUltimo e a constante -1.
		 *  Não possui parâmetro.
		 *  Retorna o valor booleano que resulta da comparação.
		 */
		bool filaVazia() {
			return numeroUltimo == -1;
		}

		/** Função inicializaFila
		 *  Limpa / inicializa a fila através do atributo numeroUltimo.
		 *	Não há o processo de apagar os dados limpados da fila, os mesmos
		 * 		serão sobrescritos pela função inclui.
		 *  Não possui parâmetro.
		 *  Não possui retorno.
		 */
		void inicializaFila() {
			numeroUltimo = -1;
		}
};
