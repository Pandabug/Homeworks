import images
import datetime
import time
a = datetime.datetime.now()

# colori
black = (0, 0, 0)
red = (255, 0, 0)
green = (0, 255, 0)
blu = (0, 0, 255)
white = (255, 255, 255)

def prova1(ftesto : str, filepng : str):
    # encoding_file_png = images.load(filepng)

    # count = 0
    # for x in encoding_file_png:
    #     for y in x:
    #         if y == (255, 0, 0):
    #             count += 1

    # print(count)


    # with open(ftesto, mode='r', encoding='utf-8') as f:
    #     read_ftesto = f.read()
    file_lines = open(ftesto, 'r').readlines()
    file_matrix = [[int(x) for x in line.split()] for line in file_lines]

    # lista : str             = []
    # check : bool            = False
    # check_border : bool            = False

    # for y in range(190):         # HEIGHT
    #     mini_lista : str    = []

    #     for x in range(260):     # WIDTH
    #         for z in range(len(file_matrix)):
    #             # if file_matrix[0][2] == x == file_matrix[0][0] or file_matrix[0][3] == y == file_matrix[0][1]:
    #             # if x == file_matrix[0][0] and y == file_matrix[0][1] or x == file_matrix[0][2] and y == file_matrix[0][3]:
    #             # if x >= file_matrix[0][0] and y >= file_matrix[0][1] or x <= file_matrix[0][2] and y <= file_matrix[0][3]:
    #             if file_matrix[z][2] >= x >= file_matrix[z][0] and file_matrix[z][3] <= y <= file_matrix[z][1]:
    #                 if not check:
    #                     if file_matrix[z][2] > x > file_matrix[z][0] and file_matrix[z][3] < y < file_matrix[z][1]:
    #                         # mini_lista.append(white)
    #                         check = True
    #                         check_border = False
    #                     else:
    #                         check_border = True
    #                         check = True
    #                         # mini_lista.append(blu)
    #             else:
    #                 check = False
    #                 # mini_lista.append(black)

    #             if check:
    #                 if check_border:
    #                     mini_lista.append(blu)
    #                 else:
    #                     mini_lista.append(white)
    #             else:
    #                 mini_lista.append(black)


    #     lista.append((mini_lista))

    max_val : list[int]                         = list(map(max, zip(*file_matrix)))
    
    image = []
    check = False
    check_inside_square = False

    for y in range(max_val[1] + 10):         # HEIGHT
        mini_lista = []

        for x in range(max_val[2] + 10):     # WIDTH
            for coordinates in file_matrix:
                if coordinates[2] >= x >= coordinates[0] and coordinates[3] <= y <= coordinates[1]:
                    if coordinates[2] > x > coordinates[0] and coordinates[3] < y < coordinates[1]:
                        check_inside_square = True
                    check = True
                    break

            if check:
                if check_inside_square:
                    mini_lista.append(white)
                else:
                    mini_lista.append(green)
                check = False
                check_inside_square = False
            else:
                mini_lista.append(black)

        image.append((mini_lista))  

    # for x in range(max(file_matrix)):
    #     mini_lista = []
        
    #     for y in range(max(file_matrix)):
    #         # for matrix_line in file_matrix:
    #         if x == file_matrix[0][0] and y == file_matrix[0][1]:
    #             mini_lista.append(white)

        # matrix_line[2]
        # matrix_line[3]
        # for y in x:
        #     print(y)
            # if x == read_ftesto[0][0] and y == read_ftesto[0][1]:
            #     mini_lista += white
            # else:
            #     mini_lista.append(black)
            
    # images.save(image, 'prova1.png')

    # count_perimeter : int = 0
    # image = [[(0, 0, 0) for _ in range(350)] for _ in range(300)]

    # for coordinate in file_matrix:
    #     for y in range(coordinate[3], coordinate[1] + 1):
    #         for x in range(coordinate[0], coordinate[2] + 1):
    #             if coordinate[0] <= x <= coordinate[2] and coordinate[3] <= y <= coordinate[1]:
    #                 if coordinate[0] < x < coordinate[2] and coordinate[3] < y < coordinate[1]:
    #                     image[y][x] = white
    #                 elif image[y][x] == green:
    #                     continue
    #                 elif image[y][x] == white:
    #                     image[y][x] = green
    #                 else:
    #                     count_perimeter += 1
    #                     image[y][x] = red


                # if coordinate[0] < x < coordinate[2] and coordinate[3] < y < coordinate[1]:
                #     image[y][x] = white
                # elif image[y][x] == white or image[y][x] == green:
                #     image[y][x] = green
                # else:
                #     count_perimeter += 1
                #     image[y][x] = red
    images.save(image, 'prova1.png')
        # time.sleep(.5)

    # return count_perimeter



