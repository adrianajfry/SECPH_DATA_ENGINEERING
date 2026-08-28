TITLE lab_3
; author: adriana
; date: 24 june 2024

INCLUDE Irvine32.inc

.data
prompt BYTE "Calculate SUM (unsign INT) index (Odd or Even) in array Hello[6] :", 0
inputMsg BYTE "Interger Input : ", 0
hello DWORD 6 DUP(0)
totalEven DWORD ?
totalOdd DWORD ?
resultMsg BYTE "Result Sum Hello[index]:", 0
sumEvenMsg BYTE "Sum Hello[even] index location = ", 0
sumOddMsg BYTE "Sum Hello[odd] index location = ", 0
newline BYTE 13, 10, 0

.code
main PROC
; Display the main prompt message
mov edx, OFFSET prompt
call WriteString
call crlf
call crlf

; Input loop to get 6 values from the user
mov ecx, 6; loop counter for 6 values
mov esi, 0; index for hello array

inputLoop:
mov edx, OFFSET inputMsg; display "Interger Input : "
call WriteString
call ReadInt; read integer input from user
mov[hello + esi], eax; store the input in hello array
add esi, 4; move to the next DWORD
loop inputLoop; repeat for all elements

; Initialize totalEvenand totalOdd to 0
mov eax, 0
mov totalEven, eax
mov totalOdd, eax

; Calculate the sum of even - indexed and odd - indexed elements
mov ecx, 6; loop counter for 6 values
mov esi, 0; index for hello array

sumLoop:
mov eax, [hello + esi]
test esi, 4; check if the index is even or odd
jz evenIndex
; Odd index
add totalOdd, eax
jmp nextElement
evenIndex :
; Even index
add totalEven, eax
nextElement :
add esi, 4; move to the next DWORD
loop sumLoop; repeat for all elements

; Display results
call crlf
mov edx, OFFSET resultMsg
call WriteString
call crlf
call crlf

; Display the sum of even - indexed elements
mov edx, OFFSET sumEvenMsg
call WriteString
mov eax, totalEven
call WriteDec
call crlf

; Display the sum of odd - indexed elements
mov edx, OFFSET sumOddMsg
call WriteString
mov eax, totalOdd
call WriteDec
call crlf

exit
main ENDP

END main

