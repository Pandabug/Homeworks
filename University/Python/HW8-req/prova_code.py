# %%
###################################### PROVA 1 ################################################


def game_solution1(board, player, height, width, lista_a_b_c):
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

	if player == 'B':
		enemy = 'W'
	else:
		enemy = 'B'

	can_end = False

	for x in range(height):
		for y in range(width):
			if board[x][y] == '.':
				if check_enemy1(board, enemy, x, y, moves, height, width):
					can_end = True
					copy_board = [list(z) for z in board]

					copy_board[x][y] = player
					change_player_board1(copy_board, moves, height, width, enemy, player, x, y)

					game_solution1(copy_board, enemy, height, width, lista_a_b_c)
				
	if not can_end:
		check_winner1(board, lista_a_b_c)

	return tuple(lista_a_b_c)


def check_enemy1(board, enemy, x, y, moves, height, width):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[x + move_x][y + move_y] == enemy:
				return True

	return False


def change_player_board1(board, moves, height, width, enemy, player, x, y):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[adjacent_x][adjacent_y] == enemy:
				board[adjacent_x][adjacent_y] = player


def check_winner1(board, lista_a_b_c):
	count_W = 0
	count_B = 0

	for z in board:
		count_W += z.count('W')
		count_B += z.count('B')

	if count_B > count_W:
		lista_a_b_c[0] += 1
	elif count_B < count_W:
		lista_a_b_c[1] += 1
	else:
		lista_a_b_c[2] += 1

	return lista_a_b_c


def dumbothello1(filename : str) -> tuple[int,int,int]:
	# il tuo programma va qui
	file_data = open(filename, mode='r').readlines()
	game_matrix = [x.split() for x in file_data]

	a = b = c = 0
	height, width = len(game_matrix), len(game_matrix[0])
			
	return game_solution1(game_matrix, 'B', height, width, [a, b, c])


################################################################################################






# %%
###################################### PROVA 2 ################################################


def game_solution2(board, player, height, width, lista_a_b_c, num, file):
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

	if player == 'B':
		enemy = 'W'
	else:
		enemy = 'B'

	can_end = False

	for x in range(height):
		if '.' in board[x]:
			for y in range(width):
				if board[x][y] == '.':
					if check_enemy2(board, enemy, x, y, moves, height, width):
						can_end = True
						copy_board = [list(z) for z in board]

						copy_board[x][y] = player
						change_player_board2(copy_board, moves, height, width, enemy, player, x, y)

						file.write(num*'\t' + f"{num} - copy_board:\n")
						for z in copy_board:
							file.write(num*'\t' + f"{z}\n")
						file.write('\n')

						game_solution2(copy_board, enemy, height, width, lista_a_b_c, num+1, file)
				
	if not can_end:
		check_winner2(board, lista_a_b_c)

	return lista_a_b_c


def check_enemy2(board, enemy, x, y, moves, height, width):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[x + move_x][y + move_y] == enemy:
				return True

	return False


def change_player_board2(board, moves, height, width, enemy, player, x, y):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[adjacent_x][adjacent_y] == enemy:
				board[adjacent_x][adjacent_y] = player


def check_winner2(board, lista_a_b_c):
	count_W = 0
	count_B = 0

	for z in board:
		count_W += z.count('W')
		count_B += z.count('B')

	if count_B > count_W:
		lista_a_b_c[0] += 1
	elif count_B < count_W:
		lista_a_b_c[1] += 1
	else:
		lista_a_b_c[2] += 1

	return lista_a_b_c


def dumbothello2(filename : str) -> tuple[int,int,int]:
	# il tuo programma va qui
	file_data = open(filename, mode='r').readlines()
	game_matrix = [x.split() for x in file_data]

	a = b = c = 0
	height, width = len(game_matrix), len(game_matrix[0])

	num = 0
	file = open('file_seq.txt', 'w', encoding='utf-8')

	return tuple(game_solution2(game_matrix, 'B', height, width, [a, b, c], num, file))


################################################################################################





# %%
###################################### PROVA 3 ################################################


def game_solution3(board, dots_coords, player, height, width, lista_a_b_c):
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
	game_result = False

	for x, y in dots_coords:
		if check_enemy3(board, enemy, x, y, moves, height, width):
			game_result = True

			# Make a copy of the board and dots_coords
			copy_board = [list(z) for z in board]
			copy_dots_coords = list(dots_coords)

			# Change board B W colors
			copy_board[x][y] = player

			for move_x, move_y in moves:
				adjacent_x = x + move_x
				adjacent_y = y + move_y

				if height > adjacent_x >= 0 and width > adjacent_y >= 0:
					if copy_board[adjacent_x][adjacent_y] == enemy:
						copy_board[adjacent_x][adjacent_y] = player

			# Remove the dot that I just check from the list
			copy_dots_coords.remove((x, y))

			game_solution3(copy_board, copy_dots_coords, enemy, height, width, lista_a_b_c)

	if not game_result:
		check_winner3(board, lista_a_b_c)

	return lista_a_b_c


