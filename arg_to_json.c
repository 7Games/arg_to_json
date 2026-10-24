// make run
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    printf("{");
    for (int i = 1; i < argc; i++) {
	if (i + 1 >= argc) {
	    break;
	}

	size_t flag_len = strlen(argv[i]);
	size_t value_len = strlen(argv[i+1]);
	if (flag_len == 0) {
	    continue;
	}
	if (value_len == 0) {
	    continue;
	}

	char* flag = (char*)malloc(sizeof(char) * flag_len);
	strncpy(flag, argv[i], flag_len + 1);
	strncat(flag, "\0", 1);
	char* value = argv[++i];

	char* clean_flag = flag;
	int skip = 0;
	while ((unsigned char)*clean_flag != '\0') {
	    if (skip == 1) break;
	    switch ((unsigned char)*clean_flag) {
	    case '\0':
		++i;
		break;
	    case ' ':
	    case '-':
		++clean_flag;
		flag_len--;
		break;
	    default:
		skip = 1;
		break;
	    }
	}

	if (flag_len == 0) {
	    continue;
	}

	if (i != 2 && i != argc) printf(",");

	printf("\"%s\":\"%s\"", clean_flag, value);

	free(flag);
    }
    printf("}");

    return 0;
}
