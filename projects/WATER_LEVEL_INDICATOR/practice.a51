org 00h
	;org 00h

mov DPTR,#400h

mov A,#38h
acall CMD
mov A,#0fh
acall CMD
mov A,#01h
acall CMD
mov A,#06h
acall CMD
mov A,#80h
acall CMD

mov r7,#08h
mov r0,#00h

again:
mov A,r0
movc A,@a+DPTR
acall data_print
inc r0
djnz r7,again

wait_here:jmp wait_here


; p1.0->r/w   p1.1->rs   p1.2->en
CMD:
	mov P3,A
	clr P1.0
	clr P1.1
	setb P1.2
	clr P1.2
	acall delay
	ret

data_print:
	mov P3,A
	clr P1.0
	setb P1.1
	setb P1.2
	clr P1.2
	acall delay
	ret
delay:
	mov r3,#10h
	here:djnz r3,here
	ret

string:
	org 400h
	db ' KLH ECE'


end

		; bit/ byte manipulation for led blinking
	
;	back:mov P1 , #0ffh
;		acall delay
;		acall delay
;		mov P1,#00h
;		acall delay
;		acall delay
;		sjmp back
;		delay:
;		mov r4,#0ffh
;		here:djnz r4,here
;		ret


	; generating a square wave of 2khz
;	start:
;	mov TMOD , #01h
;	mov TH0 , #0ffh
;	mov TL0 , #06h
;	cpl P1.2
;	setb TR0
;	
;	wait:jnb TF0 , wait
;	
;	clr TR0
;	clr TF0
;	sjmp start

	; displaying on lcd
	
	


;end