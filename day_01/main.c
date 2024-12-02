#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extract_two_numbers_as_string_from_line(char *line, char *nbr1,
                                             char *nbr2) {
  char *nbr_start;
  //   char *nbr_end;
  int len;
  while (*line == ' ') {
    line++;
  }
  len = 0;
  nbr_start = line;
  while (!(*line == ' ' || *line == '\0')) {
    len++;
    // if (*line == ' ' && *line == '\0') {
    //   nbr_end = line;
    //   break;
    // }
    line++;
  }
  memmove(nbr1, nbr_start, len);
  nbr1[len] = '\0';
  while (*line == ' ') {
    line++;
  }
  len = 0;
  nbr_start = line;
  while (*line != ' ' && *line != '\0') {
    len++;
    // if (*line == ' ') {
    //   break;
    // }
    line++;
  }
  memmove(nbr2, nbr_start, len);
  nbr2[len] = '\0';
}

int find_max_line_length(char *file_str) {
  FILE *file;
  int c;
  int line_length;
  int max_line_length;

  line_length = 0;
  max_line_length = 0;

  file = fopen(file_str, "r");
  if (!file) {
    perror("Error opening file");
    exit(1);
  }
  while ((c = fgetc(file)) != EOF) {
    line_length++;
    if (c == '\n') {
      if (line_length > max_line_length) {
        max_line_length = line_length;
      }
      line_length = 0;
    }
    if (line_length > max_line_length) {
      max_line_length = line_length;
    }
  }
  return (max_line_length);
}

int find_line_count(char *file_str) {
  FILE *file;
  int c;
  int line_count;

  line_count = 0;

  file = fopen(file_str, "r");
  if (!file) {
    perror("Error opening file");
    exit(1);
  }
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n') {
      line_count++;
    }
  }
  return (line_count);
}

void read_file_into_arrays(int *int_array_1, int *int_array_2, char *file_str) {
  FILE *file;
  int c;
  int line_length;
  int max_line_length;
  int line_count;
  char *line;
  char *input_file_str = "input.txt";
  int nbr1;
  int nbr2;
  int total;
  char nbr1_str[10];
  char nbr2_str[10];
  int index = 0;

  //   printf("Entering read_file_into_arrays\n");
  max_line_length = find_max_line_length(input_file_str);
  line_count = find_line_count(input_file_str);
  line = (char *)malloc(max_line_length * sizeof(char));
  file = fopen(input_file_str, "r");
  if (!file) {
    perror("Error opening file");
    exit(1);
  }
  //   printf("Before while loop\n");
  int i = 0;
  while (fgets(line, max_line_length + 1, file) != NULL) {
    i++;
    // printf("line: %s\n", line);
    // printf("i: %d\n", i);
    extract_two_numbers_as_string_from_line(line, nbr1_str, nbr2_str);
    nbr1 = atoi(nbr1_str);
    nbr2 = atoi(nbr2_str);
    int_array_1[index] = nbr1;
    int_array_2[index] = nbr2;
    index++;
    // printf("nbr1: %d, nbr2: %d\n", nbr1, nbr2);
  }
  fclose(file);
  free(line);
  printf("Total: %d\n", total);
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

void sort_array_with_qsort(int *array, int size,
                           int (*compare)(const void *, const void *)) {
  qsort(array, size, sizeof(int), compare);
}

int calculate_total(int *array1, int *array2, int size) {
  int total = 0;
  int single_sum;
  single_sum = 0;
  for (int i = 0; i < size + 1; i++) {
    // printf("i: %d\n", i + 1);
    single_sum = array1[i] - array2[i];
    if (single_sum < 0) {
      single_sum *= -1;
    }
    printf("single_sum: %d\n", single_sum);
    printf("total: %d\n", total);
    total += single_sum;
  }
  return total;
}

int find_and_sum_multipliers(int *array1, int *array2, int size) {
  int multiplier = 0;
  int i;
  int j;
  int partial_sum;
  int total = 0;
  for (i = 0; i < size + 1; i++) {
    multiplier = 0;
    for (j = 0; j < size + 1; j++) {
      if (array1[i] == array2[j]) {
        multiplier++;
      }
      printf("j: %d\n", j + 1);
    }
    partial_sum = array1[i] * multiplier;

    total += partial_sum;
  }
  printf("i: %d\n", i + 1);
  printf("Total: %d\n", total);
  return total;
}

int main(int argc, char *argv[]) {
  FILE *input_file;
  int max_line_length;
  int line_count;
  char *line;
  char *input_file_str = "input.txt";
  int nrb;
  int total;

  if (argc == 2) {
    input_file_str = argv[1];
  }
  //   printf("Hello, World!\n");

  max_line_length = find_max_line_length(input_file_str);
  printf("Max line length: %d\n", max_line_length);
  line_count = find_line_count(input_file_str);
  printf("Line count: %d\n", line_count);
  char *test_string = "123 456";
  char nbr1[10];
  char nbr2[10];
  extract_two_numbers_as_string_from_line(test_string, nbr1, nbr2);
  printf("nbr1: %s\n", nbr1);
  printf("nbr2: %s\n", nbr2);
  //   int *array1 = calloc(line_count, sizeof(int));
  //   int *array2 = calloc(line_count, sizeof(int));
  int *array1 = malloc(line_count * sizeof(int));
  int *array2 = malloc(line_count * sizeof(int));
  //   printf("array1: %p\n", array1);
  read_file_into_arrays(array1, array2, input_file_str);
  printf("After read_file_into_arrays\n");
  sort_array_with_qsort(array1, line_count + 1, compare);
  for (int i = 0; i < line_count; i++) {
    printf("array1[%d]: %d\n", i, array1[i]);
  }
  //   printf("After sort_array_with_qsort\n");
  sort_array_with_qsort(array2, line_count + 1, compare);
  //   for (int i = 0; i < line_count + 1; i++) {
  //     printf("array1[%d]: %d\n ", i, array1[i]);
  //   }
  //   printf("After sort_array_with_qsort\n");
  //   total = calculate_total(array1, array2, line_count);
  //   printf("Total: %d\n", total);
  total = find_and_sum_multipliers(array1, array2, line_count);

  return 0;
}