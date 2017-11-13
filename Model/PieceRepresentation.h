#ifndef PIECEREPRESENTATION_H
#define PIECEREPRESENTATION_H

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

class PieceRepresentation {
  
private:
	int x_size; 
	int y_size;
	int z_size;
	int* values;
 
public:
	PieceRepresentation(int x, int y, int z, int *v) : x_size(x), y_size(y), z_size(z), values(v) {};
	~PieceRepresentation() {
		delete[] values;
	}
	  
	void print() {
		for (int y = y_size - 1; y >= 0; --y) {
			for (int z = 0; z < z_size; ++z) {
				std::cout << " [ ";
				for (int x = 0; x < x_size; ++x) {
					std::cout << values[x + y * x_size + z * x_size * y_size] << " ";
				}
				std::cout << "] ";
			}
			std::cout << std::endl;
		}
	}

	void setX(int x) {
		x_size = x;
	}
	int getX() {
		return x_size;
	}

	void setY(int y) {
		y_size = y;
	}
	int getY() {
		return y_size;
	}

	void setZ(int z) {
		z_size = z;
	}
	int getZ() {
		return z_size;
	}

	int getValue(int x, int y, int z) {
		return values[x + y * x_size + z * x_size * y_size];
	}

	/* rotation vaut 1, 2 ou 3 
	 * ne fonctionne pas avec les fonctions cos et sin de la librairie math
	 * valeur mise en brut en fonction de la rotation
	 */
	PieceRepresentation* rotateX(int rotation) {
		/* radian = degre * pi / 180
		 * dans notre cas:
		 * degre = 90 * rotation
		 * on peut donc reduire la formule a
		 * radian = rotation * pi / 2
		 */
		//float angle = M_PI * rotation / 2;
		
		/* creation de la matrice de rotation
		 * matrice 4 * 4
		 * valeurs :
		 * 1 0			0 			0
		 * 0 cos(angle) -sin(angle) 0
		 * 0 sin(angle) cos(angle) 	0
		 * 0 0			0 			1
		 */
		int** matrix = new int*[4];
		for (int i = 0; i < 4; ++i) {
			matrix[i] = new int[4];
		}
		for (int i = 0; i < 16; ++i) {
			matrix[i / 4][i % 4] = 0;
		}
		
		matrix[0][0] = 1;
		matrix[1][1] = (rotation == 1 || rotation == 3) ? 0 : -1;
		matrix[1][2] = (rotation == 1) ? -1 : (rotation == 2) ? 0 : 1;
		matrix[2][1] = (rotation == 1) ? 1 : (rotation == 2) ? 0 : -1;
		matrix[2][2] = (rotation == 1 || rotation == 3) ? 0 : -1;
		matrix[3][3] = 1;
		
		/* creation du nouveau vecteur de 
		 * on initialise a 0
		 * on indique sa taille en x, y et z
		 * si la rotation est de 90 ou 270 degre
		 * la taille en y et z est inversee
		 */
		int* v = new int[x_size * y_size * z_size];
		for (int i = 0; i < x_size * y_size * z_size; ++i) {
			v[i] = 0;
		}
		
		int new_x_size = x_size;
		int new_y_size = z_size;
		int new_z_size = y_size;
		
		if (rotation == 2) {
			new_y_size = y_size;
			new_z_size = z_size;
		}
		
		/* on parcourt le vecteur de base
		 * pour chaque position ou il y a un 1
		 * on calcul sa nouvelle position grace au vecteur
		 * ensuite on effectue les translations necessaires
		 */
		for (int i = 0; i < x_size * y_size * z_size; ++i) {
			if (values[i] == 1) {
				int* vector = new int[4] {i % x_size, (i / x_size) % y_size, ((i / x_size) / y_size) % z_size, 1};
				int* pos = multiplication(vector, matrix);
				
				int x = pos[0];
				int y = pos[1];
				int z = pos[2];
				/** rotation de 90 degre **/
				if (rotation == 1) {
					y += z_size - 1;
				}
				/** rotation de 180 degre **/
				else if (rotation == 2) {
					y += y_size - 1;
					z += z_size - 1;
				}
				/** rotation de 270 degre **/
				else if (rotation == 3) {
					z += y_size - 1;
				}
				v[x + new_x_size * y + new_x_size * new_y_size * z] = 1;
			}
		}
		
		/* on cree un nouvel objet PieceRepresentation
		 * on passe en parametre sa taille en x, y et z
		 * on met le vecteur de donnees
		 * et on le renvoie
		 */
		PieceRepresentation* pr = new PieceRepresentation(new_x_size, new_y_size, new_z_size, v);
		
		return pr;
	}
	PieceRepresentation* rotateY(int rotation) {
		//float angle = M_PI * rotation / 2;
		
		/* creation de la matrice de rotation Y
		 * matrice 4 * 4
		 * valeurs :
		 * cos(angle)	0 sin(angle)	0
		 * 0			1 0				0
		 * -sin(angle)	0 cos(angle)	0
		 * 0			0 0				1
		 */
		int** matrix = new int*[4];
		for (int i = 0; i < 4; ++i) {
			matrix[i] = new int[4];
		}
		for (int i = 0; i < 16; ++i) {
			matrix[i / 4][i % 4] = 0;
		}
		
		matrix[0][0] = (rotation == 1 || rotation == 3) ? 0 : -1;
		matrix[0][2] = (rotation == 1) ? 1 : (rotation == 2) ? 0 : -1;
		matrix[1][1] = 1;
		matrix[2][0] = (rotation == 1) ? -1 : (rotation == 2) ? 0 : 1;
		matrix[2][2] = (rotation == 1 || rotation == 3) ? 0 : -1;
		matrix[3][3] = 1;
		
		/* creation du nouveau vecteur de position
		 * on initialise a 0
		 * on indique sa taille en x, y et z
		 * si la rotation est de 90 ou 270 degre
		 * la taille en x et z est inversee
		 */
		int* v = new int[x_size * y_size * z_size];
		for (int i = 0; i < x_size * y_size * z_size; ++i) {
			v[i] = 0;
		}
		
		int new_x_size = z_size;
		int new_y_size = y_size;
		int new_z_size = x_size;
		
		if (rotation == 2) {
			new_x_size = x_size;
			new_z_size = z_size;
		}
		
		/* on parcourt le vecteur de base
		 * pour chaque position ou il y a un 1
		 * on calcul sa nouvelle position grace au vecteur
		 * ensuite on effectue les translations necessaires
		 */
		for (int i = 0; i < x_size * y_size * z_size; ++i) {
			if (values[i] == 1) {
				int* vector = new int[4] {i % x_size, (i / x_size) % y_size, ((i / x_size) / y_size) % z_size, 1};
				int* pos = multiplication(vector, matrix);
				
				int x = pos[0];
				int y = pos[1];
				int z = pos[2];
				/** rotation de 90 degre **/
				if (rotation == 1) {
					z += x_size - 1;
				}
				/** rotation de 180 degre **/
				else if (rotation == 2) {
					z += z_size - 1;
					x += x_size - 1;
				}
				/** rotation de 270 degre **/
				else if (rotation == 3) {
					x += z_size - 1;
				}
				v[x + new_x_size * y + new_x_size * new_y_size * z] = 1;
			}
		}
		
		/* on cree un nouvel objet PieceRepresentation
		 * on passe en parametre sa taille en x, y et z
		 * on met le vecteur de donnees
		 * et on le renvoie
		 */
		PieceRepresentation* pr = new PieceRepresentation(new_x_size, new_y_size, new_z_size, v);
		
		return pr;
	}
	
