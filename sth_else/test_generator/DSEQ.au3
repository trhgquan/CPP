Global $file = @ScriptDir & '\DSEQ.inp'
FileOpen($file, 2)
Global $string

Global $max = Random(5, 1000, 1)

FileWrite($file, $max & @CRLF)

For $i = 1 To $max Step 1
	$string &= String(Random(-10^9, 10^9, 1)) & @TAB
Next

FileWrite($file, $string)
FileClose($file)


