import math
l1 = float(input("Enter L1 : "))
l2 = float(input("Enter L2 : "))
l3 = float(input("Enter L3 : "))

phi1 = math.asin(l3/(l2-l1))
phi2 = math.asin(l3/(l2+l1))

phi1 = (180 * phi1)/math.pi
phi2 = (180 * phi2)/math.pi

print(f"phi1 : {phi1}")
print(f"phi2 : {phi2}")
lmax = math.sqrt(math.pow(l2+l1,2)-math.pow(l3,2))
lmin = math.sqrt(math.pow(l2-l1,2)-math.pow(l3,2))

print(f"lmax  = {lmax}")
print(f"lmin  = {lmin}")
