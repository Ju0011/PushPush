#pragma once
#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <Digitalv.h>   

/*
MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;
*/


class Sound
{
public:
	
	/*
	void mp3Play() {
		int dwID;
		openBgm.lpstrElementName = L"BGM.mp3"; // 파일 경로 입력
		openBgm.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
		dwID = openBgm.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm);
	}
	*/

	void Play() {
		PlaySound(L"BGM.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생
	}
};

