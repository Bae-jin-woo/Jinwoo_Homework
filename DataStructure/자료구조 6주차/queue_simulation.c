#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue_simulatiion.h"

//ID�� id, ��û�ð��� arrival_time, ����Ʈ�ð��� duration�� Job�� ť�� ����
void insert_job_into_queue(int id, int arrival_time, int duration) {
	Job p;
	p.id = id;
	p.arrival_time = arrival_time;
	p.duration = duration;
	addq(p);
	//id, arrival_time, duration ���� �� job p�� ť�� ����
	//addq()���
	printf("�� job <%d>�� ���Խ��ϴ�. ����Ʈ �ð��� = %d �Դϴ�.\n", id, duration);
}
//���� job�� ť���� ���� ����(���� job id,remaining time�� ����)
void process_next_job() {
	Job p;
	p = deleteq();
	current_job_id = p.id;
	remaining_time = p.duration - 1;
	total_wait_time += (current_time - p.arrival_time);
	//deleteq()���
	//���� job�� ť���� ������
	// current_job_id, remaining_time (duration -1);
	//	total_wait_time(total_wait_time + (current_time - arrival_time)����
	++num_printed_jobs;
	printf("����Ʈ�� �����մϴ�- job<%d>...\n", current_job_id);
}
boolean is_job_arrived() {	//���ο� job�� �����ߴ����� �����ϰ� ����. True�� Ȯ���� ARRIVAL_PROB
	if (random() < JOB_ARRIVAL_PROB)
		return true;
	else
		return false;
}
boolean is_printer_idle() {	//�����Ͱ� ��� ������(���� job�� remaining time<=0) true
	if (remaining_time <= 0)
		return true;
	else
		return false;
}

double random() {	//0.0~1.0������ ���� ���� ��ȯ
	return rand() / (double)RAND_MAX;
}
int get_random_duration() {	//1-MAX_PRINTING_TIME+1 ������ ���� ���� ��ȯ
	return (int)(MAX_PRINTING_TIME*random()) + 1;
}

void addq(Job e) {
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	temp->item = e;
	temp->link = NULL;
	if (front == NULL)	front = rear = temp;
	else {
		rear->link = temp;
		rear = temp;
	}
}
Element	deleteq() {
	queue_pointer temp;
	Element item;
	if (front == NULL) return item;	//queue is empty
	item = front->item;
	temp = front;
	front = temp->link;	//front�� ���� ť�� ������
	free(temp);	//�Ǿտ� ť ��ȯ
	return item;
}
boolean is_queue_empty() {
	if (front == NULL)
		return true;
	else
		return false;
}
void queue_show() {//���� ť�� �ִ� job�� id���� ����Ʈ
	queue_pointer temp;
	temp = front;
	while (temp) {
		printf(" %d ", (temp->item).id);
		temp = temp->link;
	}
}
int main() {
	int duration;

	srand(time(NULL));
	while (current_time < MAX_SIMUL_TIME) {
		printf("\n-----time %d -----\n", current_time);

		//�� job�� ������ ť�� ����
		if (is_job_arrived()) {
			++new_job_id;
			duration = get_random_duration();
			insert_job_into_queue(new_job_id, current_time, duration);
		}
		//�����Ͱ� ��� ������ ���� �۾��� ����
		if (is_printer_idle()) {
			if (!is_queue_empty())	process_next_job();
		}
		//���� ����Ʈ ��
		else {
			printf("���� Job<%d>�� ����Ʈ�ϰ� �ֽ��ϴ�...\n", current_job_id);
			--remaining_time;
		}
		//���� ť�� ���¸� ������
		printf("���� ������ ť: [ ");
		queue_show();
		printf(" ]\n");
		++current_time;	
	}
	printf("�Ϸ�� ����Ʈ job = %d ��\n", num_printed_jobs);
	printf("��� ���� �ð�	= %lf �����ð�\n", (double)total_wait_time / num_printed_jobs);
		//��� �ڷ� ��� -�Ϸ�� ����Ʈ job��, ��� �����ð� (total_wait_time/num_printed_jobs)
}