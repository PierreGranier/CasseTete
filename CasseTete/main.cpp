#include "controler.h"
#include <QApplication>

using namespace std;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    Controler c;

    return a.exec();
/*    Interface interface;
    interface.show();

    return a.exec();*/
//    Solver s;
/*    int* matrix = new int[40];
    for (int i = 0; i < 40; ++i) {
        matrix[i] = 1;
    }
    Problem* problem = new Problem(new Position(5, 4, 2), matrix);
    s.solve(new Solution(new Position(5, 4, 2), matrix), problem, 0);
*/
/*    int* matrix = new int[25];
    for (int i = 0; i < 25; ++i) {
        if (!(i == 3 || i == 4 || i == 13 || i == 23 || i == 24)) {
            matrix[i] = 1;
        }
        else {
            matrix[i] = -1;
        }
    }
    Problem* problem = new Problem(new Position(5, 5, 1), matrix);
    s.solve(new Solution(new Position(5, 5, 1), matrix), problem, 0);
*/
/*    int* matrix = new int[36];
    for (int i = 0; i < 36; ++i) {
        if (!(i == 4 || i == 8 || i == 9 || i == 10 || i == 24 || i == 28)) {
            matrix[i] = 1;
        }
        else {
            matrix[i] = -1;
        }
    }
    Problem* problem = new Problem(new Position(4, 3, 3), matrix);
    s.solve(new Solution(new Position(4, 3, 3), matrix), problem, 0);
*/
 /*   cout << s.getSolutions().size() << endl;

    for (int i = 0; i < s.getSolutions().size(); ++i) {
        Solution sol = s.getSolutions()[i];
        for (int j = 0; j < 9; ++j) {
            PieceModel pm = sol.getPiece((PieceType) j);
            if (pm.isUsed()) {
                cout << j << " " << pm.getPosition()->getX() << " " << pm.getPosition()->getY() << " " << pm.getPosition()->getZ() << " " << pm.getRotation()->getX() << " " << pm.getRotation()->getY() << " " << pm.getRotation()->getZ() << endl;
            }
        }
        cout << endl;
    }
*/
//    return EXIT_SUCCESS;
}
