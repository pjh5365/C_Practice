//2022-04-10 �ϼ�
//�ڷᱸ������ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct student_info{	//������û�� �л����� ������ ���� ����ü 
	int id;
	char name[20];
}Stu;

typedef struct student_node{	//����öȸ�� �л����� ������ ��� ����ü 
	int id;
	char name[20];
	struct student_node *link;
}Node;

int find_pos(Stu *student, int length, int id);	//���ο� ������ ���� ��ġ�� ��ȯ�ϴ� �Լ� 
void insert_student_info(Stu *student, int *length, int pos, int id, char name[]);	//������û�� �л����� ������ ��������Ʈ�� ��� �Լ� 
void delete_student_info(Stu *student, int id, int *length);	//����öȸ�� �л����� ������ ����� �Լ� 
void insert_node(Node *list, Stu *student, int id);	//����öȸ�� �л����� ������ ���Ḯ��Ʈ�� �����ϴ� �Լ� 
void print_node(Node *list);	//����öȸ��(���Ḯ��Ʈ)�� ����ϴ� �Լ� 
void print_student(Stu *student, int length);	//������û��(��������Ʈ)�� ����ϴ� �Լ� 
int Road_student_data(Stu *student, int *length);	//����� ����(������û��)�� �ҷ����� �Լ� 
int Save_student_data(Stu *student, int length);	//�Էµ� ����(������û��)�� �����Ϳ� �����ϴ� �Լ�
int Road_Node_data(Node *list);	//����� ����(����öȸ��)�� �ҷ����� �Լ� 
int Save_Node_data(Node *list);	//�Էµ� ����(����öȸ��)�� �����Ϳ� �����ϴ� �Լ� 
 


int main(void)
{
	Stu student[MAX];
	Node *list = (Node *)malloc(sizeof(Node));	//��������͸� �Ҵ��ؼ� ��� 
	list->link = NULL;	//����������� �ʱ�ȭ 
	int length = 0, id, i = 0, pos;
	char ch;
	char name[20];
	
	Road_student_data(student, &length);	//����� ������û�ڵ��� ������ �ҷ��� 
	Road_Node_data(list);	//����� ����öȸ���� ������ �ҷ��� 
	
	while(1)
	{
		system("cls");
		printf("\n\n----------------------------------------------\n");
		printf("\t������û�� �� ���������� ����");
		printf("\n----------------------------------------------\n");
		printf("1. ������û\n");
		printf("2. ����öȸ ��û \n");
		printf("3. ������û�� ����Ʈ Ȯ�� \n");
		printf("4. ����öȸ�� ����Ʈ Ȯ�� \n");
		printf("5. ���α׷�����(Q/q) \n\n\n");
		printf("----------------------------------------------\n\n\n");
	
		printf("��ȣ�� �Է��ּ���. : ");
		ch = getche();
		
		switch(ch)
		{
			case '1' :
				system("cls");
				printf("������û�� �й��� �Է����ּ��� : ");
				scanf("%d", &id);
				printf("������û�� �̸��� �Է����ּ��� : ");
				scanf("%s", name);
				pos = find_pos(student, length, id);	//������ ������ ��ġ�� ã�� 
				if(length >= MAX)	//�迭�� ���̰� MAX�� ������ ũ�ų� �������� ���̻� �Է¹����������Ƿ� 
				{
					printf("�̹� �����Ǿ����ϴ�. [%d/%d] \n", length, MAX);
					system("PAUSE");
				}
				else
					insert_student_info(student, &length, pos, id, name);	//������û�ڸ� �߰��� 
					
				break;
				
			case '2' :
				system("cls");
				printf("����öȸ�� �й��� �Է����ּ��� : ");
				scanf("%d", &id); 
				insert_node(list, student, id);	//����öȸ�ڿ� ����߰� 
				delete_student_info(student, id, &length);	//����öȸ�� �л��� ������ ������û�ڿ��� ���� 
				break; 
				
			case '3' :
				system("cls");
				print_student(student, length);	//�л����� ������û������ ��� 
				break;
			
			case '4' :
				system("cls");
				print_node(list);	//�л����� ������û������ ��� 
				break;
					
			case 'Q' :
			case 'q' :
			case '5' :
				printf("\n���α׷��� �����մϴ�.\n");
				Save_student_data(student, length);	//������û���� ������ ���� 
				Save_Node_data(list);	//����öȸ���� ������ ���� 
				free(list);	//�Ҵ�� ������������� 
				system("PAUSE");
				return;	//���α׷� ���� 
				
			default :
				system("cls");
				printf("\n\n�߸��� ���� �ԷµǾ����ϴ�. �ٽ��Է����ּ���. \n") ;
				system("PAUSE");
		}	
	}
	
	return 0;
}

int find_pos(Stu *student, int length, int id)	//���ο� ������ ���� ��ġ�� ��ȯ�ϴ� �Լ� 
{
	int i;
	if(length < 1)
		return 0;	//���̰� 0�̹Ƿ� ã���ʿ���� 
	
	for(i = 0; i < length; i++)
	{
		if(id < student[i].id)
			return i;	//for�� ���� ���ǿ� �����ϸ� i�� ���� 
	}
	return i;	//for���� ������ i�� ���� 
}

void insert_student_info(Stu *student, int *length, int pos, int id, char name[])	//������û�� �л����� ������ ��� �Լ� 
{
	int i;
	for(i = (*length); i > pos; i--)	//pos������ ���� �ڷ� 1ĭ���̵� 
	{
		student[i].id = student[i-1].id;
		strcpy(student[i].name, student[i-1].name);
	}
	student[pos].id = id;
	strcpy(student[pos].name,name);
	(*length)++;
	
	printf("\n\n������û�� �����Ͽ����ϴ�. \n");
	system("PAUSE");
}

