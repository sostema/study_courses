water = 400
milk = 540
beans = 120
cups = 9
money = 550


def print_machine_state():
    print(rf"""The coffee machine has:
    {water} of water
    {milk} of milk
    {beans} of coffee beans
    {cups} of disposable cups
    {money} of money
    """)


def action_buy():
    global water, milk, beans, cups, money
    print("What do you want to buy? 1 - espresso, 2 - latte, 3 - cappuccino, back - to main menu:")
    drink = input()
    if drink == "back":
        return
    drink = int(drink)
    if drink == 1:
        if water < 250:
            print("Sorry, not enough water!")
        elif beans < 16:
            print("Sorry, not enough coffee beans!")
        elif cups < 1:
            print("Sorry, not enough disposable cups!")
        else:
            print("I have enough resources, making you a coffee!")
            water -= 250
            beans -= 16
            money += 4
            cups -= 1
    elif drink == 2:
        if water < 350:
            print("Sorry, not enough water!")
        elif milk < 75:
            print("Sorry, not enough milk!")
        elif beans < 20:
            print("Sorry, not enough coffee beans!")
        elif cups < 1:
            print("Sorry, not enough disposable cups!")
        else:
            print("I have enough resources, making you a coffee!")
            water -= 350
            milk -= 75
            beans -= 20
            money += 7
            cups -= 1
    else:
        if water < 200:
            print("Sorry, not enough water!")
        elif milk < 100:
            print("Sorry, not enough milk!")
        elif beans < 12:
            print("Sorry, not enough coffee beans!")
        elif cups < 1:
            print("Sorry, not enough disposable cups!")
        else:
            print("I have enough resources, making you a coffee!")
            water -= 200
            milk -= 100
            beans -= 12
            money += 6
            cups -= 1


def action_fill():
    global water, milk, beans, cups, money
    print("Write how many ml of water do you want to add:")
    water += int(input())
    print("Write how many ml of milk do you want to add:")
    milk += int(input())
    print("Write how many grams of coffee beans do you want to add:")
    beans += int(input())
    print("Write how many disposable cups of coffee do you want to add:")
    cups += int(input())


def action_take():
    global money
    print(f"I gave you ${money}")
    money = 0


def action_remaining():
    print_machine_state()


action = None

while action != "exit":
    print("Write action (buy, fill, take, remaining, exit):")
    action = input()
    print()
    if action == "buy":
        action_buy()
    elif action == "fill":
        action_fill()
    elif action == "take":
        action_take()
    elif action == "remaining":
        action_remaining()
    print()
