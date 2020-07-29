#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "adj_matrix.h"

void main()
{
	char	c;
	int		i, v;

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
	insert_edge(2, 5);
	insert_edge(3, 5);
	insert_edge(4, 5);
	printf("Graph is built  V = %d, E = %d", count - 1, count);
}
void insert_edge(int v, int w) {
	adj[v][w] = 1;
	adj[w][v] = 1;
	count++;
}
void dfs(int v) {
	int i;
	visited[v] = 1;
	printf("%d ", v);
	for (i = 1; i <= MAX_VERTICES; i++) {
		if (adj[v][i] && !visited[i]) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	int i;
	printf("%d ", v);
	visited[v] = true;
	addq(v);
	while (!is_queue_empty()) {
		v = deleteq();
		for(i=0;i<MAX_VERTICES;i++)
			if (adj[v][i] && !visited[i]) {
				visited[i] = true;
				printf("%d ", i);
				addq(i);
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