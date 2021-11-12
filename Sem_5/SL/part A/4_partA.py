def print_text():
	print("hello world")
	return

print("Printed using func:\n")
print_text()

def print_val(a,b):
	print("values of a and b are:"+str(a)+"and"+str(b))
	return

print("printed using func:\n")
print_val(10,20)

def print_def(a,b=5):
	print("the values of a and b are",a,"and",b)
	return

print_def(10)

def print_val(a,b):
	print("the values of a and b are",a,"and",b)
	return
print_val(b=5,a=10)

#recursion
def factorial(n):
	if n ==1:
		return 1
	else:
		return n*factorial(n-1)

a = factorial(5)
print("\nDone using recursion\nfactorial of 5:",a)


class complex:
	def __init__(self,r,i):
		self.r = r
		self.i = i

x = complex(3.5,4)
print("\nDone using class\nreal part:",x.r,"\nImaginary part:",x.i)

