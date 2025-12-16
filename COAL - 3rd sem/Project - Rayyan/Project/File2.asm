INCLUDE Irvine32.inc

.data
    ; easy texts
    easyText1 BYTE "The quick brown fox jumps over the lazy dog.",0
    easyText2 BYTE "Hello world, this is a simple typing test for beginners.",0
    easyText3 BYTE "Practice makes perfect when learning to type faster.",0
    easyText4 BYTE "The sun shines bright in the clear blue sky today.",0
    easyText5 BYTE "Learning to code is fun and rewarding for everyone.",0
    
    ; medium difficulty texts
    mediumText1 BYTE "Programming is the art of telling another human what one wants the computer to do.",0
    mediumText2 BYTE "The best way to learn programming is by writing code and solving problems.",0
    mediumText3 BYTE "Computer science is the study of algorithms and computational systems.",0
    mediumText4 BYTE "Software engineering requires both technical skills and creative problem solving.",0
    mediumText5 BYTE "Understanding data structures and algorithms is essential for efficient programming.",0
    
    ; hard texts
    hardText1 BYTE "Assembly language is a low-level programming language that is closely related to machine code.",0
    hardText2 BYTE "The x86 instruction set architecture includes complex addressing modes and various data types.",0
    hardText3 BYTE "Microprocessor architecture involves understanding registers, memory hierarchy, and instruction pipelining.",0
    hardText4 BYTE "Optimizing assembly code requires deep knowledge of CPU internals and instruction timing.",0
    hardText5 BYTE "System programming involves direct interaction with hardware and operating system kernel interfaces.",0
    
    ; arrays of text pointers
    easyTexts DWORD OFFSET easyText1, OFFSET easyText2, OFFSET easyText3, OFFSET easyText4, OFFSET easyText5
    mediumTexts DWORD OFFSET mediumText1, OFFSET mediumText2, OFFSET mediumText3, OFFSET mediumText4, OFFSET mediumText5
    hardTexts DWORD OFFSET hardText1, OFFSET hardText2, OFFSET hardText3, OFFSET hardText4, OFFSET hardText5
    easyCount DWORD 5
    mediumCount DWORD 5
    hardCount DWORD 5
    
    ; messages
    welcomeMsg BYTE "==============================================",0dh,0ah
              BYTE "    TYPING SPEED TESTER - ADVANCED VERSION ",0dh,0ah
              BYTE "==============================================",0
    menuMsg BYTE "========== MAIN MENU ==========",0
    menu1 BYTE "1) Start Typing Test [Normal Mode]",0
    menu2 BYTE "2) Start Typing Test [Real-time Feedback]",0
    menu3 BYTE "3) Start Typing Test [Timed Mode]",0
    menu4 BYTE "4) View Statistics",0
    menu5 BYTE "5) View Achievements",0
    menu6 BYTE "6) Reset Statistics",0
    menu7 BYTE "7) Exit",0
    menuChoice BYTE "Enter your choice (1-7): ",0
    
    difficultyMsg BYTE "========== SELECT DIFFICULTY LEVEL ==========",0
    diff1 BYTE "1) Easy",0
    diff2 BYTE "2) Medium",0
    diff3 BYTE "3) Hard",0
    diff4 BYTE "4) Random",0
    diffChoice BYTE "Enter the level of difficulty [1-4]: ",0
    
    instructionMsg BYTE "Type the text below as quickly and accurately as possible.",0
    instructionMsg2 BYTE "Press ENTER key when finished.",0
    promptMsg BYTE "Text to type:",0
    yourInputMsg BYTE "Your input:",0
    resultsMsg BYTE "========== TEST RESULTS ==========",0
    wpmMsg BYTE "Words Per Minute (WPM): ",0
    accuracyMsg BYTE "Accuracy: ",0
    percentMsg BYTE "%",0
    correctCharsMsg BYTE "Correct Characters: ",0
    incorrectCharsMsg BYTE "Incorrect Characters: ",0
    totalCharsMsg BYTE "Total Characters: ",0
    timeMsg BYTE "Time Taken: ",0
    secondsMsg BYTE " seconds",0
    millisecondsMsg BYTE " milliseconds",0
    cpmMsg BYTE "Characters Per Minute (CPM): ",0
    pressKeyMsg BYTE "Press any key to continue...",0
    newLineMsg BYTE 0dh,0ah,0
    
    statsMsg BYTE "========== YOUR STATISTICS ==========",0
    totalTestsMsg BYTE "Total Tests Completed: ",0
    bestWpmMsg BYTE "Best WPM (Words per minute): ",0
    bestAccuracyMsg BYTE "Best Accuracy: ",0
    avgWpmMsg BYTE "Average WPM (Words per minute): ",0
    avgAccuracyMsg BYTE "Average Accuracy: ",0
    totalWpmMsg BYTE "Total WPM (word per minute): ",0
    totalAccuracyMsg BYTE "Total Accuracy : ",0
    
    resetConfirmMsg BYTE "Are you sure you want to reset all statistics? Y/N: ",0
    resetSuccessMsg BYTE "Statistics have been reset!",0
    invalidChoiceMsg BYTE "Invalid choice! Please try again.",0
    
    errorAnalysisMsg BYTE "========== ERROR REPORT ==========",0
    errorPosMsg BYTE "Error positions (character numbers): ",0
    commaSpace BYTE ", ",0
    
    wordBreakdownMsg BYTE "========== WORD BREAKDOWN ==========",0
    wordCorrectMsg BYTE "Correct words: ",0
    wordIncorrectMsg BYTE "Incorrect words: ",0
    wordTotalMsg BYTE "Total words: ",0
    
    testModeMsg BYTE "========== SELECT TEST MODE ==========",0
    modeNormal BYTE "Normal Mode - Type and press ENTER when done",0
    modeRealtime BYTE "Real-time Feedback Mode - See errors as you type",0
    modeTimed BYTE "Timed Mode - Test with time limit",0
    
    timedTestMsg BYTE "========== TIMED TEST MODE ==========",0
    timeSelectMsg BYTE "Select test duration:",0
    time30 BYTE "1) 30 seconds",0
    time60 BYTE "2) 60 seconds",0
    time120 BYTE "3) 120 seconds [2 minutes]",0
    timeChoice BYTE "Enter duration [1-3]: ",0
    countdownMsg BYTE "Starting in: ",0
    timeRemainingMsg BYTE "Time Remaining: ",0
    timeUpMsg BYTE "TIME'S UP! Test submitted automatically.",0
    secondsRemaining BYTE " seconds",0
    
    realtimeMsg BYTE "========== REAL-TIME FEEDBACK MODE ==========",0
    realtimeInstruction BYTE "Type the text. Errors shown with [X], correct with [OK]",0
    correctIndicator BYTE "[OK]",0
    errorIndicator BYTE "[X]",0
    currentCharMsg BYTE "Current character: ",0
    progressMsg BYTE "Progress: ",0
    slashMsg BYTE " / ",0
    
    achievementMsg BYTE "========== ACHIEVEMENTS ==========",0
    achievementUnlocked BYTE "*** ACHIEVEMENT UNLOCKED! ***",0
    achievementListMsg BYTE "Your Achievements:",0
    noAchievementsMsg BYTE "No achievements unlocked yet. Keep practicing!",0
    
    ach50Wpm BYTE "[UNLOCKED] Speedster - Reach 50 WPM",0
    ach50WpmLocked BYTE "[LOCKED] Speedster - Reach 50 WPM",0
    ach100Wpm BYTE "[UNLOCKED] Lightning Fast - Reach 100 WPM",0
    ach100WpmLocked BYTE "[LOCKED] Lightning Fast - Reach 100 WPM",0
    achPerfect BYTE "[UNLOCKED] Perfectionist - Achieve 100% accuracy",0
    achPerfectLocked BYTE "[LOCKED] Perfectionist - Achieve 100% accuracy",0
    ach10Tests BYTE "[UNLOCKED] Dedicated - Complete 10 tests",0
    ach10TestsLocked BYTE "[LOCKED] Dedicated - Complete 10 tests",0
    ach50Tests BYTE "[UNLOCKED] Master - Complete 50 tests",0
    ach50TestsLocked BYTE "[LOCKED] Master - Complete 50 tests",0
    ach90Accuracy BYTE "[UNLOCKED] Accurate - Maintain 90%+ accuracy",0
    ach90AccuracyLocked BYTE "[LOCKED] Accurate - Maintain 90%+ accuracy",0
    
    userInput BYTE 500 DUP(?)
    inputLength DWORD ?
    choice BYTE ?
    
    startTime DWORD ?
    endTime DWORD ?
    elapsedTime DWORD ?
    correctCount DWORD 0
    incorrectCount DWORD 0
    totalChars DWORD 0
    wpm DWORD 0
    cpm DWORD 0
    accuracy DWORD 0
    wordCount DWORD 0
    correctWords DWORD 0
    incorrectWords DWORD 0
    
    totalTests DWORD 0
    bestWpm DWORD 0
    bestAccuracy DWORD 0
    totalWpmSum DWORD 0
    totalAccuracySum DWORD 0
    
    achievement50Wpm DWORD 0
    achievement100Wpm DWORD 0
    achievementPerfect DWORD 0
    achievement10Tests DWORD 0
    achievement50Tests DWORD 0
    achievement90Accuracy DWORD 0
    
    testMode DWORD 0
    timedDuration DWORD 0
    timeRemaining DWORD 0
    
    currentText DWORD ?
    currentDifficulty DWORD ?
    
    errorPositions DWORD 100 DUP(0)
    errorCount DWORD 0
    
    originalWords BYTE 500 DUP(?)
    userWords BYTE 500 DUP(?)
    
    separator BYTE "----------------------------------------",0

