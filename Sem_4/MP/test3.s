		area	sum_even,code,readonly
entry
		mov r0,#0
		mov r1,#2
		mov r2,#5
loop 	add r0,r0,r1
		add r1,r1,#2
		sub r2,r2,#1
		cmp r2,#0
		bne loop
stop  b 	stop

		end