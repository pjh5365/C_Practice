//2022-04-10 완성
//자료구조과제 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct student_info{	//수강신청한 학생들의 정보를 담을 구조체 
	int id;
	char name[20];
}Stu;

typedef struct student_node{	//수강철회한 학생들의 정보를 담는 구조체 
	int id;
	char name[20];
	struct student_node *link;
}Node;

int find_pos(Stu *student, int length, int id);	//새로운 정보를 넣을 위치를 반환하는 함수 
void insert_student_info(Stu *student, int *length, int pos, int id, char name[]);	//수강신청한 학생들의 정보를 순차리스트에 담는 함수 
void delete_student_info(Stu *student, int id, int *length);	//수강철회한 학생들의 정보를 지우는 함수 
void insert_node(Node *list, Stu *student, int id);	//수강철회한 학생들의 정보를 연결리스트에 저장하는 함수 
void print_node(Node *list);	//수강철회자(연결리스트)를 출력하는 함수 
void print_student(Stu *student, int length);	//수강신청자(순차리스트)를 출력하는 함수 
int Road_student_data(Stu *student, int *length);	//저장된 정보(수강신청자)를 불러오는 함수 
int Save_student_data(Stu *student, int length);	//입력된 정보(수강신청자)를 데이터에 저장하는 함수
int Road_Node_data(Node *list);	//저장된 정보(수강철회자)를 불러오는 함수 
int Save_Node_data(Node *list);	//입력된 정보(수강철회자)를 데이터에 저장하는 함수 
 


int main(void)
{
	Stu student[MAX];
	Node *list = (Node *)malloc(sizeof(Node));	//헤드포인터를 할당해서 사용 
	list->link = NULL;	//헤드포인터의 초기화 
	int length = 0, id, i = 0, pos;
	char ch;
	char name[20];
	
	Road_student_data(student, &length);	//저장된 수강신청자들의 정보를 불러옴 
	Road_Node_data(list);	//저장된 수강철회자의 정보를 불러옴 
	
	while(1)
	{
		system("cls");
		printf("\n\n----------------------------------------------\n");
		printf("\t수강신청자 및 수강포기자 관리");
		printf("\n----------------------------------------------\n");
		printf("1. 수강신청\n");
		printf("2. 수강철회 신청 \n");
		printf("3. 수강신청자 리스트 확인 \n");
		printf("4. 수강철회자 리스트 확인 \n");
		printf("5. 프로그램종료(Q/q) \n\n\n");
		printf("----------------------------------------------\n\n\n");
	
		printf("번호를 입력주세요. : ");
		ch = getche();
		
		switch(ch)
		{
			case '1' :
				system("cls");
				printf("수강신청자 학번을 입력해주세요 : ");
				scanf("%d", &id);
				printf("수강신청자 이름을 입력해주세요 : ");
				scanf("%s", name);
				pos = find_pos(student, length, id);	//정보가 들어가야할 위치를 찾기 
				if(length >= MAX)	//배열의 길이가 MAX의 값보다 크거나 같을때는 더이상 입력받을수없으므로 
				{
					printf("이미 마감되었습니다. [%d/%d] \n", length, MAX);
					system("PAUSE");
				}
				else
					insert_student_info(student, &length, pos, id, name);	//수강신청자를 추가함 
					
				break;
				
			case '2' :
				system("cls");
				printf("수강철회자 학번을 입력해주세요 : ");
				scanf("%d", &id); 
				insert_node(list, student, id);	//수강철회자에 명단추가 
				delete_student_info(student, id, &length);	//수강철회한 학생의 정보를 수강신청자에서 삭제 
				break; 
				
			case '3' :
				system("cls");
				print_student(student, length);	//학생들의 수강신청정보를 출력 
				break;
			
			case '4' :
				system("cls");
				print_node(list);	//학생들의 수강신청정보를 출력 
				break;
					
			case 'Q' :
			case 'q' :
			case '5' :
				printf("\n프로그램을 종료합니다.\n");
				Save_student_data(student, length);	//수강신청자의 정보를 저장 
				Save_Node_data(list);	//수강철회자의 정보를 저장 
				free(list);	//할당된 헤드포인터해제 
				system("PAUSE");
				return;	//프로그램 종료 
				
			default :
				system("cls");
				printf("\n\n잘못된 값이 입력되었습니다. 다시입력해주세요. \n") ;
				system("PAUSE");
		}	
	}
	
	return 0;
}

