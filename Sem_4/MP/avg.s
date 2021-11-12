		area	average,code
			entry

sum		rn	2
avg		rn	3
		adr	r1,values
		mov	sum,#0
		mov	r4,#10
		
again	ldrh r0,[r1],#2
			add	sum,sum,r0
			subs	r4,r4,#1
			bne	again
			
			mov r4,#10
			mov avg,#0
			
test		subs	sum,sum,r4
			addpl	avg,avg,#1
			bpl	test
			add sum,sum,r4	
stop		b	stop

values	dcw	1,2,3,4,5,6,7,8,9,10

		end