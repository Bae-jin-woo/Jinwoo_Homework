#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "adj_list.h"

void main()
{
	char c;
	int	i, v;

	front = rear = NULL;
	build_simple_graph();
	printf("\n\n********* Command *********");
	printf("\nD: DFS, B: BFS, Q: Quit\n");
	printf("***************************\n");
	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'D':
			printf("\n Start vertex: ");
			scanf("%d", &v);
			for (i = 0; i < MAX_VERTICES; i++) visited[i] = false;
			dfs(v);
			printf("\n");
			break;
		case 'B':
			printf("\n Start vertex: ");
			scanf("%d", &v);
			for (i = 0; i < MAX_VERTICES; i++) visited[i] = false;
			bfs(v);
			printf("\n");
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

void build_simple_graph() {
	insert_edge(1, 2);
	insert_edge(1, 3);
	insert_edge(1, 4);
	insert_edge(2, 1);
	insert_edge(2, 5);
	insert_edge(3, 1);
	insert_edge(3, 5);
	insert_edge(4, 1);
	insert_edge(4, 5);
	insert_edge(5, 2);
	insert_edge(5, 3);
	insert_edge(5, 4);
	printf("Graph is built. V = %d, E = %d\n", (count - 1) / 2, count / 2);
}
void insert_edge(int v, int w) {
	node_pointer temp;
	temp = (node_pointer)malloc(sizeof(node));
	temp->vertex = w;
	temp->link = adj[v];
	adj[v]=temp;
	count++;
}
void dfs(int v) {
	node_pointer w;
	printf("%d ", v);
	visited[v] = true;
	for (w = adj[v]; w; w = w->link) {
		if (!visited[w->vertex])
			dfs(w->vertex);
	}
}
void bfs(int v) {
	node_pointer w;
	printf("%d ", v);
	visited[v] = true;
	addq(v);
	while (!is_queue_empty()) {
		v = deleteq();
		for (w = adj[v]; w; w = w->link) {
			if (!visited[w->vertex]) {
				printf("%d ", w->vertex);
				visited[w->vertex] = true;
				addq(w->vertex);
			}
		}
	}
}
void addq(Element e) {
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	temp->item = e;
	temp->link = NULL;
	if (front == NULL)	front = rear = temp;
	else {
		rear->link = temp;
		rear = temp;
	}
}
Element deleteq() {
	queue_pointer temp;
	Element item;
	if (front == NULL) return item;	//queue is empty
	item = front->item;
	temp = front;
	front = temp->link;	//front를 다음 큐를 보내고
	free(temp);	//맨앞에 큐 반환
	return item;
}
boolean is_queue_empty() {
	if (front == NULL)
		return true;
	else
		return false;
}