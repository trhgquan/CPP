; hv.cpp test generator

Global $max = Random(1, 20, 1)

ConsoleWrite($max & @CRLF)

Global $string
FileDelete(@ScriptDir & '\hv.inp')
Global $file = FileOpen(@ScriptDir & '\hv.inp', 1)

FileWrite($file, $max & @CRLF)

For $lalala = 1 To $max step 1
	Global $Rand = 1Random(1,1800,1)
	ConsoleWrite($Rand & @CRLF)

	FileWrite($file, $Rand & @CRLF)
	For $i = 1 To $Rand * 2 Step 1
		$string = '';
		For $j = 1 To $Rand * 2 Step 1
			$string &= String(Random(0,1,1)) & @TAB
		Next
		FileWrite($file, $string & @CRLF);
	Next
	ConsoleWrite("+> Success: " & $lalala & "/" & $max & @CRLF)
Next

FileClose($file)
