# -*- coding: utf-8 -*-
'''
    Abbiamo una sequenza di N interi con N dispari. Sottoponiamo la sequenza alla seguente
    procedura che portera' all'eventuale cancellazione di elementi della sequenza:
    - Finche' nella sequenza sono presenti numeri uguali:
       - si selezionano nella sequenzai due numeri uguali ed li si eliminano ricompattando i numeri rimanenti.

    Data la sequenza di interi noi siamo interessati a trovare tutte le
    sequenze finali che e' possibile ottenere applicando la procedura descritta fintanto che è applicabile.
    Nota che tutte queste sequenze sono composte da uno stesso numero positivo di interi distinti.

    Si consideri ad esempio l'albero delle sequenze  che si ottiene a partire dalla
    1 2 0 1 0 0 1  e che e' riportato nel file game_tree.pdf
    Le foglie dell'albero sono le sequenze finali.

    Nota: questo è un esempio di albero definito implicitamente dalle regole del gioco.
    - la radice è la sequenza iniziale
    - i nodo figli di un qualsiasi nodo si ottengono eliminando una coppia di numeri uguali
    - le foglie sono le sequenze in cui non è più applicare la regola di eliminazione delle coppie

    Definire una funzione ex1(s) ricorsiva (o che fa uso di funzioni o
    metodi ricorsive/i) che prende come parametro  una  stringa  che codifica  una
    sequenza di N interi con N dispari (in questa stringa i numeri della sequenza
    compaiono uno di seguito all'altro e separati da uno spazio) e  restituisce
    l'insieme delle codifiche (stringhe con i numeri separati da uno spazio)
    delle sequenze finali che e' possibile ottenere.
      Ad esempio con s='1 2 0 1 0 0 1' la funzione ex1 deve restituire  l'insieme
      {'2 0 1', '2 1 0', '1 2 0'}


NOTA: il timeout previsto per questo esercizio è di 1 secondo per ciascun test.

ATTENZIONE: Almeno una delle funzioni/metodi che risolvono l'esercizio DEVE essere ricorsiva.
ATTENZIONE: per fare in modo che il macchinario di test riconosca automaticamente la presenza della ricorsione
    questa funzione ricorsiva DEVE essere una funzione esterna oppure il metodo di una classe
    (non può essere una funzione definita all'interno di un'altra funzione/metodo)

ATTENZIONE: Non potete usare altre librerie

ATTENZIONE: assicuratevi di salvare il programma con encoding utf8
(ad esempio usando come editor Notepad++ oppure Spyder)

'''

def s_split_list(s):
    result = {x: [] for x in s}
    
    for index, char in enumerate(s):
        result[char].append(index)

    return result


def check_sequence(s, i=0):
    for n in s:
        if not s.count(n) % 2:
            s = [x for x in s if x != n]

    while i < len(s):
        char = s[i]
        count_s = s.count(char)

        if count_s < len(s) - i and all(True if k == char else False for k in s[i:i + count_s]) and count_s % 2:
            s[i : i + count_s] = [char]

        i += 1

    return s


def recursive_def(s, result):
    check = False

    for value in s_split_list(s).values():
        if len(value) > 1:
            for x, y in map(sorted, {frozenset((x, y)) for x in value for y in value if x != y}):
                recursive_def(s[:x] + s[x + 1:y] + s[y + 1:], result)

            check = True
            break

    if not check:
        result.append(s)

    return result


def ex1(s):
    return set(map(lambda x: " ".join(x), recursive_def(check_sequence(s.split()), [])))



if __name__ == '__main__':
    pass
    # inserite qui i vostri test personali
    # print(ex1('1 2 0 1 0 0 1'))