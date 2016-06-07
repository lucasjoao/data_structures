#include "NoAVL.hpp"
#include <iostream>

int main() {
	// teste de insercao pego da internet
	NoAVL<int> *avl = new NoAVL<int>(10);

	avl->inserir(20, avl);
	avl->inserir(30, avl);
	avl->inserir(40, avl);
	avl->inserir(50, avl);
	avl->inserir(25, avl);

	/* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
	*/

    std::cout << "shit: " << *avl->getDireita()->getDado() << "\n";
    std::cout << "shit: " << *avl->getDado() << "\n";
   	avl->preOrdem(avl);
	return 0;
}