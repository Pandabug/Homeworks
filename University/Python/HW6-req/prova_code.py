import images
import time
import datetime

a = datetime.datetime.now()

green = (0, 255, 0)
red = (255, 0, 0)
grey = (128, 128, 128)
orange = (255, 128, 0)

def prova1(start_img: str, position: list[int, int], commands: str):
	image_matrix : list[list[tuple(int, int, int)]] = images.load(start_img)

	commands_list : list[str]                       = commands.split()
	commands_done : int                             = 0
	snake_len : int                                 = 1
	stop_snake : bool                               = False
	snake_tail_position                             = []

	image_matrix[position[1]][position[0]] = green
	snake_tail_position.append(position)

	for command in range(len(commands_list)):
		if commands_list[command] == 'N':
			position[1] -= 1

			if command + 1 == len(commands_list) or commands_list[command + 1] == 'SW' and commands_list[command - 1] == 'SE' or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'SW':
				stop_snake = True
		if commands_list[command] == 'S':
			position[1] += 1

			if command + 1 == len(commands_list) or commands_list[command + 1] == 'NE' and commands_list[command - 1] == 'NW' or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'NE':
				stop_snake = True

		if commands_list[command] == 'W':
			position[0] -= 1

			if command + 1 == len(commands_list) or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'NW' or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'SE':
				stop_snake = True

		if commands_list[command] == 'E':
			position[0] += 1

			if command + 1 == len(commands_list) or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'SE' or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'NW':
				stop_snake = True


		if commands_list[command] == 'NW':
			position[0] -= 1
			position[1] -= 1
			
		if commands_list[command] == 'NE':
			position[0] += 1
			position[1] -= 1
			
		if commands_list[command] == 'SE':
			position[0] += 1
			position[1] += 1
			
		if commands_list[command] == 'SW':
			position[0] -= 1
			position[1] += 1
			

		# Snake out screen
		if position[0] >= len(image_matrix[0]) or -position[0] >= len(image_matrix[0]):
			position[0] = 0
		if position[1] >= len(image_matrix) or -position[1] >= len(image_matrix):
			position[1] = 0

		# Snake suicide or Snake hit red
		if image_matrix[position[1]][position[0]] == green or image_matrix[position[1]][position[0]] == red:
			break

		commands_done += 1  # ALSO CAN DO WITH FIND INDEX


		# Snake eat orange
		if image_matrix[position[1]][position[0]] == orange:
			snake_tail_position.append(position)
			snake_len += 1

		# Snake / snake path
		# Check snake current pos add tail position in snake_tail_position and update it 
		# if len(commands_list) - commands_done <= snake_len:
		#     image_matrix[position[1]][position[0]] = green
		# else:
		image_matrix[position[1]][position[0]] = grey

		print(snake_tail_position)
		if len(snake_tail_position) > 0:
			for x in snake_tail_position:
				image_matrix[x[1]][x[0]] = green

		if len(snake_tail_position) > 0:
			image_matrix[x[1]][x[0]] = green
			if snake_len < len(snake_tail_position):
				snake_tail_position.pop()

		# time.sleep(.3)
		images.save(image_matrix, 'prova1.png')

		if stop_snake:
			break

	return snake_len

def prova2(start_img: str, position: list[int, int], commands: str): # NO CHECK BOOL
	image_matrix : list[list[tuple(int, int, int)]] = images.load(start_img)

	commands_list : list[str]                       = commands.split()
	commands_done : int                             = 0
	snake_len : int                                 = 1
	check_snake_path : bool                         = False
	stop_snake : bool                               = False

	image_matrix[position[1]][position[0]] = grey

	for command in range(len(commands_list)):
		if commands_list[command] == 'N':
			position[1] -= 1

			if check_snake_path: 
				if command + 1 == len(commands_list) or commands_list[command + 1] == 'SW' and commands_list[command - 1] == 'SE' or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'SW':
					stop_snake = True

			check_snake_path = False
		if commands_list[command] == 'S':
			position[1] += 1

			if check_snake_path:
				if command + 1 == len(commands_list) or commands_list[command + 1] == 'NE' and commands_list[command - 1] == 'NW' or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'NE':
					stop_snake = True

			check_snake_path = False
		if commands_list[command] == 'W':
			position[0] -= 1

			if check_snake_path:
				if command + 1 == len(commands_list) or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'NW' or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'SE':
					stop_snake = True

			check_snake_path = False
		if commands_list[command] == 'E':
			position[0] += 1

			if check_snake_path:
				if command + 1 == len(commands_list) or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'SE' or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'NW':
					stop_snake = True

			check_snake_path = False

		if commands_list[command] == 'NW':
			position[0] -= 1
			position[1] -= 1
			
			check_snake_path = True
		if commands_list[command] == 'NE':
			position[0] += 1
			position[1] -= 1
			
			check_snake_path = True
		if commands_list[command] == 'SE':
			position[0] += 1
			position[1] += 1
			
			check_snake_path = True
		if commands_list[command] == 'SW':
			position[0] -= 1
			position[1] += 1
			
			check_snake_path = True

		# Snake out screen
		if position[0] >= len(image_matrix[0]) or -position[0] >= len(image_matrix[0]):
			position[0] = 0
		if position[1] >= len(image_matrix) or -position[1] >= len(image_matrix):
			position[1] = 0

		# Snake suicide or Snake hit red
		if image_matrix[position[1]][position[0]] == green or image_matrix[position[1]][position[0]] == red:
			break

		commands_done += 1  # ALSO CAN DO WITH FIND INDEX


		# Snake eat orange
		if image_matrix[position[1]][position[0]] == orange:
			snake_len += 1

		# Snake / snake path
		if len(commands_list) - commands_done <= snake_len:
			image_matrix[position[1]][position[0]] = green
		else:
			image_matrix[position[1]][position[0]] = grey

		# time.sleep(.2)
		images.save(image_matrix, 'prova1.png')

		if stop_snake:
			break

	return snake_len





