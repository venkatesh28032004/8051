;org 100h
;	back:
;		acall delay
;		acall delay
;		cpl P1.0
;		acall delay
;		acall delay
;		sjmp back
;		delay:
;		mov r0,#08h
;		here3:mov r1,#0ffh
;		here2: mov r2,#0ffh
;		here:djnz r2,here
;		djnz r1,here2
;		djnz r2,here3
;			ret
;end
org 00h
CLR P1.0
BACK:CLR P1.0
ACALL DELAY
SETB P1.0
ACALL DELAY
SJMP BACK 
DELAY:MOV R5,#0FFH
AGAIN:DJNZ R5,AGAIN
RET
end
;	
;	
;	
;	
;	
;	
;	
;	
;	ORG 00H
;CLR P1.0
;BACK:CLR P1.0
;ACALL DELAY
;SETB P1.0
;ACALL DELAY
;SJMP BACK 
;DELAY:MOV R5,#0FFH
;AGAIN:DJNZ R5,AGAIN
;RET
;END