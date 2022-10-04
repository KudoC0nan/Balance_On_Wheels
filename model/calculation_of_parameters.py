import math
thetha1 = float(input("Enter Thetha1 "))
thetha2 = float(input("Enter Thetha2 "))
phi1 = math.pi*(thetha1)/180
phi2 = math.pi*(thetha2)/180
l3 = float(input("Enter L3 : "))
val1 = l3/math.sin(phi1)
val2 = l3/math.sin(phi2)

l2 = (val1+val2)/2
l1 = (val2-val1)/2

print(f"L1 : {l1}")
print(f"L2 : {l2}")

lmax = math.sqrt(math.pow(l2+l1,2)-math.pow(l3,2))
lmin = math.sqrt(math.pow(l2-l1,2)-math.pow(l3,2))

print(f"lmax  = {lmax}")
print(f"lmin  = {lmin}")
