		area apsum,code,readonly
	;entry
		mov r0,#0
		mov r1,#3
		mov r2,#1
loop	add r0,r0,r1
		add r1,r1,#7
		add r2,r2,#1
		cmp r2,#6
		bne loop
stop	b	stop
	end