.code
main PROC
    call Clrscr
    
main_loop:
    call DisplayMenu
    call ReadChar
    mov choice, al
    call WriteChar
    call Crlf
    call Crlf
    
    cmp choice, '1'
    je start_test_normal
    cmp choice, '2'
    je start_test_realtime
    cmp choice, '3'
    je start_test_timed
    cmp choice, '4'
    je view_stats
    cmp choice, '5'
    je view_achievements
    cmp choice, '6'
    je reset_stats
    cmp choice, '7'
    je exit_program
    
    mov edx, OFFSET invalidChoiceMsg
    call WriteString
    call Crlf
    call Crlf
    mov edx, OFFSET pressKeyMsg
    call WriteString
    call ReadChar
    call Clrscr
    jmp main_loop
    
start_test_normal:
    mov testMode, 0
    call SelectDifficulty
    call RunTypingTest
    call UpdateStatistics
    call CheckAchievements
    jmp main_loop
    
start_test_realtime:
    mov testMode, 1
    call SelectDifficulty
    call RunRealtimeTypingTest
    call UpdateStatistics
    call CheckAchievements
    jmp main_loop
    
start_test_timed:
    mov testMode, 2
    call SelectTimedDuration
    call SelectDifficulty
    call RunTimedTypingTest
    call UpdateStatistics
    call CheckAchievements
    jmp main_loop
    
