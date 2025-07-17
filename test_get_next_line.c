#include "get_next_line.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

# define STDIN 0

int main() {
	int fd = open("./files/empty", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/multiple_nlx5.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/alternate_line_nl_no_nl.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/alternate_line_nl_with_nl.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/multiple_line_no_nl.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/multiple_line_with_nl.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/multiple_nl.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/just_one_newline", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/test1", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/test2", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/test3", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/small_no_newline", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("----------\n");

	fd = open("./files/big_no_newline", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n----------\n");

	fd = STDIN;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n----------\n");
}
