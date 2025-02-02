import datetime
a = datetime.datetime.now()

def prova1(filename: str):
    final_string = ''

    with open(filename, mode='r', encoding='utf8') as f:
        raw_text = f.read().split()
        
        for x in raw_text:
            with open(raw_text[0], mode='r', encoding='utf8') as f:
                

                final_string += x


def prova2(filename: str):
    final_string = ''

    next_file_raw = filename
    string_list = []
    tmp_dic = {}

    while 1:
        with open(next_file_raw, mode='r', encoding='utf8') as f:
            raw_text = f.read().split()

            next_file_raw = raw_text[0]
            string_list.extend(raw_text[1:])

        if next_file_raw == filename:
            break
        
    for index in range(max(map(len, string_list))):
        for x in string_list:
            if len(x) <= index: continue
            if index in tmp_dic:
                if x[index] in tmp_dic[index]:
                    tmp_dic[index][x[index]] += 1
                else:
                    tmp_dic[index].update({x[index] : 1})

            else: 
                tmp_dic.update({index : {x[index] : 1}})

    for index in tmp_dic:
        for k, v in sorted(tmp_dic[index].items()):
            if v == max(tmp_dic[index].values()):
                final_string += k
                break





    # print(string_list)

    # i = 0
    # while i <= max(map(len, string_list)):
    #     for x in string_list:
    #         if i < len(x):
    #             if x[i] in tmp_dic: tmp_dic[x[i]] += 1
    #             else: tmp_dic[x[i]] = 1
    #     i += 1


    # for index in range(max(map(len, string_list))):
    #     for x in string_list:
    #         if len(x) <= index: continue
    #         if x[index] in tmp_dic: tmp_dic[x[index]] += 1
    #         else: tmp_dic[x[index]] = 1






###################################################################################### 
    # new_dic = {}

    # for index in tmp_dic:
    #     for k, v in tmp_dic[index].items():
    #         if not k in new_dic:
    #             new_dic.update({k : v})
    #         else:
    #             if v > new_dic[k]:
    #                 new_dic[k] = v

    # print(f'new_dic: {new_dic}')

    # temp = {val: key for key, val in new_dic.items()}
    # res = {val: key for key, val in temp.items()}

    # for k, v in new_dic.items():
    #     if len(final_string) <= max(map(len, string_list)):
    #         final_string += k

    # print(f'res: {res}')
###################################################################################### 

    


    # for index in range(max(map(len, string_list))):
    #     for x in string_list:
    #         if len(x) <= index: continue
    #         if x[index] in tmp_dic: tmp_dic.update({x[index] : {'position' : index, 'times' : tmp_dic[x[index]]['times']+1}})
    #         else: tmp_dic.update({x[index] : {'position' : index, 'times' : 1}})




    # tmp_dic = dict(sorted(tmp_dic, key=lambda x:x[0],reverse = True))
    # print(f'sorted Fals {tmp_dic}')
    # tmp_dic = dict(sorted(tmp_dic.items(), key=lambda x:x[0],reverse = True))
    # for k, v in tmp_dic.items():
    #     final_string += k

    # i = 0
    # for x in range(len(string_list)):
    #     count = 0
    #     print(string_list[x])
    #     for y in range(x + 1, len(string_list)):
    #         print(string_list[y])
    #         if string_list[x][i] == string_list[y][i]:
    #             count += 1
    #             print(string_list[x][i], count)

    #     i += 1

    # print(f'sorted False {dict(sorted(tmp_dic.items(), key = lambda x:x[0]))}')


    # for k, _ in tmp_dic.items():
    #     final_string += k

    print(string_list)

    # st = ''
    # for x in range(len(string_list)):
    #     for y in range(len(string_list[x])):
    #         # if y != 0:
    #         print(string_list[x][y])
    #             # for z in string_list[x][y]:
    #             #     st = z
    #                 # print(f'Index: {string_list[x][y].index(st)}')
    #         tmp_dic.append({z : string_list[x][y].index(z) for z in string_list[x][y]})

                    # print(string_list[x][y].count(st))

    print(tmp_dic)
    # for x in tmp_dic:
    #     for k, v in x.items():

    #         final_string += k

    # print(tmp_dic)

    # for lst in string_list:
    #     newlist = []
    #     for sublst in lst:
    #         newlist.append(sublst)

    #     list2 = dict((i, newlist.count(i)) for i in newlist)
    #     print(list2)

    return final_string



def prova3(filename):
    next_file_raw = filename
    string_list = []

    while 1:
        with open(next_file_raw, mode='r', encoding='utf8') as f:
            raw_text = f.read().split()

            next_file_raw = raw_text[0]
            string_list.extend(raw_text[1:])

        if next_file_raw == filename:
            break

    # print(string_list)
        
    final_string = ''
    tmp_dic = {}

    for x in range(max(map(len, string_list))):
        for y in string_list:
            if x < len(y):
                if x in tmp_dic:
                    if y[x] in tmp_dic[x]:
                        tmp_dic[x][y[x]] += 1
                    else:
                        tmp_dic[x].update({y[x] : 1})

                else:
                    tmp_dic.update({x : {y[x] : 1}})
        
        for k, v in sorted(tmp_dic[x].items()):
            if v == max(tmp_dic[x].values()):
                final_string += k
                break

    # print(tmp_dic)

    return final_string

