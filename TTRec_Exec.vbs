cmdLine="Plugins\TTRec_Exec.bat"
If WScript.Arguments.Count >= 1 Then
  cmdLine=cmdLine & " """ & Wscript.Arguments(0) & """"
End If

CreateObject("WScript.Shell").Run cmdLine
'��\�����s�������Ƃ���
'CreateObject("WScript.Shell").Run cmdLine,0
