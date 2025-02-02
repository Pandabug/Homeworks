# -*- coding: utf-8 -*-

''' 
Abbiamo una stringa int_seq contenente una sequenza di interi non-negativi
    separati da virgole ed un intero positivo subtotal.

Progettare una funzione ex1(int_seq, subtotal) che
    riceve come argomenti la stringa int_seq e l'intero subtotal e
    restituisce il numero di sottostringhe di int_seq
    la somma dei cui valori è subtotal.

Ad esempio, per int_seq='3,0,4,0,3,1,0,1,0,1,0,0,5,0,4,2' e subtotal=9,
    la funzione deve restituire 7.

Infatti:
'3,0,4,0,3,1,0,1,0,1,0,0,5,0,4,2'
 _'0,4,0,3,1,0,1,0'_____________
 _'0,4,0,3,1,0,1'_______________
 ___'4,0,3,1,0,1,0'_____________
____'4,0,3,1,0,1'_______________
____________________'0,0,5,0,4'_
______________________'0,5,0,4'_
 _______________________'5,0,4'_

NOTA: è VIETATO usare/importare ogni altra libreria a parte quelle già presenti

NOTA: il timeout previsto per questo esercizio è di 1 secondo per ciascun test (sulla VM)

ATTENZIONE: quando caricate il file assicuratevi che sia nella codifica UTF8
    (ad esempio editatelo dentro Spyder)
'''

def ex1(int_seq, subtotal):
    # Inserisci qui il tuo codice
    new_int_seq : list[int]     = [int(x) for x in int_seq.split(',')]

    if new_int_seq.count(new_int_seq[0]) == len(new_int_seq):
        return len(new_int_seq) - subtotal + 1
    
    count_subtotal : int        = 0

    for i in range(len(new_int_seq)):
        if int_seq[i] == 0:
            count_subtotal += 1
            continue

        somma : int             = 0
        
        for j in range(i, len(new_int_seq)):
            somma += new_int_seq[j]

            if somma < subtotal: continue
            elif somma == subtotal: count_subtotal += 1
            else: break

    return count_subtotal
    # pass



if __name__ == '__main__':
    pass