# def next_move(commands_list, command, position):
#     stop_snake = False

#     if commands_list[command] == 'N':
#         position[1] -= 1

#         if command + 1 == len(commands_list) or commands_list[command + 1] == 'SW' and commands_list[command - 1] == 'SE' or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'SW':
#             stop_snake = True
#     if commands_list[command] == 'S':
#         position[1] += 1

#         if command + 1 == len(commands_list) or commands_list[command + 1] == 'NE' and commands_list[command - 1] == 'NW' or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'NE':
#             stop_snake = True

#     if commands_list[command] == 'W':
#         position[0] -= 1

#         if command + 1 == len(commands_list) or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'NW' or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'SE':
#             stop_snake = True

#     if commands_list[command] == 'E':
#         position[0] += 1

#         if command + 1 == len(commands_list) or commands_list[command + 1] == 'NW' and commands_list[command - 1] == 'SE' or commands_list[command + 1] == 'SE' and commands_list[command - 1] == 'NW':
#             stop_snake = True

#     return stop_snake

# def next_diagonal_move(commands_list, command, position):
#     if commands_list[command] == 'NW':
#         position[0] -= 1
#         position[1] -= 1
		
#     if commands_list[command] == 'NE':
#         position[0] += 1
#         position[1] -= 1
		
#     if commands_list[command] == 'SE':
#         position[0] += 1
#         position[1] += 1
		
#     if commands_list[command] == 'SW':
#         position[0] -= 1
#         position[1] += 1


def prova3(start_img: str, position: list[int, int], commands: str):
	image_matrix : list[list[tuple(int, int, int)]] = images.load(start_img)
	

	index_of_wrong = 0
	wrong_list = [
		# ['NW', 'E', 'SW'],
		# ['SW', 'E', 'NW'],
		# ['NE', 'W', 'SE'],
		# ['SE', 'W', 'NE'],
		# ['SW', 'N', 'SE'],
		# ['SE', 'N', 'SW'],
		# ['NW', 'S', 'NE'],
		# ['NE', 'S', 'NW'], 
		# 
		'NW E SW',
		'SW E NW',
		'NE W SE',
		'SE W NE',
		'SW N SE',
		'SE N SW',
		'NW S NE',
		'NE S NW',
		]
	
	for x in wrong_list:
		if x in commands:
			if index_of_wrong == 0:
				index_of_wrong = commands.index(x)
			if commands.index(x) < index_of_wrong:
				index_of_wrong = commands.index(x)

	commands_list : list[str]                           = commands[:index_of_wrong + 4].split()

	commands_position_dict : dict[str, list[int, int]]  = {
		'N' : [0, -1],
		'S' : [0, 1],
		'W' : [-1, 0],
		'E' : [1, 0],
		'NW' : [-1, -1],
		'NE' : [1, -1],
		'SW' : [-1, 1],
		'SE' : [1, 1],
	}

	# wrong_list = [
	#     # ['NW', 'E', 'SW'],
	#     # ['SW', 'E', 'NW'],
	#     # ['NE', 'W', 'SE'],
	#     # ['SE', 'W', 'NE'],
	#     # ['SW', 'N', 'SE'],
	#     # ['SE', 'N', 'SW'],
	#     # ['NW', 'S', 'NE'],
	#     # ['NE', 'S', 'NW'], 
	#     # 
	#     'NW E SW',
	#     'SW E NW',
	#     'NE W SE',
	#     'SE W NE',
	#     'SW N SE',
	#     'SE N SW',
	#     'NW S NE',
	#     'NE S NW',
	#     ]

	snake_len : int                                     = 1
	snake_tail : list                                   = []
	# stop_snake = False

	image_matrix[position[1]][position[0]] = grey
	snake_tail.append([position[0], position[1]])

	# index_of_wrong = 0
	
	# for x in wrong_list:
	#     index_of = 0
	#     if x[0] in commands_list:
	#         index_of = commands_list.index(x[0])
	#         print(x, index_of, commands_list[index_of], commands_list[index_of+1], commands_list[index_of+2])
	#         if x[1] == commands_list[index_of + 1] and x[2] == commands_list[index_of + 2]:
	#             print('find wrong')
	# #     if x in commands:
	# #         if index_of_wrong == 0:
	# #             index_of_wrong = commands.index(x)
	# #         if commands.index(x) < index_of_wrong:
	# #             index_of_wrong = commands.index(x)

	# print(commands[0 : index_of_wrong+7])

	for command in range(len(commands_list)):
		position[0] += commands_position_dict[commands_list[command]][0]
		position[1] += commands_position_dict[commands_list[command]][1]
		# stop_snake = next_move(commands_list, command, position)
		# next_diagonal_move(commands_list, command, position)
		
		if position[0] >= len(image_matrix[0]) or -position[0] >= len(image_matrix[0]):
			position[0] = 0
		if position[1] >= len(image_matrix) or -position[1] >= len(image_matrix):
			position[1] = 0

		if position in snake_tail or image_matrix[position[1]][position[0]] == red:
			snake_tail.pop(0)
			break

		if image_matrix[position[1]][position[0]] == orange:
			snake_len += 1

		snake_tail.append([position[0], position[1]])
		if snake_len < len(snake_tail):
			snake_tail.pop(0)

		image_matrix[position[1]][position[0]] = grey

		# if stop_snake:
		#     print('why', stop_snake)
		#     snake_tail.pop(0)
		#     break
	
	for x in snake_tail:
		image_matrix[x[1]][x[0]] = green
		
	images.save(image_matrix, 'prova1.png')

	return snake_len




