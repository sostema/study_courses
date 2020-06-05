def computepay(h, r):
    pay = 0
    if h > 40:
        pay += 40 * r
        h -= 40
        pay += h * r * 1.5
    else:
        pay = h * r
    return pay


hrs = input("Enter Hours:")
rph = input("Enter Rate:")
h = float(hrs)
r = float(rph)
p = computepay(h, r)
print("Pay", p)