view_stats:
    call DisplayStatistics
    jmp main_loop
    
view_achievements:
    call DisplayAchievements
    jmp main_loop
    
reset_stats:
    call ResetStatistics
    jmp main_loop
    
exit_program:
    exit
main ENDP

DisplayMenu PROC
    pushad
    
    mov edx, OFFSET welcomeMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET menuMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET menu1
    call WriteString
    call Crlf
    
    mov edx, OFFSET menu2
    call WriteString
    call Crlf
    
    mov edx, OFFSET menu3
    call WriteString
    call Crlf
    
    mov edx, OFFSET menu4
    call WriteString
    call Crlf
    
    mov edx, OFFSET menu5
    call WriteString
    call Crlf
    
    mov edx, OFFSET menu6
    call WriteString
    call Crlf
    
    mov edx, OFFSET menu7
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET menuChoice
    call WriteString
    
    popad
    ret
DisplayMenu ENDP

SelectDifficulty PROC
    pushad
    
    call Clrscr
    mov edx, OFFSET difficultyMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET diff1
    call WriteString
    call Crlf
    
    mov edx, OFFSET diff2
    call WriteString
    call Crlf
    
    mov edx, OFFSET diff3
    call WriteString
    call Crlf
    
    mov edx, OFFSET diff4
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET diffChoice
    call WriteString
    
    call ReadChar
    mov choice, al
    call WriteChar
    call Crlf
    call Crlf
    
    cmp choice, '1'
    je select_easy
    cmp choice, '2'
    je select_medium
    cmp choice, '3'
    je select_hard
    cmp choice, '4'
    je select_random
    
    mov choice, '1'
    jmp select_easy
    
