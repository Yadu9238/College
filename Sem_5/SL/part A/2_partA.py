#lists
print("********* LIST OPERATIONS ********\n")

a = [12,24,36,48,60]

print("set of values of list:",a[2:4],"\n")
print("Retrieve using negative index:",a[-2],"\n")

a[3] = "third multiple"

print("list after changing",a,"\n")

del a[3]
print("list after deleting",a,"\n")

a.insert(1,0)
print("List after inserting at a pos:",a,"\n")
a.reverse()
print("reversed list:",a,"\n")
a.reverse()
a.sort()
print("Sorted list:",a,"\n")


print("*********** TUPLE OPERATIONS *************\n\n")
b = (15,30,45,60,75)
tuple2 = ("a","b","c")
tuple3 = b+tuple2


print("tuple 1:",b,"\n")
print("tuple 2:",tuple2,"\n")
print("two tuples concatenated",tuple3,"\n")
del tuple3
#print(tuple3)

print("max in first tuple:",max(b))
print("min in first tuple:",min(b))
print("length of first tuple",len(b))


print("\b******** DICTIONARY OPERATIONS **********\n\n")

d = {
	1:'amazon',
	2:'flipkart',
	3:'Alibaba',
	4:'croma'
}

print("Dictionary is:\n",d,"\n")
print("Retrieving first value:",d[1],"\n")
del d[4]
print("Dictionary after deletion:\n",d,"\n")
print("list of key value pairs:\n",d.items())

print("list of keys:\n",d.keys(),"\n")
print("list of values:\n",d.values(),"\n")

e = d.copy()
print("copy of Dictionary:\n",e,"\n")

d.clear()
print("empty Dictionary:\n",d)