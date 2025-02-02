def prova1(ftesto : str, a : int, b : int, n : int):
    file_string  = ''
        
    with open(ftesto, mode='r', encoding='utf-8') as f:
        file_string = f.read().replace('\n', '').strip()

    returning_list = []
    value = ''

    for x in file_string:
        value += x

        if a <= len(value) <= b:
            count_sottosequenza = 0
            new_str = ''

            for y in range(len(file_string)):
                new_str += file_string[y:]

                if value == new_str:
                    count_sottosequenza += 1

            if not [count_sottosequenza, [value]] in returning_list:
                returning_list.append((count_sottosequenza, [value]))

        elif len(value) > b:
            value = ''

    return returning_list




print(prova1('ft1.txt', 2, 4, 20))