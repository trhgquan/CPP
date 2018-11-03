; hv.cpp test generator

Global $max = InputBox("How many test?", "", "")

Global $string
FileDelete(@ScriptDir & '\hv.inp')
Global $file = FileOpen(@ScriptDir & '\hv.inp', 1)

FileWrite($file, $max & @CRLF)

For $lalala = 1 To $max step 1
	Global $Rand = Random(10,100,1)

	FileWrite($file, $Rand & @CRLF)
	For $i = 1 To $Rand * 2 Step 1
		$string = '';
		For $j = 1 To $Rand * 2 Step 1
			$string &= String(Random(0,1,1)) & @TAB
		Next
		FileWrite($file, $string & @CRLF);
	Next
Next

FileClose($file)
