@echo off
echo �y�\��J�n�E�I�����o�b�`�̎Q�l��z
echo �E�^�C�~���O��ExecOnStartRec=�\��J�n����AExecOnEndRec=�\��I����2�b��
echo �E�o�b�N�O���E���h�ŋN������̂Ńo�b�`�������Ɏ��̗\�񂪎n�܂邱�Ƃ�����
echo �E�u�A������\��C�x���g��1�t�@�C���ɂ܂Ƃ߂�v�̂Ƃ��͍Ō�̗\��̏I�����
echo   �N������B���̂Ƃ��C�x���g���Ȃǂ͍ŏ��̗\��̂��̂��i�[�����
echo �E�J�����g�f�B���N�g����TVTest.exe�̂���ꏊ
echo �E�e����͊��ϐ��Ɋi�[�����
echo �E�o�b�`�łȂ��Ă�����
echo   (��)ExecOnEndRec=""C:\windows\system32\wscript" "Plugins\TTRec_Exec.vbs""
echo.
echo ���s�^�C�~���O       %TTRecExec%
echo �\��J�n����         %TTRecStartTime%
echo �\��̒���           %TTRecDuration%
echo OriginalNetworkID    %TTRecONID%
echo TransportStreamID    %TTRecTSID%
echo ServiceID            %TTRecSID%
echo EventID              %TTRecEID%
echo.
echo ���ȉ��͗\��J�n���ƏI�����̃J�E���g���̍����狁�߂�����
echo ���\��J�n����10�b�ȓ��̃J�E���g�͔��f����Ȃ�
echo ���v�����s(�G���[�J�E���g���Z�b�g�����Ƃ��Ȃ�)�̂Ƃ�-1�ɂȂ�
echo �h���b�v��           %TTRecDrops%
echo �G���[��             %TTRecErrors%
echo �X�N�����u����       %TTRecScrambles%
echo.
echo ���ȉ��́u���邾���v�̂Ƃ��Z�b�g����Ȃ�
echo ���R�}���h���C�������ɂ��i�[�����(�o�b�`�ł͂������̂ق����֗�)
echo �t�@�C���̃t���p�X   "%TTRecFilePath%"
echo �R�}���h���C������   "%~1"
echo.
echo ���ȉ���EPG��񂻂̂��̂Ȃ̂Ńt�@�C�����Ɏg�p�ł��Ȃ��L�����܂ނ�������Ȃ�
echo �T�[�r�X��           "%TTRecServiceName%"
echo �C�x���g�J�n����     %TTRecEventStartTime%
echo �C�x���g�̒���       %TTRecEventDuration%
echo �C�x���g��           "%TTRecEventName%"
setlocal EnableDelayedExpansion
echo (�C�x���g�e�L�X�g)
echo "!TTRecEventText!"
echo (�C�x���g�g���e�L�X�g)
echo "!TTRecEventExText!"
endlocal
echo.
echo �y�t�@�C�����ɃG���[�J�E���g��t�����z
echo if "%TTRecExec%"=="EndRec" if exist "%~1" rename "%~1" "%~n1-D%TTRecDrops%E%TTRecErrors%S%TTRecScrambles%%~x1"
pause
