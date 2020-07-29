
typedef struct {
	char name[10];
	int id;
	char grade[4];
} StudentRecord;

StudentRecord r[100];
int num_record = 0;
char *fname = "grade.txt";

void read_record(char *fname);
void print_record();
void search_record();
void change_record();
void write_record(char *fname);

void read_record(char *fname)
{
	int i = 0;
	FILE *ifp;

	ifp = fopen(fname, "r");
	while (fscanf(ifp, "%s %d %s", r[i].name, &r[i].id, r[i].grade) == 3)
		++i;
	num_record = i;
	fclose(ifp);
}

void print_record()
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%s %d %s\n", r[i].name, r[i].id, r[i].grade);
	}
}
void search_record()
{
	int name[10];
	scanf("%s", name);
	for (int i = 0; i < 10; i++)
	{
		if (strcmp(r[i].name, name) == 0)
		{
			printf("%s %d %s\n", r[i].name, r[i].id, r[i].grade);
		}
	}
}
void change_record()
{
	char change_grade[4];
	int name[10];
	scanf("%s", name);
	for (int i = 0; i < 10; i++)
	{
		if (strcmp(r[i].name, name) == 0)
		{
			printf("바꿀 학점 입력 : ");
			scanf("%s", change_grade);
			strcpy(r[i].grade, change_grade);
		}
	}
}
void write_record(char *fname)
{
	int i;
	FILE *ofp;
	ofp = fopen(fname, "w+");

	for (i = 0; i < 4; i++)
	{
		fprintf(ofp, "%s %d %s\n", r[i].name, r[i].id, r[i].grade);
	}

	fclose(ofp);
}