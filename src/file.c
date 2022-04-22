#include "include/file.h"

const char* create_file(const char* name){
	FILE* fp = fopen(name, "wx");
	if(!fp){
		perror("File creation failed");
		return NULL;
	}
	fclose(fp);
	return name;
}

const char* delete_file(const char* name){
	int result = remove(name);
	if(result != 0){
		perror("File deletion failed");
		return name;
	}
	else{
		return NULL;
	}
}

char* read_last_line_from_file(const char* name){
	FILE* fp = fopen(name, "r");
	if(!fp){
		perror("File open failed");
		return NULL;
	}
	long prev = 0;
	long last_new_line = 0;
	int c;
	int l = 0;
	int p = 0;
	while((c = fgetc(fp)) != EOF){
		l++;
		if(c == '\n'){
			p = l;
			l = 0;
			prev = last_new_line;
			last_new_line = ftell(fp);
		}
	}
	fseek(fp, prev, SEEK_SET);
	char* arr = (char*)calloc(p, sizeof(char));
	for(size_t i = 0; i != p; i++){
		arr[i] = 0;
	}
	l = 0;
	while((c = fgetc(fp)) != '\n'){
		arr[l] = c;
		l++;
	}
	fclose(fp);
	return arr;
};

void add_line_to_file(const char* name, char* line){
	FILE* fp = fopen(name, "a");
	if(!fp){
		perror("File open failed");
	}
	fputs(line, fp);	
	putc('\n', fp);
	fclose(fp);
};