void delete_student_info(Stu *student, int id, int *length)	//����öȸ�� �л����� ������ ����� �Լ� 
{
	int i = 0, j; 
	if(id == 0)	//id�� �Է¹����� 0�̸� ����ü�迭�� �ʱ�ȭ���� ���ļ� ���� �����ؾ���
	{
		printf("\n\n����öȸ�� �й��� �ٽ��ѹ� Ȯ�����ּ���. \n");
		system("PAUSE");	
		return;	
	} 
	while(student[i].id != id)
	{
		i++;
		if(i >= MAX)	//������ �й��� ã�����Ͽ����� 
		{
			printf("\n\n����öȸ�� �й��� �ٽ��ѹ� Ȯ�����ּ���. \n");
			system("PAUSE");
			return;
		}
	}
	for(j = i; j < (*length); j++)	//�ڿ��ִ������� ������ ��ܿ��鼭 length�� ���̵� -1�Ͽ� ���� 
	{
		student[j].id = student[j+1].id;
		strcpy(student[j].name, student[j+1].name);
	}
	(*length)--;
	
	printf("\n\n����öȸ�� �����Ͽ����ϴ�. \n");
	system("PAUSE");
}

void insert_node(Node *list, Stu *student, int id)	//����öȸ�ڸ� ���Ḯ��Ʈ�� ����� �Լ� 
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *p = list->link;
	int i = 0;
	
	if(id == 0)	//id�� �Է¹����� 0�̸� ����ü�迭�� �ʱ�ȭ���� ���ļ� ���� �����ؾ��� 
		return;
		 
	while(student[i].id != id)
	{
		i++;
		if(i >= MAX)	//�й��� ã���� ������ �Լ����� 
			return;
	}
	if(p == NULL)	//ù��° ��尡 ������ 
	{
		new_node->link = list->link;
		new_node->id = student[i].id;
		strcpy(new_node->name, student[i].name);
		list->link = new_node;
	}
	else if(id > p->id)	//���ε��� �й��� ù��° ����� �й����� Ŭ�� 
	{					
		while(id > p->id)
		{
			if(p->link == NULL)	//p�� ������ ����ϰ�� 
				break;
			if(p->link->id >id)	//p���������id�� id���� �� Ŭ��쿡 ���� 
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

void print_node(Node *list)		//����öȸ�� ����� ����ϴ� �Լ� 
{
	Node *p = list->link;
	int i; 
	printf("\n\n\t����öȸ�� ��� \n");
	if(p == NULL)
		printf("\n����öȸ�� ����� ������ֽ��ϴ�. \n\n");
	else
	{
		for(p = list->link, i = 1; p != NULL; p = p->link, i++)
			printf("%2d. �й� : [%d]\t �̸� : [%s] \n",i , p->id, p->name);
	}
	system("PAUSE");

}

void print_student(Stu *student, int length)	//������û�� ����� ����ϴ� �Լ� 
{
	int i;
	printf("\n\n\t������û�� ��� \n");
	if(length == 0)
		printf("\n������û�� ����� ������ֽ��ϴ�.\n\n");
	else
	{
		for(i = 0; i < length; i++)
			printf("%2d. �й� : [%d]\t �̸� : [%s] \n", i+1, student[i].id, student[i].name);
	}
	system("PAUSE");
}

int Road_student_data(Stu *student, int *length)	//����� ������ �ҷ����� �Լ� 
{
	int id;
	char name[20];
	FILE *fp = fopen("apply.dat", "rt");
	if(fp == NULL)	//���Ͽ��¿� ����������
	{
		printf("���Ͽ��¿��� \n");
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

int Save_student_data(Stu *student, int length)	//�Էµ� ������ �����Ϳ� �����ϴ� �Լ� 
{
	int i;
	FILE *fp = fopen("apply.dat", "wt");
	if(fp == NULL)	//���Ͽ��¿� ����������
	{
		printf("���Ͽ��¿��� \n");
		return -1;
	}
	for(i = 0; i < length; i++)
		fprintf(fp, "%d %s ", student[i].id, student[i].name);
		
	fclose(fp);
}
int Road_Node_data(Node *list)	//����� ������ �ҷ����� �Լ�
{
	int id;
	char name[20]; 
	Node *p = list->link;
	FILE *fp = fopen("drop.dat", "rt");
	if(fp == NULL) 	//���Ͽ��¿� ����������
	{
		printf("���Ͽ��¿��� \n");
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
			p = list->link;	//p�� �ٽ� ��������Ͱ� ����Ű�� ��ũ������ �ʱ�ȭ (������ �� �ȵ���? )
		}
		else
		{
			new_node->link = p->link;
			p->link = new_node; 
			new_node->id = id;
			strcpy(new_node->name, name);
		}
		if(p->link != NULL)	//�߰��� ��尡 �������� �ƴҶ� 
			p = p->link;
	}
	fclose(fp);
}

int Save_Node_data(Node *list)	//�Էµ� ������ �����Ϳ� �����ϴ� �Լ� 
{
	int i;
	Node *p;
	FILE *fp = fopen("drop.dat", "wt");
	if(fp == NULL)	//���Ͽ��¿� ���������� 
	{
		printf("���Ͽ��¿��� \n");
		return -1;
	}
	for(p = list->link; p != NULL; p = p->link)	//p�� �ѳ�� �����ΰ��� �̹� ������ ������带 �Ҵ����� 
		fprintf(fp, "%d %s ", p->id, p->name);
	
	p = list->link;
	while(list->link != NULL)	//�޸��Ҵ����� 
	{
		p = list->link;
		list->link = list->link->link;
		free(p);
	}
	
	fclose(fp);
}
