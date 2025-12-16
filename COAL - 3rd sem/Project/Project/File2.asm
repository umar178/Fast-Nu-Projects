TITLE Simple Vehicle Parking Management System (With Fee Calculator)

INCLUDE Irvine32.inc

SPOT_COUNT      = 10
PLATE_LENGTH    = 15
RECORD_SIZE     = 16
HOURLY_RATE     = 50

.data
    strHeader       BYTE "--------------------------------------------------", 0dh, 0ah
                    BYTE "    VEHICLE PARKING SYSTEM (WITH FEE CALCULATOR)  ", 0dh, 0ah
                    BYTE "--------------------------------------------------", 0dh, 0ah, 0
    strMenu         BYTE 0dh, 0ah, "1. Allocate Spot (Park Vehicle)", 0dh, 0ah
                    BYTE "2. Vacate Spot & Calculate Fee", 0dh, 0ah
                    BYTE "3. Check Status", 0dh, 0ah
                    BYTE "4. Search Vehicle", 0dh, 0ah
                    BYTE "5. Exit", 0dh, 0ah
                    BYTE "Enter Choice: ", 0
   
    strEnterPlate   BYTE "Enter License Plate (Max 15 chars): ", 0
    strEnterSpot    BYTE "Enter Spot Number (1-10): ", 0
   
    strAskHours     BYTE "Enter Hours Parked: ", 0
    strTotalFee     BYTE "Total Parking Fee: ", 0
    strCurrency     BYTE " /-", 0dh, 0ah, 0

    strInvalidSpot  BYTE "Error: Invalid Spot Number! ", 0dh, 0ah, 0
    strSpotOccupied BYTE "Error: That spot is already occupied!", 0dh, 0ah, 0
    strSpotEmpty    BYTE "Error: That spot is already empty!", 0dh, 0ah, 0
    strSuccessPark  BYTE "Vehicle Parked Successfully.", 0dh, 0ah, 0
    strSuccessVac   BYTE "Spot Vacated & Fee Paid.", 0dh, 0ah, 0
    strNotFound     BYTE "Vehicle not found.", 0dh, 0ah, 0
    strFoundAt      BYTE "Vehicle found at Spot: ", 0
    strStatusHead   BYTE "--- Parking Status ---", 0dh, 0ah, 0
    strSpotLabel    BYTE "Spot ", 0
    strColon        BYTE ": ", 0
    strEmptyLabel   BYTE "[EMPTY]", 0
   
    parkingData     BYTE SPOT_COUNT * RECORD_SIZE DUP(0)

    tempStr         BYTE RECORD_SIZE DUP(0)
    userChoice      DWORD ?
    spotIndex       DWORD ?                

.code
main PROC
MainLoop:
    call Clrscr
    mov  edx, OFFSET strHeader
    call WriteString
   
    call DisplayAvailability

    mov  edx, OFFSET strMenu
    call WriteString
    call ReadInt
    mov  userChoice, eax

    cmp eax, 1
    je  AllocSpot
    cmp eax, 2
    je  VacateSpot
    cmp eax, 3
    je  StatusSpot
    cmp eax, 4
    je  SearchSpot
    cmp eax, 5
    je  ExitProgram
    jmp MainLoop

AllocSpot:
    call Crlf
    mov  edx, OFFSET strEnterSpot
    call WriteString
    call ReadInt
   
    cmp eax, 1
    jl  InvalidInput
    cmp eax, SPOT_COUNT
    jg  InvalidInput
   
    dec eax                
    mov spotIndex, eax
    mov ebx, spotIndex
    imul ebx, RECORD_SIZE  
    lea esi, parkingData[ebx]
   
    mov al, [esi]
    cmp al, 0
    jne IsOccupied
   
    mov  edx, OFFSET strEnterPlate
    call WriteString
    mov  edx, esi          
    mov  ecx, PLATE_LENGTH
    call ReadString
   
    mov  edx, OFFSET strSuccessPark
    call WriteString
    call WaitMsg
    jmp  MainLoop

