#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int min_matrix(int **m,int taille){
  int min=m[0][0];
  for(int i=0 ; i < taille ; i++){
    for(int j=0 ; j < 3 ; j++){
      if(m[i][j] < min){
	min = m[i][j];
      }
    }
  }
  return min;
}	
  
int** multiplication(int **M,int **N,int taille){
  int **mat;
  
  mat=new int*[taille];
  for(int i=0 ; i < taille ; i++ )
      mat[i]=new int[3];
  
  for (int i=0;i<taille;i++)
	{
		for (int j=0;j<3;j++)
		{
			for (int k=0;k<3;k++)
			{
				mat[i][j]=M[i][k]*N[k][j]+mat[i][j];
			}
		}
	}
	return mat;
}
  

int** V_position (int ***T,int x,int y,int z,int &n){
    int **mat;
    int m=0;
    for(int i=0 ; i < z ; i++ ){
	  for(int j=0 ; j < y ; j++){
	    for(int k=0 ; k < x ; k++){
	      if(T[k][j][i]==1){
		m++;
	      }
	    }
	  }
    }
    
    
    mat=new int *[m];
    for(int i=0 ; i < m ; i++ )
      mat[i]=new int[3];
    n=0;
    
     for(int i=0 ; i < z ; i++ ){
	  for(int j=0 ; j < y ; j++){
	    for(int k=0 ; k < x ; k++){
	      if(T[k][j][i]==1){
		mat[n][0]=k+1;
		mat[n][1]=j+1;
		mat[n][2]=i+1;
		n++;
	      }
	    }
	  }
    }
    return mat;
}
      
  
void init_piece(int ***T,int x,int y,int z){
     
	for(int i=0 ; i < z ; i++ ){
	  for(int j=0 ; j < y ; j++){
	    for(int k=0 ; k < x ; k++){
	    T[k][j][i]=0;
	    }
	  }
	}
   }
   


void afficher_piece(int ***T,int x,int y,int z){

  for(int i=0 ; i < z ; i++ ){
    cout<<"\n z="<<i<<endl;
    for(int j=0 ; j < y ; j++){
      cout<< "\n";
      for(int k=0 ; k < x ; k++){
	cout << T[k][j][i];
	cout << "\t";
      }
    }
  }
}

void afficher_matrice(int **m,int x){
       
      for(int j=0 ; j < x ; j++){
      cout<< "\n";
      for(int k=0 ; k < 3 ; k++){
	cout << m[j][k];
	cout << "\t";
      }
    }
}

int ***con_piece(int **m,int taille){
  int x,y,z;
  x=m[0][0];
  y=m[0][1];
  z=m[0][2];
  for(int i=0; i < taille ; i++){
    if(m[i][0]>x)
      x=m[i][0];
  if(m[i][1]>y)
      y=m[i][1];
  if(m[i][2]>z)
      z=m[i][2];
  }
  
  int ***mat;
  mat=new int **[x];
  for(int i=0;i<x;i++){
    mat[i]=new int *[y];
    for(int j=0;j<y;j++){
      mat[i][j]=new int [z];
    }
  }
  init_piece(mat,x,y,z);
  for(int i=0; i < taille ; i++){
    mat[(m[i][0]-1)][(m[i][1]-1)][(m[i][2]-1)]=1;
  }
  afficher_piece(mat,x,y,z);
  return mat;
}
  
int **rotation_x(int **m,int taille){
  
  // matrice de retation sur X
      int **mat_rx;
      mat_rx=new int*[3];
      for(int i=0 ; i < 3 ; i++ )
      mat_rx[i]=new int[3];
      
      mat_rx[0][0]=1;
      mat_rx[0][1]=0;
      mat_rx[0][2]=0;
      mat_rx[1][0]=0;
      mat_rx[1][1]=0;
      mat_rx[1][2]=-1;
      mat_rx[2][0]=0;
      mat_rx[2][1]=1;
      mat_rx[2][2]=0;
    int min;
    int **mat_resultat;
    mat_resultat=multiplication(m,mat_rx,taille);
    min=min_matrix(mat_resultat,taille);
    for(int i=0;i<taille;i++)
      mat_resultat[i][2]=mat_resultat[i][2]-min+1;
    return mat_resultat;
}

