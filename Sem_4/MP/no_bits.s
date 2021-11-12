		area 	no_of_bits,code
		
noz 	rn 1
noo 	rn 2
n 		rn 0
			entry
 			ldr n,=0xabcd
			mov	noz,#0
			mov noo,#0
rotate	lsrs	n,#1
			addcs noo,noo,#1
			addcc noz,noz,#1
			cmp n,#0
			bne rotate

stop		b		stop

		end