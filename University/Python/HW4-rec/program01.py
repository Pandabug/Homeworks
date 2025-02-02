#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Uno dei meccanismi utilizzati per conservare e gestire grandi
quantità di dati è costituito dai database. Esistono tantissimi
tipi di database, ma quello che ha rivoluzionato il settore è
costituito dai database organizzati secondo il modello relazionale
teorizzato da Codd ormai mezzo secolo fa. Secondo questo modello
i dati sono organizzati in tabelle e relazioni fra di esse, in
modo da ottimizzare le richieste di memoria, favorire la coerenza
dei dati e minimizzare gli errori.

Dobbiamo progettare un insieme di funzioni che implementi una
semplice forma di database relazionale di una scuola di formazione
in cui ci sono quattro tabelle, ovvero students, teachers, courses
ed exams. I database sono di tre diverse dimensioni, ovvero small,
medium e large. Le tabelle del database di dimensione dbsize sono
salvate in quattro file json <dbsize>_<nometabella>.json (ad esempio,
il db small è composto dai file small_students.json, small_teachers.json,
small_courses.json e small_exams.json). Le tabelle sono organizzate in
liste di dizionari (si veda ad esempio small_students.json) e hanno le
seguenti strutture:
	- students: chiavi stud_code, stud_name, stud_surname, stud_email
	- teachers: chiavi teach_code, teach_name, teach_surname, teach_email
	- courses: chiavi course_code, course_name, teach_code
	- exams: chiavi exam_code, course_code, stud_code, date, grade.
La relazione fra le tabelle implica che ogni riga in ognuna delle
tabelle ha un riferimento ad un'altra tabella: ad esempio, un esame
(exam_code) corrisponde ad un voto (grade) dato da un docente
(teach_code) ad uno studente (stud_code) per aver sostanuto
l'esame di un certo corso (course_code) in una certa data (date). Ogni
studente può aver sostenuto diversi esami. Ogno docente può tenere
diversi corsi. Ogni corso è tenuto da un solo docente.

Il campo stud_code è una chiave primaria per la tabella students poiché
identifica univocamente uno studente, ovvero non esistono due studenti
con lo stesso stud_code. Similmente, teach_code, course_code ed exam_code
sono le chiavi primarie rispettivamente delle tabelle teachers, courses ed
exams. Per questo motivo, tali campi vengono utilizzati per realizzare
la relazione fra le tabelle.

Inoltre, i campi in tutte le tabelle non sono mai vuoti.

Dobbiamo realizzare alcune funzioni per poter interrogare i database delle
diverse dimensioni. Quindi, le funzioni prevedono di usare sempre il
parametro dbsize di tipo stringa, che può assumere i valori 'small',
'medium' e 'large'. Le funzioni sono:
	- media_studente(stud_code, dbsize), che riceve una stud_code di
	  uno studente e ritorna la media dei voti degli esami sostenuti,
	  dallo studente.
	- media_corso(course_code, dbsize), che riceve un identificatore per un
	  corso e ritorna la media dei voti degli esami per quel corso,
	  sostenuti da tutti gli studenti.
	- media_docente(teach_code, dbsize), che riceve un identificatore
	  di un docente e ritorna la media dei voti per gli esami
	  sostenuti in tutti i corsi del docente.
	- studenti_brillanti(dbisze), che ritorna la lista delle matricole
	  (stud_code) con una media di esami sostenuti superiore o uguale a 28,
	  ordinate in modo decrescente per media e, in caso di parità, in
	  ordine lessicografico per il cognome e il nome dello studente. In
	  caso di ulteriore parità, si usi il valore numerico dello stud_code
	  in ordine crescente.
	- stampa_esami_sostenuti(stud_code, fileout, dbsize), che riceve un
	  numero di stud_code e salva nel file fileout la lista degli esami
	  sostenuti dallo studente identificato dal valore stud_code.
	  Le righe nel file devono essere ordinate in modo crescente
	  per data di esame sostenuto e, in caso di stessa data, in ordine
	  alfabetico. Il file ha una riga iniziale con il testo
	   "Esami sostenuti dallo studente  <stud_surname> <stud_name>, matricola <stud_code>",
	  mentre le righe seguenti hanno la seguente struttura
		"<course_name>\t<date>\t<grade>", in cui i campi sono allineati
	  rispetto al nome del corso più lungo (ovvero tutte le date e
	  i voti sono allineati verticalmente). La funzione ritorna
	  il numero di esami sostenuti dallo studente.
	- stampa_studenti_brillanti(fileout, dbsize), che salva nel file
	  fileout una riga per ogni studente con una media di esami
	  sostenuti superiore o uguale a 28. Le righe nel file
	  devono essere ordinate in modo decrescente per media e,
	  in caso di parità, in ordine lessicografico per il
	  cognome e il nome dello studente.
	  Le righe nel file hanno la seguente struttura:
		  "<stud_surname> <stud_name>\t<media>", in cui il valore media
	  è allineato verticalmente per tutte le righe. La funzione
	  ritorna il numero di righe salvate nel file.
	- stampa_verbale(exam_code, fileout, dbsize), che riceve un identificatore
	  di esame e salva nel fileout le informazioni relative
	  all'esame indicato, usando la seguente formula
		"Lo studente <stud_surname> <stud_name>, matricola <stud_code>, ha sostenuto in data <date> l'esame di <course_name> con il docente <teach_surname> <teach_name> con votazione <grade>."
	  La funzione ritorna il voto dell'esame associato
	  all'identificatore ricevuto in input.

