#selection constructs
print("********* SELECTION CONSTRUCTS *********\n\n")
a = input("enter first number\n")
b = input("enter second number\n")
print("a:"+a+" b:"+b)
if a>b:
	print("A greater than b\n")
elif b>a:
	print("B greater than a\n")
else:
	print("Equal\n")

#looping constructs

print("********* LOOPING CONSTRUCTS ***********\n\n")
for n in range(2,10):
	flag = 0
	for x in range(2,n):
		if n%x ==0:
			print(str(n) +" = "+str(x)+"*"+str(n//x))
			flag =1
			break
	if flag == 0:
		print(str(n)+" is a prime number")