int find_pos(Stu *student, int length, int id)	//새로운 정보를 넣을 위치를 반환하는 함수 
{
	int i;
	if(length < 1)
		return 0;	//길이가 0이므로 찾을필요없음 
	
	for(i = 0; i < length; i++)
	{
		if(id < student[i].id)
			return i;	//for문 도중 조건에 만족하면 i값 리턴 
	}
	return i;	//for문이 끝나면 i값 리턴 
}

void insert_student_info(Stu *student, int *length, int pos, int id, char name[])	//수강신청한 학생들의 정보를 담는 함수 
{
	int i;
	for(i = (*length); i > pos; i--)	//pos까지의 값을 뒤로 1칸씩이동 
	{
		student[i].id = student[i-1].id;
		strcpy(student[i].name, student[i-1].name);
	}
	student[pos].id = id;
	strcpy(student[pos].name,name);
	(*length)++;
	
	printf("\n\n수강신청에 성공하였습니다. \n");
	system("PAUSE");
}

void delete_student_info(Stu *student, int id, int *length)	//수강철회한 학생들의 정보를 지우는 함수 
{
	int i = 0, j; 
	if(id == 0)	//id를 입력받을때 0이면 구조체배열의 초기화값과 겹쳐서 따로 정의해야함
	{
		printf("\n\n수강철회할 학번을 다시한번 확인해주세요. \n");
		system("PAUSE");	
		return;	
	} 
	while(student[i].id != id)
	{
		i++;
		if(i >= MAX)	//삭제할 학번을 찾지못하였을때 
		{
			printf("\n\n수강철회할 학번을 다시한번 확인해주세요. \n");
			system("PAUSE");
			return;
		}
	}
	for(j = i; j < (*length); j++)	//뒤에있던값들을 앞으로 당겨오면서 length의 길이도 -1하여 삭제 
	{
		student[j].id = student[j+1].id;
		strcpy(student[j].name, student[j+1].name);
	}
	(*length)--;
	
	printf("\n\n수강철회에 성공하였습니다. \n");
	system("PAUSE");
}

void insert_node(Node *list, Stu *student, int id)	//수강철회자를 연결리스트로 만드는 함수 
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *p = list->link;
	int i = 0;
	
	if(id == 0)	//id를 입력받을때 0이면 구조체배열의 초기화값과 겹쳐서 따로 정의해야함 
		return;
		 
	while(student[i].id != id)
	{
		i++;
		if(i >= MAX)	//학번을 찾을수 없을때 함수종료 
			return;
	}
	if(p == NULL)	//첫번째 노드가 없을때 
	{
		new_node->link = list->link;
		new_node->id = student[i].id;
		strcpy(new_node->name, student[i].name);
		list->link = new_node;
	}
	else if(id > p->id)	//새로들어올 학번이 첫번째 노드의 학번보다 클때 
	{					
		while(id > p->id)
		{
			if(p->link == NULL)	//p가 마지막 노드일경우 
				break;
			if(p->link->id >id)	//p다음노드의id가 id보다 더 클경우에 종료 
				break;
				 
			p = p->link;	
		}
		new_node->link = p->link;
		new_node->id = student[i].id;
		strcpy(new_node->name, student[i].name);
		p->link = new_node;
	}
	else
	{
		new_node->link = list->link;
		new_node->id = student[i].id;
		strcpy(new_node->name, student[i].name);
		list->link = new_node;
	}
}

