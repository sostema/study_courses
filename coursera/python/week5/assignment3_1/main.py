hrs = input("Enter Hours:")
rph = input("Enter Rate:")
h = float(hrs)
r = float(rph)
pay = 0
if h > 40:
    pay = 40*r
    h -= 40
    r *= 1.5
    pay += r*h
else:
    pay = r*h
print(pay)
