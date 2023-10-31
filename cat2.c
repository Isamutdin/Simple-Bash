#include "cat2.h"
void flag_n(int *str_num, char *ch);
void flag_b(int *str_num, char *ch);
void flag_s(int *count, int *str_num, char *ch);
void flag_e(char *ch);
void flag_t(char *ch);
void flag_v(char *ch);

int main(int argc, char **argv) {
	FILE *f;
	struct Flags flags = {0};
	char ch[256], short_flags[8] = "EenbvstT";
	int str_num = 1;

struct option long_options[] = {{"number_nonblank", no_argument, NULL, 'b'},
                                       {"number", no_argument, NULL, 'n'},
                                       {"squeeze-blank", no_argument, NULL, 's'},
                                       {0, 0, 0, 0}};

	for(int i = 1; i < argc; i++) { //для открытия файла
		if(*argv[i] != '-') { 
			f = fopen(argv[i], "r");
		}
	}

    int res = 0, index = 0;
 while ((res = getopt_long(argc, argv, short_flags, long_options, &index)) != -1) {
          switch (res) {
           	case 'n':
				flags.n = 1;
				break;
			case 'b':
				flags.b = 1;
				break;
			case 's':
				flags.s = 1;
				break;
            case 'e':
                flags.e = 1;
                break;
			case 't':
				flags.t = 1;
				break;
			case 'T':
				flags.T = 1;
				break;
			case 'E':
				flags.E = 1;
				break;
			case 'v':
				flags.v = 1;
				break;
          }
      }

	char charStr;	
	int numStr = 1;
	while(charStr = (fgetc(f) != EOF)) { 	
		if(numStr && (flags.n == 1 || (flags.b && charStr != '\n')))
			printf("%6d", ++numStr);
 		else 
			printf("%c", charStr);
	}
		

	fclose(f);
	return 0;
}









/*
	char chr = fgetc(f); 
	int number = 0, a = 0;
	while(chr != EOF && fgets(ch, 256, f)) {
		if(flags.e == 1 && chr == '\n') {
			printf("$");
		}
		if(flags.n == 1) {
			if(a == 0 && chr == '\n') {
				printf("%6d\t%c", ++number, chr);
				a == 0;
			}	
		} 
		chr = getc(f); 
		a = 1;
	}
*/

/*
	int count = 0, n = 0, q = 1;
	while(fgets(ch, 256, f) != NULL) { 
		if(flags.n == 1) 
			flag_n(&str_num, ch);
		else if(flags.b == 1) 
			flag_b(&str_num, ch);
		else if(flags.s == 1)
			flag_s(&count, &str_num, ch);
        else if(flags.e == 1 || flags.E == 1) 
            flag_e(ch);
		else if(flags.t == 1 || flags.T == 1)
			flag_t(ch);
		else if(flags.v = 1)
			flag_v(ch);
		else
			printf("%s", ch);
	}
	fclose(f);
	return 0;
}

void flag_n(int *str_num, char *ch) {
	printf("%6d\t%s", *str_num, ch);
	*str_num += 1;
}

void flag_b(int *str_num, char *ch) {
	if(*ch != '\n') {
		printf("%6d\t%s", *str_num, ch);
		*str_num += 1;
	} else {
		printf("\n");
	}
}

void flag_s(int *count, int *str_num, char *ch) {
	if(*ch != '\n') {
		printf("%s", ch);
		*count = 0;
	} else if (*ch == '\n' && *count == 0) {
		printf("%s", ch);
		*count = 1;
	} 
}

void flag_e(char *ch) {
	for(int i = 0; i < strlen(ch); i++) {
		if(ch[i] != '\n') 
			printf("%c", ch[i]);
		else if(ch[i] >= 0 && ch[i] <= 31 || ch[i] == 127) 
			printf("^%c", ch[i]^64);
		else 
			printf("$%c", ch[i]);
	}
}

void flag_t(char *ch) {
	for(int i = 0; i < strlen(ch); i++) {
		if(ch[i] == '\n') 
			printf("%c", ch[i]);
		else if(ch[i] >= 0 && ch[i] <= 31 || ch[i] == 127) {
			printf("^%c", ch[i]^64);
			if(i = strlen(ch) - 1) 
				printf("%d", strlen(ch) - 1);
		} 
		else
			printf("%c", ch[i]);
	}
}

void flag_v(char *ch) {
	for(int i = 0; i < strlen(ch); i++) {
		if(ch[i] == '\n')
			printf("%c", ch[i]);
		else if(ch[i] != '\t' && ch[i] >= 0 && ch[i] <= 31 || ch[i] == 127) 
			printf("^%c", ch[i] ^ 64);
		else
			printf("%c", ch[i]);
	}
}
*/
