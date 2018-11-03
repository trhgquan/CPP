Global $file = @ScriptDir & '\COIN.inp'
FileOpen($file, 2)
Global $string
For $i = 1 To 4 Step 1
	$string = ''
	For $j = 1 To 4 Step 1
		If (Random(0,1,1) == 0) Then
			$string &= 'b'
		Else
			$string &= 'w'
		EndIf
	Next
	FileWrite($file, $string & @CRLF)
Next
$data = FileRead($file)
ClipPut($data)
FileClose($file)


