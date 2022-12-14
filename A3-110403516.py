"""
Assignment 3
Name: 李倬安
Student Number: 110403516
Course 2022-CE1001-A
"""

file_input = open('input.txt', 'r')

file_output = open('output.txt', 'w')

column = int(file_input.readline())

# Because writing to file needs string, so I define a string in the function and return it.


def CreatePyramid(column):
    ans_string = ''
    for i in range(1, column + 1):
        for k in range(1, column - i + 1):
            ans_string += ' '
        if i == 1:
            ans_string += '1'  # avoid the first line in isPrime function
        else:
            for j in range(i**2-(i-1)*2, i ** 2 + 1):
                ans_string += isPrime(j)
        if (i != column):
            ans_string += '\n'  # avoid the last line has '\n'
    return ans_string


def isPrime(number):
    if number == 1:
        return 1
    for i in range(2, number):
        if number % i == 0:
            return 'N'
    return 'Y'


file_output.write(CreatePyramid(column))
file_input.close()
file_output.close()
