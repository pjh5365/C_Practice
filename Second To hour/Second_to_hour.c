#include <stdio.h>

int second_to_minute(int input, int * second, int * minute)
{
	while(1)	//�Է¹��� �ʰ� 0�ʰ� �ɶ����� �ݺ�  
	{
		(*second)++;
		input--;
		 
		if((*second) == 60)	//60�ʰ��Ǹ� 1������ ��ȯ  
		{
			(*second) -= 60;
			(*minute)++;
		}
		
		if(input == 0)
			break;
	}
}

int minute_to_hour(int * minute, int * hour)
{
	while(1)
	{	 
		if((*minute) >= 60)	//���� 60���� �Ѿ�� 1�ð����� ��ȯ 
		{
			(*minute) -= 60;
			(*hour)++;
		}
		else
		break;
	}
}

int main(void)
{
	int input;
	int hour = 0, minute = 0, second = 0;
	printf("��ȯ�� �ʸ� �Է����ּ��� : ");
	
	scanf("%d", &input);
	
	if(input >= 60)
	{
		second_to_minute(input, &second, &minute);	//�Է¹��� �ʸ� ������ ��ȯ 
		if(minute >= 60)		//���� 60���� �Ѿ�� �ð����� ��ȯ   
		{
			minute_to_hour(&minute, &hour);
		}
	}
	else
	{
		second = input;
	}
	
	printf("%d�� %d�� %d��\n", hour, minute, second);

	return 0;	
} 