select_easy:
    mov currentDifficulty, 1
    mov esi, OFFSET easyTexts
    mov ecx, easyCount
    call SelectRandomText
    jmp difficulty_done
    
select_medium:
    mov currentDifficulty, 2
    mov esi, OFFSET mediumTexts
    mov ecx, mediumCount
    call SelectRandomText
    jmp difficulty_done
    
select_hard:
    mov currentDifficulty, 3
    mov esi, OFFSET hardTexts
    mov ecx, hardCount
    call SelectRandomText
    jmp difficulty_done
    
select_random:
    call Randomize
    mov eax, 3
    call RandomRange
    inc eax
    
    cmp eax, 1
    je select_easy
    cmp eax, 2
    je select_medium
    jmp select_hard
    
difficulty_done:
    popad
    ret
SelectDifficulty ENDP

SelectRandomText PROC
    pushad
    
    call Randomize
    mov eax, ecx
    call RandomRange
    
    mov ebx, 4
    mul ebx
    add esi, eax
    mov eax, [esi]
    mov currentText, eax
    
    popad
    ret
SelectRandomText ENDP

RunTypingTest PROC
    pushad
    
    call Clrscr
    
    mov edx, OFFSET instructionMsg
    call WriteString
    call Crlf
    mov edx, OFFSET instructionMsg2
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET promptMsg
    call WriteString
    call Crlf
    mov edx, currentText
    call WriteString
    call Crlf
    call Crlf
    
    call GetMseconds
    mov startTime, eax
    
    mov edx, OFFSET userInput
    mov ecx, SIZEOF userInput
    call ReadString
    mov inputLength, eax
    
    call GetMseconds
    mov endTime, eax
    
    mov eax, endTime
    sub eax, startTime
    mov elapsedTime, eax
    
    call CalculateMetrics
    call DisplayResults
    call DisplayErrorAnalysis
    call DisplayWordBreakdown
    
    call Crlf
    mov edx, OFFSET separator
    call WriteString
    call Crlf
    mov edx, OFFSET pressKeyMsg
    call WriteString
    call ReadChar
    
    popad
    ret
RunTypingTest ENDP

CalculateMetrics PROC
    pushad
    
    mov edi, currentText
    call StrLength
    mov totalChars, eax
    
    mov esi, currentText
    mov edi, OFFSET userInput
    mov ecx, inputLength
    mov correctCount, 0
    mov incorrectCount, 0
    mov errorCount, 0
    mov ebx, 0
    
    cmp ecx, totalChars
    jbe compare_loop
    mov ecx, totalChars
    
compare_loop:
    cmp ecx, 0
    je compare_done
    
    mov al, [esi]
    mov dl, [edi]
    
    cmp al, dl
    jne char_incorrect
    
    inc correctCount
    jmp char_next
    
char_incorrect:
    inc incorrectCount
    push edi
    mov edi, OFFSET errorPositions
    mov eax, errorCount
    mov edx, 4
    mul edx
    add edi, eax
    mov eax, ebx
    inc eax
    mov [edi], eax
    inc errorCount
    pop edi
    
char_next:
    inc esi
    inc edi
    inc ebx
    dec ecx
    jmp compare_loop
    
compare_done:
    mov eax, inputLength
    cmp eax, totalChars
    jae no_extra_chars
    
    mov eax, totalChars
    sub eax, inputLength
    add incorrectCount, eax
    
no_extra_chars:
    mov eax, inputLength
    cmp eax, totalChars
    jbe no_extra_input
    
    mov eax, inputLength
    sub eax, totalChars
    add incorrectCount, eax
    
no_extra_input:
    mov eax, correctCount
    mov ebx, 100
    mul ebx
    mov ebx, totalChars
    cmp ebx, 0
    je accuracy_zero
    div ebx
    mov accuracy, eax
    jmp accuracy_done
    
accuracy_zero:
    mov accuracy, 0
    
accuracy_done:
    mov eax, elapsedTime
    mov ebx, 1000
    mov edx, 0
    div ebx
    mov ebx, eax
    
    cmp ebx, 0
    je skip_calculations
    
    mov eax, inputLength
    mov ebx, 60
    mul ebx
    mov ebx, 1000
    mul ebx
    mov ebx, elapsedTime
    mov edx, 0
    div ebx
    mov cpm, eax
    
    mov eax, cpm
    mov ebx, 5
    mov edx, 0
    div ebx
    mov wpm, eax
    jmp calculations_done
    
