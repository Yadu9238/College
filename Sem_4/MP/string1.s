		area	string1,code

			entry
			
			ldr r0,=dststr
			adr r1,srcstr
			
repeat	ldrb r2,[r1],#1
			strb r2,[r0],#1
			cmp r2,#0
			bne	repeat
			
go		b go
srcstr	dcb	"this is source string",0
			area	dststring,data,readwrite
dststr	space 30
		
			end