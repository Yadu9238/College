from functools import reduce
in_lis = [10,20,30,40,60]

list_using_comp = [x for x in in_lis if x % 6 == 0]

print("list using list_comprehension:",list_using_comp)


d = {}
for x in in_lis:
	if x %6 != 0:
		d[x] = x**2

print("output dictionary:",d)

x = lambda a,b : a*b
print("Done using lambda ",x(5,6))

#reduce

sum = reduce((lambda x,y:x+y),in_lis)
print(sum)