"""
Assignment 1
Name: 李倬安
Student Number: 110403516
Course 2022-CE1001-A
"""

pass_int=0
chinese_float=float(input("Please enter your Chinese score: "))
english_float=float(input("Please enter your English score: "))
math_float=float(input("Please enter your Math score: "))
science_float=float(input("Please enter your Science score: "))
average_float=(chinese_float+english_float+math_float+science_float)/4
print("Your average score is:", average_float,sep=" ")
if(chinese_float>58.74):
    pass_int+=1
if(english_float>68.30):
    pass_int+=1
if(math_float>38.93):
    pass_int+=1
if(science_float>88.56):
    pass_int+=1
if(pass_int==4):
    print("Welcome to NCU CSIE!")
else:
    print("Sorry, you can't enter NCU CSIE.")