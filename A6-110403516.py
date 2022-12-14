"""
Assignment 6
Name: 李倬安
Student Number: 110403516
Course 2022-CE1001-A
"""


def print_dec(dec_num):
    total = 0
    global r
    k = 0
    for i in dec_num:
        total += int(i)*2**(len(dec_num)-1-k)
        k += 1
    dec_num = total
    r = total
    print("NUM(DEC) : {}".format(dec_num))


def print_oct(oct_num):
    total = 0
    layer = 10
    ax = 10
    g, h = divmod(oct_num, 8)
    oct_num = g
    total += h
    while g != 0:
        g, h = divmod(oct_num, 8)
        oct_num = g
        total += layer*h
        layer *= ax

    oct_num = total
    print("NUM(OCT) : {}".format(oct_num))


def print_err_msg():
    err_msg = "Not Binary Number!"
    print(err_msg)


while 1:
    print("NUM(BIN) : ", end='')
    input_string = input()
    if input_string == "-1":
        break
    key = 0
    if input_string.isdigit():
        for i in input_string:
            if int(i) <= 1:
                key += 1
        if key == len(input_string):
            print_dec(input_string)
            print_oct(r)
            continue
        else:
            print_err_msg()
            continue

    else:
        print_err_msg()
        continue
