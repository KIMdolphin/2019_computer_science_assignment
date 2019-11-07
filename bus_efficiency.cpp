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
	system("mode con cols=200 lines=120 | title bus efficiency(�����̾߱�)");
}

void title() {
	printf("\n");
	printf(" ��������    ���       ��� ��������\n");
	printf(" ���        ��� ���        ��� ���������\n");
	printf(" ���        ��� ���        ��� ���           \n");
	printf(" ��������   ���        ��� ���������\n");
	printf(" ���          �� ����      ��� ���������\n");
	printf(" ���          �� ����      ���            ���\n");
	printf(" ���        ��� ����      ��� ��������\n");
	printf(" ��������     �������� ������� \n\n");
	
	printf(" �������� �������� �������� �������� �������� �������� �������� �����      �� �������� ���     ���\n");
	printf(" ���           ���           ���                ���      ���                ���      ���           �����      �� ���           ���    ���\n");
	printf(" ���           �������� ��������      ���      ���                ���      ���           ���  ���    �� ���             ��� ���\n");
	printf(" �������� �������   �������        ���      ���                ���      �������� ���   ���   �� ���             ��� ���\n");
	printf(" �������� ���           ���                ���      ���                ���      �������� ���   ���   �� ���               ���\n");
	printf(" ���           ���           ���                ���      ���                ���      ���           ���    ���  �� ���               ���\n");
	printf(" ���           ���           ���           �������� �������� �������� ���           ���     ��� �� ��������     ���\n");
	printf(" �������� ���           ���           �������� �������� �������� �������� ���      ���� ��������     ��� \n\n");
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
	printf("���α׷� ����");
	gotoxy(x+15,y);
	printf("|");
	gotoxy(x-3,y+2);
	printf("|");
	gotoxy(x,y+2);
	printf("���α׷� ����");
	gotoxy(x+15,y+2);
	printf("|");
	gotoxy(x-3,y+4);
	printf("|");
	gotoxy(x+4,y+4);
	printf("����");
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
            	printf("����!");
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
					printf("���ʿ� �Ұ����ؿ�");
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
	printf(" ���������������������������������������������������������������������\n");
	printf(" ���������������������������������������������������������������������\n");
	for(int i=0; i<25; i++){
		gotoxy(132,2+i);
		printf(" ���");
		gotoxy(0,2+i);
	    printf(" ���");
	}
	gotoxy(128,19);
	printf(" ���");
	gotoxy(128,25);
	printf(" ���");
	for(int i=0; i<7; i++){
		gotoxy(124,19+i);
		printf(" ���");
	}
	for(int i=0; i<15; i++){
		gotoxy(110,2+i);
	    printf(" ���");
	}
	printf("�����������");
	gotoxy(0,27);
	printf(" ���������������������������������������������������������������������\n");
	printf(" ����                  ���������������                                        ���������������\n");
	printf(" ���                      ������������                                               ������������\n");
	printf("                            ����������                                                   �����������\n");
	
}
void description() {
	bus();
	gotoxy(7,10);
	printf("��縦 ���� ��..");
	gotoxy(7,12);
	printf("������ �� ���¶� �ð��� ���߾� �����ϴµ� �ٷ� ���� ������ ����.");
	gotoxy(7,14);
	printf("�ѱ��������� �ٷ� õ���� ��������� ���� ������ 7�� ���Ұ�,");
	gotoxy(7,16);
	printf("��û���� ���� ������ �� �����Ѵ�.\n");
	gotoxy(7,18);
	printf("���� ������ ��ٸ��� ���� ������,");
	gotoxy(7,19);
	printf("��û���� ���� ��û���� õ���� ���������� ���� ������ ����Ÿ�� �� �� ������?");
	gotoxy(80, 25);
	printf("space�� ���� ���� ȭ������..");
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
	printf("space�� ������ ���� ȭ������ �̵��մϴ�..");
	gotoxy(7,10);
	printf("���� ���� �ð���?");
	gotoxy(7,11);
	time(); 
	gotoxy(7,13);
	int after; 
	printf("���ݺ��� �� �� �� �Ŀ� ����ϳ���? :");
	gotoxy(47,13);
	printf("(��)");
	gotoxy(45,13); 
	scanf("%d", &after); 
	gotoxy(7,15);
	char run[10];
	printf("�����忡 �پ����? (��/�ƴϿ�) : ");
	scanf("%s", run); 
	gotoxy(7,16);
	if(strcmp(run, "��") == 0){
		printf(">> �پ�Ƿ� 2���� �ҿ�˴ϴ�"); 
	} 
	else{
		printf(">> �ɾ�Ƿ� 4���� �ҿ�˴ϴ�"); 
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
  		strcpy(week, "��");
		break;
	  }
	case 1: {
  		strcpy(week, "��");
		break;
	  }
	case 2: {
  		strcpy(week, "ȭ");
		break;
	  }
	case 3: {
  		strcpy(week, "��");
		break;
	  }
	case 4: {
  		strcpy(week, "��");
		break;
	  }
	case 5: {
  		strcpy(week, "��");
		break;
	  }
	case 6: {
  		strcpy(week, "��");
		break;
	  }            
  }
  printf("%d-%d-%d (%s) %d:%d:%d\n",
         tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, week, tm.tm_hour, tm.tm_min, tm.tm_sec);
 
}
