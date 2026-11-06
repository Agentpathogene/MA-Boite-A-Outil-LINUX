

   ### ⚠️ CE PROJET EST DESTINE A UN USAGE ETHIQUE ET LEGAL ⚠️


   ## pour assembler le code 
   + il faux tout compiler en incluant gtk dans un fichier main
   + puis decommenter la fonction main du fichier 9 et le compiler en basic_image ! le nom est important
   + le fichier ainsi cree sera execute au redemarrage du system infecte


# 1: Cet infostealer est concu pour Linux / Debian et necessite la presence de gtk sur le system

---

Des le lancement  le malware execute son payload parcourant de maniere recursive les fichiers a la recherche des fichiers de mot de pass , de config
ou meme des cles ssh et cookies de sessions ...


<img width="765" height="314" alt="Capture d’écran du 2026-11-04 23-10-46" src="https://github.com/user-attachments/assets/a5b0d9b3-0441-403f-bfe1-c2f7b57a41a9" />

Il copie et tar tout les fichier ainsi trouve dans un fichier temporaire qu'il envoi au server discord de l'attaquant , vous avez qu'a mettre le webhook de votre server pour essayer ce projet.
It met egalement en place une tache planifie s'executant au demarrage du system et exfiltrant a nouveau les donnes de la machine victim .

Votre antivirus saura t'il le bloque ?
Telecharger le fichier main et basic_image dans le meme repos puis lancer main !!! 

## ⚠️ A EXECUTER SUR UNE MACHINE VIRTUEL !!!

<img width="809" height="239" alt="Capture d’écran du 2026-11-04 23-11-28" src="https://github.com/user-attachments/assets/4592dc55-5b94-4e9a-98d6-9094c955f810" />

<img width="599" height="503" alt="Capture d’écran du 2026-11-04 23-12-23" src="https://github.com/user-attachments/assets/535a93c1-c522-424f-a159-ba6e76f2a859" />

Ensuite il affiche un popup de phishing et demande le mot de pass root , qui est a son tour exfiltre vers le server de l'attaquant.

Ce malware est une poc pas une cyber arme , il est a but eductif !
Pour nos amis forensic executer le sur une vm et essayer de retracer son activite !


<img width="1267" height="976" alt="Capture d’écran du 2026-11-02 14-15-03" src="https://github.com/user-attachments/assets/ff6d5bbb-aabb-4b0f-a3df-5b8fc9e8a324" />



pour plus de question je reste joignable sur mon linkdin...

























