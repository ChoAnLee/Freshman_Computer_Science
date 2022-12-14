"""
Assignment 4
Name: 李倬安
Student Number: 110403516
Course 2022-CE1001-A
"""


def num_exist(number_string):
    input_file = open('Input.txt', 'r')
    global input_string_list1
    input_string = input_file.readline()
    input_string_list = input_string.split()

    while input_string:
        if number_string == input_string_list[0][7:]:
            input_string_list.pop(0)
            input_string_list1 = input_string_list
            return True
        else:
            input_string = input_file.readline()
            input_string_list = input_string.split()
    input_file.close()
    return False


def count_prime(input_string_list1):
    prime_num_int = 0
    for i in input_string_list1:
        key = 1
        if int(i) != 1:
            for j in range(2, int(i)):
                if int(i) % j == 0:
                    key = 0
                    break
            if key == 1:
                prime_num_int += 1
    return prime_num_int


def count_factor(number_string):
    factor_num_int = 0
    for i in range(1, int(number_string)+1):
        if int(number_string) % i == 0:
            factor_num_int += 1
    return factor_num_int


while 1:

    number_string = input('Input the number to check exist or exit : ')
    if number_string == 'exit':
        break
    if num_exist(number_string):
        print("Number_", end='')
        print(number_string, 'exists in the document and the number of factor is', count_factor(
            number_string), 'and the number of prime is', count_prime(input_string_list1))
        print('Please input the next number or input "exit" to leave')
        continue
    else:
        print("Number_", end='')
        print(number_string,
              'is not exist, please input a new number or input "exit" to leave program')
        continue
