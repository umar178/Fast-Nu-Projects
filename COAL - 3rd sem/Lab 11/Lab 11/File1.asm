include Irvine32.inc

.data
filename        BYTE "students.txt",0
fileHandle      DWORD ?

; Single Record Buffers
nameBuffer      BYTE 32 DUP(0)
rollBuffer      BYTE 20 DUP(0)
gpaBuffer       BYTE 10 DUP(0)
searchBuffer    BYTE 20 DUP(0)

; Sorting Data
REC_SIZE        = 62
MAX_RECORDS     = 50
allRecords      BYTE 3100 DUP(?)
recCount        DWORD ?         
tempSwap        BYTE 62 DUP(?)

; --- FUNCTION HEADERS ---
headerAdd       BYTE "========== ADD STUDENT RECORD ==========",0dh,0ah,0
headerView      BYTE "========== VIEW ALL RECORDS ==========",0dh,0ah,0
headerSearch    BYTE "========== SEARCH BY ROLL NUMBER ==========",0dh,0ah,0
headerRector    BYTE "========== RECTOR LIST (GPA 4.00) ==========",0dh,0ah,0
headerDean      BYTE "========== DEAN LIST (GPA 3.50+) ==========",0dh,0ah,0
headerWarn      BYTE "========== WARNING LIST (GPA < 2.00) ==========",0dh,0ah,0
headerSort      BYTE "========== MERIT LIST (HIGHEST GPA FIRST) ==========",0dh,0ah,0
headerReset     BYTE "========== RESET DATABASE ==========",0dh,0ah,0

; --- MAIN MENU STRINGS ---
menuTitle       BYTE "STUDENT RECORD MANAGEMENT SYSTEM",0dh,0ah,0
menu1           BYTE "1. Add Student",0dh,0ah,0
menu2           BYTE "2. View All Records",0dh,0ah,0
menu3           BYTE "3. Search by Roll No",0dh,0ah,0
menu4           BYTE "4. Academic Reports (Lists)",0dh,0ah,0
menu5           BYTE "5. View Merit List (Descending GPA)",0dh,0ah,0
menu6           BYTE "6. Delete/Reset File",0dh,0ah,0
menu7           BYTE "7. Exit",0dh,0ah,0
promptSelect    BYTE "Enter Choice: ",0

; --- SUB MENU STRINGS ---
subMenuTitle    BYTE "--- ACADEMIC REPORTS MENU ---",0dh,0ah,0
sub1            BYTE "1. Rector List",0dh,0ah,0
sub2            BYTE "2. Dean List",0dh,0ah,0
sub3            BYTE "3. Warning List",0dh,0ah,0
sub4            BYTE "4. Back to Main Menu",0dh,0ah,0

msgName         BYTE "Enter Name: ",0
msgRoll         BYTE "Enter Roll No: ",0
msgGPA          BYTE "Enter GPA (format X.XX): ",0
msgSearch       BYTE "Enter Roll No to Search: ",0
msgSaved        BYTE "Record Saved Successfully.",0dh,0ah,0
msgReset        BYTE "File Database Reset.",0dh,0ah,0
msgInvalid      BYTE "Invalid Input. Please try again.",0dh,0ah,0
msgEmpty        BYTE "No records found (File missing or empty).",0dh,0ah,0
msgNotFound     BYTE "Student not found.",0dh,0ah,0
msgSorting      BYTE "Generating Merit List...",0dh,0ah,0

separator       BYTE "-----------------------------------",0dh,0ah,0
strName         BYTE "Name: ",0
strRoll         BYTE "Roll: ",0
strGPA          BYTE "GPA:  ",0
newline         BYTE 0dh,0ah,0

.code
main PROC
    call Clrscr             ; Clear screen only once at start

