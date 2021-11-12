def remove_dups(lis): #function to remove duplicates
	res = []
	for i in lis:
		if i not in res:
			res.append(i)
	return res	



n  = int(input("Enter number of elements"))
ls = []

for i in range(n):
	i = input("Enter elements")
	ls.append(i)
print("\nEntered elements are:\n")
print(ls)
new_ls = remove_dups(ls)

print("\nList without duplicates:\n")
print(new_ls)

even_ls = [x for x in range(n) if x%2 == 0]
print("\nList of even numbers made using list comprehension:\n")
print(even_ls) #making even numbers list using list comprehension

ls.reverse()
rev_lis = ls

print("\nReversed List of elements:\n")
print(rev_lis) #printing elements in reverse