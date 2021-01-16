#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Link
{
	int data;

	struct Link* next;
};


typedef struct Link_List
{
	int data;

	struct Link_List* next;
}Node;

static Node* ptr[15] = {NULL};
//头插法：
Node* creat_from_head(int* value, uint8_t len)
{
	if(value == NULL)
	{
		return NULL;
	}

	Node* head = (Node*)(malloc(sizeof(Node)));

	head->data = value[0];

	head->next = NULL;

	for(uint8_t i = 1; i < len; i++)
	{
		Node* node = (Node*)(malloc(sizeof(Node)));

		node->data = value[i];

		node->next = head;

		head = node;
	}

	return head;
}

//尾插法：
 Node* creat_form_tail(int* value, uint8_t len)
 {
 	if(value == NULL)
	{
		return NULL;
	}

	Node* head = (Node*)(malloc(sizeof(Node)));

	head->data = value[0];

	head->next = NULL;

	Node* tail = head;

	ptr[0] = head;

	for(uint8_t i = 1; i<len; i++)
	{
		Node* node = (Node*)malloc(sizeof(Node));

		node->data = value[i];

		node->next = NULL;

		tail->next = node;

		tail = node;

		ptr[i] = node;
	}

	return head;
 }


//遍历列表
void link_list_traversal(Node* head)
{
	if(head == NULL)
	{
		printf("%s\n", "Head is NULL");;
	}

	Node* node = head;

	while(node != NULL)
	{
		printf("%d -> ", node->data);

		node = node->next;
	}
	printf("\r\n");
}


//链表反转
Node* link_list_reserse(Node* head)
{
	if(head == NULL || head->next == NULL)
	{
		return head;
	}

	Node* pre = NULL;

	Node* cur = head;

	while(cur != NULL)
	{
		Node* next = cur->next;

		cur->next = pre;

		pre = cur;

		cur = next;
	}

	head = pre;

	return head;
}


//求链表倒数第k个值
int value_k(Node* head, uint8_t k)
{
	Node* pre = head;

	Node* rear = head;

	for(uint8_t i = 0; i < k; i++)
	{
		if(rear == NULL)
		{
			printf("%s\n", "链表长度不足k");
		}
		else
		{
			rear = rear->next;
		}
	}

	while(rear != NULL)
	{
		pre = pre->next;

		rear = rear->next;
	}

	return pre->data;
}


//判断链表是否有环
Node* is_loop(Node* head)
{
	if(head == NULL)
	{
		return NULL;
	}

	Node * slow_point = head;

	Node * fast_point = head;

	do
	{
		fast_point = fast_point->next->next;

		slow_point = slow_point->next;

	}while((fast_point->next != NULL) && (fast_point->next->next != NULL) && (fast_point != slow_point));

	if(fast_point == slow_point)
	{
		return slow_point;
	}
	else
	{
		return NULL;
	}

}

//找到环的入口
Node* find_entry(Node* head)
{
	if(head == NULL)
	{
		return NULL;
	}

	Node* pre = head;

	Node* rear = is_loop(head);

	if(rear = NULL)
	{
		return NULL;
	}

	while(pre != rear)
	{
		pre = pre->next;

		rear = rear->next;
	}

	return pre;
}

//删除节点
int delete_node(Node* head, Node* del_node)
{
	if(head == NULL && del_node == NULL)
	{
		return -1;
	}

	if(del_node->next == NULL)//最后一个节点
	{
		Node* cur_node = head;

		while(cur_node->next != NULL)
		{
			cur_node = cur_node->next;
		}

		cur_node->next = NULL;

		free(del_node);
	}
	else
	{
		Node* p = del_node->next;

		int temp = del_node->data;

		del_node->data = p->data;

		p->data = temp;

		del_node->next = p->next;

		free(p);
	}

	return 0;
}

int main(void)
{
	int data_buf[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	uint8_t len = sizeof(data_buf)/sizeof(int);

	Node* head = creat_form_tail(data_buf, len);

	printf("len: %d\n", len);

	link_list_traversal(head);

	//head = link_list_reserse(head);

	//link_list_traversal(head);

	for(uint8_t i = 0; i < len; i++)
	{
		printf("ptr[%d]: %d   %08x\r\n", i, ptr[i]->data, ptr[i]);
	}

	//printf("ptr[%d]->next: %d   %08x\r\n", 14, ptr[14]->next->data, ptr[14]->next);

	//printf("value[%d]: %d\r\n", 3, value_k(head, 3));

	delete_node(head, ptr[9]);

	link_list_traversal(head);

	return 0;
}