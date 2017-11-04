#include "PieceRepresentation.h"
#include "PieceAngle.h"

int main (int argc, char *argv[]) {
	PieceAngle pa;
	
	PieceRepresentation *pr = pa.rotate(0, 0, 0);
	pr->print();
	
	std::cout << std::endl;
	
	pr = pa.rotate(1, 2, 1);
	pr->print();

	return 0;
}
