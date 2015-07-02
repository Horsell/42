#!/usr/bin/python2.7
from random import randrange

quit = 1
while quit == 1:
	n = input("Veuillez entrer un nombre entre 0 et 50 : ")
	mise = input("Veuillez entrer votre mise :")
	rand = randrange(50)
	if n == rand:
		mise *= 3
		print("Bravo vous avez fait mouche, votre mise est maintenant de : ", mise)
	elif n % 2 == rand % 2:
		mise /= 2
		print("Vous avez la couleur, votre mise est maintenant de : ", mise)
	else:
		mise = 0
		print("Dommage vous avez tout perdu !")
	quit = input("Entrez 1 si vous voulez continuer, 0 pour quitter.")
