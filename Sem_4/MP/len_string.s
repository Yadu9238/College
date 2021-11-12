area	string1,code

	entry
			
		
	adr r1,srcstr
	mov r0,#0		
repeat	ldrb r2,[r1],#1
	cmp r2,#0
	beq go
	add r0,r0,#1
	bal repeat
			
go	b go
srcstr	dcb	"this is source string",0
			
	end