MenuLoop:
    mov edx, OFFSET newline
    call WriteString
    mov edx, OFFSET menuTitle
    call WriteString
    mov edx, OFFSET separator
    call WriteString
    
    mov edx, OFFSET menu1
    call WriteString
    mov edx, OFFSET menu2
    call WriteString
    mov edx, OFFSET menu3
    call WriteString
    mov edx, OFFSET menu4
    call WriteString
    mov edx, OFFSET menu5
    call WriteString
    mov edx, OFFSET menu6
    call WriteString
    mov edx, OFFSET menu7
    call WriteString

    mov edx, OFFSET promptSelect
    call WriteString
    
    call ReadChar  
    call WriteChar 
    
    cmp al, '1'
    je OpAdd
    cmp al, '2'
    je OpView
    cmp al, '3'
    je OpSearch
    cmp al, '4'
    je OpReports
    cmp al, '5'
    je OpSort
    cmp al, '6'
    je OpReset
    cmp al, '7'
    je ExitProg
    
    jmp MenuLoop

OpAdd:
    call AddStudent
    jmp MenuLoop
OpView:
    call ViewRecords
    jmp MenuLoop
OpSearch:
    call SearchStudent
    jmp MenuLoop
OpReports:
    call Clrscr
    call ReportsMenuLoop
    call Clrscr
    jmp MenuLoop
OpSort:
    call SortByGPA
    jmp MenuLoop
OpReset:
    call ResetFile
    jmp MenuLoop
ExitProg:
    exit
main ENDP

ReportsMenuLoop PROC
    mov edx, OFFSET newline
    call WriteString
    mov edx, OFFSET subMenuTitle
    call WriteString
    mov edx, OFFSET separator
    call WriteString

    mov edx, OFFSET sub1
    call WriteString
    mov edx, OFFSET sub2
    call WriteString
    mov edx, OFFSET sub3
    call WriteString
    mov edx, OFFSET sub4
    call WriteString

    mov edx, OFFSET promptSelect
    call WriteString
    call ReadChar
    call WriteChar

    cmp al, '1'
    je CallRector
    cmp al, '2'
    je CallDean
    cmp al, '3'
    je CallWarn
    cmp al, '4'
    je ReturnToMain

    jmp ReportsMenuLoop

CallRector:
    call RectorList
    jmp ReportsMenuLoop
CallDean:
    call DeanList
    jmp ReportsMenuLoop
CallWarn:
    call WarningList
    jmp ReportsMenuLoop
ReturnToMain:
    ret
ReportsMenuLoop ENDP

ClearBuffer PROC
    push esi
    push ecx
    mov esi, edx
    mov al, 0
CLoop:
    mov [esi], al
    inc esi
    loop CLoop
    pop ecx
    pop esi
    ret
ClearBuffer ENDP

AddStudent PROC
    call Clrscr
    mov edx, OFFSET headerAdd
    call WriteString
    mov edx, OFFSET newline
    call WriteString

AskName:
    mov edx, OFFSET nameBuffer
    mov ecx, 32
    call ClearBuffer
    mov edx, OFFSET msgName
    call WriteString
    mov edx, OFFSET nameBuffer
    mov ecx, 31
    call ReadString
    cmp eax, 0
    je NameError
    jmp AskRoll
NameError:
    mov edx, OFFSET msgInvalid
    call WriteString
    jmp AskName
AskRoll:
    mov edx, OFFSET rollBuffer
    mov ecx, 20
    call ClearBuffer
    mov edx, OFFSET msgRoll
    call WriteString
    mov edx, OFFSET rollBuffer
    mov ecx, 19
    call ReadString
    cmp eax, 0
    je RollError
    jmp AskGPA
RollError:
    mov edx, OFFSET msgInvalid
    call WriteString
    jmp AskRoll
AskGPA:
    mov edx, OFFSET gpaBuffer
    mov ecx, 10
    call ClearBuffer
    mov edx, OFFSET msgGPA
    call WriteString
    mov edx, OFFSET gpaBuffer
    mov ecx, 6
    call ReadString
    cmp eax, 4
    jne GPAError
    mov al, gpaBuffer[0]
    cmp al, '0'
    jb GPAError
    cmp al, '4'
    ja GPAError
    mov al, gpaBuffer[1]
    cmp al, '.'
    jne GPAError
    mov al, gpaBuffer[2]
    cmp al, '0'
    jb GPAError
    cmp al, '9'
    ja GPAError
    mov al, gpaBuffer[3]
    cmp al, '0'
    jb GPAError
    cmp al, '9'
    ja GPAError
    jmp SaveToFile
