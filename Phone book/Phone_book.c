//2022-02-05
//����,���ı�� �̱��� ���۽ð� 1�ð�30��  

#include <stdio.h>
#include <stdlib.h>


typedef struct phonebook{
	char name[10];
	char num[20];
}Phone;

void insertdata(void)	//�������Է��ϴ� �Լ� 
{
	Phone input;
	char exit;
	FILE *fp = fopen("��ȭ��ȣ��.txt", "at");
	if(fp == NULL)
	{
		printf("���Ͽ��¿��� \n");
		return -1;
	}
	while(1)
	{
		fputs("�̸��� ��ȭ��ȣ�� �Է����ּ��� (EX)ȫ�浿 010-1234-1234) \n", stdout);
		fputs("�̸��� ��ȭ��ȣ : ", stdout);
		scanf("%s %s",input.name, input.num);
		fputs(input.name, fp);
		fputc(' ', fp);
		fputs(input.num, fp);
		fputc('\n', fp);
		getchar();
		fputs("���ư����� n�� �Է��ϼ��� : ", stdout);
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
void deletedata()	//������ �����ϴ� �Լ�  
{
	Phone buf[100];
	FILE *fp1 = fopen("��ȭ��ȣ��.txt", "rt");
	buf = fp1; 
	FILE *fp2 = fopen("��ȭ��ȣ��.txt", "wt");
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("���Ͽ��¿��� \n");
		return -1;
	}
}
*/
void searchdata(void)	//�̸����� �˻��ϴ� �Լ� 
{
	char search[10];
	char buf[10];
	
	FILE *fp = fopen("��ȭ��ȣ��.txt", "rt");
	if(fp == NULL)
	{
		printf("���Ͽ��¿��� \n");
		return -1;
	}
	printf("�˻��� �̸��� �Է��ϼ��� : ");
	scanf("%s", search);
	getchar();
	while(feof(fp) == 0)	//���ϳ������������� �ʾ����� ���� 
	{
		fscanf(fp, "%s", buf);
		if(strcmp(buf, search) == 0)
		{
			printf("%s ",buf);	//�̸���� 
			fscanf(fp, "%s", buf);
			printf("%s \n\n", buf);	//��ȭ��ȣ��� 
			break;
		}
	}
	fclose(fp);
	system("PAUSE");
	system("cls");
	return;
}

void print_all(void)	//��ȭ��ȣ�θ� ��½�Ű�� �Լ� 
{
	char ch;
	FILE *fp = fopen("��ȭ��ȣ��.txt", "rt");
	if(fp == NULL)
	{
		printf("���Ͽ��¿��� \n");
		return -1;
	}
	while(feof(fp) == 0)	//���ϳ������������� �ʾ����� ���� 
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
		printf("--------��ȭ��ȣ��-------- \n");
		printf("1.�Է� \n2.���� \n3.�˻� \n4.��ü��� \n5.���� \n6.����\n");
		printf("\n\n��ȣ�� �������ּ��� : ");
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
