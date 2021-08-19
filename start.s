.section ".text.boot"
 
.global _start
 
_start:
	ldr r3, =main
	blx r3

halt:
	wfe
	b halt