GPAError:
    mov edx, OFFSET msgInvalid
    call WriteString
    jmp AskGPA

SaveToFile:
    INVOKE CreateFile,
      ADDR filename, 
      GENERIC_WRITE, 
      DO_NOT_SHARE, 
      NULL, 
      OPEN_EXISTING, 
      FILE_ATTRIBUTE_NORMAL, 
      0
    
    mov fileHandle, eax
    cmp eax, INVALID_HANDLE_VALUE
    jne FileExists

    mov edx, OFFSET filename
    call CreateOutputFile
    mov fileHandle, eax
    jmp WriteData

FileExists:
    INVOKE SetFilePointer, fileHandle, 0, 0, 2

WriteData:
    mov eax, fileHandle
    mov edx, OFFSET nameBuffer
    mov ecx, 32
    call WriteToFile
    mov eax, fileHandle
    mov edx, OFFSET rollBuffer
    mov ecx, 20
    call WriteToFile
    mov eax, fileHandle
    mov edx, OFFSET gpaBuffer
    mov ecx, 10
    call WriteToFile
    mov eax, fileHandle
    call CloseFile
    
    mov edx, OFFSET msgSaved
    call WriteString
    ret
AddStudent ENDP

ViewRecords PROC
    call Clrscr
    mov edx, OFFSET headerView
    call WriteString
    mov edx, OFFSET newline
    call WriteString

    mov edx, OFFSET filename
    call OpenInputFile
    cmp eax, INVALID_HANDLE_VALUE
    je ViewFileError
    mov fileHandle, eax
ReadLoop:
    mov eax, fileHandle
    mov edx, OFFSET nameBuffer
    mov ecx, 32
    call ReadFromFile
    cmp eax, 0
    je CloseView
    mov eax, fileHandle
    mov edx, OFFSET rollBuffer
    mov ecx, 20
    call ReadFromFile
    mov eax, fileHandle
    mov edx, OFFSET gpaBuffer
    mov ecx, 10
    call ReadFromFile
    call DisplayOneRecord
    jmp ReadLoop
ViewFileError:
    mov edx, OFFSET msgEmpty
    call WriteString
    jmp ViewRet
CloseView:
    mov eax, fileHandle
    call CloseFile
ViewRet:
    ret
ViewRecords ENDP

SearchStudent PROC
    call Clrscr
    mov edx, OFFSET headerSearch
    call WriteString
    mov edx, OFFSET newline
    call WriteString

    mov edx, OFFSET msgSearch
    call WriteString
    mov edx, OFFSET searchBuffer
    mov ecx, 19
    call ReadString
    mov edx, OFFSET filename
    call OpenInputFile
    cmp eax, INVALID_HANDLE_VALUE
    je SearchError
    mov fileHandle, eax
SearchLoop:
    mov eax, fileHandle
    mov edx, OFFSET nameBuffer
    mov ecx, 32
    call ReadFromFile
    cmp eax, 0
    je NotFound
    mov eax, fileHandle
    mov edx, OFFSET rollBuffer
    mov ecx, 20
    call ReadFromFile
    mov eax, fileHandle
    mov edx, OFFSET gpaBuffer
    mov ecx, 10
    call ReadFromFile
    push ecx
    mov esi, OFFSET rollBuffer
    mov edi, OFFSET searchBuffer
    mov ecx, 20 
    cld
    repe cmpsb
    pop ecx
    je FoundRec
    jmp SearchLoop
FoundRec:
    call DisplayOneRecord
    jmp CloseSearch
NotFound:
    mov edx, OFFSET msgNotFound
    call WriteString
    jmp CloseSearch
SearchError:
    mov edx, OFFSET msgEmpty
    call WriteString
