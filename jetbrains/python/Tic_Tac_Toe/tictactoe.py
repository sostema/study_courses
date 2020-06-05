def print_field(field):
    print("---------")
    for row in field:
        print(f"| {row[0]} {row[1]} {row[2]} |")
    print("---------")


def check_field(field):
    x_amount = 0
    o_amount = 0
    winner = None

    for row in field:
        for cell in row:
            if cell == "X":
                x_amount += 1
            elif cell == "O":
                o_amount += 1

    for row in range(len(field)):
        if field[row][0] == field[row][1] == field[row][2] and field[row][0] != "_":
            win = field[row][0]
            if winner is not None and win != winner:
                winner = "Impossible"
            else:
                winner = win
        if field[0][row] == field[1][row] == field[2][row] and field[0][row] != "_":
            win = field[0][row]
            if winner is not None and win != winner:
                winner = "Impossible"
            else:
                winner = win

    if field[0][0] == field[1][1] == field[2][2] and field[0][0] != "_":
        win = field[0][0]
        if winner is not None and win != winner:
            winner = "Impossible"
        else:
            winner = win

    if field[0][2] == field[1][1] == field[2][0] and field[0][2] != "_":
        win = field[0][2]
        if winner is not None and win != winner:
            winner = "Impossible"
        else:
            winner = win

    if winner == "Impossible" or abs(x_amount - o_amount) >= 2:
        print("Impossible")
    elif winner == "X":
        print("X wins")
        return True
    elif winner == "O":
        print("O wins")
        return True
    else:
        if x_amount + o_amount == 9:
            print("Draw")
            return True
        else:
            return False


game_field = [['_' for i in range(0, 3)] for k in range(0, 3)]

print_field(game_field)
curchar = "X"
while (True):
    try:
        inp = input("Enter the coordinates: ").split(' ')
        x = int(inp[0])
        y = int(inp[1])
    except Exception as e:
        print("You should enter numbers!")
        continue
    if x in [1, 2, 3] and y in [1, 2, 3]:
        x = x - 1
        y = 3 - y
        if game_field[y][x] == '_':
            game_field[y][x] = curchar
            if curchar == "X":
                curchar = "O"
            else:
                curchar = "X"
            print_field(game_field)
            b = check_field(game_field)
            if b:
                break
        else:
            print("This cell is occupied! Choose another one!")
            continue
    else:
        print("Coordinates should be from 1 to 3!")
        continue