skip_calculations:
    mov cpm, 0
    mov wpm, 0
    
calculations_done:
    call CalculateWordBreakdown
    
    popad
    ret
CalculateMetrics ENDP

CalculateWordBreakdown PROC
    pushad
    
    mov correctWords, 0
    mov incorrectWords, 0
    mov wordCount, 0
    
    mov esi, currentText
    mov ecx, totalChars
    mov wordCount, 1
    
word_count_loop:
    cmp ecx, 0
    je word_count_done
    mov al, [esi]
    cmp al, ' '
    jne not_space
    inc wordCount
not_space:
    inc esi
    dec ecx
    jmp word_count_loop
    
word_count_done:
    mov eax, wordCount
    mov ebx, accuracy
    mul ebx
    mov ebx, 100
    mov edx, 0
    div ebx
    mov correctWords, eax
    
    mov eax, wordCount
    sub eax, correctWords
    mov incorrectWords, eax
    
    popad
    ret
CalculateWordBreakdown ENDP

DisplayResults PROC
    pushad
    
    call Crlf
    mov edx, OFFSET resultsMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET timeMsg
    call WriteString
    mov eax, elapsedTime
    call WriteDec
    mov edx, OFFSET millisecondsMsg
    call WriteString
    call Crlf
    
    mov edx, OFFSET totalCharsMsg
    call WriteString
    mov eax, totalChars
    call WriteDec
    call Crlf
    
    mov edx, OFFSET correctCharsMsg
    call WriteString
    mov eax, correctCount
    call WriteDec
    call Crlf
    
    mov edx, OFFSET incorrectCharsMsg
    call WriteString
    mov eax, incorrectCount
    call WriteDec
    call Crlf
    
    mov edx, OFFSET accuracyMsg
    call WriteString
    mov eax, accuracy
    call WriteDec
    mov edx, OFFSET percentMsg
    call WriteString
    call Crlf
    
    mov edx, OFFSET cpmMsg
    call WriteString
    mov eax, cpm
    call WriteDec
    call Crlf
    
    mov edx, OFFSET wpmMsg
    call WriteString
    mov eax, wpm
    call WriteDec
    call Crlf
    
    popad
    ret
DisplayResults ENDP

DisplayErrorAnalysis PROC
    pushad
    
    cmp errorCount, 0
    je no_errors
    
    call Crlf
    mov edx, OFFSET errorAnalysisMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET errorPosMsg
    call WriteString
    
    mov esi, OFFSET errorPositions
    mov ecx, errorCount
    mov ebx, 0
    
error_display_loop:
    cmp ecx, 0
    je error_display_done
    
    mov eax, [esi]
    call WriteDec
    
    dec ecx
    cmp ecx, 0
    je error_display_done
    
    mov edx, OFFSET commaSpace
    call WriteString
    
    add esi, 4
    jmp error_display_loop
    
error_display_done:
    call Crlf
    jmp error_analysis_done
    
no_errors:
    call Crlf
    mov edx, OFFSET errorAnalysisMsg
    call WriteString
    call Crlf
    call Crlf
    
error_analysis_done:
    popad
    ret
DisplayErrorAnalysis ENDP

DisplayWordBreakdown PROC
    pushad
    
    call Crlf
    mov edx, OFFSET wordBreakdownMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET wordTotalMsg
    call WriteString
    mov eax, wordCount
    call WriteDec
    call Crlf
    
    mov edx, OFFSET wordCorrectMsg
    call WriteString
    mov eax, correctWords
    call WriteDec
    call Crlf
    
    mov edx, OFFSET wordIncorrectMsg
    call WriteString
    mov eax, incorrectWords
    call WriteDec
    call Crlf
    
    popad
    ret
DisplayWordBreakdown ENDP

UpdateStatistics PROC
    pushad
    
    inc totalTests
    
    mov eax, wpm
    cmp eax, bestWpm
    jbe check_accuracy
    mov bestWpm, eax
    
check_accuracy:
    mov eax, accuracy
    cmp eax, bestAccuracy
    jbe update_sums
    mov bestAccuracy, eax
    
update_sums:
    mov eax, wpm
    add totalWpmSum, eax
    mov eax, accuracy
    add totalAccuracySum, eax
    
    popad
    ret
