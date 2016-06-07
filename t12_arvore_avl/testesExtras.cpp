#include "NoAVL.hpp"
#include <iostream>

int main() {
	// teste de insercao que utiliza todos os casos de rotacao
	NoAVL<int> *avl = new NoAVL<int>(10);

	/* right right */
	// avl = avl->inserir(15, avl);
	// avl = avl->inserir(20, avl);
	// /* left left */
	// avl = avl->inserir(9, avl);
	// avl = avl->inserir(8, avl);
	//  right left
	// avl = avl->inserir(25, avl);
	// avl = avl->inserir(22, avl);
	// /* left right */
	// avl = avl->inserir(5, avl);
	// avl = avl->inserir(7, avl);

	// codigo do primeiro remover do teste
	// avl = avl->inserir(5, avl);
 //    avl = avl->inserir(15, avl);
 //    avl = avl->inserir(14, avl);
 //    avl = avl->inserir(16, avl);
 //    avl = avl->inserir(6, avl);
 //    avl = avl->inserir(17, avl);
 //    avl = avl->inserir(13, avl);
 //    avl = avl->inserir(18, avl);
 //    avl = avl->inserir(7, avl);
 //    avl = avl->inserir(8, avl);
 //    avl = avl->inserir(3, avl);
 //    avl = avl->inserir(19, avl);

    // teste de remocao que utiliza todos os casos de rotacao
    /* right right */
    avl = avl->inserir(14, avl);
    avl = avl->inserir(8, avl);
	avl = avl->inserir(16, avl);
	avl = avl->remover(avl, 8);
	/* left left */
	// avl = avl->inserir(5, avl);
	// avl = avl->remover(16, avl);
	// /* right left */
	// avl = avl->inserir(12, avl);
	// avl = avl->inserir(15, avl);
	// avl = avl->remover(5, avl);
	// avl = avl->remover(15, avl);
	/* left right */





   	avl->emOrdem(avl);

   	std::vector<NoAVL<int>*> vector = avl->getElementos();

   	for (unsigned int i = 0; i < vector.size(); i++)
   		std::cout << *vector[i]->getDado() << std::endl;

   	delete avl;
	return 0;
}