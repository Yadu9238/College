	Area arr,code
	entry
	
	ldr r0,=value
	ldr r1,[r0]
	mov r2,r1
	cmp r1,#0x09
	bhi grt
	add r1,r1,#0x030
	bl nxt1

grt	add r1,r1,#0x037
	
nxt1	ldr r4,=0x40000000
	str r1,[r4]

stop b stop

	area data,code
value dcd &07
