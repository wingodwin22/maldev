INJECTION SHELLCODE   EXO1

OBJECTIF

dans cet exercice, le scenario que voulais mettre en oeuvre est d'avoir un binaire affichant la date et l'heure actuelle. Et un auttre affichant un texte et juste apres continu avec l'execution du fichier de date.

pour que le programme fonctionne comme souhaiter, le but est de modifier l'addresse de debut du binaire de date par l'adresse de debut du binaire affichant le texte et de mettre l'adresse de debut du binaire de date 
a la fin du binaire texte.

Avec readelf -h nom du binaire pour lire le point d'entree des fichier et avec hexedit faire les modication.
