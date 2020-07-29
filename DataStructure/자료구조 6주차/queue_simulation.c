#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue_simulatiion.h"

//ID가 id, 요청시간이 arrival_time, 프린트시간이 duration인 Job을 큐에 삽입
void insert_job_into_queue(int id, int arrival_time, int duration) {
	Job p;
	p.id = id;
	p.arrival_time = arrival_time;
	p.duration = duration;
	addq(p);
	//id, arrival_time, duration 설정 후 job p를 큐에 삽입
	//addq()사용
	printf("새 job <%d>에 들어왔습니다. 프린트 시간은 = %d 입니다.\n", id, duration);
}
//다음 job을 큐에서 꺼내 수행(현재 job id,remaining time등 설정)
void process_next_job() {
	Job p;
	p = deleteq();
	current_job_id = p.id;
	remaining_time = p.duration - 1;
	total_wait_time += (current_time - p.arrival_time);
	//deleteq()사용
	//다음 job을 큐에서 꺼내와
	// current_job_id, remaining_time (duration -1);
	//	total_wait_time(total_wait_time + (current_time - arrival_time)설정
	++num_printed_jobs;
	printf("프린트를 시작합니다- job<%d>...\n", current_job_id);
}
boolean is_job_arrived() {	//새로운 job이 도착했는지를 랜덤하게 결정. True일 확률은 ARRIVAL_PROB
	if (random() < JOB_ARRIVAL_PROB)
		return true;
	else
		return false;
}
boolean is_printer_idle() {	//프린터가 놀고 있으면(현재 job의 remaining time<=0) true
	if (remaining_time <= 0)
		return true;
	else
		return false;
}

double random() {	//0.0~1.0사이의 랜덤 값을 반환
	return rand() / (double)RAND_MAX;
}
int get_random_duration() {	//1-MAX_PRINTING_TIME+1 사이의 랜덤 값을 반환
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
	front = temp->link;	//front를 다음 큐로 보내고
	free(temp);	//맨앞에 큐 반환
	return item;
}
boolean is_queue_empty() {
	if (front == NULL)
		return true;
	else
		return false;
}
void queue_show() {//현재 큐에 있는 job의 id들을 프린트
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

		//새 job이 들어오면 큐에 삽입
		if (is_job_arrived()) {
			++new_job_id;
			duration = get_random_duration();
			insert_job_into_queue(new_job_id, current_time, duration);
		}
		//프린터가 놀고 있으면 다음 작업을 수행
		if (is_printer_idle()) {
			if (!is_queue_empty())	process_next_job();
		}
		//아직 프린트 중
		else {
			printf("아직 Job<%d>을 프린트하고 있습니다...\n", current_job_id);
			--remaining_time;
		}
		//현재 큐의 상태를 보여줌
		printf("현재 프린터 큐: [ ");
		queue_show();
		printf(" ]\n");
		++current_time;	
	}
	printf("완료된 프린트 job = %d 개\n", num_printed_jobs);
	printf("평균 지연 시간	= %lf 단위시간\n", (double)total_wait_time / num_printed_jobs);
		//통계 자료 출력 -완료된 프린트 job수, 평균 지연시간 (total_wait_time/num_printed_jobs)
}