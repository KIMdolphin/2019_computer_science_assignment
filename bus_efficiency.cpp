#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#define UP 2
#define DOWN 3
#define ENTER 4


void ui();
void title();
void gotoxy(int, int);
int menu();
int keyControl();

int main(){
	ui();
	title();
	menu();
}

void ui() {
	system("mode con cols=200 lines=120 | title bus efficiency");
}

void title() {
	printf("\n");
	printf(" ■■■■■■■    ■■       ■■ ■■■■■■■\n");
	printf(" ■■        ■■ ■■        ■■ ■■■■■■■■\n");
	printf(" ■■        ■■ ■■        ■■ ■■           \n");
	printf(" ■■■■■■■   ■■        ■■ ■■■■■■■■\n");
	printf(" ■■          ■ ■■■      ■■ ■■■■■■■■\n");
	printf(" ■■          ■ ■■■      ■■            ■■\n");
	printf(" ■■        ■■ ■■■      ■■ ■■■■■■■\n");
	printf(" ■■■■■■■     ■■■■■■■ ■■■■■■ \n\n");
	
	printf(" ■■■■■■■ ■■■■■■■ ■■■■■■■ ■■■■■■■ ■■■■■■■ ■■■■■■■ ■■■■■■■ ■■■■      ■ ■■■■■■■ ■■     ■■\n");
	printf(" ■■           ■■           ■■                ■■      ■■                ■■      ■■           ■■■■      ■ ■■           ■■    ■■\n");
	printf(" ■■           ■■■■■■■ ■■■■■■■      ■■      ■■                ■■      ■■           ■■  ■■    ■ ■■             ■■ ■■\n");
	printf(" ■■■■■■■ ■■■■■■   ■■■■■■        ■■      ■■                ■■      ■■■■■■■ ■■   ■■   ■ ■■             ■■ ■■\n");
	printf(" ■■■■■■■ ■■           ■■                ■■      ■■                ■■      ■■■■■■■ ■■   ■■   ■ ■■               ■■\n");
	printf(" ■■           ■■           ■■                ■■      ■■                ■■      ■■           ■■    ■■  ■ ■■               ■■\n");
	printf(" ■■           ■■           ■■           ■■■■■■■ ■■■■■■■ ■■■■■■■ ■■           ■■     ■■ ■ ■■■■■■■     ■■\n");
	printf(" ■■■■■■■ ■■           ■■           ■■■■■■■ ■■■■■■■ ■■■■■■■ ■■■■■■■ ■■      ■■■ ■■■■■■■     ■■ \n\n");
	printf("         developed by 2-1-8 chaerin KIM");
}

void gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menu(){
	int x=100;
	int y=20;
	gotoxy(x-5,y);
	printf("> |");
	gotoxy(x,y);
	printf("프로그램 설명");
	gotoxy(x+15,y);
	printf("|");
	gotoxy(x-3,y+2);
	printf("|");
	gotoxy(x,y+2);
	printf("프로그램 시작");
	gotoxy(x+15,y+2);
	printf("|");
	gotoxy(x-3,y+4);
	printf("|");
	gotoxy(x+4,y+4);
	printf("종료");
	gotoxy(x+15,y+4);
	printf("|");
	while (1) { 
		int ch = keyControl();
        switch (ch) {           
            case DOWN: {
        		if(y<24){
        			gotoxy(x-5, y);
        			printf(" ");
        			y=y+2;
        			gotoxy(x-5, y);
					printf(">"); 
			 }
				break;
			}
            case UP: {
                if(y>20){
                	gotoxy(x-5, y);
        			printf(" ");
        			y=y-2;
        			gotoxy(x-5, y);
					printf(">"); 
				}
				break;
            }
            case ENTER: {
            	gotoxy(x+17,y);
            	printf("선택!");
				break;
			}
        }
    }
}



int keyControl() {
	char temp = _getch();
	if (temp == 's' || temp == 'S'){
		return DOWN;
	}
	else if ( temp == 'w' || temp == 'W'){
		return UP;
	}
	else if (temp == ' '){
		return ENTER;
	}
}
