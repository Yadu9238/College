n = int(input("Enter number of elements\n"))

ls = []

def find_max(ls):
	if len(ls) == 1:
		return ls[0]
	else:
		return max(ls[0],find_max(ls[1:]))	
print("Enter numbers one by one\n")
for i in range(n):
	ls.append(int(input()))
print(ls)

count = find_max(ls)
print("\nMax number out of the inputs are :"+str(count))