def prova2(ftesto : str, filepng : str):
    file_lines : str                            = open(ftesto, 'r').readlines()
    file_matrix : list[list[int]]               = []
    max_val_1 : int                             = 0
    max_val_2 : int                             = 0

    for line in file_lines:
        min_lista : list[int]                   = []

        for coordinate in line.split():
            min_lista.append(int(coordinate))

        file_matrix.append(min_lista)

        if max_val_1 < min_lista[1]:
            max_val_1 = min_lista[1]
        if max_val_2 < min_lista[2]:
            max_val_2 = min_lista[2]


    count_perimeter : int                       = 0
    image  : list[list[tuple(int, int, int)]]   = [[(0, 0, 0) for _ in range(max_val_2 + 10)] for _ in range(max_val_1 + 10)]

    for coordinate in file_matrix:
        # for y in range(coordinate[3], coordinate[1] + 1):
        #     for x in range(coordinate[0], coordinate[2] + 1):
        #         if coordinate[0] <= x <= coordinate[2] and coordinate[3] <= y <= coordinate[1]:
        #             if coordinate[0] < x < coordinate[2] and coordinate[3] < y < coordinate[1]:
        #                 image[y][x] = white
        #             else:
        #                 image[y][x] = green
        if file_matrix[len(file_matrix) - 1][0] < coordinate[0] and file_matrix[len(file_matrix) - 1][1] > coordinate[1] and file_matrix[len(file_matrix) - 1][2] > coordinate[2] and file_matrix[len(file_matrix) - 1][3] < coordinate[3] :
            for y in range(coordinate[3], coordinate[1] + 1):
                for x in range(coordinate[0], coordinate[2] + 1):
                    if coordinate[0] < x < coordinate[2] and coordinate[3] < y < coordinate[1]:
                        image[y][x] = white
                    else:
                        image[y][x] = green
        else:
            for y in range(file_matrix[len(file_matrix) - 1][3], file_matrix[len(file_matrix) - 1][1] + 1):
                for x in range(file_matrix[len(file_matrix) - 1][0], file_matrix[len(file_matrix) - 1][2] + 1):
                    if file_matrix[len(file_matrix) - 1][0] < x < file_matrix[len(file_matrix) - 1][2] and file_matrix[len(file_matrix) - 1][3] < y < file_matrix[len(file_matrix) - 1][1]:
                        image[y][x] = white
                    else:
                        image[y][x] = green
            break

    for y in range(len(image)):
        for x in range(len(image[y])):
            if image[y][x] == green:
                if image[y][x + 1] == black:
                    image[y][x] = red
                if image[y][x - 1] == black:
                    image[y][x] = red

                if image[y + 1][x] == black:
                    image[y][x] = red
                if image[y - 1][x] == black:
                    image[y][x] = red
                
                if image[y + 1][x + 1] == black:
                    image[y][x] = red
                if image[y + 1][x - 1] == black:
                    image[y][x] = red
                if image[y - 1][x - 1] == black:
                    image[y][x] = red
                if image[y - 1][x + 1] == black:
                    image[y][x] = red

            if image[y][x] == red:
                count_perimeter += 1

    images.save(image, 'prova1.png')

    return count_perimeter


def prova3(ftesto : str, filepng : str):
    file_lines : str                            = open(ftesto, 'r').readlines()
    file_matrix : list[list[int]]               = [[int(coordinate) for coordinate in line.split()] for line in file_lines]

	# max_val : list[int]                         = list(map(max, zip(*file_matrix)))
    max_val_1, max_val_2 = max(x[1] for x in file_matrix), max(x[2] for x in file_matrix)

    count_perimeter : int                       = 0
	# image  : list[list[tuple(int, int, int)]]   = [[black for _ in range(max_val_2 + 10)] for _ in range(max_val_1 + 10)]
    image  : list[list[tuple(int, int, int)]]   = []

    for coordinate in file_matrix:
        for y in range(max_val_1 + 10):
            mini_lista = [black for _ in range(max_val_2 + 10)]
            # mini_lista = []

            for x in range(max_val_2 + 10):
                if coordinate[0] <= x <= coordinate[2] and coordinate[3] <= y <= coordinate[1]:
                    if coordinate[0] < x < coordinate[2] and coordinate[3] < y < coordinate[1]:
                        mini_lista[x] = white
                    else:
                        mini_lista[x] = green
                else:
                    mini_lista[x] = black

            image.append(mini_lista)
    images.save(image, 'prova1.png')

    for y in range(len(image)):
        for x in range(len(image[y])):
            if image[y][x] == green and (image[y+1][x] == black or image[y+1][x+1] == black or image[y+1][x-1] == black or image[y-1][x] == black or image[y-1][x+1] == black or image[y-1][x-1] == black or image[y][x+1] == black or image[y][x-1] == black):
                image[y][x] = red
                count_perimeter += 1


    return count_perimeter


id = 0
id_list = [1, 2, 5, 25, 45, 65, 85, 105, 125, 145, 165, 185, 'sidebyside', 'hidden']

print(prova2(f'rectangles_{id_list[id]}.txt', f'res_{id_list[id]}.png'))

b = datetime.datetime.now()
print(b-a)