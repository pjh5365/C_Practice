#include <stdio.h>

int second_to_minute(int input, int * second, int * minute)
{
	while(1)	//입력받은 초가 0초가 될때까지 반복  
	{
		(*second)++;
		input--;
		 
		if((*second) == 60)	//60초가되면 1분으로 변환  
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
		if((*minute) >= 60)	//분이 60분을 넘어가면 1시간으로 변환 
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
	printf("변환할 초를 입력해주세요 : ");
	
	scanf("%d", &input);
	
	if(input >= 60)
	{
		second_to_minute(input, &second, &minute);	//입력받은 초를 분으로 변환 
		if(minute >= 60)		//분이 60분을 넘어갈때 시간으로 변환   
		{
			minute_to_hour(&minute, &hour);
		}
	}
	else
	{
		second = input;
	}
	
	printf("%d시 %d분 %d초\n", hour, minute, second);

	return 0;	
} 
