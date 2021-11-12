		area 	sum_cubes,code
n 			rn 1
nplus	rn 2
temp 	rn 3
res 		rn 4
			entry
			mov n,#3	
			add nplus,n,#1
			mul temp,n,nplus
			lsr temp,temp,#1
			mul res,temp,temp
			
			ldr r0,=0x40000000
			str res,[r0]
stop 		b stop
			end
				