UpdateStatistics ENDP

DisplayStatistics PROC
    pushad
    
    call Clrscr
    mov edx, OFFSET statsMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET totalTestsMsg
    call WriteString
    mov eax, totalTests
    call WriteDec
    call Crlf
    
    cmp totalTests, 0
    je no_stats
    
    mov edx, OFFSET bestWpmMsg
    call WriteString
    mov eax, bestWpm
    call WriteDec
    call Crlf
    
    mov edx, OFFSET bestAccuracyMsg
    call WriteString
    mov eax, bestAccuracy
    call WriteDec
    mov edx, OFFSET percentMsg
    call WriteString
    call Crlf
    
    mov edx, OFFSET avgWpmMsg
    call WriteString
    mov eax, totalWpmSum
    mov ebx, totalTests
    mov edx, 0
    div ebx
    call WriteDec
    call Crlf
    
    mov edx, OFFSET avgAccuracyMsg
    call WriteString
    mov eax, totalAccuracySum
    mov ebx, totalTests
    mov edx, 0
    div ebx
    call WriteDec
    mov edx, OFFSET percentMsg
    call WriteString
    call Crlf
    jmp stats_done
    
no_stats:
    mov edx, OFFSET promptMsg
    call WriteString
    call Crlf
    
stats_done:
    call Crlf
    mov edx, OFFSET separator
    call WriteString
    call Crlf
    mov edx, OFFSET pressKeyMsg
    call WriteString
    call ReadChar
    
    popad
    ret
DisplayStatistics ENDP

ResetStatistics PROC
    pushad
    
    call Clrscr
    mov edx, OFFSET resetConfirmMsg
    call WriteString
    
    call ReadChar
    call WriteChar
    call Crlf
    call Crlf
    
    cmp al, 'Y'
    je do_reset
    cmp al, 'y'
    je do_reset
    jmp reset_done
    
do_reset:
    mov totalTests, 0
    mov bestWpm, 0
    mov bestAccuracy, 0
    mov totalWpmSum, 0
    mov totalAccuracySum, 0
    mov achievement50Wpm, 0
    mov achievement100Wpm, 0
    mov achievementPerfect, 0
    mov achievement10Tests, 0
    mov achievement50Tests, 0
    mov achievement90Accuracy, 0
    
    mov edx, OFFSET resetSuccessMsg
    call WriteString
    call Crlf
    
reset_done:
    call Crlf
    mov edx, OFFSET pressKeyMsg
    call WriteString
    call ReadChar
    
    popad
    ret
ResetStatistics ENDP

SelectTimedDuration PROC
    pushad
    
    call Clrscr
    mov edx, OFFSET timedTestMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET timeSelectMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET time30
    call WriteString
    call Crlf
    
    mov edx, OFFSET time60
    call WriteString
    call Crlf
    
    mov edx, OFFSET time120
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET timeChoice
    call WriteString
    
    call ReadChar
    mov choice, al
    call WriteChar
    call Crlf
    call Crlf
    
    cmp choice, '1'
    je set_30
    cmp choice, '2'
    je set_60
    cmp choice, '3'
    je set_120
    
    mov timedDuration, 60
    jmp duration_done
    
set_30:
    mov timedDuration, 30
    jmp duration_done
    
set_60:
    mov timedDuration, 60
    jmp duration_done
    
set_120:
    mov timedDuration, 120
    
duration_done:
    popad
    ret
SelectTimedDuration ENDP

RunRealtimeTypingTest PROC
    pushad
    
    call Clrscr
    
    mov edx, OFFSET realtimeMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET realtimeInstruction
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET promptMsg
    call WriteString
    call Crlf
    mov edx, currentText
    call WriteString
    call Crlf
    call Crlf
    
    mov edi, currentText
    call StrLength
    mov totalChars, eax
    
    mov edi, OFFSET userInput
    mov ecx, 500
    mov al, 0
    rep stosb
    
    mov inputLength, 0
    mov esi, currentText
    mov edi, OFFSET userInput
    
    call GetMseconds
    mov startTime, eax
    
