#include"DxLib.h"
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
	ChangeWindowMode(TRUE), DxLib_Init(); SetDrawScreen(DX_SCREEN_BACK);

	int picture = LoadGraph("�ϐ��^�ƕ\�L�ɂ���.bmp");

	//�����^�̕ϐ��ɂ��āBnormal,&normal�Ƃ����\���̗]�n������B
	int normal = 10;

	//�����^��normal�ϐ��̃n���h�����n���h���^��*handle�ϐ��ɓ����Bhandle,*handle,&handle�Ƃ����\���̗]�n������B
	int *handle = &normal;


	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		DrawFormatString(0, 50, GetColor(255, 255, 255), "�����^�̕ϐ�normal�̐��l��%d�Ƃ��܂����B\n �����normal�̃A�h���X�̐��l(&normal)��%d�ƂȂ�܂����B",normal, &normal);
		DrawFormatString(0, 100, GetColor(255, 255, 255), "normal�̃A�h���X�ł���&normal�̐��l���n���h���^��*handle�ɕۑ����܂���");
		DrawFormatString(0, 150, GetColor(255, 255, 255), "�Ȃ̂ł������handle�̐��l��%d�ƂȂ�܂��B",handle);
		DrawFormatString(0, 200, GetColor(255, 255, 255), "%d(handle)���Ɏ��[����Ă��鐔�l��%d(*handle)�ł���܂��I", handle, *handle);
		DrawFormatString(0, 250, GetColor(255, 255, 255), "�]�k�ł��������handle�̃A�h���X�̐��l��%d(&handle)�ƂȂ�܂����B",&handle);

		DrawGraph(0, 340, picture, TRUE);
	}

	DxLib_End();
	return 0;

}


