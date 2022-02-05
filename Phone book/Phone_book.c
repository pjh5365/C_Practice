//2022-02-05
//삭제,정렬기능 미구현 제작시간 1시간30분  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSON 100	//100명까지의 정보만저장 

typedef struct phonebook{
	char name[20];
	char num[20];
}Phone;

void Road_data(Phone *ptr, int *p_num)	//저장된 정보를 불러오는 함수 
{
	FILE *fp = fopen("전화번호부.dat", "rt");
	if(fp == NULL)
	{
	//	printf("파일오픈에러 \n");
		return -1;
	}
	while(feof(fp) == 0)
	{
		fscanf(fp, "%s %s ",ptr[*p_num].name, ptr[*p_num].num);
		(*p_num)++;
	}
	fclose(fp);
}

void Save_data(Phone *ptr, int num)	//입력된 정보를 데이터에 저장하는 함수 
{
	int i;
	FILE *fp = fopen("전화번호부.dat", "wt");
	if(fp == NULL)
	{
		printf("파일오픈에러 \n");
		return -1;
	}
	for(i = 0; i < num; i++)
		fprintf(fp, "%s %s ", ptr[i].name, ptr[i].num);
		
	fclose(fp);
} 

void insert_data(Phone *ptr, int *p_num)	//정보를입력하는 함수
{
	char exit;
	while(1)
	{
		fputs("이름과 전화번호를 입력해주세요 (EX)홍길동 010-1234-1234) \n", stdout);
		fputs("이름과 전화번호 : ", stdout);
		scanf("%s %s",ptr[*p_num].name, ptr[*p_num].num);
		(*p_num)++;
		getchar();
		fputs("돌아가려면 n을 입력하세요 : ", stdout);
		scanf("%c", &exit);
		getchar();
		system("cls");
		
		if(exit == 'n' || exit == 'N')
			break; 
	}
	return;
}

void delete_data(Phone *ptr, int *p_num)	//정보를 삭제하는 함수  
{
	int i, j;
	char name[20];
	fputs("삭제할 이름을 입력해주세요 : ", stdout);
	scanf("%s", name);
	getchar();
	for(i = 0; i < (*p_num); i++)
	{
		if(strcmp(name, ptr[i].name) == 0)
		{
			for(j=i+1; j < *p_num; j++)
			{
				strcpy(ptr[j-1].name, ptr[j].name);
				strcpy(ptr[j-1].num, ptr[j].num);
			}
			(*p_num)--;
			system("cls");
			return;
		}
	}
	fputs("해당정보를 찾을 수 없습니다. \n", stdout);
	system("PAUSE");
	system("cls");
}

void search_data(Phone *ptr, int p_num)	//이름으로 검색하는 함수
{
	char search[10];
	int i;
	
	printf("검색할 이름을 입력하세요 : ");
	scanf("%s", search);
	getchar();
	
	for(i = 0; i < p_num; i++)
	{
		if(strcmp(ptr[i].name, search) == 0)
		{
			printf("\n%s %s \n\n",ptr[i].name, ptr[i].num);
			system("PAUSE");
			system("cls");
			return;
		}
	}
	printf("입력한 정보를 찾지못했습니다. \n\n");
	system("PAUSE");
	system("cls");
}

void print_all(Phone *ptr, int p_num)	//전화번호부를 출력시키는 함수 
{
	int i;
	for(i = 0; i < p_num; i++)
		printf("%s %s \n",ptr[i].name, ptr[i].num);
		
	printf("\n");
	system("PAUSE");
	system("cls");
}

void sort_data(Phone *ptr, int p_num)
{
	int i, j;
	Phone tmp;
	for(i = p_num -1; i > 0; i--)
	{
		for(j = 0; j <i; j++)
		{
			if(strcmp(ptr[j].name, ptr[j+1].name) > 0)	//앞의 이름이 더크면 0보다 큰 값을 반환 
			{
				strcpy(tmp.name, ptr[j].name);
				strcpy(tmp.num, ptr[j].num);
				strcpy(ptr[j].name, ptr[j+1].name);
				strcpy(ptr[j].num, ptr[j+1].num);
				strcpy(ptr[j+1].name, tmp.name);
				strcpy(ptr[j+1].num, tmp.num );
			}
		}
	}
	fputs("이름순으로 정렬이 완료되었습니다 \n\n", stdout);
	system("PAUSE");
	system("cls");
}

int main(void)
{
	Phone ptr[MAX_PERSON];	//데이터저장을 위한 배열
	int person_num = 0;
	int menu;
	
	Road_data(ptr, &person_num);
	 
	while(1)
	{
		printf("--------전화번호부-------- \n");
		printf("1.입력 \n2.삭제 \n3.검색 \n4.전체출력 \n5.정렬 \n6.종료\n");
		printf("\n\n번호를 선택해주세요 : ");
		scanf("%d", &menu);
		getchar();
		system("cls");
		
		switch(menu){
			
			case 1:
			{
				insert_data(ptr, &person_num);
				break;
			}
			
			case 2:
			{
				delete_data(ptr, &person_num);
				break;
			}
				
			case 3:
			{
				search_data(ptr, person_num);
				break;
			}
				
			case 4:
			{
				print_all(ptr, person_num);
				break;		
			}
			
			case 5:
			{
				sort_data(ptr, person_num);
				break;
			}
				
			case 6:
			{
				Save_data(ptr, person_num);
				return 0; 
			}
		}
	}
	return 0;
}
