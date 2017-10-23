#include "PieceRepresentation.h"

int main (int argc, char *argv[]) {
	int* c = new int[18];
	
	
	/* Matrice suivante :
	 *  z0 |  z1 |  z2
	 * 1 0 | 1 0 | 1 0
	 * 1 0 | 1 0 | 1 0
	 * 1 1 | 1 0 | 1 0
	 */
	
	for (int i = 0; i < 3; ++i) {
		c[0 + i * 6] = 1;
		c[1 + i * 6] = 1;
		c[2 + i * 6] = 1;
		c[3 + i * 6] = 0;
		c[4 + i * 6] = 1;
		c[5 + i * 6] = 0;
	}
	PieceRepresentation pr(2, 3, 3, c);
	pr.print();
	
	std::cout << std::endl;
	
	PieceRepresentation* pr2 = pr.rotateX(3);
	pr2->print();

	return 0;
}