VacateSpot:
    call Crlf
    mov  edx, OFFSET strEnterSpot
    call WriteString
    call ReadInt
   
    cmp eax, 1
    jl  InvalidInput
    cmp eax, SPOT_COUNT
    jg  InvalidInput
   
    dec eax
    mov spotIndex, eax
   
    mov ebx, spotIndex
    imul ebx, RECORD_SIZE
    lea edi, parkingData[ebx]
   
    mov al, [edi]
    cmp al, 0
    je  IsAlreadyEmpty

    mov  edx, OFFSET strAskHours
    call WriteString
    call ReadInt
   
    mov  ebx, HOURLY_RATE
    imul eax, ebx
   
    mov  edx, OFFSET strTotalFee
    call WriteString
    call WriteDec
    mov  edx, OFFSET strCurrency
    call WriteString
    call Crlf
   
    mov eax, spotIndex
    imul eax, RECORD_SIZE
    lea edi, parkingData[eax]
   
    mov BYTE PTR [edi], 0
   
    mov  edx, OFFSET strSuccessVac
    call WriteString
    call WaitMsg
    jmp  MainLoop

StatusSpot:
    call Clrscr
    mov  edx, OFFSET strStatusHead
    call WriteString
   
    mov ecx, SPOT_COUNT
    mov ebx, 0  

StatusLoop:
    mov  edx, OFFSET strSpotLabel
    call WriteString
    mov  eax, ebx
    inc  eax
    call WriteDec
    mov  edx, OFFSET strColon
    call WriteString
   
    mov eax, ebx
    imul eax, RECORD_SIZE
    lea edx, parkingData[eax]
   
    mov al, [edx]
    cmp al, 0
    je  PrintEmpty
   
    call WriteString
    call Crlf
    jmp  NextStatus

PrintEmpty:
    push edx
    mov  edx, OFFSET strEmptyLabel
    call WriteString
    call Crlf
    pop  edx

NextStatus:
    inc ebx
    loop StatusLoop
   
    call WaitMsg
    jmp  MainLoop

SearchSpot:
    call Crlf
    mov  edx, OFFSET strEnterPlate
    call WriteString
    mov  edx, OFFSET tempStr
    mov  ecx, PLATE_LENGTH
    call ReadString

    mov ecx, SPOT_COUNT
    mov ebx, 0

SearchLoop:
    mov eax, ebx
    imul eax, RECORD_SIZE
    lea esi, parkingData[eax]
    mov edi, OFFSET tempStr  
   
    push ecx
    push esi
    push edi
    mov ecx, PLATE_LENGTH
    cld
    repe cmpsb
    pop edi
    pop esi
    pop ecx
    je FoundVehicle
   
    inc ebx
    loop SearchLoop
   
    mov edx, OFFSET strNotFound
    call WriteString
    call WaitMsg
    jmp MainLoop

FoundVehicle:
    mov edx, OFFSET strFoundAt
    call WriteString
    mov eax, ebx
    inc eax
    call WriteDec
    call Crlf
    call WaitMsg
    jmp MainLoop

DisplayAvailability:
    mov ecx, SPOT_COUNT
    mov ebx, 0
    mov esi, 0
   
CountLoop:
    mov eax, esi
    imul eax, RECORD_SIZE
    lea edi, parkingData[eax]
    mov al, [edi]
    cmp al, 0
    je  SkipCount
    inc ebx
SkipCount:
    inc esi
    loop CountLoop
   
    mov eax, SPOT_COUNT
    sub eax, ebx
   
    push eax
    mov  eax, ebx
    call WriteDec
    mov  al, '/'
    call WriteChar
    mov  eax, SPOT_COUNT
    call WriteDec
    mov  edx, OFFSET strColon
    call WriteString
    mov  edx, OFFSET strEmptyLabel
    call WriteString
    call Crlf
    pop eax
    ret

InvalidInput:
    mov  edx, OFFSET strInvalidSpot
    call WriteString
    call WaitMsg
    jmp  MainLoop

IsOccupied:
    mov  edx, OFFSET strSpotOccupied
    call WriteString
    call WaitMsg
    jmp  MainLoop

IsAlreadyEmpty:
    mov  edx, OFFSET strSpotEmpty
    call WriteString
    call WaitMsg
    jmp  MainLoop

ExitProgram:
    exit
main ENDP
END main