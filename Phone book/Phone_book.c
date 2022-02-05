//2022-02-05
//삭제,정렬기능 미구현 제작시간 1시간30분  

#include <stdio.h>
#include <stdlib.h>


typedef struct phonebook{
	char name[10];
	char num[20];
}Phone;

void insertdata(void)	//정보를입력하는 함수 
{
	Phone input;
	char exit;
	FILE *fp = fopen("전화번호부.txt", "at");
	if(fp == NULL)
	{
		printf("파일오픈에러 \n");
		return -1;
	}
	while(1)
	{
		fputs("이름과 전화번호를 입력해주세요 (EX)홍길동 010-1234-1234) \n", stdout);
		fputs("이름과 전화번호 : ", stdout);
		scanf("%s %s",input.name, input.num);
		fputs(input.name, fp);
		fputc(' ', fp);
		fputs(input.num, fp);
		fputc('\n', fp);
		getchar();
		fputs("돌아가려면 n을 입력하세요 : ", stdout);
		scanf("%c", &exit);
		getchar();
		system("cls");
		
		if(exit == 'n' || exit == 'N')
			break; 
	}
	
	fclose(fp);
	return;
}
/*
void deletedata()	//정보를 삭제하는 함수  
{
	Phone buf[100];
	FILE *fp1 = fopen("전화번호부.txt", "rt");
	buf = fp1; 
	FILE *fp2 = fopen("전화번호부.txt", "wt");
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("파일오픈에러 \n");
		return -1;
	}
}
*/
void searchdata(void)	//이름으로 검색하는 함수 
{
	char search[10];
	char buf[10];
	
	FILE *fp = fopen("전화번호부.txt", "rt");
	if(fp == NULL)
	{
		printf("파일오픈에러 \n");
		return -1;
	}
	printf("검색할 이름을 입력하세요 : ");
	scanf("%s", search);
	getchar();
	while(feof(fp) == 0)	//파일끝까지도달하지 않았을때 실행 
	{
		fscanf(fp, "%s", buf);
		if(strcmp(buf, search) == 0)
		{
			printf("%s ",buf);	//이름출력 
			fscanf(fp, "%s", buf);
			printf("%s \n\n", buf);	//전화번호출력 
			break;
		}
	}
	fclose(fp);
	system("PAUSE");
	system("cls");
	return;
}

void print_all(void)	//전화번호부를 출력시키는 함수 
{
	char ch;
	FILE *fp = fopen("전화번호부.txt", "rt");
	if(fp == NULL)
	{
		printf("파일오픈에러 \n");
		return -1;
	}
	while(feof(fp) == 0)	//파일끝까지도달하지 않았을때 실행 
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	fclose(fp);
	printf("\n");
	system("PAUSE");
	system("cls");
	return;
}

int main(void)
{
	int inputnum;
	while(1)
	{
		printf("--------전화번호부-------- \n");
		printf("1.입력 \n2.삭제 \n3.검색 \n4.전체출력 \n5.정렬 \n6.종료\n");
		printf("\n\n번호를 선택해주세요 : ");
		scanf("%d", &inputnum);
		getchar();
		system("cls");
		
		switch(inputnum){
			
			case 1:
			{
				insertdata();
				break;
			}
			
			case 2:
			{
			//	deletedata();
				break;
			}
				
			case 3:
			{
				searchdata();
				break;
			}
				
			case 4:
			{
				print_all();
				break;		
			}
				
			case 6:
				return 0; 
				
		}
	}
	return 0;
}
