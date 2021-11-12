#menu driven program for temp conversion

def cel_to_f(c):
	f = c*1.8 + 32
	return f

def f_to_cel(f):
	c = (f-32)/1.8
	return c

def c_to_k(c):
	return (c+273)

def k_to_c(k):
	return (k-273)

def f_to_k(f):
	return c_to_k(f_to_cel(f))

def k_to_f(k):
	return cel_to_f(k_to_c(k))

print("Enter your choice\n\n")
print("1.Celsius to Fahrenheit\n2.Fahrenheit to Celsius")
print("3.Celsius to kelvin\n4.Kelvin to Celsius")
print("5.Fahrenheit to kelvin\n6.kelvin to Fahrenheit")
n = int(input())
temp = float(input("Enter the temperature\n"))

if n == 1:
	print("Fahrenheit temp:"+str(cel_to_f(temp)))

elif n ==2:
	print("Celsius temp:"+str(f_to_cel(temp)))

elif n ==3:
	print("kelvin temp:"+str(c_to_k(temp)))

elif n ==4:
	print("Celsius temp:"+str(k_to_c(temp)))

elif n ==5:
	print("Kelvin temp:"+str(f_to_k(temp)))

elif n ==6:
	print("Fahrenheit temp:"+str(k_to_f(temp)))
else:
	print("invalid option\n")

