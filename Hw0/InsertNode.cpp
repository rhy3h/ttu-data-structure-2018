#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *nextNode;
} Node;

Node* GetNode();
Node* InsertNode(Node* ptrRoot, int itemData);
void PrintList(Node *ptrRoot);

int main()
{
	int input;
	Node* rootList = NULL;

	while (printf("Input an integer? ") && scanf("%d", &input) != EOF)
	{
		rootList = InsertNode(rootList, input);
		PrintList(rootList);
	}

	return 0;
}

Node* GetNode()
{
	Node* pNode;

	pNode = (Node*)malloc(sizeof(Node));
	if (pNode)	pNode->nextNode = NULL;
	return pNode;
}

Node* InsertNode(Node* ptrRoot, int itemData)
{
	Node* pNodeInsert = GetNode();
	Node* pCurNode, *pPreNode;

	pCurNode = ptrRoot;
	pPreNode = NULL;

	pNodeInsert->data = itemData;

	while (pCurNode != NULL && itemData > pCurNode->data) {
		pPreNode = pCurNode;
		pCurNode = pCurNode->nextNode;
	}

	if (pPreNode != NULL) {
		pPreNode->nextNode = pNodeInsert;
		pNodeInsert->nextNode = pCurNode;
		return ptrRoot;
	}

	else {
		pNodeInsert->nextNode = pCurNode;
		return pNodeInsert;
	}
}

void PrintList(Node *ptrRoot)
{
	while (ptrRoot != NULL)
	{
		printf("%d ", ptrRoot->data);
		ptrRoot = ptrRoot->nextNode;
	}
	printf("\n");
}