	PieceRepresentation* rotateZ(int rotation) {
		//float angle = M_PI * rotation / 2;
		
		/* creation de la matrice de rotation Z
		 * matrice 4 * 4
		 * valeurs :
		 * cos(angle) 	-sin(angle) 0 0
		 * sin(angle) 	cos(angle)  0 0
		 * 0 			0 			1 0
		 * 0 			0			0 1
		 */
		int** matrix = new int*[4];
		for (int i = 0; i < 4; ++i) {
			matrix[i] = new int[4];
		}
		for (int i = 0; i < 16; ++i) {
			matrix[i / 4][i % 4] = 0;
		}
		
		matrix[0][0] = (rotation == 1 || rotation == 3) ? 0 : -1;
		matrix[0][1] = (rotation == 1) ? -1 : (rotation == 2) ? 0 : 1;
		matrix[1][0] = (rotation == 1) ? 1 : (rotation == 2) ? 0 : -1;
		matrix[1][1] = (rotation == 1 || rotation == 3) ? 0 : -1;
		matrix[2][2] = 1;
		matrix[3][3] = 1;
		
		/* creation du nouveau vecteur de position
		 * on initialise a 0
		 * on indique sa taille en x, y et z
		 * si la rotation est de 90 ou 270 degre
		 * la taille en x et y est inversee
		 */
		int* v = new int[x_size * y_size * z_size];
		for (int i = 0; i < x_size * y_size * z_size; ++i) {
			v[i] = 0;
		}
		
		int new_x_size = y_size;
		int new_y_size = x_size;
		int new_z_size = z_size;
		
		if (rotation == 2) {
			new_x_size = x_size;
			new_y_size = y_size;
		}		
		/* on parcourt le vecteur de base
		 * pour chaque position ou il y a un 1
		 * on calcul sa nouvelle position grace au vecteur
		 * ensuite on effectue les translations necessaires
		 */
		for (int i = 0; i < x_size * y_size * z_size; ++i) {
			if (values[i] == 1) {
				int* vector = new int[4] {i % x_size, (i / x_size) % y_size, ((i / x_size) / y_size) % z_size, 1};
				int* pos = multiplication(vector, matrix);
				
				int x = pos[0];
				int y = pos[1];
				int z = pos[2];
				/** rotation de 90 degre **/
				if (rotation == 1) {
					x += y_size - 1;
				}
				/** rotation de 180 degre **/
				else if (rotation == 2) {
					x += x_size - 1;
					y += y_size - 1;
				}
				/** rotation de 270 degre **/
				else if (rotation == 3) {
					y += x_size - 1;
				}
				v[x + new_x_size * y + new_x_size * new_y_size * z] = 1;
			}
		}
		
		/* on cree un nouvel objet PieceRepresentation
		 * on passe en parametre sa taille en x, y et z
		 * on met le vecteur de donnees
		 * et on le renvoie
		 */
		PieceRepresentation* pr = new PieceRepresentation(new_x_size, new_y_size, new_z_size, v);
		
		return pr;		
	}
	
	int* multiplication(int* vector, int** matrix) {
		int* v = new int[4];
		for (int i = 0; i < 4; ++i) {
			v[i] = 0;
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				v[i] += matrix[i][j] * vector[j];
			}
		}
		return v;
	}
};

#endif
