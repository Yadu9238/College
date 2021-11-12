		area	factorial,code,readonly
	;entry
		mov r0,#5
		mov r1,#1
loop	cmp r0,#0
		mulgt r1,r0,r1
		subgt r0,r0,#1
		bgt loop
stop b stop
		end