void print_node(Node *list)		//수강철회자 명단을 출력하는 함수 
{
	Node *p = list->link;
	int i; 
	printf("\n\n\t수강철회자 명단 \n");
	if(p == NULL)
		printf("\n수강철회자 명단이 비워져있습니다. \n\n");
	else
	{
		for(p = list->link, i = 1; p != NULL; p = p->link, i++)
			printf("%2d. 학번 : [%d]\t 이름 : [%s] \n",i , p->id, p->name);
	}
	system("PAUSE");

}

void print_student(Stu *student, int length)	//수강신청자 명단을 출력하는 함수 
{
	int i;
	printf("\n\n\t수강신청자 명단 \n");
	if(length == 0)
		printf("\n수강신청자 명단이 비워져있습니다.\n\n");
	else
	{
		for(i = 0; i < length; i++)
			printf("%2d. 학번 : [%d]\t 이름 : [%s] \n", i+1, student[i].id, student[i].name);
	}
	system("PAUSE");
}

int Road_student_data(Stu *student, int *length)	//저장된 정보를 불러오는 함수 
{
	int id;
	char name[20];
	FILE *fp = fopen("apply.dat", "rt");
	if(fp == NULL)	//파일오픈에 실패했을때
	{
		printf("파일오픈에러 \n");
		return -1;
	}
	while(fscanf(fp, "%d %s", &id, name) != EOF)
	{
		student[*length].id = id;
		strcpy(student[*length].name, name);
		(*length)++;
	}
	fclose(fp);
}

int Save_student_data(Stu *student, int length)	//입력된 정보를 데이터에 저장하는 함수 
{
	int i;
	FILE *fp = fopen("apply.dat", "wt");
	if(fp == NULL)	//파일오픈에 실패했을때
	{
		printf("파일오픈에러 \n");
		return -1;
	}
	for(i = 0; i < length; i++)
		fprintf(fp, "%d %s ", student[i].id, student[i].name);
		
	fclose(fp);
}
int Road_Node_data(Node *list)	//저장된 정보를 불러오는 함수
{
	int id;
	char name[20]; 
	Node *p = list->link;
	FILE *fp = fopen("drop.dat", "rt");
	if(fp == NULL) 	//파일오픈에 실패했을때
	{
		printf("파일오픈에러 \n");
		return -1;
	}
	while(fscanf(fp, "%d %s", &id, name) != EOF)
	{	
		Node *new_node = (Node *)malloc(sizeof(Node));
		
		if(list->link == NULL)
		{
			new_node->link = list->link; 
			list->link = new_node;
			new_node->id = id;
			strcpy(new_node->name, name);
			p = list->link;	//p를 다시 헤드포인터가 가르키는 링크값으로 초기화 (없으면 왜 안되지? )
		}
		else
		{
			new_node->link = p->link;
			p->link = new_node; 
			new_node->id = id;
			strcpy(new_node->name, name);
		}
		if(p->link != NULL)	//추가한 노드가 마지막이 아닐때 
			p = p->link;
	}
	fclose(fp);
}

int Save_Node_data(Node *list)	//입력된 정보를 데이터에 저장하는 함수 
{
	int i;
	Node *p;
	FILE *fp = fopen("drop.dat", "wt");
	if(fp == NULL)	//파일오픈에 실패했을때 
	{
		printf("파일오픈에러 \n");
		return -1;
	}
	for(p = list->link; p != NULL; p = p->link)	//p가 한노드 앞으로가면 이미 저장한 이전노드를 할당해제 
		fprintf(fp, "%d %s ", p->id, p->name);
	
	p = list->link;
	while(list->link != NULL)	//메모리할당해제 
	{
		p = list->link;
		list->link = list->link->link;
		free(p);
	}
	
	fclose(fp);
}
