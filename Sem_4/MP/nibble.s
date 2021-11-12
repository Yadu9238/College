	area nibble,code
	entry
	
	ldr r1,value
	ldr r2,mask
	mov r3,r1,lsr#0x4
	mov r3,r3,lsl#0x8
	and r1,r1,r2
	add r1,r1,r3
	
	str r1,result

end	b end


value	dcb &fb
	align	
mask	dcw &000f
	align
	
result	dcd 0

	end