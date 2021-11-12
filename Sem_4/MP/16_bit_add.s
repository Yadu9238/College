	area	array-addition,code
	entry

	adr r7,values
	mov r2,#0
	ldr r6,=len
	
loop	ldrh r5,[r7],#2
	add r2,r5,r2
	subs r6,#1
	cmp r6,#0
	bne loop
	
	mov r4,#0x40000001C
	str r2,[r4]

stop 	b stop
	end
	
	