def find_diagonal(commands):
	wrong_list : list[str]  							= [
		'NW E SW',
		'SW E NW',
		'NE W SE',
		'SE W NE',
		'SW N SE',
		'SE N SW',
		'NW S NE',
		'NE S NW',
		]


	try:
		return min(commands.index(x) for x in wrong_list if x in commands), True
	except:
		return len(commands) - 4, False

def screnn_size(position, image_matrix):
	if position[0] >= len(image_matrix[0]) or -position[0] >= len(image_matrix[0]):
		position[0] = 0
	if position[1] >= len(image_matrix) or -position[1] >= len(image_matrix):
		position[1] = 0

def prova4(start_img: str, position: list[int, int], commands: str, out_img = 'prova1.png'):
	image_matrix : list[list[tuple(int, int, int)]] 	= images.load(start_img)
	
	# index_of_wrong, pop_last = find_diagonal(commands)
	index_of_wrong = find_diagonal(commands)
	commands_list : list[str]                           = commands[:index_of_wrong + 4].split()
	# commands_list : list[str] = commands.split()

	commands_position_dict : dict[str, list[int, int]]  = {
		'N' : [0, -1],
		'S' : [0, 1],
		'W' : [-1, 0],
		'E' : [1, 0],
		'NW' : [-1, -1],
		'NE' : [1, -1],
		'SW' : [-1, 1],
		'SE' : [1, 1],
	}

	snake_len : int                                     = 1
	snake_tail : list                                   = []

	image_matrix[position[1]][position[0]] = grey
	snake_tail.append([position[0], position[1]])

	for command in commands_list:
	# for index, command in enumerate(commands_list):
		# if index == len(commands_list) - 1 and pop_last:
		# 	del snake_tail[0]
		# 	break
		
		if len(command) == 2:
			tmp_position_0 = position[0] + commands_position_dict[command][0]
			tmp_position_1 = position[1] + commands_position_dict[command][1]

			if [tmp_position_0, position[1]] in snake_tail and [position[0], tmp_position_1] in snake_tail:
				break

		position[0] += commands_position_dict[command][0]
		position[1] += commands_position_dict[command][1]

		screnn_size(position, image_matrix)

		if position in snake_tail or image_matrix[position[1]][position[0]] == red:
			break

		if image_matrix[position[1]][position[0]] == orange:
			snake_len += 1

		snake_tail.append([position[0], position[1]])

		if snake_len < len(snake_tail):
			del snake_tail[0]

		image_matrix[position[1]][position[0]] = grey

	for x in snake_tail:
		image_matrix[x[1]][x[0]] = green
		
	images.save(image_matrix, out_img)

	return snake_len





#################################################################################### 


