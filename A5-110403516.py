"""
Assignment 5
Name: 李倬安
Student Number: 110403516
Course 2022-CE1001-A
"""
file_score = open('score.txt', 'r')
file_cmd = open('cmd.txt', 'r')
file_output = open('output.txt', 'w')


def split_info(score_string_list):
    return_list = []
    for i in range(int(len(score_string_list)/5)):
        return_list.append([score_string_list[i*5], score_string_list[i*5+1],
                           score_string_list[i*5+2], score_string_list[i*5+3], score_string_list[i*5+4]])
    return return_list


def grading_system(student_list):
    return_str = ''
    key = 0
    if int(student_list[1]) >= 12:
        key += 1
    if int(student_list[2]) >= 12:
        key += 1
    if int(student_list[3]) >= 8:
        key += 1
    if int(student_list[4]) >= 12:
        key += 1
    if key == 4:
        return_str = "Hello " + student_list[0] + ", welcome to NCU CSIE!"
    else:
        return_str = "Sorry, " + student_list[0] + " can't enter NCU CSIE."
    return return_str


def find_grade(two_dim_list, student_name, subject):
    return_str = ''
    for i in range(len(two_dim_list)):
        if two_dim_list[i][0] == student_name:
            if subject == 'chinese':
                return_str = two_dim_list[i][1]
            elif subject == 'english':
                return_str = two_dim_list[i][2]
            elif subject == 'math':
                return_str = two_dim_list[i][3]
            elif subject == 'science':
                return_str = two_dim_list[i][4]
            else:
                return_str = 'Error'
    return return_str


total_string = ''
total_string2 = ''
ans_string = ''
two_dim_list2 = []
# readline() 讀完之後會有'\n'，但因為split()會自動去掉，所以不用擔心
score_string = file_score.readline()
while score_string:
    total_string += score_string
    score_string = file_score.readline()
# split() 默认为所有的空字符，包括空格、换行(\n)、制表符(\t)
score_string_list = total_string.split()

two_dim_list = split_info(score_string_list)
for i in range(len(two_dim_list)):
    ans_string += grading_system(two_dim_list[i])+'\n'

cmd_string = file_cmd.readline()  # readline() 讀完之後會有'\n'，但因為split()會自動去掉，所以不用擔心
while cmd_string:
    total_string2 += cmd_string
    cmd_string = file_cmd.readline()
cmd_string_list = total_string2.split()


for i in range(int(len(cmd_string_list)/2)):
    two_dim_list2.append([cmd_string_list[i*2], cmd_string_list[i*2+1]])

for i in range(len(two_dim_list2)):
    ans_string += find_grade(two_dim_list,
                             two_dim_list2[i][0], two_dim_list2[i][1])+'\n'

file_output.write(ans_string)
file_output.close()
file_cmd.close()
file_score.close()
