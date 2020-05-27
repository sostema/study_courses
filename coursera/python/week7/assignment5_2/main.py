largest = None
smallest = None
while True:
    num = input("Enter a number: ")
    if num == "done" : break
    try:
        num = int(num)
        if num > largest or largest is None:
            largest = num
        if num < smallest or smallest is None:
            smallest = num
    except:
        print("Invalid input")
print("Maximum is", largest)
print("Minimum is", smallest)
