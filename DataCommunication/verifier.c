#include <stdio.h>
#include <string.h>

int main() {
	char frame[50] = { NULL };		//11011101
	char original_frame[50] = { NULL };
	char sub_frame[50] = { NULL };
	char generator[50] = { NULL };	//101
	char divide[50] = { NULL };
	char remainder[50] = { NULL };
	scanf("%s", frame);		//read n-bit message
	scanf("%s", generator);	//k-bit polynomial
	int size = strlen(generator);
	int position = 0;	//position of generator
	int crc_num = 0;	//remainder
	int result;

	strcpy(sub_frame, frame);
	strcpy(original_frame, frame);	//for alter calculation, save frame

	for (int i = 0; i < strlen(generator) - 1; i++) {	//add 0 * dimension of generator
		char c[2] = "0";
		strcat(sub_frame, c);
	}

	//printf("before frame = %s\n", sub_frame);
	//printf("repeat: %d\n", strlen(sub_frame) - strlen(generator));
	for (int i = 0; i < strlen(sub_frame) - strlen(generator); i++) {	//n-1¹ø loop
		for (int i = 0; i < size; i++) {
			divide[i] = sub_frame[i + position];
		}
		
		//printf("partition : %s\n", divide);
		
		if (atoi(divide) < atoi(generator)) {	//no divide case
			position++;
			//printf("after cal frame = %s\n", sub_frame);
			continue;
		}

		for (int i = 0; i < size; i++) {	//dicide k bit and CRC with XOR
			if (sub_frame[i + position] == generator[i]) {
				sub_frame[i + position] = '0';
			}
			else if (sub_frame[i + position] != generator[i]) {
				sub_frame[i + position] = '1';
			}
		}
		//printf("after frame = %s\n", sub_frame);
		position++;
	}
	crc_num = atoi(sub_frame);	//add remainder to frame
	sprintf(remainder, "%d", crc_num);
	strcat(frame, remainder);

	position = 0;

	for (int i = 0; i < strlen(frame) - strlen(generator); i++) {	//repeat CRC calculation, if remainder is 0 = correct
		for (int i = 0; i < size; i++) {							//else error
			divide[i] = frame[i + position];
		}

		//printf("partiton : %s\n", divide);

		if (atoi(divide) < atoi(generator)) {	//no devide case
			position++;
			//printf("after frame = %s\n", frame);
			continue;
		}

		for (int i = 0; i < size; i++) {	//dicide k bit and CRC with XOR
			if (frame[i + position] == generator[i]) {
				frame[i + position] = '0';
			}
			else if (frame[i + position] != generator[i]) {
				frame[i + position] = '1';
			}
		}
		//printf("after frame = %s\n", frame);
		position++;

	}
	result = atoi(frame);
	if (result == 0) {
		printf("Corrct!!\n");
	}
	else printf("Error!!\n");
}
