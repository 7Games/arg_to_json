CC     := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic

SOURCES := "arg_to_json.c"
OUT     := "arg_to_json"

bugless: arg_to_json.c
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT)

.PHONY: run
run: arg_to_json
	./$(OUT)