def find_diagonal(commands):
	# index_of_wrong : int    							= 0
	# pop_last : bool         							= False
	wrong_list : list[str]  							= [
		'NW E SW',
		'SW E NW',
		'NE W SE',
		'SE W NE',
		'SW N SE',
		'SE N SW',
		'NW S NE',
		'NE S NW',
		]


	try:
		return min(commands.index(x) for x in wrong_list if x in commands)
	except:
		return len(commands) - 4

def screnn_size(position, image_matrix):
	if position[0] >= len(image_matrix[0]) or -position[0] >= len(image_matrix[0]):
		position[0] = 0
	if position[1] >= len(image_matrix) or -position[1] >= len(image_matrix):
		position[1] = 0
	
	return position

def last_save(start_img: str, position: list[int, int], commands: str, out_img = 'prova1.png') -> int:
	red = (255, 0, 0)
	green = (0, 255, 0)
	grey = (128, 128, 128)
	orange = (255, 128, 0)

	image_matrix : list[list[tuple(int, int, int)]] 	= images.load(start_img)
	
	index_of_wrong = find_diagonal(commands)
	commands_list : list[str]                           = commands[:index_of_wrong + 4].split()
	# commands_list : list[str] = commands.split()

	commands_position_dict : dict[str, list[int, int]]  = {
		'N' : [0, -1],
		'S' : [0, 1],
		'W' : [-1, 0],
		'E' : [1, 0],
		'NW' : [-1, -1],
		'NE' : [1, -1],
		'SW' : [-1, 1],
		'SE' : [1, 1],
	}

	snake_len : int                                     = 1
	snake_tail : list                                   = []

	image_matrix[position[1]][position[0]] = grey
	snake_tail.append([position[0], position[1]])

	for command in commands_list:
		# if len(command) == 2:
		# 	tmp_position_0 = position[0] + commands_position_dict[command][0]
		# 	tmp_position_1 = position[1] + commands_position_dict[command][1]

		# 	if [tmp_position_0, position[1]] in snake_tail and [position[0], tmp_position_1] in snake_tail:
		# 		break

		position[0] += commands_position_dict[command][0]
		position[1] += commands_position_dict[command][1]

		screnn_size(position, image_matrix)

		if position in snake_tail or image_matrix[position[1]][position[0]] == red:
			break

		if image_matrix[position[1]][position[0]] == orange:
			snake_len += 1

		snake_tail.append([position[0], position[1]])

		if snake_len < len(snake_tail):
			del snake_tail[0]

		image_matrix[position[1]][position[0]] = grey

	for x in snake_tail:
		image_matrix[x[1]][x[0]] = green
		
	images.save(image_matrix, out_img)

	return snake_len


#################################################################################### 



