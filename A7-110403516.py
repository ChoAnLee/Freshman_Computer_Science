"""
Assignment 7
Name: 李倬安
Student Number: 110403516
Course 2022-CE1001-A
"""
total = 0


def get_maze():
    input_file = open('input.txt', 'r')
    maze = []
    for lines in input_file.readlines():
        maze.append(lines.split())
    input_file.close()
    return maze


def dfs_total_times(start_x, start_y, end_x, end_y, maze):
    global total
    next_step = [[0, 1], [1, 0]]
    if start_x == end_x and start_y == end_y:
        total += 1
    for i in next_step:
        if maze[start_x+i[0]][start_y+i[1]] == '1':
            maze[start_x+i[0]][start_y+i[1]] = '0'
            dfs_total_times(start_x+i[0], start_y+i[1], end_x, end_y, maze)
            maze[start_x+i[0]][start_y+i[1]] = '1'
    return total


maze = get_maze()
start_x = 1
start_y = 1
end_x = 5
end_y = 5
print(dfs_total_times(start_x, start_y, end_x, end_y, maze))
