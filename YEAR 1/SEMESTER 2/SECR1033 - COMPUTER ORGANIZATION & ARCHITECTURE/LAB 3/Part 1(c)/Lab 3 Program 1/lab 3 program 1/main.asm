TITLE lab_3
; author: adriana
; date: 23 june 2024

INCLUDE Irvine32.inc

.data
sideHex1 DWORD ?
sideHex2 DWORD ?
Perimeter_hexagon1 DWORD ?
Perimeter_hexagon2 DWORD ?
TotalPerimeter DWORD ?
message BYTE "Calculate Perimeter 2-Hexagon (LOOP and ADD instructions):", 0
message1 BYTE "Input Hexagon 1 (side length) : ", 0
message2 BYTE "Input Hexagon 2 (side length) : ", 0
message3 BYTE "Result of Perimeter Hexagon 1 and 2:", 0
message4 BYTE "Total Perimeter Hexagon 1 and 2: ", 0
newline BYTE 13, 10, 0

.code
main PROC
; Display the main message
mov edx, OFFSET message
call WriteString
call crlf
call crlf

; Input for Hexagon 1
mov edx, OFFSET message1
call WriteString
call ReadDec
mov sideHex1, eax

; Input for Hexagon 2
mov edx, OFFSET message2
call WriteString
call ReadDec
mov sideHex2, eax

; Calculate perimeter for Hexagon 1
mov eax, sideHex1
mov ecx, 6
mul ecx
mov Perimeter_hexagon1, eax

; Calculate perimeter for Hexagon 2
mov eax, sideHex2
mov ecx, 6
mul ecx
mov Perimeter_hexagon2, eax

; Add both perimeters
mov eax, Perimeter_hexagon1
add eax, Perimeter_hexagon2
mov TotalPerimeter, eax

; Display results
call crlf
mov edx, OFFSET message3
call WriteString
call crlf

; Display Perimeter of Hexagon 1
mov eax, Perimeter_hexagon1
call WriteDec
call crlf

; Display Perimeter of Hexagon 2
mov eax, Perimeter_hexagon2
call WriteDec
call crlf

; Display total perimeter
call crlf
mov edx, OFFSET message4
call WriteString
mov eax, TotalPerimeter
call WriteDec
call crlf

exit
main ENDP

END main
