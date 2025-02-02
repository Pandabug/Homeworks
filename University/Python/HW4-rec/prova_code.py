import json
import datetime

a = datetime.datetime.now()

with open('small_exams.json', 'r') as f:
    # exams = {x['exam_code']: x for x in json.load(f)}
    exams = json.load(f)
for x in exams:
    print({x['stud_code']: x})

# for i in exams:
#     if i['stud_code'] == '1803891':
#         print(i, i['date'], i['stud_code'])
# print(exams)

# print(json.load(open('small_exams.json', 'r')))















b = datetime.datetime.now()
print(b-a)