CloseSearch:
    mov eax, fileHandle
    call CloseFile
    ret
SearchStudent ENDP

RectorList PROC
    call Clrscr
    mov edx, OFFSET headerRector
    call WriteString
    mov edx, OFFSET newline
    call WriteString

    mov edx, OFFSET filename
    call OpenInputFile
    cmp eax, INVALID_HANDLE_VALUE
    je RecFileError
    mov fileHandle, eax
RecLoop:
    mov eax, fileHandle
    mov edx, OFFSET nameBuffer
    mov ecx, 32
    call ReadFromFile
    cmp eax, 0
    je CloseRec
    mov eax, fileHandle
    mov edx, OFFSET rollBuffer
    mov ecx, 20
    call ReadFromFile
    mov eax, fileHandle
    mov edx, OFFSET gpaBuffer
    mov ecx, 10
    call ReadFromFile
    call ParseGPA
    cmp eax, 400
    jne RecNext
    call DisplayOneRecord
RecNext:
    jmp RecLoop
RecFileError:
    mov edx, OFFSET msgEmpty
    call WriteString
    jmp RecRet
CloseRec:
    mov eax, fileHandle
    call CloseFile
RecRet:
    ret
RectorList ENDP

DeanList PROC
    call Clrscr
    mov edx, OFFSET headerDean
    call WriteString
    mov edx, OFFSET newline
    call WriteString

    mov edx, OFFSET filename
    call OpenInputFile
    cmp eax, INVALID_HANDLE_VALUE
    je DeanFileError
    mov fileHandle, eax
DeanLoop:
    mov eax, fileHandle
    mov edx, OFFSET nameBuffer
    mov ecx, 32
    call ReadFromFile
    cmp eax, 0
    je CloseDean
    mov eax, fileHandle
    mov edx, OFFSET rollBuffer
    mov ecx, 20
    call ReadFromFile
    mov eax, fileHandle
    mov edx, OFFSET gpaBuffer
    mov ecx, 10
    call ReadFromFile
    call ParseGPA
    cmp eax, 350
    jb DeanNext
    call DisplayOneRecord
DeanNext:
    jmp DeanLoop
DeanFileError:
    mov edx, OFFSET msgEmpty
    call WriteString
    jmp DeanRet
CloseDean:
    mov eax, fileHandle
    call CloseFile
DeanRet:
    ret
DeanList ENDP

WarningList PROC
    call Clrscr
    mov edx, OFFSET headerWarn
    call WriteString
    mov edx, OFFSET newline
    call WriteString

    mov edx, OFFSET filename
    call OpenInputFile
    cmp eax, INVALID_HANDLE_VALUE
    je WarnFileError
    mov fileHandle, eax
WarnLoop:
    mov eax, fileHandle
    mov edx, OFFSET nameBuffer
    mov ecx, 32
    call ReadFromFile
    cmp eax, 0
    je CloseWarn
    mov eax, fileHandle
    mov edx, OFFSET rollBuffer
    mov ecx, 20
    call ReadFromFile
    mov eax, fileHandle
    mov edx, OFFSET gpaBuffer
    mov ecx, 10
    call ReadFromFile
    call ParseGPA
    cmp eax, 200
    jae WarnNext
    call DisplayOneRecord
WarnNext:
    jmp WarnLoop
WarnFileError:
    mov edx, OFFSET msgEmpty
    call WriteString
    jmp WarnRet
CloseWarn:
    mov eax, fileHandle
    call CloseFile
WarnRet:
    ret
WarningList ENDP

SortByGPA PROC
    call Clrscr
    mov edx, OFFSET headerSort
    call WriteString
    mov edx, OFFSET newline
    call WriteString

    mov edx, OFFSET msgSorting
    call WriteString
    mov edx, OFFSET filename
    call OpenInputFile
    cmp eax, INVALID_HANDLE_VALUE
    je SortError
    mov fileHandle, eax
    mov recCount, 0
    mov esi, OFFSET allRecords
