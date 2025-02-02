# -*- coding: utf-8 -*-
'''
Una serie di poster rettangolari sono stati affissi ad un muro.  I
   loro lati sono orizzontali e verticali. Ogni poster può essere
   parzialmente o totalmente coperto dagli altri. Chiameremo
   perimetro la lunghezza del contorno dell'unione di tutti i posters
   sul muro. Si guardi l'immagine in "posters.png" in cui i poster sulla
   parete compaiono in bianco coi bordi blu e la si confronti con l'immagine
   "posters1.png" in cui in rosso vengono evidenziati i soli
   bordi che contribuiscono al perimetro.

Vogliamo un programma che calcola il perimetro dei poster e produce
   una immagine simile a "posters1.png".

Progettare dunque una funzione
     ex1(ftesto, filepng)
   che prenda come parametri
   - ftesto, l'indirizzo di un file di testo contenente le informazioni sulla
     posizione dei poster sul muro,

   - filepng, nome del file immagine in formato PNG da produrre

   e restituisca il perimetro dei poster come numero di pixel rossi.

Il file di testo contiene tante righe quanti sono i poster,
   nell'ordine in cui sono stati affissi alla parete. In ciascuna
   riga ci sono le coordinate intere del vertice in basso a sinistra e
   del vertice in alto a destra del poster. I valori di queste
   coordinate sono dati come coppie ordinate della coordinata x
   seguita dalla coordinata y. Si veda ad esempio il file
   rettangoli_1.txt contenente le specifiche per i 7 posters in
   "posters.png".
   
L'immagine da salvare in filepng deve avere lo sfondo nero, altezza h
   +10 e larghezza w+10 dove h è la coordinata x massima del muro su
   cui compaiono poster e w la coordinata y massima del muro su cui
   compaiono posters. I bordi visibili dei poster sono colorati di
   rosso o di verde a seconda che appartengano al perimetro o meno.
   Notare che un pixel si trova sul perimetro (e quindi è rosso) se nel
   suo intorno (gli 8 pixel adiacenti) si trova almeno un pixel esterno
   a tutti i poster.

   Per caricare e salvare i file PNG si possono usare le funzioni load
   e save presenti nel modulo "images".

Per esempio: ex1('rettangoli_1.txt', 'test_1.png') deve costruire un file PNG
   identico a "posters1.png" e restituire il valore 1080.
   
NOTA: il timeout previsto per questo esercizio è di 1.5 secondi per ciascun
   test

ATTENZIONE: quando caricate il file assicuratevi che sia nella
    codifica UTF8 (ad esempio editatelo dentro Spyder)

'''

import images

def ex1(ftesto, filepng):
    # inserisci qui il tuo codice
	black = (0, 0, 0)
	red = (255, 0, 0)
	green = (0, 255, 0)
	white = (255, 255, 255)

	file_lines : str                            = open(ftesto, 'r').readlines()
	file_matrix : list[list[int]]               = [[int(coordinate) for coordinate in line.split()] for line in file_lines]

	max_val : list[int]                         = list(map(max, zip(*file_matrix)))
	# max_val_1, max_val_2 = max(x[1] for x in file_matrix), max(x[2] for x in file_matrix)

	count_perimeter : int                       = 0
	image  : list[list[tuple(int, int, int)]]   = [[black for _ in range(max_val[2] + 10)] for _ in range(max_val[1] + 10)]

	for coordinate in file_matrix:
		if file_matrix[len(file_matrix) - 1][0] < coordinate[0] and file_matrix[len(file_matrix) - 1][1] > coordinate[1] and file_matrix[len(file_matrix) - 1][2] > coordinate[2] and file_matrix[len(file_matrix) - 1][3] < coordinate[3]:
			continue
		else:
			for y in range(coordinate[3], coordinate[1] + 1):
				for x in range(coordinate[0], coordinate[2] + 1):
					if coordinate[0] < x < coordinate[2] and coordinate[3] < y < coordinate[1]:
						image[y][x] = white
					else:
						image[y][x] = green

	for y in range(5, len(image) - 5):
		for x in range(3, len(image[y]) - 7):
			if image[y][x] == green and (image[y + 1][x] == black or image[y + 1][x + 1] == black or image[y + 1][x - 1] == black or image[y - 1][x] == black or image[y - 1][x + 1] == black or image[y - 1][x - 1] == black or image[y][x + 1] == black or image[y][x - 1] == black):
				image[y][x] = red
				count_perimeter += 1

	images.save(image, filepng)

	return count_perimeter
    # pass





if __name__ == '__main__':
    pass
    # inserisci qui i tuoi test