def check_enemy3(board, enemy, x, y, moves, height, width):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[adjacent_x][adjacent_y] == enemy:
				return True

	return False


def check_winner3(board, lista_a_b_c):
	count_W = 0
	count_B = 0

	for x in board:
		count_W += x.count('W')
		count_B += x.count('B')

	if count_B > count_W: lista_a_b_c[0] += 1
	elif count_B < count_W: lista_a_b_c[1] += 1
	else: lista_a_b_c[2] += 1


def dumbothello3(filename : str) -> tuple[int,int,int]:
	# il tuo programma va qui
	file_data = open(filename, mode='r').readlines()
	game_matrix = [x.split() for x in file_data]
	
	height, width = len(game_matrix), len(game_matrix[0])
	
	dots_coords = [(x, y) for x in range(height) for y in range(width) if game_matrix[x][y] == '.']
	a = b = c = 0

	return tuple(game_solution3(game_matrix, dots_coords, 'B', height, width, [a, b, c]))



################################################################################################


# %%
###################################### NO MEM ###############################################


def game_solution(board, dots_coords, player, height, width):
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
	game_result = False
	a = b = c = 0

	for x, y in dots_coords:
		if check_enemy(board, enemy, x, y, moves, height, width):
			game_result = True

			# Make a copy of the board and dots_coords
			copy_board = [list(z) for z in board]
			copy_dots_coords = list(dots_coords)

			# Change board B W colors
			copy_board[x][y] = player

			for move_x, move_y in moves:
				adjacent_x = x + move_x
				adjacent_y = y + move_y

				if height > adjacent_x >= 0 and width > adjacent_y >= 0:
					if copy_board[adjacent_x][adjacent_y] == enemy:
						copy_board[adjacent_x][adjacent_y] = player

			# Remove the dot that I just check from the list
			copy_dots_coords.remove((x, y))

			res = game_solution(copy_board, copy_dots_coords, enemy, height, width)
			a += res[0]
			b += res[1]
			c += res[2]

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


def check_winner(board):
	count_W = 0
	count_B = 0

	for x in board:
		count_W += x.count('W')
		count_B += x.count('B')

	if count_B > count_W: return [1, 0, 0]
	elif count_B < count_W: return [0, 1, 0]
	else: return [0, 0, 1]


def dumbothello(filename : str) -> tuple[int,int,int]:
	# il tuo programma va qui
	file_data = open(filename, mode='r').readlines()
	game_matrix = [x.split() for x in file_data]
	
	height, width = len(game_matrix), len(game_matrix[0])
	
	dots_coords = [(x, y) for x in range(height) for y in range(width) if game_matrix[x][y] == '.']

	return game_solution(game_matrix, dots_coords, 'B', height, width)


################################################################################################





# %%
###################################### PROVA 4 ################################################


def game_solution4(my_dict, board, dots_coords, player, height, width):
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
		if check_enemy4(board, enemy, x, y, moves, height, width):
			game_result = True

			copy_board = [list(z) for z in board]
			copy_dots_coords = list(dots_coords)

			copy_board[x][y] = player
			change_player_board4(copy_board, moves, height, width, enemy, player, x, y)
			copy_dots_coords.remove((x, y))

			str_board = ''.join([''.join(z) for z in copy_board])
			
			if not (str_board, player) in my_dict:
				my_dict[(str_board, player)] = game_solution4(my_dict, copy_board, copy_dots_coords, enemy, height, width)

			a += my_dict[(str_board, player)][0]
			b += my_dict[(str_board, player)][1]
			c += my_dict[(str_board, player)][2]

	if not game_result:
		return check_winner4(board)

	return (a, b, c)


def check_enemy4(board, enemy, x, y, moves, height, width):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[adjacent_x][adjacent_y] == enemy:
				return True

	return False


def change_player_board4(board, moves, height, width, enemy, player, x, y):
	for move_x, move_y in moves:
		adjacent_x = x + move_x
		adjacent_y = y + move_y

		if height > adjacent_x >= 0 and width > adjacent_y >= 0:
			if board[adjacent_x][adjacent_y] == enemy:
				board[adjacent_x][adjacent_y] = player

	return board


def check_winner4(board):
	count_W = 0
	count_B = 0

	for x in board:
		count_W += x.count('W')
		count_B += x.count('B')

	if count_B > count_W: return (1, 0, 0)
	elif count_B < count_W: return (0, 1, 0)
	else: return (0, 0, 1)


def dumbothello4(filename : str) -> tuple[int,int,int]:
	# il tuo programma va qui
	file_data = open(filename, mode='r').readlines()
	game_matrix = [x.split() for x in file_data]
	
	height, width = len(game_matrix), len(game_matrix[0])
	
	dots_coords = [(x, y) for x in range(height) for y in range(width) if game_matrix[x][y] == '.']

	my_dict = {}

	return game_solution4(my_dict, game_matrix, dots_coords, 'B', height, width)



################################################################################################




