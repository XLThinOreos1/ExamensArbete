#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char title[100];
  char genre[50];
  char studio[50];
  int episodes;
} Anime;

int jsonThing() {
  FILE *file = fopen("./database.json", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *data = (char *)malloc(length + 1);
  if (data == NULL) {
    perror("Error allocating memory");
    fclose(file);
    return EXIT_FAILURE;
  }

  fread(data, 1, length, file);
  data[length] = '\0';
  fclose(file);

  cJSON *json = cJSON_Parse(data);
  free(data);
  if (json == NULL) {
    fprintf(stderr, "Error parsing JSON: %s\n", cJSON_GetErrorPtr());
    return EXIT_FAILURE;
  }

  char *formatted_json = cJSON_Print(json);
  if (formatted_json == NULL) {
    fprintf(stderr, "Error printing JSON\n");
    cJSON_Delete(json);
    return EXIT_FAILURE;
  }

  printf("%s\n", formatted_json);

  free(formatted_json);
  cJSON_Delete(json);

  return EXIT_SUCCESS;
}

int main() {
  jsonThing();
  return 0;
}
