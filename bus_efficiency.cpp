#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>

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
int readfile();
void insert(int idx, char cho);
void append(char cho);
int now;
int inputNum;
void barobus();
void arrowbaro();
void terbus_citybus();
void arrowter(); 
void arrowcity();


//char tablelist[100];

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
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	if(strcmp(run, "네") == 0){
		printf(">> 뛰어가므로 2분이 소요됩니다"); 
		inputNum = tm.tm_hour * 60 + tm.tm_min + after +2; 
	} 
	else{
		printf(">> 걸어가므로 4분이 소요됩니다"); 
		inputNum = tm.tm_hour * 60 + tm.tm_min + after +4; 
	}
	barobus();
	terbus_citybus();
//	gotoxy(7,18);
//	readfile();
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


void terbus_citybus(){
	
	if(inputNum>1356){
		gotoxy(7,21);
		printf("환승 노선 : 불가능");
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
	
	int i(0);
	int min(9999);
	int k(0);
	int n, m, l;
	int terbus[][80] = {{364, 396, 421, 446, 471, 496, 536, 576, 616, 656, 696, 736, 776, 816, 856, 896, 936, 976, 1016, 1056, 1096, 1136, 1176, 1216, 1256, 1296, 1321, 1356}, {387, 402, 414, 426, 438, 450, 462, 474, 486, 498, 510, 522, 534, 546, 558, 570, 583, 596, 610, 624, 638, 652, 666, 680, 694, 708, 722, 736, 749, 762, 776, 790, 804, 818, 832, 846, 860, 874, 888, 902, 916, 930, 944, 958, 972, 986, 1000, 1014, 1034, 1048, 1063, 1078, 1094, 1109, 1123, 1138, 1153, 1167, 1181, 1195, 1209, 1223, 1233, 1249, 1265, 1281, 1297, 1313, 1330, 1347}, {433, 474, 496, 518, 542, 572, 622, 648, 673, 701, 757, 780, 801, 829, 874, 904, 930, 954, 1004, 1028, 1081, 1105, 1133, 1161, 1191, 1217, 1241, 1273, 1301, 1334}, {408, 456, 597, 729, 852, 978, 1057}};
	 for (int j=0; j<4; j++){
		for( i=0 ; i<56; i++)
		{
			if(0<(terbus[j][i]-inputNum) && (terbus[j][i]-inputNum)<min){
				min = terbus[j][i]-inputNum;
				k = terbus[j][i];
				n=j;
				l=i;
			}
		}
		
	}

			
	if(n==0){
		m=311;
	}
	else if (n==1){
		m=360;
	}
	else if (n==2){
		m=355;
	}
	else if (n==3){
		m=358;
	}
	gotoxy(7,21);	
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	gotoxy(7,22);
	printf("환승 노선 : %d번 %d시%d분", m, k/60, k%60);
	arrowter();
	
	inputNum=k+8;
	
	if(inputNum>1355){
		printf("불가능");
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

	min=9999;
	int citybus[][100]={{405, 445, 485, 520, 565, 595, 625, 660, 705, 765, 810, 845, 875, 905, 945, 985, 1035, 1080, 1120, 1150, 1180, 1230, 1265, 1305, 1355}, {359, 381, 436, 546, 616, 676, 761, 836, 896, 966, 1046, 1106, 1166, 1226}, {380, 396, 412, 428, 444, 460, 476, 492, 508, 524, 540, 556, 572, 589, 606, 621, 638, 655, 673, 690, 708, 728, 747, 764, 782, 800, 817, 834, 852, 868, 884, 901, 917, 936, 953, 968, 986, 1004, 1025, 1043, 1061, 1079, 1097, 1115, 1133, 1151, 1167, 1182, 1200, 1218, 1236, 1254, 1272, 1290, 1308, 1338}, {400, 425, 455, 485, 515, 535, 565, 615, 675, 705, 745, 785, 825, 865, 905, 945, 985, 1025, 1065, 1105, 1145, 1185, 1225, 1255, 1275}}; 
	 for (int j=0; j<4; j++){
		for( i=0 ; i<58; i++)
		{
			if(0<(citybus[j][i]-inputNum) && (citybus[j][i]-inputNum)<min){
				min = citybus[j][i]-inputNum;
				k = citybus[j][i];
				n=j;
				l=i;
			}
		}
		//311 360 355 358 
	}
			
	if(n==0){
		m=331;
	}
	else if (n==1){
		m=343;
	}
	else if (n==2){
		m=340;
	}
	else if (n==3){
		m=300;
	}
	printf("%d번 %d시%d분", m, k/60, k%60);
	arrowcity(); 
	printf("%d시%d분 도착 ", (k+6)/60, (k+6)%60);
}

void barobus(){
	
	if(inputNum>1344){
		gotoxy(7,21);
		printf("직행, 기본 노선 : 불가능");
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
	int i(0);
	int min(99999999);
	int d, k(0);
	int n, m, l;
	int barobus[][24] = {{409, 444, 474, 504, 554, 584, 629, 669, 719, 764, 799, 839, 879, 919, 959, 1009, 1059, 1099, 1144, 1184, 1224, 1274, 1328}, {379, 419, 454, 479, 524, 564, 602, 644, 689, 739, 779, 814, 854, 894, 934, 979, 1026, 1066, 1106, 1151, 1196, 1244, 1294, 1344}};
	for (int j=0; j<2; j++){
		for( i=0 ; i<24 ; i++)
		{
			if(barobus[j][i] > inputNum){
				d=barobus[j][i]-inputNum;
			}
			if(barobus[j][i] < inputNum){
				d=inputNum-barobus[j][i];
			}
			if(d<min){
				min = d;
				k = barobus[j][i];
				n=j;
				l=i;
			}
		}
	if(k<=inputNum){
		if(n==0){
			k=barobus[1][l+1];
			n=1;
		}
		else if (n==1){
			k=barobus[0][l];
		}
	}
	if(n==0){
		m=335;
	}
	else if (n==1){
		m=336;
	}
		}
	gotoxy(7,18);
	printf("--------------------------------");
	gotoxy(7,20);
	printf("직행 노선 : %d번 %d시%d분", m, k/60, k%60);
	arrowbaro();
	printf("%d시%d분 도착", (k+12)/60, (k+12)%60);

}

void arrowbaro(){
	Sleep(100);
	printf(" -");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("이"); 
	Sleep(100);
	printf("동");
	Sleep(100);
	printf("시");
	Sleep(100);
	printf("간");
	Sleep(100);
	printf("(12분)");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("> ");
	Sleep(100);
}

void arrowter(){
	Sleep(100);
	printf(" -");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("이"); 
	Sleep(100);
	printf("동");
	Sleep(100);
	printf("시");
	Sleep(100);
	printf("간");
	Sleep(100);
	printf("(8분)");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("> ");
	Sleep(100);
}

void arrowcity(){
	Sleep(100);
	printf(" -");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("이"); 
	Sleep(100);
	printf("동");
	Sleep(100);
	printf("시");
	Sleep(100);
	printf("간");
	Sleep(100);
	printf("(6분)");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("-");
	Sleep(100);
	printf("> ");
	Sleep(100);
}

//int readfile(){
//	Sleep(1000);
//	FILE *fps;
//	char str[100];
//	int tempnum;
//	
//	fps=fopen("table.txt", "rt");
//	
//	if(fps==NULL){
//		printf("실패\n");
//	}
//	while(feof(fps)==0){
//		fgets(str, 100, fps);
//  
//    }    
//
//	fclose(fps);
//}

