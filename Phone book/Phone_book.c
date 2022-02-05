//2022-02-05
//����,���ı�� �̱��� ���۽ð� 1�ð�30��  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSON 100	//100������� ���������� 

typedef struct phonebook{
	char name[20];
	char num[20];
}Phone;

void Road_data(Phone *ptr, int *p_num)	//����� ������ �ҷ����� �Լ� 
{
	FILE *fp = fopen("��ȭ��ȣ��.dat", "rt");
	if(fp == NULL)
	{
	//	printf("���Ͽ��¿��� \n");
		return -1;
	}
	while(feof(fp) == 0)
	{
		fscanf(fp, "%s %s ",ptr[*p_num].name, ptr[*p_num].num);
		(*p_num)++;
	}
	fclose(fp);
}

void Save_data(Phone *ptr, int num)	//�Էµ� ������ �����Ϳ� �����ϴ� �Լ� 
{
	int i;
	FILE *fp = fopen("��ȭ��ȣ��.dat", "wt");
	if(fp == NULL)
	{
		printf("���Ͽ��¿��� \n");
		return -1;
	}
	for(i = 0; i < num; i++)
		fprintf(fp, "%s %s ", ptr[i].name, ptr[i].num);
		
	fclose(fp);
} 

void insert_data(Phone *ptr, int *p_num)	//�������Է��ϴ� �Լ�
{
	char exit;
	while(1)
	{
		fputs("�̸��� ��ȭ��ȣ�� �Է����ּ��� (EX)ȫ�浿 010-1234-1234) \n", stdout);
		fputs("�̸��� ��ȭ��ȣ : ", stdout);
		scanf("%s %s",ptr[*p_num].name, ptr[*p_num].num);
		(*p_num)++;
		getchar();
		fputs("���ư����� n�� �Է��ϼ��� : ", stdout);
		scanf("%c", &exit);
		getchar();
		system("cls");
		
		if(exit == 'n' || exit == 'N')
			break; 
	}
	return;
}

void delete_data(Phone *ptr, int *p_num)	//������ �����ϴ� �Լ�  
{
	int i, j;
	char name[20];
	fputs("������ �̸��� �Է����ּ��� : ", stdout);
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
	fputs("�ش������� ã�� �� �����ϴ�. \n", stdout);
	system("PAUSE");
	system("cls");
}

void search_data(Phone *ptr, int p_num)	//�̸����� �˻��ϴ� �Լ�
{
	char search[10];
	int i;
	
	printf("�˻��� �̸��� �Է��ϼ��� : ");
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
	printf("�Է��� ������ ã�����߽��ϴ�. \n\n");
	system("PAUSE");
	system("cls");
}

void print_all(Phone *ptr, int p_num)	//��ȭ��ȣ�θ� ��½�Ű�� �Լ� 
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
			if(strcmp(ptr[j].name, ptr[j+1].name) > 0)	//���� �̸��� ��ũ�� 0���� ū ���� ��ȯ 
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
	fputs("�̸������� ������ �Ϸ�Ǿ����ϴ� \n\n", stdout);
	system("PAUSE");
	system("cls");
}

int main(void)
{
	Phone ptr[MAX_PERSON];	//������������ ���� �迭
	int person_num = 0;
	int menu;
	
	Road_data(ptr, &person_num);
	 
	while(1)
	{
		printf("--------��ȭ��ȣ��-------- \n");
		printf("1.�Է� \n2.���� \n3.�˻� \n4.��ü��� \n5.���� \n6.����\n");
		printf("\n\n��ȣ�� �������ּ��� : ");
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