Tutte le medie devono essere arrotondate alla seconda cifra decimale,
anche prima di ogni funzione di ordinamento.
Tutti i file devono avere encoding "utf8".
Per stampare agevolmente righe allineate considerare la funzione format con
i modificatori per l'allineamento (https://pyformat.info/#string_pad_align)
e con i parametri dinamici (https://pyformat.info/#param_align).
"""
import json


def media_studente(stud_code, dbsize):
	average = 0
	count = 0

	with open(f'{dbsize}_exams.json', "r") as f:
		for object in json.load(f):
			if object['stud_code'] == stud_code:
				count += 1
				average += object['grade']

	return round(average / count, 2)


def media_corso(course_code, dbsize):
	average = 0
	count = 0

	with open(f'{dbsize}_exams.json', "r") as f:
		for object in json.load(f):
			if object['course_code'] == course_code:
				count += 1
				average += object['grade']

	return round(average / count, 2)


def media_docente(teach_code, dbsize):
	average = 0
	count = 0

	with open(f'{dbsize}_courses.json', "r") as f:
		teacher_course_code = [course['course_code'] for course in json.load(f) if course['teach_code'] == teach_code]

	with open(f'{dbsize}_exams.json', "r") as f:
		for exam in json.load(f):
			if exam['course_code'] in teacher_course_code:
				count += 1
				average += exam['grade']

	return round(average / count, 2)


def studenti_brillanti(dbsize):
	brilliant_students = []
	average_dict = {}

	with open(f'{dbsize}_students.json', 'r') as f:
		students = {student['stud_code'] : student for student in json.load(f)}
		
		for student in students:
			if not student in average_dict:
				average = media_studente(student, dbsize)

				if average >= 28:
					brilliant_students.append(student)
					average_dict[student] = average

	brilliant_students.sort(key = lambda x : (-average_dict[x], students[x]["stud_surname"], students[x]["stud_name"], int(x)))

	return brilliant_students

def stampa_verbale(exam_code, dbsize, fileout):
	with open(f'{dbsize}_exams.json', 'r') as f:
		for exam in json.load(f):
			if exam['exam_code'] == exam_code:
				student_code = exam['stud_code']
				exam_date = exam['date']
				exam_grade = exam['grade']
				course_code = exam['course_code']

	with open(f'{dbsize}_students.json', 'r') as f:
		for student in json.load(f):
			if student['stud_code'] == student_code:
				stud_name = student['stud_name']
				stud_surname = student['stud_surname']

	with open(f'{dbsize}_courses.json', 'r') as f:
		for course in json.load(f):
			if course['course_code'] == course_code:
				course_name = course['course_name']
				teacher_code = course['teach_code']

	with open(f'{dbsize}_teachers.json', 'r') as f:
		for teacher in json.load(f):
			if teacher['teach_code'] == teacher_code:
				teach_name = teacher['teach_name']
				teach_surname = teacher['teach_surname']

	with open(fileout, 'w') as f:
		f.write(f'Lo studente {stud_name} {stud_surname}, matricola {student_code}, ha sostenuto in data {exam_date} l\'esame di {course_name} con il docente {teach_name} {teach_surname} con votazione {exam_grade}.')

	return exam_grade


def stampa_esami_sostenuti(stud_code, dbsize, fileout):
	with open(f'{dbsize}_exams.json', 'r') as f:
		exams = {exam['exam_code'] : exam for exam in json.load(f)}
		exams_list = [(exam, exams[exam]['date']) for exam in exams if exams[exam]['stud_code'] == stud_code]
	
	with open(f'{dbsize}_students.json', 'r') as f:
		for student in json.load(f):
			if student['stud_code'] == stud_code:
				student_surname = student['stud_surname']
				student_name = student['stud_name']

	with open(f'{dbsize}_courses.json', 'r') as f:
		courses = {course['course_code'] : course for course in json.load(f)}
		
	exams_list.sort(key = lambda x : (x[1], courses[exams[x[0]]["course_code"]]["course_name"]))
	max_len = max([len(courses[exams[x[0]]["course_code"]]["course_name"]) for x in exams_list])

	with open(fileout, 'w') as f:
		f.write(f'Esami sostenuti dallo studente {student_surname} {student_name}, matricola {stud_code}')

		for x in exams_list:
			f.write(f'\n{courses[exams[x[0]]["course_code"]]["course_name"]:<{max_len}}\t{exams[x[0]]["date"]}\t{exams[x[0]]["grade"]}')

	return len(exams_list)


def stampa_studenti_brillanti(dbsize, fileout):
	brilliant_students = []
	average_dict = {}

	with open(f'{dbsize}_students.json', 'r') as f:
		students = {student['stud_code'] : student for student in json.load(f)}
		
		for student in students:
			if not student in average_dict:
				average = media_studente(student, dbsize)

				if average >= 28:
					brilliant_students.append((student, average))
					average_dict[student] = average

	brilliant_students.sort(key = lambda x : (-average_dict[x[0]], students[x[0]]["stud_surname"], students[x[0]]["stud_name"], int(x[0])))

	with open(f'{dbsize}_students.json', 'r') as f:
		students = {student['stud_code'] : student for student in json.load(f)}

	max_len = max([len(students[x[0]]['stud_surname']) + len(students[x[0]]['stud_name']) for x in brilliant_students])

	with open(fileout, 'w') as f:
		for student in brilliant_students:
			for x in students:
				if student[0] == x:
					surname_name = f'{students[student[0]]["stud_surname"]} {students[student[0]]["stud_name"]}'

			f.write(f'{surname_name:<{max_len + 1}}\t{student[1]:<{max_len}}\n')

	return len(brilliant_students)

