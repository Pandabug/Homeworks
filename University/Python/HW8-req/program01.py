#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Othello, o Reversi (https://en.wikipedia.org/wiki/Reversi), è un gioco da tavolo
giocato da due giocatori su una scacchiera 8x8. Pur avendo regole
relativamente semplici, Othello è un gioco di notevole profondità strategica.
In questo esercizio bisognerà simulare una versione semplificata di othello,
chiamata Dumbothello, in cui un giocatore cattura le pedine dell'avversario in
prossimità della propria pedina appena giocata.
Ecco le regole di Dumbothello:
- ogni giocatore ha un colore associato: bianco, nero;
- il giocatore con il nero è sempre il primo a giocare;
- a turno, ogni giocatore deve mettere una pedina del suo colore in modo tale
  da catturare una o più pedine avversarie;
- catturare una o più pedine avversarie vuol dire che la pedina giocata dal
  giocatore trasforma nel colore del giocatore tutte le pedine avversarie
  direttamente adiacenti, in una qualunque direzione orizzontale, verticale o diagonale;
- dopo aver giocato la propria pedina, le pedine avversarie catturate cambiano
  tutte colore e diventano dello stesso colore del giocatore che ha appena giocato;
- quando il giocatore di turno non può aggiungere ulteriori pedine in gioco,
  la partita termina. Vince il giocatore che ha più pedine sulla scacchiera
  oppure avviene un pareggio se il numero di pedine dei due giocatori è uguale;
- il giocatore di turno non può aggiungere ulteriori pedine se non ha modo di
  catturare nessuna pedina avversaria con nessuna mossa, oppure non ci sono
  più caselle libere sulla scacchiera.

Si deve scrivere una funzione dumbothello(filename) che legga da un file di testo
indicato dalla stringa filename una configurazione della scacchiera e,
seguendo le regole di Dumbothello, generi ricorsivamente l'albero di gioco completo
delle possibili evoluzioni della partita, in modo tale che ogni foglia dell'albero
sia una configurazione da cui non sia più possibile effettuare alcuna mossa.

La configurazione inziale della scacchiera nel file è rappresentata riga per
riga nel file. Una lettera "B" identifica una pedina del nero, una "W" una
pedina del bianco e il carattere "." una casella vuota. Le lettere sono
separate da uno o più caratteri di spaziatura.

In particolare, la funzione dumbothello restituirà una tripla (a, b, c), in cui:
- a è il numero totale di evoluzioni che terminano con una vittoria del nero;
- b è il numero totale di evoluzioni che terminano con una vittoria del bianco;
- c è il numero totale di evoluzioni che terminano con un pari.

Ad esempio, dato in input un file di testo contenente la scacchiera:
. . W W
. . B B
W W W B
W B B W

La funzione ritornerà la tripla:
(2, 16, 0)

ATTENZIONE: la funzione dumbothello o qualche altra 
funzione usata per la soluzione deve essere ricorsiva.

'''

def game_solution(my_dict, board, dots_coords, player, height, width):
	moves = [
		(0, -1), 		# LEFT
		(-1, -1), 		# TOP-LEFT
		(-1, 0), 		# TOP
		(-1, +1), 		# TOP-RIGHT
		(0, +1), 		# RIGHT
		(+1, +1), 		# BOTTOM-RIGHT
		(+1, 0), 		# BOTTOM
		(+1, -1), 		# BOTTOM-LEFT
	]

	enemy = 'W' if player == 'B' else 'B'
	a = b = c = 0
	game_result = False

	for x, y in dots_coords:
		if check_enemy(board, enemy, x, y, moves, height, width):
			game_result = True

			copy_board = [list(z) for z in board]
			copy_dots_coords = list(dots_coords)

			copy_board[x][y] = player
			change_player_board(copy_board, moves, height, width, enemy, player, x, y)
			copy_dots_coords.remove((x, y))

			str_board = ''.join([''.join(z) for z in copy_board])
			
			if not (str_board, player) in my_dict:
				my_dict[(str_board, player)] = game_solution(my_dict, copy_board, copy_dots_coords, enemy, height, width)

			a += my_dict[(str_board, player)][0]
			b += my_dict[(str_board, player)][1]
			c += my_dict[(str_board, player)][2]

	if not game_result:
		return check_winner(board)

	return (a, b, c)


def check_enemy(board, enemy, x, y, moves, height, width):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[adjacent_x][adjacent_y] == enemy:
				return True

	return False


def change_player_board(board, moves, height, width, enemy, player, x, y):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[adjacent_x][adjacent_y] == enemy:
				board[adjacent_x][adjacent_y] = player

	return board


def check_winner(board):
	count_W = 0
	count_B = 0

	for x in board:
		count_W += x.count('W')
		count_B += x.count('B')

	if count_B > count_W: return (1, 0, 0)
	elif count_B < count_W: return (0, 1, 0)
	else: return (0, 0, 1)


def dumbothello(filename : str) -> tuple[int,int,int]:
	# il tuo programma va qui
	file_data = open(filename, mode='r').readlines()
	game_matrix = [x.split() for x in file_data]
	
	height, width = len(game_matrix), len(game_matrix[0])
	
	dots_coords = [(x, y) for x in range(height) for y in range(width) if game_matrix[x][y] == '.']

	my_dict = {}

	return game_solution(my_dict, game_matrix, dots_coords, 'B', height, width)


if __name__ == "__main__":
	R = dumbothello("boards/01.txt")
	print(R)