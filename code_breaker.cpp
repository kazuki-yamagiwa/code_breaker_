/*code_breaker.cpp :
4 桁の数をランダムに決め、各桁の数を入力し
全ての桁の数が一致するまで繰り返す。

仕様
数が被らない様にランダムな 4 桁の数を決める
4 桁入力し、ランダムに決めた数と一桁ずつ見比べる
同じ桁で、数も同じであれば「Hit」とする
Hit した桁を除いて、違う桁で数字が一致していたら「Blow」とする
「Hit」の個数と「Blow」の個数をカウントして画面に表示する
4 桁全て「Hit」になればクリア
最初にランダムな 4 桁の数を決め、クリアするまでを 1 ゲームとする
1 ゲームクリアするまでに繰り返した回数をセーブデータに保存する
セーブデータのフォーマットはテキストファイル
ゲームをクリアする度にセーブデータに回数を追加書き込みする
*/

#include <iostream>
#include<stdio.h>
#include<time.h>

int Answer[4];
int input[4];
struct  Number
{
	int a;//千の位
	int b;//百の位
	int c;//十の位
	int d;//一の位
};
int hitcount;
int blowcount;


void DispNumbers(Number num)
{
	printf("%d%d%d%d\n", num.a, num.b, num.c, num.d);
}
int main()
{
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		Answer[i] = rand() % 10;
		if (Answer[i] == Answer[i - 1] || Answer[i] == Answer[i - 2] || Answer[i] == Answer[i - 3])
			Answer[i] = rand() % 10;
	}


	Number random =
	{
		Answer[0],Answer[1],Answer[2],Answer[3]
	};
	Number Input =
	{
		input[0],input[1],input[2],input[3]
	};

	
	while (true)
	{
		scanf_s("%d%d%d%d", &input[0], &input[1], &input[2], &input[3]);
		for (int i = 0; i < 4; i++)
		{
			if (input[i] == Answer[i])
				hitcount++;
			if (input[i] != Answer[i])
			{
				if(input[i] == Answer[i+1] || input[i] == Answer[i-1])
				blowcount++;
			}
		}

		DispNumbers(random);
		printf_s("%d", hitcount);
		printf_s("%d", blowcount);
	}
	
	return 0;
}

