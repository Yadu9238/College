
class sentence: #class definition
	st = ""
	def __init__(self,st):
		self.st = st

	def rev(self): #reversing the string input
		ls = list(self.st.split(" "))
		ls.reverse()
		new_st = ' '.join(ls)
		return new_st

def print_vow(ls2): #printing strings in order according to vowel count
	count =dict.fromkeys(ls2,0)
	for i in ls2:
		vow = 0	#vowel initial value
		
		#print(count)
		string = i.lower()
		#print((string))
		for j in string:
			if j == 'a' or j == 'e' or j == 'i' or j == 'o' or j=='u':
				vow = vow+1
		count[i] = vow
		
	#print(count)
		#fin.update(count)
	#print(fin)
	a= dict(sorted(count.items(),key = lambda x:x[1],reverse = True) )#sorting the dictionary
	for i in a:
		print(i)


st_class = sentence("This is a test case") #instances of class
st2_class = sentence("hello world")
st3_class = sentence("good morning")

print("\nStrings initialised are:\n")
print(st_class.st+"\n"+st2_class.st+"\n"+st3_class.st+"\n\n")

ls2 = [st_class.rev(),st2_class.rev(),st3_class.rev()] #making a list of the strings instances

print("Reversed Strings in descending order of vowels: \n")
print_vow(ls2)
#rev_string = st_class.rev()
#print(rev_string)