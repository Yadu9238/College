	area cmpstr,code

len1 rn 3
len2 rn 4

	adr r0,string1
	adr r1,string2
	mov len1,#0
	mov len2,#0

count1	ldrb r5,[r0],#1		;finding string length
	cmp r5,#0
	beq count2
	add len1,len1,#1
	bal count1

count2  ldrb r5,[r1],#1		;finding string length
	cmp r5,#0
	beq next
	add len2,len2,#1
	bal count2
	
next	mov r2,#0x00
	cmp len1,len2		;comparing string length
	bne done		;if not equal,string not matching

	cmp len1,#0
	beq same
	
	adr r0,string1	; r0 and r1 have changed due to post increment - needed re initialization
	adr r1,string2	
	
loop	ldrb r5,[r0],#1		;comparing
	ldrb r6,[r1],#1
	cmp r5,r6
	bne done
	subs r3,r3,#1
	beq same
	
	bal loop


same	mov r2,#0xff
	b done
	
done 	mov r4,#0x40000001C
	str r2,[r4]
	b go

go 	b go


string1 dcb "Micro",0
string2 dcb "Macro",0
	end
