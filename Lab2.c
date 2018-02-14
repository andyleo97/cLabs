#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
  char firstName[100];
  char lastName[100];
  int age;
};

typedef struct record record;

static int sizeOfDatabase;
static int accessesToTheDatabase;
const unsigned long sizeofRec = sizeof(record);

record *addRecord(record *current, record newRec);
record *deleteRecord(record *current);
record createNewRecord();
void printDatabase(record *database);

int main(int argc, char const *argv[]) {
  record *currentDB = NULL;

  while (1) {

    int choice = 0;
    printf("MENU\n=======\n");
    printf("1. Print all records\n2. Print number of records\n");
    printf("3. Print size of database\n4. Add record\n");
    printf("5. Delete record\n");
    printf("6. Print number of accesses to database\n7. Exit\n");

    scanf("%d", &choice);
    while ((getchar()) != '\n')
      ;

    switch (choice) {
    case 1:
      printDatabase(currentDB);
      continue;
    case 2:
      fprintf(stderr, "The size of the database is: %d\n", sizeOfDatabase);
      continue;
    case 3:
      fprintf(stderr, "The size of the database is: %lu\n",
              (sizeOfDatabase * sizeofRec));
      continue;
    case 4:
      currentDB = addRecord(currentDB, createNewRecord());
      continue;
    case 5:
      currentDB = deleteRecord(currentDB);
      continue;
    case 6:
      fprintf(stderr, "The number of database accesses is: %d\n",
              accessesToTheDatabase);
      continue;
    case 7:
      exit(0);
    default:
      fprintf(stderr, "Must enter a number between 1-7\n");
    }
  }
  return 0;
}

record *addRecord(record *current, record newRec) {

  record *newCurrent = malloc((sizeOfDatabase + 1) * sizeofRec);

  int i = 0;

  record *nextNew = newCurrent;
  record *nextCurrent = current;
  for (i = 0; i < sizeOfDatabase; i++) {
    memcpy(nextNew, nextCurrent, sizeofRec);
    nextNew = nextNew + sizeofRec;
    nextCurrent = nextCurrent + sizeofRec;
  }
  if (current != NULL) {
    free(current);
  }

  memcpy(nextNew, &newRec, sizeofRec);
  sizeOfDatabase++;
  accessesToTheDatabase++;

  return newCurrent;
}

record *deleteRecord(record *current) {
  if (sizeOfDatabase == 0) {
    fprintf(stderr, "There is nothing in the Database.\n");
    return NULL;
  }
  record *newCurrent = NULL;
  if (sizeOfDatabase > 1) {
    newCurrent = malloc((sizeOfDatabase - 1) * (sizeofRec));
  }
  sizeOfDatabase--;

  record *nextNew = newCurrent;
  record *nextCurrent = current;
  for (int i = 0; i < sizeOfDatabase; i++) {
    memcpy(nextNew, nextCurrent, sizeofRec);
    nextNew = nextNew + sizeofRec;
    nextCurrent = nextCurrent + sizeofRec;
  }

  free(current);
  accessesToTheDatabase++;
  return newCurrent;
}

record createNewRecord() {
  char first[100];
  char last[100];
  int age;
  printf("Enter first name:\n");
  scanf("%s", (char *)&first);
  printf("Enter last name:\n");
  scanf("%s", (char *)&last);
  printf("Enter age:\n");
  scanf("%d", &age);
  record rec;
  strncpy(rec.firstName, first, 100);
  strncpy(rec.lastName, last, 100);
  rec.age = age;

  return rec;
}

void printDatabase(record *database) {
  if (sizeOfDatabase == 0) {
    fprintf(stderr, "There are no entries into the database yet.\n");
  }
  record *x = database;
  for (int i = 0; i < sizeOfDatabase; i++) {
    fprintf(stderr, "Record #%d\n\tFirstname: %s\n\tLastname: %s\n\tAge: %d\n",
            (i + 1), x->firstName, x->lastName, x->age);
    x = x + sizeofRec;
  }

  accessesToTheDatabase++;
}
