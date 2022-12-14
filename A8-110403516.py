"""
Assignment 8
Name: 李倬安
Student Number: 110403516
Course 2022-CE1001-A
"""


def preprocess():
    with open('input.txt', 'r') as file:
        data = list(map(int, file.read().split()))
        file.close()
    return data


def bubble(data, original):
    for i in range(len(data)-1):
        for j in range(len(data)-1-i):
            if data[j] > data[j+1]:
                data[j], data[j+1] = data[j+1], data[j]
        showlist(i+1, data)
    return show_original(original)


def showlist(count, listname):
    print('第', count, '次', listname)


def show_original(listname):
    print('原資料：', listname)


oringinal = preprocess()
bubble(preprocess(), oringinal)