int **rotation_y(int **m,int taille){
  
  // matrice de retation sur Y
      int **mat_ry;
      mat_ry=new int*[3];
      for(int i=0 ; i < 3 ; i++ )
      mat_ry[i]=new int[3];
      
      mat_ry[0][0]=0;
      mat_ry[0][1]=0;
      mat_ry[0][2]=1;
      mat_ry[1][0]=0;
      mat_ry[1][1]=1;
      mat_ry[1][2]=0;
      mat_ry[2][0]=-1;
      mat_ry[2][1]=0;
      mat_ry[2][2]=0;
    int min;
    int **mat_resultat;
    mat_resultat=multiplication(m,mat_ry,taille);
    min=min_matrix(mat_resultat,taille);
    for(int i=0;i<taille;i++)
      mat_resultat[i][0]=mat_resultat[i][0]-min+1;
    return mat_resultat;
  
}
int **rotation_z(int **m,int taille){
  
  // matrice de retation sur Y
      int **mat_ry;
      mat_ry=new int*[3];
      for(int i=0 ; i < 3 ; i++ )
      mat_ry[i]=new int[3];
      
      mat_ry[0][0]=0;
      mat_ry[0][1]=-1;
      mat_ry[0][2]=0;
      mat_ry[1][0]=1;
      mat_ry[1][1]=0;
      mat_ry[1][2]=0;
      mat_ry[2][0]=0;
      mat_ry[2][1]=0;
      mat_ry[2][2]=1;
    int min;
    int **mat_resultat;
    mat_resultat=multiplication(m,mat_ry,taille);
    min=min_matrix(mat_resultat,taille);
    for(int i=0;i<taille;i++)
      mat_resultat[i][1]=mat_resultat[i][1]-min+1;
    return mat_resultat;
  
}

  
int main(int argc, char **argv) {
    std::cout << endl << "Hello, world!" << std::endl;
  
    // PIECE_L  
   int ***piece_L ;
    
     piece_L = new int **[4];
     for (int i=0 ; i < 4 ; i++){
       piece_L[i]= new int *[2];
       for (int n = 0 ; n < 2 ; n++){
	 piece_L[i][n]=new int [1];
      }
     }
   
  init_piece(piece_L,4,2,1);
 
    piece_L[0][0][0]=1;
    piece_L[1][0][0]=1;
    piece_L[2][0][0]=1;
    piece_L[3][0][0]=1;
    piece_L[3][1][0]=1;
 // FIN PIECE_L
    
 // les rotation sur l'axe des x  
    std::cout << endl << "PIECE L!" << std::endl;
    afficher_piece(piece_L,4,2,1);
    
    int ***piece;
    int **M;
    int **mr;
    int n;

      M=V_position(piece_L,4,2,1,n);
      cout<<"\n\n piece L rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece L rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece L rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
      
      //fin de rotation z
      
          // PIECE_Y 
   int ***piece_Y ;
    
     piece_Y = new int **[4];
     for (int i=0 ; i < 4 ; i++){
       piece_Y[i]= new int *[2];
       for (int n = 0 ; n < 2 ; n++){
	 piece_Y[i][n]=new int [1];
      }
     }
   
  init_piece(piece_Y,4,2,1);
 
    piece_Y[0][0][0]=1;
    piece_Y[1][0][0]=1;
    piece_Y[2][0][0]=1;
    piece_Y[2][1][0]=1;
    piece_Y[3][1][0]=1;
    
    std::cout << endl << "PIECE Y!" << std::endl;
    afficher_piece(piece_Y,4,2,1);
  
 // FIN PIECE_Y
    
    M=V_position(piece_Y,4,2,1,n);
      cout<<"\n\n piece Y rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece Y rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece Y rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
      
      //fin de rotation z
      
      // PIECE_P 
   int ***piece_P ;
    
     piece_P = new int **[3];
     for (int i=0 ; i < 3 ; i++){
       piece_P[i]= new int *[2];
       for (int n = 0 ; n < 2 ; n++){
	 piece_P[i][n]=new int [1];
      }
     }
   
  init_piece(piece_P,3,2,1);
 
    piece_P[0][0][0]=1;
    piece_P[0][1][0]=1;
    piece_P[1][0][0]=1;
    piece_P[1][1][0]=1;
    piece_P[2][0][0]=1;
   
    std::cout << endl << "PIECE P!" << std::endl;
    afficher_piece(piece_P,3,2,1);
  
 // FIN PIECE_P
    M=V_position(piece_P,3,2,1,n);
      cout<<"\n\n piece P rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece Y rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece Y rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
      
      //fin de rotation z
        // PIECE_G  
   int ***piece_G ;
    
     piece_G = new int **[3];
     for (int i=0 ; i < 3 ; i++){
       piece_G[i]= new int *[2];
       for (int n = 0 ; n < 2 ; n++){
	 piece_G[i][n]=new int [2];
      }
     }
   
  init_piece(piece_G,3,2,2);
 
    piece_G[0][0][0]=1;
    piece_G[0][0][1]=1;
    piece_G[0][1][0]=1;
    piece_G[1][1][0]=1;
    piece_G[2][1][0]=1;
   
    std::cout << endl << "PIECE G!" << std::endl;
    afficher_piece(piece_G,3,2,2);
    
      M=V_position(piece_G,3,2,2,n);
      cout<<"\n\n piece G rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece G rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece G rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
      
  
    // PIECE_IG  
   int ***piece_IG ;
    
     piece_IG = new int **[3];
     for (int i=0 ; i < 3 ; i++){
       piece_IG[i]= new int *[2];
       for (int n = 0 ; n < 2 ; n++){
	 piece_IG[i][n]=new int [2];
      }
     }
   
  init_piece(piece_IG,3,2,2);
 
    piece_IG[0][0][0]=1;
    piece_IG[0][1][0]=1;
    piece_IG[0][1][1]=1;
    piece_IG[1][0][0]=1;
    piece_IG[2][0][0]=1;
   
    std::cout << endl << "PIECE IG!" << std::endl;
    afficher_piece(piece_IG,3,2,2);
  
 // FIN PIECE_IG
    
        M=V_position(piece_G,3,2,2,n);
      cout<<"\n\n piece IG rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece IG rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece IG rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
      
      //fin IG
      int ***piece_i ;
    
     piece_i = new int **[2];
     for (int i=0 ; i < 2 ; i++){
       piece_i[i]= new int *[3];
       for (int n = 0 ; n < 3 ; n++){
	 piece_i[i][n]=new int [2];
      }
     }
   
  init_piece(piece_i,2,3,2);
 
    piece_i[0][1][0]=1;
    piece_i[0][1][1]=1;
    piece_i[1][0][0]=1;
    piece_i[1][1][0]=1;
    piece_i[1][2][0]=1;
   
    std::cout << endl << "PIECE I!" << std::endl;
    afficher_piece(piece_i,2,3,2);
  
 // FIN PIECE_i
     M=V_position(piece_i,2,3,2,n);
      cout<<"\n\n piece i rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece i rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece i rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);  
      
       // PIECE_T  
   int ***piece_T ;
    
     piece_T = new int **[3];
     for (int i=0 ; i < 3 ; i++){
       piece_T[i]= new int *[3];
       for (int n = 0 ; n < 3 ; n++){
	 piece_T[i][n]=new int [1];
      }
     }
   
  init_piece(piece_T,3,3,1);
 
    piece_T[0][0][0]=1;
    piece_T[0][1][0]=1;
    piece_T[0][2][0]=1;
    piece_T[1][1][0]=1;
    piece_T[2][1][0]=1;
   
    std::cout << endl << "PIECE T!" << std::endl;
    afficher_piece(piece_T,3,3,1);
  
 // FIN PIECE_T
    M=V_position(piece_T,3,3,1,n);
      cout<<"\n\n piece T rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece T rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece T rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);  
      
      // PIECE_PL  
   int ***piece_PL ;
    
     piece_PL = new int **[3];
     for (int i=0 ; i < 3 ; i++){
       piece_PL[i]= new int *[3];
       for (int n = 0 ; n < 3 ; n++){
	 piece_PL[i][n]=new int [1];
      }
     }
   
  init_piece(piece_PL,3,3,1);
 
    piece_PL[0][0][0]=1;
    piece_PL[1][0][0]=1;
    piece_PL[2][0][0]=1;
    piece_PL[2][1][0]=1;
    piece_PL[2][2][0]=1;
   
    std::cout << endl << "PIECE PL!" << std::endl;
    afficher_piece(piece_PL,3,3,1);
  
 // FIN PIECE_PL 
    M=V_position(piece_PL,3,3,1,n);
      cout<<"\n\n piece petit L rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece petit L rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece petit L rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);  
        
      // PIECE_PLUS  
   int ***piece_PLUS ;
    
     piece_PLUS = new int **[3];
     for (int i=0 ; i < 3 ; i++){
       piece_PLUS[i]= new int *[3];
       for (int n = 0 ; n < 3 ; n++){
	 piece_PLUS[i][n]=new int [1];
      }
     }
   
  init_piece(piece_PLUS,3,3,1);
 
    piece_PLUS[0][1][0]=1;
    piece_PLUS[1][0][0]=1;
    piece_PLUS[1][1][0]=1;
    piece_PLUS[1][2][0]=1;
    piece_PLUS[2][1][0]=1;
   
    std::cout << endl << "PIECE PLUS!" << std::endl;
    afficher_piece(piece_PLUS,3,3,1);
    
     M=V_position(piece_PLUS,3,3,1,n);
      cout<<"\n\n piece PLUS rotation sur l'axe des x"<<endl;
   
      mr=rotation_x(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_x(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_x(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_x(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   
  //fin des rotation x;
  //rotation y    
      cout<<"\n\n piece petit PLUS rotation sur l'axe des y"<<endl;
   
      mr=rotation_y(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_y(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_y(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_y(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);
   //fin de rotation y
      //rotation z
      cout<<"\n\n piece petit PLUS rotation sur l'axe des z"<<endl;
   
      mr=rotation_z(M,n);
      cout<< "90 °\n";
      piece=con_piece(mr,n);
      
      cout<< "\n";
      mr=rotation_z(mr,n);
      cout<< "180 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n";
      
      mr=rotation_z(mr,n);
      cout<< "270 °\n";
      piece=con_piece(mr,n);
      
       cout<< "\n"; 
      
       mr=rotation_z(mr,n);
      cout<< "360 °\n";
      piece=con_piece(mr,n);  
  
 // FIN PIECE_PLUS
    return 0;
}


