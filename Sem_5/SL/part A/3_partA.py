n = int(input("Enter any number"))
if n%2 == 0:
	print(str(n)+" is even")
else:
	print(str(n)+" is odd")

#looping with lists
def common_data(lis1,lis2):
	res = False
	for x in lis1:
		for y in lis2:
			if x ==y:
				res = True
				return res
print("list looping:\n")
lis1 = [1,2,3,4,5]
lis2 = [5,6,7,8,9]
print("Common data present in \n"+str(lis1)+"\n"+str(lis2))
print(common_data(lis1,lis2))
print("\nCommon data present in \n"+str(lis1[:3])+"\n"+str(lis2[2:4]))
print(common_data(lis1[:3],lis2[2:4]))
print("\n")

#looping with tuples
print("tuple looping:\n")
t = (10,20,30,40,50)
for v in t:
	print(t.index(v),v)


#looping with dictionary
def sum_math(di):
	for d in di:
		n1 = d.pop('V')
		n2 = d.pop('VI')
		d['V '+'VI'] = (n1+n2)/2
		return d
st_det = [
	{'id':1,'subj':'math','V':70,'VI':82},
	{'id':2,'subj':'math','V':25,'VI':52},
	{'id':3,'subj':'math','V':63,'VI':87}

]
print("looping with dictionary:\n")
print(sum_math(st_det))