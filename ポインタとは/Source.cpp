#include"DxLib.h"
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
	ChangeWindowMode(TRUE), DxLib_Init(); SetDrawScreen(DX_SCREEN_BACK);

	int picture = LoadGraph("変数型と表記について.bmp");

	//整数型の変数について。normal,&normalという表現の余地がある。
	int normal = 10;

	//整数型のnormal変数のハンドルをハンドル型の*handle変数に入れる。handle,*handle,&handleという表現の余地がある。
	int *handle = &normal;


	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		DrawFormatString(0, 50, GetColor(255, 255, 255), "整数型の変数normalの数値を%dとしました。\n そんなnormalのアドレスの数値(&normal)は%dとなりました。",normal, &normal);
		DrawFormatString(0, 100, GetColor(255, 255, 255), "normalのアドレスである&normalの数値をハンドル型の*handleに保存しました");
		DrawFormatString(0, 150, GetColor(255, 255, 255), "なのでもちろんhandleの数値は%dとなります。",handle);
		DrawFormatString(0, 200, GetColor(255, 255, 255), "%d(handle)内に収納されている数値は%d(*handle)であります！", handle, *handle);
		DrawFormatString(0, 250, GetColor(255, 255, 255), "余談ですがそんなhandleのアドレスの数値は%d(&handle)となりました。",&handle);

		DrawGraph(0, 340, picture, TRUE);
	}

	DxLib_End();
	return 0;

}