realtime_loop:
    mov eax, inputLength
    cmp eax, totalChars
    jae realtime_done
    
    call Crlf
    mov edx, OFFSET progressMsg
    call WriteString
    mov eax, inputLength
    call WriteDec
    mov edx, OFFSET slashMsg
    call WriteString
    mov eax, totalChars
    call WriteDec
    call Crlf
    
    mov edx, OFFSET currentCharMsg
    call WriteString
    mov al, [esi]
    call WriteChar
    call Crlf
    call Crlf
    
    call ReadChar
    
    cmp al, 0Dh
    je realtime_done
    
    cmp al, 08h
    je handle_backspace
    
    mov [edi], al
    call WriteChar
    
    mov bl, [esi]
    cmp al, bl
    je char_correct_realtime
    
    mov edx, OFFSET errorIndicator
    call WriteString
    jmp char_next_realtime
    
char_correct_realtime:
    mov edx, OFFSET correctIndicator
    call WriteString
    
char_next_realtime:
    inc esi
    inc edi
    inc inputLength
    call Crlf
    jmp realtime_loop
    
handle_backspace:
    cmp inputLength, 0
    je realtime_loop
    
    dec esi
    dec edi
    dec inputLength
    mov byte ptr [edi], 0
    call Crlf
    jmp realtime_loop
    
realtime_done:
    call GetMseconds
    mov endTime, eax
    
    mov eax, endTime
    sub eax, startTime
    mov elapsedTime, eax
    
    call CalculateMetrics
    call DisplayResults
    call DisplayErrorAnalysis
    call DisplayWordBreakdown
    
    call Crlf
    mov edx, OFFSET separator
    call WriteString
    call Crlf
    mov edx, OFFSET pressKeyMsg
    call WriteString
    call ReadChar
    
    popad
    ret
RunRealtimeTypingTest ENDP

RunTimedTypingTest PROC
    pushad
    
    call Clrscr
    
    mov edx, OFFSET countdownMsg
    call WriteString
    mov eax, 3
countdown_loop:
    call WriteDec
    call Crlf
    push eax
    mov eax, 1000
    call Delay
    pop eax
    dec eax
    cmp eax, 0
    jg countdown_loop
    
    call Clrscr
    
    mov edx, OFFSET instructionMsg
    call WriteString
    call Crlf
    mov edx, OFFSET timeRemainingMsg
    call WriteString
    mov eax, timedDuration
    call WriteDec
    mov edx, OFFSET secondsRemaining
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET promptMsg
    call WriteString
    call Crlf
    mov edx, currentText
    call WriteString
    call Crlf
    call Crlf
    
    mov eax, timedDuration
    mov ebx, 1000
    mul ebx
    mov timeRemaining, eax
    
    call GetMseconds
    mov startTime, eax
    
    mov edi, OFFSET userInput
    mov ecx, 500
    mov al, 0
    rep stosb
    mov inputLength, 0
    
    mov edx, OFFSET userInput
    mov ecx, SIZEOF userInput
    call ReadString
    mov inputLength, eax
    
    call GetMseconds
    mov ebx, eax
    sub ebx, startTime
    mov eax, timeRemaining
    cmp ebx, eax
    jae time_up
    jmp timed_done
    
time_up:
    call Crlf
    call Crlf
    mov edx, OFFSET timeUpMsg
    call WriteString
    call Crlf
    
timed_done:
    call GetMseconds
    mov endTime, eax
    
    mov eax, endTime
    sub eax, startTime
    mov elapsedTime, eax
    
    mov eax, timedDuration
    mov ebx, 1000
    mul ebx
    cmp elapsedTime, eax
    jbe use_actual_time
    mov elapsedTime, eax
    
use_actual_time:
    call CalculateMetrics
    call DisplayResults
    call DisplayErrorAnalysis
    call DisplayWordBreakdown
    
    call Crlf
    mov edx, OFFSET separator
    call WriteString
    call Crlf
    mov edx, OFFSET pressKeyMsg
    call WriteString
    call ReadChar
    
    popad
    ret
RunTimedTypingTest ENDP

CheckAchievements PROC
    pushad
    
    mov eax, wpm
    cmp eax, 50
    jb check_100wpm
    cmp achievement50Wpm, 1
    je check_100wpm
    mov achievement50Wpm, 1
    call DisplayAchievementUnlocked
    mov edx, OFFSET ach50Wpm
    call WriteString
    call Crlf
    call Crlf
    
