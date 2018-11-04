Global $file = @ScriptDir & '\BCLKCOUN.inp'

FileOpen($file, 2)

Global $N, $M, $string

$N = Random(10, 1000, 1)
$M = Random(10, 1000, 1)


FileWrite($file, $N & @TAB & $M & @CRLF)
For $i = 1 To $N Step 1
	$string = ''
	For $j = 1 To $M Step 1
		if (Random(0,1,1) == 1) Then
			$string &= 'W'
		Else
			$string &= '.'
		endif
	Next
	FileWrite($file, $string & @CRLF)
Next

FileClose($string)