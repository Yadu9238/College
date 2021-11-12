		area		ap,code
			entry
		mov r2,#9
		mov r0,#3
		
		ldr r1,=values
		str r0,[r1]
		
repeat	add r0,r0,#7
			str r0,[r1,#4]!
			subs r2,r2,#1
			bne repeat

go		b	go

			area mydata,data,readwrite
values	space 10
	
			end