def prova4(filename):
    next_file_raw : str             = filename
    string_list : list[str]         = []

    while True:
        with open(next_file_raw, mode='r', encoding='utf8') as f:
            raw_text = f.read().split()

            next_file_raw = raw_text[0]
            string_list.extend(raw_text[1:])

        if next_file_raw == filename:
            break

    final_string : str              = ''
    largest_word_len = range(max(map(len, string_list)))

    for x in largest_word_len:
        tmp_dic : dict[str, int]    = {}

        for y in string_list:
            if x < len(y):
                if y[x] in tmp_dic:
                    tmp_dic[y[x]] += 1
                else:
                    tmp_dic.update({y[x] : 1})

        tmp_dic = dict(sorted(tmp_dic.items()))
        final_string += max(tmp_dic, key=tmp_dic.get)

    return final_string



def prova5(filename):
    next_file_raw = filename
    string_list = []

    while 1:
        with open(next_file_raw, mode='r', encoding='utf8') as f:
            raw_text = f.read().split()

            next_file_raw = raw_text[0]
            string_list.extend(raw_text[1:])

        if next_file_raw == filename:
            break

    letters = ''
    tot_appear = 0
    count = 0
    
    final_string = ''

    for x in range(max(map(len, string_list))):
        letters = ''

        for y in string_list:
            if x < len(y):
                if tot_appear < count:
                    letters = y

        final_string += ''.join(sorted(letters))[0]

    return final_string


def prova6(filename):
    
    final_string = ''

    next_file_raw = filename
    string_list = []
    tmp_dic = []

    while 1:
        with open(next_file_raw, mode='r', encoding='utf8') as f:
            raw_text = f.read().split()

            next_file_raw = raw_text[0]
            string_list.extend(raw_text[1:])

        if next_file_raw == filename:
            break

    for x in string_list:
        for y in range(len(x)):
            try:
                if x[y] in tmp_dic[y]:
                    tmp_dic[y][x[y]] += 1
                else:
                    tmp_dic[y][x[y]] = 1
            except:
                tmp_dic.append({x[y] : 1})

    for x in tmp_dic:
        boh = dict(sorted(x.items()))
        final_string += max(boh, key=boh.get)

    return final_string






    # for index in range(max(map(len, string_list))):
    #     for x in string_list:
    #         if len(x) <= index: continue
    #         if index in tmp_dic:
    #             if x[index] in tmp_dic[index]:
    #                 tmp_dic[index][x[index]] += 1
    #             else:
    #                 tmp_dic[index].update({x[index] : 1})

    #         else: 
    #             tmp_dic.update({index : {x[index] : 1}})

    # for index in tmp_dic:
    #     for k, v in sorted(tmp_dic[index].items()):
    #         if v == max(tmp_dic[index].values()):
    #             final_string += k
    #             break




def prova7(filename):
    final_string = ''

    next_file_raw = filename
    string_list = []
    tmp_dic = {}

    while 1:
        with open(next_file_raw, mode='r', encoding='utf8') as f:
            raw_text = f.read().split()

            next_file_raw = raw_text[0]
            string_list.extend(raw_text[1:])

        if next_file_raw == filename:
            break

    for x in string_list:
        for y in range(len(x)):
            if y in tmp_dic:
                if x[y] in tmp_dic[y]:
                    tmp_dic[y][x[y]] += 1
                else:
                    tmp_dic[y].update({x[y] : 1})

            else: 
                tmp_dic.update({y : {x[y] : 1}})
                
    for x in tmp_dic:
        boh = dict(sorted(tmp_dic[x].items()))
        final_string += max(boh, key=boh.get)

    return final_string



















#############################################################################################
# BEST TIME



def most_frequent_chars(filename: str) -> str:
    wrd_fr = {}
    next_f = ''
    first = filename
    while next_f != first:
        with open(filename, encoding='utf-8') as fin:
            file = fin.read().split()
            next_f = filename = file.pop(0)
            for i in file:
                wrd_fr[i] = wrd_fr.get(i, 0)+1
    ran = len(max(wrd_fr.keys(), key=len))
    final_ls = [{} for _ in range(ran)]
    for key, value in wrd_fr.items():
        for d, char in zip(final_ls, key):
            d[char] = d.get(char,0)+value
    final_str = ''
    for i in final_ls:
        mas = max(i.values())
        final_str += min([x for x,y in i.items() if y == mas])
    return final_str










#############################################################################################


# lista : list[str] = [
#     'test01/A.txt',
#     'test02/bullfight.txt',
#     'test03/woodchuck.txt',
#     'test04/pampers.txt',
#     'test05/avocados.txt',
#     'test06/strums.txt',
#     'test07/sinew.txt',
#     'test08/boilings.txt',
#     'test09/meddles.txt',
#     'test10/aileron.txt',
#     'test11/metonymies.txt',
#     'test12/incipience.txt',
#     ]
# for filename in lista:
# print(prova2('test01/A.txt'))
# print(prova3('test01/A.txt'))
# print(prova4('test01/A.txt'))
# print(prova5('test01/A.txt'))
# print(prova6('test01/A.txt'))
print(prova7('test01/A.txt'))


# z = ['osihfgdb', 'alih', 'augfba']

# for cucicuci in range(max(map(len, z))):
#     for x in z:
#         if cucicuci < len(x):
#             print(x, x[cucicuci], x.rfind(x[cucicuci]))



b = datetime.datetime.now()
print(b-a)