LoadLoop:
    cmp recCount, MAX_RECORDS
    jae CloseLoad
    mov eax, fileHandle
    mov edx, esi
    mov ecx, REC_SIZE
    call ReadFromFile
    cmp eax, 0
    je CloseLoad
    inc recCount
    add esi, REC_SIZE
    jmp LoadLoop
CloseLoad:
    mov eax, fileHandle
    call CloseFile
    cmp recCount, 0
    je SortError
    cmp recCount, 1
    je DisplaySorted
    mov ecx, recCount
    dec ecx
OuterLoop:
    push ecx
    mov esi, OFFSET allRecords
    InnerLoop:
        mov edi, esi
        add edi, REC_SIZE
        
        ; --- DESCENDING SORT LOGIC START ---
        ; We use 'jb' (Jump if Below) to Swap
        ; If Current(esi) < Next(edi), we swap to push smaller numbers down
        
        ; Check 1st digit (e.g. '3'.5 vs '2'.5)
        mov al, [esi + 52]
        mov bl, [edi + 52]
        cmp al, bl
        jb  SwapRec         ; SWAP if Current < Next (Descending)
        ja  NextIter        ; KEEP if Current > Next
        
        ; Check 1st decimal
        mov al, [esi + 54]
        mov bl, [edi + 54]
        cmp al, bl
        jb  SwapRec
        ja  NextIter
        
        ; Check 2nd decimal
        mov al, [esi + 55]
        mov bl, [edi + 55]
        cmp al, bl
        jb  SwapRec
        ; --- DESCENDING SORT LOGIC END ---
        
        jmp NextIter

    SwapRec:
        push ecx
        push esi
        push edi
        mov ecx, REC_SIZE
    DoSwap:
        mov al, [esi]
        mov bl, [edi]
        mov [esi], bl
        mov [edi], al
        inc esi
        inc edi
        loop DoSwap
        pop edi
        pop esi
        pop ecx

    NextIter:
        add esi, REC_SIZE
        loop InnerLoop
    pop ecx
    loop OuterLoop
DisplaySorted:
    mov ecx, recCount
    mov esi, OFFSET allRecords
PrintLoop:
    push ecx
    push esi
    mov edi, OFFSET nameBuffer
    mov ecx, 32
    rep movsb
    mov edi, OFFSET rollBuffer
    mov ecx, 20
    rep movsb
    mov edi, OFFSET gpaBuffer
    mov ecx, 10
    rep movsb
    call DisplayOneRecord
    pop esi
    pop ecx
    add esi, REC_SIZE
    loop PrintLoop
    jmp SortRet
SortError:
    mov edx, OFFSET msgEmpty
    call WriteString
SortRet:
    ret
SortByGPA ENDP

ResetFile PROC
    call Clrscr
    mov edx, OFFSET headerReset
    call WriteString
    mov edx, OFFSET newline
    call WriteString

    mov edx, OFFSET filename
    call CreateOutputFile
    mov fileHandle, eax
    call CloseFile
    mov edx, OFFSET msgReset
    call WriteString
    ret
ResetFile ENDP

DisplayOneRecord PROC
    mov edx, OFFSET separator
    call WriteString
    mov edx, OFFSET strName
    call WriteString
    mov edx, OFFSET nameBuffer
    call WriteString
    call Crlf
    mov edx, OFFSET strRoll
    call WriteString
    mov edx, OFFSET rollBuffer
    call WriteString
    call Crlf
    mov edx, OFFSET strGPA
    call WriteString
    mov edx, OFFSET gpaBuffer
    call WriteString
    call Crlf
    ret
DisplayOneRecord ENDP

ParseGPA PROC
    movzx eax, byte ptr [gpaBuffer]
    sub eax, 48
    imul eax, 100
    mov ecx, eax
    movzx eax, byte ptr [gpaBuffer+2]
    sub eax, 48
    imul eax, 10
    add ecx, eax
    movzx eax, byte ptr [gpaBuffer+3]
    sub eax, 48
    add eax, ecx
    ret
ParseGPA ENDP

END main