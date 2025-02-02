import datetime

a = datetime.datetime.now()



def ex1(s):
    lista = set()
    s = s.split()

    for position, x in enumerate(s):
        is_repeating = s.count(x)

        if is_repeating > 1:
            val = ''

            for second_position, y in enumerate(s):
                if x == y and position != second_position:
                    continue

                val += y
            
            if not val in lista:
                lista.add(" ".join(val))

    # lista |= ex1(lista)
    
    return lista






def ex2(s):
    # lista_con_tutte_seq = set()
    lista = set()
    s = s.split()

    print(s)
    # val = ''
    for position, x in enumerate(s):
        is_repeating = s.count(x)

        if is_repeating > 1:
            val = ''

            for second_position, y in enumerate(s):
                if len(val) <= len(s) - 1:
                    if x == y and position != second_position:
                        continue
                    
                    val += y

            if not val in lista:
                new_val = " ".join(val)

                check = False
                print(f'val = {val}')
                for z in val:
                    is_again_repeating = val.count(z)

                    if is_again_repeating > 1:
                        check = True
                
                if check:
                    rec = ex2(new_val)
                    print(f'recal of {new_val} = {" ".join(rec)}')

                    # if not rec in lista_con_tutte_seq:
                    #     lista_con_tutte_seq.add(" ".join(rec))

                    # v = ex1(new_val)
                    # print(f'v = {v}')
                    lista.add(str(rec))
        # else:
        #     val += x

        print('-----------------End For-----------------')
    # if not val in lista:
    #     lista.add(" ".join(val))

    
    return lista







def ex3(s):
    lista = set()
    s = s.split()

    if len(s) == 1:
        return set(s)
    for position, x in enumerate(s):
        is_repeating = s.count(x)

        if is_repeating > 1:
            val = ''

            count = 0
            for second_position, y in enumerate(s):
                if x == y and position != second_position and count < 2:
                    count += 1
                    continue

                val += y

            new_val = " ".join(val)
            if not new_val in lista:
                check = False
                for z in val:
                    is_again_repeating = val.count(z)

                    if is_again_repeating > 1:
                        check = True

                if check:
                    rec = ex3(new_val)

                    for i in rec:
                        lista.add(i)
                else:
                    lista.add(new_val)

    return lista





def ex4(s):
    lista = set()
    s = s.split()

    print(s)
    # if len(s) == 1:
    #     return set(s)
    for position, x in enumerate(s):
        is_repeating = s.count(x)

        if is_repeating % 2 == 0 or is_repeating > 1:
        # if is_repeating > 1:
            val = ''

            is_ag_rep = 0
            check = False
            for second_position, y in enumerate(s, position):
                if x == y and position != second_position:
                    continue

                val += y

                is_ag_rep = s[position:].count(y)
                print(f'val {val}')

                if x == y and is_ag_rep > 1:
                    check = True

            if check:
                val = ex4(" ".join(val))
                print(f'recal {val}')
            
            lista.add(" ".join(val))

    return lista



# print(ex1('1 2 0 1 0 0 1'))
# print(ex2('1 2 0 1 0 0 1'))
# print(ex3(' '.join(['1']*2)+' 2'))
print(ex4('1 2 0 1 0 0 1'))
# print(ex4(' '.join(['1']*2)+' 2'))





b = datetime.datetime.now()
print(b-a)