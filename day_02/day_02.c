#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// find the max line length, as the title says
int find_max_line_length() {
  char *file_name = "input.txt";
  FILE *file;
  int c;
  int line_length = 0;
  int max_line_length = 0;

  file = fopen(file_name, "r");
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

int find_line_count() {
  FILE *file;
  int c;
  int line_count;
  char *file_name = "input.txt";
  line_count = 0;

  file = fopen(file_name, "r");
  if (!file) {
    perror("Error opening file");
    exit(1);
  }
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n') {
      line_count++;
    }
  }
  line_count++;
  return (line_count);
}

int check_array_ascending_order(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return (0);
    }
  }
  return (1);
}

int check_array_descending_order(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      return (0);
    }
  }
  return (1);
}

int check_array_ascending_or_descending_order(int *arr, int size) {
  if (check_array_ascending_order(arr, size)) {
    return (1);
  } else if (check_array_descending_order(arr, size)) {
    return (1);
  }
  return (0);
}

void convert_report_str_into_report_int_arr(char *report_str) {
  printf("Entering convert_report_str_into_report_int_arr\n");
  int elements_in_report = 0;
  int *report_arr = NULL;
  int i = 0;
  int j = 0;
  //   int report_str_len = strlen(report_str);
  //   report_arr = (int *)malloc(report_str_len * sizeof(int));
  printf("report_str: %s\n", report_str);
  while (report_str[i] != '\0') {
    printf("report_str[%d]: %c\n", i, report_str[i]);
    // printf("first while\n");
    while (report_str[i] == ' ' && report_str[i] != '\0') {
      i++;
    }
    if (isdigit(report_str[i])) {
      elements_in_report++;
      i++;
      printf("elements_in_report: %d\n", elements_in_report);
      while (isdigit(report_str[i] && report_str[i] != '\0')) {
        i++;
      }
    }
    if (report_str[i] != '\0') {
      i++;
    }
  }
  printf("elements_in_report: %d\n", elements_in_report);
  report_arr = malloc(elements_in_report * sizeof(int));
  i = 0;
  j = 0;
  int nbr = 0;
  while (report_str[i] != '\0') {
    while (report_str[i] == ' ' && report_str[i] != '\0') {
      i++;
    }
    report_arr[j] = atoi(&report_str[i]);
    // report_arr[j] = atol(&report_str[i]);
    printf("report_arr after atol [%d]: %d\n", j, report_arr[j]);
    j++;
    printf("report_str[%d]: %c\n", i, report_str[i]);
    while (isdigit(report_str[i]) && report_str[i] != '\0') {
      //   printf("second while\n");
      i++;
    }
    if (report_str[i] != '\0') {
      i++;
    }
  }
  for (int k = 0; k < elements_in_report; k++) {
    printf("report_arr[%d]: %d\n", k, report_arr[k]);
  }

  if (check_array_ascending_or_descending_order(report_arr, elements_in_report)) {
    printf("Safe report\n");
  }
  else if (check_distance_between_elements(report_arr, elements_in_report)) {
    printf("Safe report\n");
  }
  else {
    printf("Dangerous report\n");
  }

  free(report_arr);
}

/*
while (report_str[i] != '\0') {
  if (report_str[i] == ' ') {
    i++;
  }
  report_arr[j] = report_str[i] - '0';
  i++;
  j++;


	printf("Dangerous report\n");", k, report_arr[k]);
}
*/

// read the file adn divide it into strings
void parse_reports() {
  FILE *file;

  char *file_name = "input.txt";
  int max_line_length_c_str = 0;
  char *line = NULL;
  int number_of_reports = 0;
  char *report_str = NULL;
  char **reports_str_arr = NULL;
  int *reports_arr = NULL;

  max_line_length_c_str = find_max_line_length() + 1;
  file = fopen(file_name, "r");
  if (!file) {
    perror("Error opening file");
    exit(1);
  }
  number_of_reports = find_line_count();
  report_str = (char *)malloc(max_line_length_c_str * sizeof(char));
  reports_str_arr = (char **)malloc(number_of_reports * sizeof(char *));
  int i = 0;
  //   line = (char *)malloc(max_line_length * sizeof(char));
  while (fgets(report_str, max_line_length_c_str + 1, file) != NULL) {
    reports_str_arr[i] = strdup(report_str);
    i++;
    // printf("report_str[%d]: %s\n", i, report_str);
  }
  for (int j = 0; j < number_of_reports; j++) {
    convert_report_str_into_report_int_arr(reports_str_arr[j]);
  }

  printf("Number of reports: %d\n", number_of_reports);
}

int main() {
  int safe_reports;
  safe_reports = 0;
  printf("Hello, World!\n");
  parse_reports();
}