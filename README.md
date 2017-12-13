# CasseTete
Résolution de casse tête 3D en C++/Qt/OpenGl


- Partie Model/ Systeme de resolution:

	Pour effectuer des tests sur la recherche de solution:
	-Ouvrir le fichier main.cpp
	-Possibilité 1:Choisir le probleme à tester parmi ceux deja proposés ( dans la fonction main())
		-Commenter ou decommenter le bloc d'insctrcution representatant le problème
	-Possibilité 2: Creer un nouveau probleme prennant en compte
		- Le casse tete à resoudre de "PièceRepresentation"
		- et les pièces à utiliser ou non dans ce probleme 
			
		Chaque type  pièces est representé par un indice dans l'ensemble du projet:
			piecesplus -> 0
			piecesangle -> 1
			pieceZ -> 2
			pieceY -> 3
			pieceP ->4
			pieceD ->5
			pieceG -> 6
			pieceL ->7
			pieceT ->8 
		-lancer le MakeFile


	-En resultat: il est affiché dans le terminal la matrice representant solution dont les cases sont à 1 		(pour les espaces utilisées) ou -1

	Ps: le probleme de base sur lequel la plupart des tests ont été effectués sur le  probleme 5*4*2 		( parallélépipède 8 pièces  sans la pièces plus ) avec une première solution trouvée au environ de 		4min 10s sur une machine de caracteristique suivantes:
		-CPU :Intel Core I5-4330 M CPU @2.80GHZ * 4
		-Carte Graphique :Quadro K610 M/PCle/SSE2
		-Type Systeme: 64 bits
		-Memoire: 8 GO 

		
		
	

-Pour la partie OpenGL : 
	Il faut installer la version 5.9 Qt en suivant le lien : https://linuxhint.com/install-qt-5-9-1-qt-creator-4-3-1-ubuntu/
	Ne pas oublier de forcer le bash à compiler sous la version 5.9
	Ensuite il faut installer les librairies : 
		LIBS   += -lopengl32
		LIBS   += -lglu32
		LIBS   += -lglut32


		