# 0
print(prova4('./data/input_00.png', [12, 13], 'S W S W W W S W W N N W N N N N N W N'))
# 1
# print(prova4('./data/input_01.png', [1, 28], 'N N E E E E E E E E E E E NE NE NE NE NE NW NW NW NW NW NW NE NW NE NE NE NE E E SE N SW SW N S NE N NE W SW S NE NE S S NW SW N NE E W SW SW W W SE S S W N S S SW SW E S S W W S S W SE W W N SE E NW N N S SW S SE E NE E S S SE SE W SE W SE N S E SW NW W NE NE SW S S NW S NE E SE E S N E NW N S NE S N E E SW S S SE E E NW NW S S S E N S E E S W SW E S SE NW SE E S SW N N SW SW SW N SW SE NE E N SW N NW N SE W SE N N E N NW N SW NW W S NW NE SW NE NE NE S S W NE W NW S E NW SW S N S N W SW NW S W S SE S NW SE SE E N E W N S SW S SE NE NW W E N SW N SW S N S E S NE SW SW W E E S E W N SE S S W NE SW SW SW S S NW E SW S N SW SE SE SW SW NW E SE W E SE W E N SW N E SE SE N W S W S W SW S NE N SW SW S SW S SW NE S E SW S SW SW SW SE SW N S NE SW E SE SE NE NW S NE W SE W SW W W S SW W S N N S E E NE SE E S E E W E NW SE NW N S E W NW S E SE S NW NW S N S S SE SE NW W NE NW NE E SE NW S S N E E NE SW SE SE S SW E N S E NW NE S NW S NE N SW W NW SW W NE SW E NW NE N W E W NW E SE SW NW SE SE W NW E W SE SW E SW S N E S E S SE S S E W N NW N NE E NE NE S SW S NE W W NE NE E SE E NE SE E E N N S N NE W W S SE W SW S E W N SW N E W N S W NE S SW SE NW NW NW S W NW N N NW SW W S E S S S N SE NE W NW SW NE NW SE N SW NE S W NW NE NW NE S E NW S N NE W NE SE SE S E SE NW NE NE SW S S SW NW E SW SE S NE W E SW N SE W W E W SW SE SW W E SE SW E SW NE SE S SW N E E S NE NE NE NW SE SW E SE NE E E SE NW S S N SW S NW W NW NW S N SE S E N W NE W S S NE S NW S SW SE S S S S S SE S S S E W N NW N NE NE E SW N NW E S N N S NE SE NW E NW SW E SE SW NE NW NE N E E NW NW N S NE N W NW SE E S S SW SE NE NW E NE N E S N NW SE S S SW N SW NW SE S E SE NW W NE W SE SE S NE SE S E NW S S NE E SW SW E S NE SE SE E S S SW SW SE N E W N NW NW S N NE E E S NW NE NW N E NE S S W E S SW SW E SW NE W SE NW N'))
# 2
# print(prova4('./data/input_02.png', [12, 25], 'S S S S S W W W W N N N N W N N N W N N N E SE SE SE SW SW SW N N N N N N NE N NW NE NW NE NW NE S E E E E E N E E S S S W S S S S S S S S S S S S S S S E S E SW S S S S W SE W S S SW SE S NW NE SE S NW S N NE W S NW SE SE E S S W NW NW W S NW N NW NE NW N E S SE SW SW E S E N SW SE SW S NW S NW E NW S S NE W S W NE S E S S NW SE S NW W S NW SE W N S NW E S S S SW NW SE S E NW SW SW W S S NE NE S N S S NW W S SE NW SE N SE NW S NW S S N S W SW S S SE NE SW SW S N E SW N N E S N S N S N N SE NW N S NW NE NW S SW NW SE NW SW S W SW E S E SW S SE S N S NE NW N W SW W W S NW S N E S NW S S SE SW NE N NW E NW N N NW NW S W SW SW W E W W E S E W NW W S S S S E S NE SW NW NE SW E NW N S NE S W SE SE N NW SE W SW W NW NW S S N W NE S E S W SW NE NE SW S N SE SW N S SW S NE E SW NE S W SE NW E NW NW SW S SW SW NW SE S NE NE NE SW E E S W NE SE SW SE NW W W SE S S S NW W SE SE NW NW E W S N SE W S NW W NE NW NE E NW NE N N SW N S S SE SW NE SE S SW NE N NE SE S SW S E E S S W N NW E SW N NW E W S SW W NW E NE N E N W S S N NW NW SW NE SW NE S S S W N NW SW NE NE SE E E S S S S SE NE NW S SW S S NW S S NW NE N NW W NW E S'))
# 3 - Check green!!!
# print(prova4('./data/input_03.png', [1, 20], 'S S E E E E E N N N N N E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E N N N N N N N N N N N N N N N N N N E N N N N N N N N E E E E E S S E S S E S E S S S SE SE SE SE SE SE SE SE SE NE NE NE SE NE SE NE NE NE NE NE N NE NE NE N N N N E E E E S S S S S S S S S S S S S S S W N E SW NW E S SE W E E SE SE NE W E S S E SE N SW W SE N SE S NE NE W S NE S E NW S NE N E E E NE S SE W W E S W SE E N NE S SW E SW W NW E SE N NE S S SW S SW N NW NE E N N NE SW S SE E NW NE NE NW S SE W SW SE W SE E S W N N S SW SW SW S NE E E N N S SE N NW W E NE NE S W SW N E W S W NW S S NE S E S NW SE N W SE S SE NE S N SW W SW S NE W N SW NE SE NW W S W SW SW E SE SE S NE W S W W SE NE S NW NE E S E SW S NW SE SE S N W NE NE N W W NW E W NW SE S S S S NW W SW N W S N NE N NW S S NW E SW E E N W NW W S W E W W SE SE NE SW W SW SW SE N NE N W W S N SE SE S S S SE W SE SE SW N SW NE W SW E NW SE SW SW SW SE NW SE S W NE W SW S E W W N S E S SW E N NW SW S E S W E S SE N SE E SW E SE S SW SW SE E SW NW S W SW N SE SW S E E E N SE SE N S S NE N SW SW E S W E E S NW NW E W SW SE W NE SE E NE S E N W NW W SE S NE W SW N S NW NW NW SE NE W SW NW S SW NW SW SW SW S E S NE SW W S W E E S N S N E S W SE NW W S NW S NW SE W S NE SE E NE SE SE SE S SE SE N E NE NE S SW N NW N S N SW SE S S SE W E E NE E S NW N E W W S N N E SE W S E S S E S SE S S E N E NW N W N N SE S SW S NE S W SE W NW SW E NW SW SE NW SW W NE NW NE NW N NW S NE NE S S NE E N NW N W S W SW W W E S S E SW S W NE SW N S S S S SW SE S W E SE W NE S E S W W S W S NE N W N S S E W W SE SW S SE E SW S S SW NW E NE S S NW E SW S N NW NE W W E E S NE S NE S SE N N S S NW N NW SW E S SE S NE E NE SE NW S W SW SE NE NW S SE N NW SW E SE N SE S SE W N E W S S W SW N NW SW SE SE E N SW S NW NE N SW S SW NW S E E S N W E E NW E W S N S SE SE E NW W S NE S NW SE N W S E NW SW N S W E S SW SE E E NE NW S SW S SW S W SE SW NW E SW NW E NE NE NE N E NE N W S S SE S S NE N E SE W N E S S NW S NE NE SE N W S NW NE W SW N S NE W E S S S W SW N S W N W W SW NE NW S N SE N E NW N SE S E N SE N S N SW E N SE N NE E N E E NE SW NW N NE S NE NE NE SE SE E W W N SW N N S S E E S N S E E W N S NW W S S SE S N SW S W SW NE S SW SE SW S SE N SW S NW S W W E S E S S NE S S N S NE S SE NW SE S SW S S NW NW S E NW S SE SE SE SE NW N SW NE E S N NE S NW W S W W S N S S NW NW S S NW SW S E SE SW S SW NW N NW SW S'))
# 4 - Check green!!!
# print(prova4('./data/input_04.png', [19, 35], 'S S S S W W W W N N N N N N E E E E E E E N E S S S E E E E S E S E S E S E S E N N N N N N N E N E E N E N N E N E N E N E N E N N W N W N W N W W W N W N W N W N W W W N N N N E N N E N E E E E NE NE NE NE S NW SW NE NE S SE S E W S W N E NW SE S NW NW NE SE NE S S E SW W NE NE S W NW SE S S SE NE N SW SW NW NW S S N SE SW E SE SW NW NW SW SW NE W W N SE SW S S SW S SW S S S W S E N NW NW SW S NE S SW SE NE S NW W NE W N S S SW NE SW NE SW SW NE W SW SE E W N SW W NE SE SE S W SE NW NW N E NE SW NW SW W NE NW NW NE S N E NE NE N N E E S NW SW NW E NW NE S E SW N W NE S NW NE N N N N NW SW S SW NW SW SW W NW SW SW E SE W W W NE SE SE S E S SE E W NW SE NE S SW E NW NW S SE S N W NE NW SW S E S E S NW SW S E S NW N SW N W W NE E E N N E E S W NE SE NW E SW S SW N W S S NE NW SW NE NE N W S SE SE S SE S W N S N N NW NW NW S SE S S S SW E W NE NE NW SW W N NW W NW W S N N NE NE S S W SW S N E S NW SW N'))
# 5 - Check green!!!
# print(prova4('./data/input_05.png', [32, 94], 'NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE W W W W W W W S S S S S S S E S S N N N SW SW S W S N E S E W S N NW S SE W N S E SW SW S W E NW S S E E E SW S SE E NW N S NW S E NW SW E SE N SW NW NE S NE NE NE E N S S W E NE S S W SE NE SE E N SE SE SW S E S S NW E NW S S NE N NE NE W W SW NW N SW S NE S W S NE NW NW NW SW SE S SW NE S S N E E E NE S NE W E SW NW SW S NE SE W SW E NE NE NE S NW S NW S W SW SW N SE E SE NE S SE W SW S W SW N W NE S W W SE NE S E S N SW SW S E N SE SE S SW S NW SW E NW E E W S N S NW S W E S SE S N E E N SW SE E W S E S SW SE E NW W NW W N SW SW S E N SW NW SW W E NW E N E S N S SW E E S E NW NE NE SE S N S NE N NW W S S S SW E W NE W E S SE E N NE NE W SE SW NW SW E S E N SE E S NE S E NW S SW NW E S NW S SE NW NW S S S S SE N SE SE NE SE NE N SE NW NW NW NE SE NE S S N N S SW S W W E NE SW W N NE NW NW S S E SE E N E SW SE S NE N NW E E NE NE S S S NW W SW W S S N S E E S N S SE S W W SW SW W SW NW S SE E SE W NE W W S E NW SW N NW SW S NE SW SW SE S SW N W SW NE W NE NE NE NW S S S SW NW S N W S W NE S S S S W S'))
# 6 - Check green!!!
# print(prova4('./data/input_06.png', [28, 1], 'S S S S E S S S E E E E E E E E E E E E E E E E E E N E N N N N E S E E E N W W N W W W S S E N E S E E N W N W W W W W W W W W W N N N N W N E E S S S S E E N E E S S S S W N N W W W W N W W W W N W S S S S W S W S W N W N E N N N W W W W S S S S S W W N N N W W N W W W S S S S S E E E E E E E S S S S S SE SE SE SE SE SE SE SE NE NE S E E E E E E E E E E E E E E E E E E E NE NE NE NE NE S NW S SE SE SE SE SE SE SE SE NE NE S E E E E E E E E E E E E E E E E E E E NE NE NE NE NE S'))
# 7 - Check green!!!
# print(prova4('./data/input_07.png', [2, 18], 'E E E E S S W S S S E S E E E E E E E E E E N E E N NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE N E S S E S E E E N NE E E E S E N N W W W W W S E E E E S E N N W W W W W W W W W N E E E E E E E E E E NE NE N W N N E E E E E N E N N W N N N E N N E N E N N N N E E S S S S E E E E E E E E E S S S S S S S S S E E E E S W W W W N SE NW NW SE E N W SE W N NW S W NE N S SW SE SE SW SW S NE E S W N S SW W SE SE N SW SE W E W SW E NW NW NW N N NE S E N SE W E SW E E N N S NW S W S S SE SW NE SW SE NW S NE S S S NE W E S S W S SE E SE NE W W NE SE NE W SE NW NE SE NE N NE SW NW SE N S SE SW S NE E SW NW N SW NE W E N N W E S W S S S N S SW NW E SW NE NE S SE S NW SE W W NW S E S NE S NW W S W NW W SW NE W W W NW SE SW SW W NE W S NW S S'))
# 8 - Check green!!!
# print(prova4('./data/input_08.png', [2, 18], 'S S E E S E S E S S E E E E E E E N W W W W N W N W N N E E E E N W N N E N E N N N E E S E S E E E E E N W N E E E E E E N N W N W W W N N E E E N W N E E E E S S S S E S S S S S S W W W S S E S S S E N N N N E E N N N N N N N N E E S S W S S S S S S E E E E N N N N E N N E E N E E E S S S S E E S W S S E E E N N E S S S W S S E S S E S S S S S S W W W S W W N W W N W S S S S S S S E E S S S E S S S S S S S S W S S W N N W S S S S S S S S S W W W W W S S S S W S S E E E E S S W W S W S W S W S W S W S W S S S E S S S S S E S S S W S S E E N E N N E S S S S S W S W S W W S W S S S S E S W S E E S S S S E E E S S S W W W W W W W W W W N N N E N N N N N N N N N N N N W W W W W W S S S W W N N N N N N E S E E N N N N N N N W W N E E E E E N N N W W N W N W N W N W N N N N N W NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NE NE NE NE N N N N N N N N N N N NW NW NW NW NW NW NW NW W W W S W S W SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW W W N N E E N N E N N E N N N N E S E N N E N N E SE N SW N N E N N N N E S E N N E N N E SE N SW'))
# 9 - Check green!!!
# print(prova4('./data/input_09.png', [39, 16], 'SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW SW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NW NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE SE NE NE SE NE SE NE SE NE SE NE SE NE SE NE SE NE NE SE NE SE NE SE NE SE SE SE SE NE NE SE NE SE NE SE NE SE NE SE SE SE SE SE NE NE SE NE NE NE SE SE SE SE SW SW SW SW SW SW SW SW SW SW N N N SW N SW SW N SW N SW N SW N SW N SW N SW N SW SW SW N SW N SW SW N N N N SW N SW N SW N SW N N N N SW N SW N SW N SW N SW N SW N SW SW N SW N N N SW SW N SW SW SW SW SW SW SW SE SE SE SE SE SE SE SE SE SE NE NE NE NE NE NE NE N N N NW NW NW NW S NE NW S SW S E S NE E S NW SE NE SE SE NW S E SE E N SE S N NW E S SW NE S S S E W NE NE SE N W E S S S NE S S N S NW E SW S N NE NE N N NW SE S S SE E E S SE SW NW S SE E E NE SW NW E S S NE N N NE SE S SE NW W S S NE W NW N W S SE E S N SE S SE SE S S W N SE SW SE NW N E NE SE S SE SW N NW SE NW SW W NE W N S NW SE W S E SE NW N SE E NW W NW SW S S E W SE W NW N W SW S SE NE S S SW S SW N W S SE E NE S N SE S N NW S S S NE W S SE SE E NE E W S NE N SW S S NW S SE W E S NE E NE E SW SE W NW SW NW SE E W SE NE E SW SW E NW SE NE S NW SW W NE W E S N NE S E NE S SW S W NW W N NW SE SE E NE NE SE NE S NW W SE SE N S S NW W E NW S SW W NW W E NW S NE SE W W NW SW NE NW S NW NW SW SE SE N NE E SW N NW E SE SW NE SE NE W S NW NE NW S E S NW SE S S SE N NE N NE N W NE NE E SW NW E S S E S S NW SW N W SE S NE NE S N S E SE W NW S E NW SE S E SW SW N SW S NE NW N E SE S S S S E S S SW NW SE SW NW NW NW S E SW SE NE NE E SW W NE SE W SW S S S SW S S NE W S S SW W NW SW E N E NW W E SW SE SW NE SW SW SE E N'))
# 10 - Check green!!!
# print(prova4('./data/input_10.png', [40, 7], 'S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S E N E N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N N W S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S S W S W S W S W S S W W W S S S S W W W W W W S W W W S S S S W W N E N N N N E E E N E N N N N N N N NW NW NW NW NW NW NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE NE N N N N N W W W S S W S S S S W W N W NW NW NW NW NW NW NW NW NW NW W W W W W W S W W W S S S E S S S S S E S S S S S S W W W W S S S E N E E S S S S W S W S W S W N N N N N W N N N N N N N N N W W N N N N W W N W N N N W W S S S S S S S S S S S E S E E E S S S S S W S W S W S S S S S S S S E S E S S E E E E E E E E E E E E E E E E E E E E E E E E E E N W W W W W W W W W W W W W W W W W W W W W W W W W N N W N W N N N N N N E N E N E N N N N N N NW NE NW NE NW NE NW NE NW NE NW NE NW NE NW NE NE S NW N E NW NE SW N S NW E NE SE SE SE NW W E E SE S S NE S S E NW S NE SE NW E S S SE W NW SW N NE SE SW S SE NE W S SW N W W S SE S E SW NW NW NE NE NW W SE SW NW N W NE NE S W S NE W NE E E S NE N S W SE NE NW NE NE E E NE SE NE S NE W NW NE E S W E SW SW N S N S SE W SE N SE E NW SW S SW S SE E S S SE NW SE S N N E E NE SE S S W S SE NE S SW S SE S W NW SW S W N S SE SW N E E S NW E SW NW S N NW S S NW NW S SE S E N S NW NW SW SW SE N NE NE NE S SE W SW NE S E SW SW SE W SW S S SE SW SW W SW NE S S SE W W SW S E N E N SE N S N S S SE SE N N S S N NW E N S S S NE S W NE N W S N N NE S E SE NE E E SW N W NW N NW S NW NE NW SW S S SE S S E SE NE NE NE W SW NW NE E SE E S NE NW NE SW NE W S SE NW E NE SE SE S SE NE NE S S SE W SW E W NW S SE NE NW SW NE S E SW NW NW NW E E NE S S SW NE E W NE N NW W E SW NW W E N E S NW NE S W SW SW W W S E SW NW E N SE SE S SE S S S SE NE NE E NW SW S W SE NE SE S S SE W NE N NW W NW W SW N SW N S NW E SE SE W SW SW NE E NE SW E N E E N S NE NE NE SE NE SW S NW W W S N W N S SE S SE SE NE N N N SE S N SE NE W N SW S S S NW E N SW W NW NW N SW NW W NW NW NE SE NE S S E W E NE S SE NW NE SW NW S E NW NE S W NW SE SE E SE E E N NE NW NW NW SW SW S N W SW S SE S E SE SE S NW E SW NW SW SE E SE SW NW NW E W NW W E N N W SE N SE NW S S N W NW N S SE SE SW W NE SE N S SE SE W E W S SW NW S SW N NW S S N W S NW S S SE NE SE SW W SE E SW E N S S W SE N E N SW W W S NW SE N S S NE S N W SW NW NE W NW NE S S S N N S N NW N NE S W S SE NW E NE E E W S N SE SW SE N E NE SE S E N W S SW S S N S N W E SW NW SE SE W SW NW S E S NW S N N S N SE E S NE SE N W S NE W NE NW E NW S SE NW S W S S S NE NW SE E S SW NE SE S S SE NW NW NE NE E S NW E NE N NW NE W SW E N NW NE W W N S W S N SW SE N S N S E SE W NW S N S SE E S NE SE N SW SW SW SE S N NW SE N NE S W S E N E SE S S NE N E NW SE SE NE SW S NW S S SW SW SW W E NW S S SE W NE N SW W N N SW S SW NE E NE SE NE SE S S NE NE NE E NW NE N NE W S N SE E W S S NW N SW NE W E E SE S SW NW NE W N W W S W NW NE W SE SW W NE W E N N N W S S N S SW NW S N SE NE N N SE NW SE E E NW NW NE SW N S N E W S E SW S NW SE NW S E SW N N S SW W N N NE N W NE SW S E W NW SE N E W SE NW E S NE SE E E S N S SE E NE E NE SW NE NE SE SW E S S S S W SW E NW E S SE E S SW SW W NE N W SW S NW NW E E NE E NE SW W NE W S W W SW E W NW S SE W SW E NW S SE S SE W W E NW NW W N SW N S E SW NE NE W E N NE S NW E S E S N S NW S SE N SW'))

b = datetime.datetime.now()
print(b - a)

