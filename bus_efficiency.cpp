#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

#define UP 2
#define DOWN 3
#define ENTER 4


void ui();
void title();
void gotoxy(int, int);
void description();
int menu();
int keyControl();
void exit(int status);
void bus();
void start();

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
            	Sleep(1000);
            	if(y==20){
            		description();
				}
				else if(y==22){
					 start();
				}
				else if(y==24){
					exit(0); 
				}
				else {
					printf("애초에 불가능해요");
				}
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

void bus(){
	system( "cls" );
	printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	for(int i=0; i<25; i++){
		gotoxy(132,2+i);
		printf(" ■■");
		gotoxy(0,2+i);
	    printf(" ■■");
	}
	for(int i=0; i<15; i++){
		gotoxy(110,2+i);
	    printf(" ■■");
	}
	printf("■■■■■■■■■■");
	gotoxy(0,28);
	printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf(" ■■■                  ■■■■■■■■■■■■■■                                        ■■■■■■■■■■■■■■\n");
	printf(" ■■                      ■■■■■■■■■■■                                               ■■■■■■■■■■■\n");
	printf("                            ■■■■■■■■■                                                   ■■■■■■■■■■\n");
	
}
void description() {
	bus();
	gotoxy(7,10);
	printf("세미나를 가는 길... ");
	gotoxy(7,12);
	printf("늦잠을 잔 상태라 시간에 맞추어 가야하는데 바로 오는 버스는 없다.");
	gotoxy(7,14);
	printf("터미널에서 바로 천수동 정류장까지 가는 버스가 7분 남았고,");
	gotoxy(7,16);
	printf("시청으로 가는 버스는 곧 도착한다.\n");
	gotoxy(7,18);
	printf("직행 버스를 기다리는 것이 빠를까,");
	gotoxy(7,19);
	printf("시청으로 가서 시청에서 천수동 정류장으로 가는 버스를 갈아타는 게 더 빠를까?");
	gotoxy(80, 25);
	printf("space를 눌러 메인 화면으로..");
	while (1) { 
		int ch = keyControl();
        switch (ch) {           
        	case ENTER: {
        		main();
				break;
			} 
			}
        }
    }
    
void start(){
	bus();
	while (1) { 
		int ch = keyControl();
        switch (ch) {           
        	case ENTER: {
        		main();
				break;
			} 
			}
        }
    }
