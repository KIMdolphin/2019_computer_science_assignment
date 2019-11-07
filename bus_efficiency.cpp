#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define UP 72
#define DOWN 80
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
void time();

int main(){
	ui();
	title();
	menu();
	
}

void ui() {
	system("mode con cols=200 lines=120 | title bus efficiency(버스이야기)");
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
	if (temp == 80){
		return DOWN;
	}
	else if ( temp == 72){
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
	gotoxy(128,19);
	printf(" ■■");
	gotoxy(128,25);
	printf(" ■■");
	for(int i=0; i<7; i++){
		gotoxy(124,19+i);
		printf(" ■■");
	}
	for(int i=0; i<15; i++){
		gotoxy(110,2+i);
	    printf(" ■■");
	}
	printf("■■■■■■■■■■");
	gotoxy(0,27);
	printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf(" ■■■                  ■■■■■■■■■■■■■■                                        ■■■■■■■■■■■■■■\n");
	printf(" ■■                      ■■■■■■■■■■■                                               ■■■■■■■■■■■\n");
	printf("                            ■■■■■■■■■                                                   ■■■■■■■■■■\n");
	
}
void description() {
	bus();
	gotoxy(7,10);
	printf("행사를 가는 길..");
	gotoxy(7,12);
	printf("늦잠을 잔 상태라 시간에 맞추어 가야하는데 바로 오는 버스는 없다.");
	gotoxy(7,14);
	printf("한국병원에서 바로 천수동 정류장까지 가는 버스가 7분 남았고,");
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
	gotoxy(80, 25);
	printf("space를 누르면 메인 화면으로 이동합니다..");
	gotoxy(7,10);
	printf("지금 현재 시각은?");
	gotoxy(7,11);
	time(); 
	gotoxy(7,13);
	int after; 
	printf("지금부터 약 몇 분 후에 출발하나요? :");
	gotoxy(47,13);
	printf("(분)");
	gotoxy(45,13); 
	scanf("%d", &after); 
	gotoxy(7,15);
	char run[10];
	printf("정류장에 뛰어가나요? (네/아니오) : ");
	scanf("%s", run); 
	gotoxy(7,16);
	if(strcmp(run, "네") == 0){
		printf(">> 뛰어가므로 2분이 소요됩니다"); 
	} 
	else{
		printf(">> 걸어가므로 4분이 소요됩니다"); 
	}
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
    
void time(){
	char week[10] = "\0";
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    switch(tm.tm_wday){
  	case 0: {
  		strcpy(week, "일");
		break;
	  }
	case 1: {
  		strcpy(week, "월");
		break;
	  }
	case 2: {
  		strcpy(week, "화");
		break;
	  }
	case 3: {
  		strcpy(week, "수");
		break;
	  }
	case 4: {
  		strcpy(week, "목");
		break;
	  }
	case 5: {
  		strcpy(week, "금");
		break;
	  }
	case 6: {
  		strcpy(week, "토");
		break;
	  }            
  }
  printf("%d-%d-%d (%s) %d:%d:%d\n",
         tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, week, tm.tm_hour, tm.tm_min, tm.tm_sec);
 
}
