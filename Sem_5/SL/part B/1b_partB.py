import pprint

file= open("test.txt",'r') 	#opening file to be read
f= list(file.read().split(" ")) #making a list of all the words present

count = {} #initialise empty dictionary to keep count of words

for i in f:
	
	if i not  in count:
		count[i] = 1
	else:
		count[i] +=1
pprint.pprint(count) #pprint is used to pretty print the output
