#include "PieceRepresentation.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"
#include "../Position.h"



int main (int argc, char *argv[]) {

	/*-------------- Test PieceY-----------------*/
	PieceY py;
	
	PieceRepresentation *pr = py.rotate(0, 0, 0);
	std::cout << " Piece Y" << std::endl;
	pr->print();
	
	std::cout << std::endl;
	
	pr = py.rotate(0, 0, 1); 
	std::cout << " Piece Y après rotation 90 en z " << std::endl;	
	pr->print();

	std::cout << std::endl;

	/*--------- Test PieceAngle----------------*/

	PieceAngle pa;
	
	/*PieceRepresentation*/ pr = pa.rotate(0, 0, 0);
	std::cout << " Piece Angle " << std::endl;
	pr->print();
	
	std::cout << std::endl;
	
	pr = pa.rotate(0, 2, 0); 
	std::cout << " Piece Angle après rotation 180 en Y " << std::endl;
	pr->print();

	std::cout << std::endl;
	
	/*--------- Test PieceZ----------------*/

	PieceZ pz;
	
	/*PieceRepresentation*/ pr = pz.rotate(0, 0, 0);
	std::cout << " Piece Z " << std::endl;
	pr->print();
	
	std::cout << std::endl;
	
	pr = pz.rotate(1, 2, 0); 
	
	std::cout << " Piece Z après  2 rotation successives:90  en X et 180 et Y " << std::endl;
	pr->print();
	std::cout << std::endl;



	/*--------- Test PieceP----------------*/

	PieceP pp;
	
	/*PieceRepresentation*/ pr = pp.rotate(0, 0, 0);
	std::cout << " Piece P" << std::endl;		
	pr->print();
	
	std::cout << std::endl;
	
	pr = pp.rotate(3, 0, 0); 
	std::cout << " Piece P après rotation 270 en X " << std::endl;
	pr->print();

	std::cout << std::endl;

	/*--------- Test modification de cordonnée----------------*/

	std::cout << "coordonnée en Z P:"<< pp.getPosition().getZ() << std::endl;

	Position pos(1,2,3);
	pp.setPosition(pos);

	std::cout << "Cordonnée en Z P modifiée:"<< pp.getPosition().getZ() << std::endl;
	

	
	
	return 0;
}
