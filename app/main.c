#include <stdio.h>
#include <stdlib.h>

typedef struct set
{
	double arr[50];
	
}set;

typedef struct Node
{
	double data;
	struct Node* next;
}Node;

Node* createNode(double data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertAtHead(Node** head,int data)
{
	Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

void deleteNode(Node** head,int key)
{
	Node* temp = *head;
	Node* prev = NULL;

	if (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) return;
	
	prev->next = temp->next;
	free(temp);
}

void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void SavetoNode(double arr[],int b,int e,Node* head)
{
	;
}

//数组，大小，开始，结束,目标数
void fun(double arr[],int s,int b,int e,int tar)
{
	double sum = 0;
	double dif = 0; 
	for (int i = b;i >= b && i <= e;++i)
	{
		dif = tar - arr[i];
		for(int ii = b+1;ii < s-1;++ii)
		{
			if (dif > arr[ii])
			{
				dif -= arr[ii];
			}
		}
	}
}

int main()
{
	double num[] = {402478.00, 350000.00, 243402.00, 61841.80, 54401.77, 125445.60, 24566.15, 20000.00, 30000.00, 67369.50, 68680.00, 106538.16, 60000.00, 20750.00, 22301.93, 22360.00, 60500.00, 70000.00, 76500.00, 5900.86, 47704.00, 60227.50, 21360.00, 83003.00, 29938.80, 127600.00, 6000.00, 84524.78, 6600.00, 389855.69, 68963.00, 109500.00, 78200.00, 13000.00, 3112778.34, 150000.00, 53206.00, 17217.00, 131600.00, 90000.00, 118755.00, 20000.00, 62640.00, 65847.51, 20000.00, 60619.20, 218.04, 80000.00, 64266.15, 124080.00, 129000.00, 11872.00, 140195.00, 5000.00, 80000.00, 122000.00, 74587.50, 21577.89,24285.50,130000.00,3004.00,236128.42,24209.27};
	
	double num2[] = {0,1,2,3,4,5,6,7,8,9};
	double tar = 185852;
	int size_num = sizeof(num)/sizeof(double);
	double *p_num = num;
	
	//原数组从大到小排列	
	for (int ii = 0;ii < size_num-1;++ii)
	{
		for (int i = 0;i < size_num-1-ii && i >= 0;++i)
		{
			if ( num[i] < num[i+1])
			{
				double t;
				t = num[i];
				num[i] = num[i+1];
				num[i+1] = t;
			}
		}
	}
	
	//输出原数组
	for (int ii = 0;ii < size_num;++ii)
	{
		if(ii%5==0 && ii!=0) printf("\n");
		printf("%2d.%10.2f; ",ii+1,num[ii]);

	}
	printf("\n");

	
	
	//找出从哪儿开始比目标数小
	int id_begin;
	for (id_begin = 0;id_begin < size_num;++id_begin)
	{
		if ( num[id_begin] < tar )
		{
			printf("%2d.%10.2f\n",id_begin+1,num[id_begin]);
			break;
		}
	}	
	
	//从最小数往大数开始累加，找到和刚超过目标数的位置
	int id_end;
	double sumend;
	for (int i = size_num - 1 ;i > id_begin;--i)
	{	
		sumend += num[i];
		if (sumend >= tar)
		{
			id_end = i;
			printf("%2d.%10.2f\n",i+1,num[i]);
			sumend -= num[i];//这个也是最终要比较的和之一，也是第一个被计算出来的和
			printf("%10.2f\n",sumend);
			printf("id_begin=%d\n",id_begin);
			printf("id_end=%d\n",id_end);
			break;
		}
		
	}

	//id_begin到id_end是要计算的范围	
	//数组，大小，开始，结束,目标数
	fun(num,size_num,id_begin,id_end,tar);


	return 0;
}

