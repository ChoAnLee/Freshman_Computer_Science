"""
Assignment 2
Name: 李倬安
Student Number: 110403516
Course 2022-CE1001-A
"""

detect_upper_case_int = 0
detect_lower_case_int = 0
detect_number_int = 0
detect_symbol_int = 0

while 1:
    password_string = input("Please enter your password: ")
    if password_string == "exit":
        break
    password_string_again = input("Please enter your password again: ")
    if password_string_again != password_string:
        print("Password settings are not consistent, try again or type \"exit\" to leave.")
        continue
    if 6 > len(password_string) or len(password_string) > 10:
        print("Password should contain 6 to 10 characters, try again or type \"exit\" to leave.")
        continue
    for upper_case_string in password_string:
        if 65 <= ord(upper_case_string) <= 90:
            detect_upper_case_int = 1
            break
        else:
            continue
    if detect_upper_case_int == 0:
        print("Password should contain at least one upper-case alphabetical character, try again or type \"exit\" to leave.")
        continue
    for lower_case_string in password_string:
        if 97 <= ord(lower_case_string) <= 122:
            detect_lower_case_int = 1
            break
        else:
            continue
    if detect_lower_case_int == 0:
        print("Password should contain at least one lower-case alphabetical character, try again or type \"exit\" to leave.")
        continue
    for number_string in password_string:
        if 48 <= ord(number_string) <= 57:
            detect_number_int = 1
            break
        else:
            continue
    if detect_number_int == 0:
        print("Password should contain at least one number, try again or type \"exit\" to leave.")
        continue
    for symbol_string in password_string:
        if 32 <= ord(symbol_string) <= 47 or 58 <= ord(symbol_string) <= 64 or 91 <= ord(symbol_string) <= 96 or 123 <= ord(symbol_string) <= 126:
            detect_symbol_int = 1
            break
        else:
            continue
    if detect_symbol_int == 0:
        print("Password should contain at least one special character, try again or type \"exit\" to leave.")
        continue
    if password_string == password_string[::-1]:
        print("Symmetric password is not allowed, try again or type \"exit\" to leave.")
        continue
    print("Password is valid.")
    break
