#include "NoAVL.hpp"
#include <iostream>

int main() {
	// teste de insercao que utiliza todos os casos de rotacao
	// emOrdem deve ser 5 7 8 9 10 15 20 22 25
	NoAVL<int> *avl = new NoAVL<int>(10);

	std::cout << "Abra o arquivo para (des)comentar o teste desejado.\n\n";

	/* right right */
	// avl = avl->inserir(15, avl);
	// avl = avl->inserir(20, avl);
	/* left left */
	// avl = avl->inserir(9, avl);
	// avl = avl->inserir(8, avl);
	/* right left */
	// avl = avl->inserir(25, avl);
	// avl = avl->inserir(22, avl);
	/* left right */
	// avl = avl->inserir(5, avl);
	// avl = avl->inserir(7, avl);

    // teste de remocao que utiliza todos os casos de rotacao
    /* right right */
    // emOrdem deve ser 10 14 16
	// avl = avl->inserir(14, avl);
	// avl = avl->inserir(8, avl);
	// avl = avl->inserir(16, avl);
	// avl = avl->remover(avl, 8);
	/* left left */
	// anterior precisa estar descomentado, emOrdem deve ser 5 10 14
	// avl = avl->inserir(5, avl);
	// avl = avl->remover(avl, 16);
	// /* right left */
	// emOrdem deve ser 10 12 15
	// avl = avl->inserir(15, avl);
	// avl = avl->inserir(5, avl);
	// avl = avl->inserir(12, avl);
	// avl = avl->inserir(20, avl);
	// avl = avl->remover(avl, 20);
	// avl = avl->remover(avl, 5);
	/* left right */
	// emordem deve ser 8 9 10
	// avl = avl->inserir(15, avl);
	// avl = avl->inserir(8, avl);
	// avl = avl->inserir(6, avl);
	// avl = avl->inserir(9, avl);
	// avl = avl->remover(avl, 6);
	// avl = avl->remover(avl, 15);

   	avl->emOrdem(avl);

   	std::vector<NoAVL<int>*> vector = avl->getElementos();

   	for (unsigned int i = 0; i < vector.size(); i++)
   		std::cout << *vector[i]->getDado() << std::endl;

   	delete avl;
	return 0;
}