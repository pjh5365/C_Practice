#include <stdio.h>
int hour = 0, minute = 0, second = 0;	//�����͸� ��������� ���� ����� �ȳ���. 

int second_to_minute(int a)
{
	while(1)	//�Է¹��� �ʰ� 0�ʰ� �ɶ����� �ݺ�  
	{
		second++;
		a--;
		 
		if(second == 60)	//60�ʰ��Ǹ� 1������ ��ȯ  
		{
			second -= 60;
			minute++;
		}
		
		if(a == 0)
			break;
	}
}

int minute_to_hour(void)
{
	while(1)
	{	 
		if(minute >= 60)	//���� 60���� �Ѿ�� 1�ð����� ��ȯ 
		{
			minute -= 60;
			hour++;
		}
		else
		break;
	}
}

int main(void)
{
	int a;
	printf("��ȯ�� �ʸ� �Է����ּ��� : ");
	
	scanf("%d", &a);
	
	if(a >= 60)
	{
		second_to_minute(a);	//�Է¹��� �ʸ� ������ ��ȯ 
		if(minute >= 60)		//���� 60���� �Ѿ�� �ð����� ��ȯ   
		{
			minute_to_hour();
		}
	}
	else
	{
		second = a;
	}
	
	printf("%d�� %d�� %d��\n", hour, minute, second);

	return 0;	
} 