check_100wpm:
    mov eax, wpm
    cmp eax, 100
    jb check_perfect
    cmp achievement100Wpm, 1
    je check_perfect
    mov achievement100Wpm, 1
    call DisplayAchievementUnlocked
    mov edx, OFFSET ach100Wpm
    call WriteString
    call Crlf
    call Crlf
    
check_perfect:
    mov eax, accuracy
    cmp eax, 100
    jb check_10tests
    cmp achievementPerfect, 1
    je check_10tests
    mov achievementPerfect, 1
    call DisplayAchievementUnlocked
    mov edx, OFFSET achPerfect
    call WriteString
    call Crlf
    call Crlf
    
check_10tests:
    mov eax, totalTests
    cmp eax, 10
    jb check_50tests
    cmp achievement10Tests, 1
    je check_50tests
    mov achievement10Tests, 1
    call DisplayAchievementUnlocked
    mov edx, OFFSET ach10Tests
    call WriteString
    call Crlf
    call Crlf
    
check_50tests:
    mov eax, totalTests
    cmp eax, 50
    jb check_90accuracy
    cmp achievement50Tests, 1
    je check_90accuracy
    mov achievement50Tests, 1
    call DisplayAchievementUnlocked
    mov edx, OFFSET ach50Tests
    call WriteString
    call Crlf
    call Crlf
    
check_90accuracy:
    mov eax, accuracy
    cmp eax, 90
    jb achievements_done
    cmp achievement90Accuracy, 1
    je achievements_done
    mov achievement90Accuracy, 1
    call DisplayAchievementUnlocked
    mov edx, OFFSET ach90Accuracy
    call WriteString
    call Crlf
    call Crlf
    
achievements_done:
    popad
    ret
CheckAchievements ENDP

DisplayAchievementUnlocked PROC
    pushad
    call Crlf
    mov edx, OFFSET achievementUnlocked
    call WriteString
    call Crlf
    popad
    ret
DisplayAchievementUnlocked ENDP

DisplayAchievements PROC
    pushad
    
    call Clrscr
    mov edx, OFFSET achievementMsg
    call WriteString
    call Crlf
    call Crlf
    
    mov edx, OFFSET achievementListMsg
    call WriteString
    call Crlf
    call Crlf
    
    cmp achievement50Wpm, 1
    je show_50wpm_unlocked
    mov edx, OFFSET ach50WpmLocked
    call WriteString
    call Crlf
    jmp show_100wpm
show_50wpm_unlocked:
    mov edx, OFFSET ach50Wpm
    call WriteString
    call Crlf
    
show_100wpm:
    cmp achievement100Wpm, 1
    je show_100wpm_unlocked
    mov edx, OFFSET ach100WpmLocked
    call WriteString
    call Crlf
    jmp show_perfect
show_100wpm_unlocked:
    mov edx, OFFSET ach100Wpm
    call WriteString
    call Crlf
    
show_perfect:
    cmp achievementPerfect, 1
    je show_perfect_unlocked
    mov edx, OFFSET achPerfectLocked
    call WriteString
    call Crlf
    jmp show_10tests
show_perfect_unlocked:
    mov edx, OFFSET achPerfect
    call WriteString
    call Crlf
    
show_10tests:
    cmp achievement10Tests, 1
    je show_10tests_unlocked
    mov edx, OFFSET ach10TestsLocked
    call WriteString
    call Crlf
    jmp show_50tests
show_10tests_unlocked:
    mov edx, OFFSET ach10Tests
    call WriteString
    call Crlf
    
show_50tests:
    cmp achievement50Tests, 1
    je show_50tests_unlocked
    mov edx, OFFSET ach50TestsLocked
    call WriteString
    call Crlf
    jmp show_90accuracy
show_50tests_unlocked:
    mov edx, OFFSET ach50Tests
    call WriteString
    call Crlf
    
show_90accuracy:
    cmp achievement90Accuracy, 1
    je show_90accuracy_unlocked
    mov edx, OFFSET ach90AccuracyLocked
    call WriteString
    call Crlf
    jmp achievements_display_done
show_90accuracy_unlocked:
    mov edx, OFFSET ach90Accuracy
    call WriteString
    call Crlf
    
achievements_display_done:
    call Crlf
    mov edx, OFFSET separator
    call WriteString
    call Crlf
    mov edx, OFFSET pressKeyMsg
    call WriteString
    call ReadChar
    
    popad
    ret
DisplayAchievements ENDP

END main