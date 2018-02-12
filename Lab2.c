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
const int sizeofRec = sizeof(record);

record** addRecord(record **current, record newRec);
record** deleteRecord();
record createNewRecord();
void printDatabase(record **database);

int main(int argc, char const *argv[]) {
  record **currentDB;

  while (1) {

    int choice;
    printf("MENU\n=======\n");
    printf("1. Print all records\n2. Print number of records\n");
    printf("3. Print size of database\n4. Add record\n");
    printf("5. Delete record\n");
    printf("6. Print number of accesses to database\n7. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
    case 1:

      continue;
    case 2:
      fprintf(stderr, "The size of the database is: %d\n", sizeOfDatabase);
      continue;
    case 3:
    fprintf(stderr, "The size of the database is: %lu\n", (sizeOfDatabase * sizeof(sizeofRec)));
      continue;
    case 4:
      currentDB = addRecord(currentDB, createNewRecord());
      continue;
    case 5:
    currentDB =  deleteRecord();
      continue;
    case 6:
      fprintf(stderr, "%The number of database accesses is: %d\n", accessesToTheDatabase);
      continue;
    case 7:
      exit(0);
    }
  }
  return 0;
}

record** addRecord(record **current, record new) {

     record** newCurrent = malloc((sizeOfDatabase + 1) * sizeof(sizeofRec));

    for (int i = 0; i < sizeOfDatabase; i++) {
      strncpy(newCurrent[i]->firstName, current[i]->firstName, 100);
      strncpy(newCurrent[i]->lastName, current[i]->lastName, 100);
      newCurrent[i]->age = current[i]->age;
    }
    free(current);

    strncpy(newCurrent[sizeOfDatabase]->firstName, current[sizeOfDatabase]->firstName, 100);
    strncpy(newCurrent[sizeOfDatabase]->lastName, current[sizeOfDatabase]->lastName, 100);
    newCurrent[sizeOfDatabase]->age = current[sizeOfDatabase]->age;
    sizeOfDatabase++;
    accessesToTheDatabase++;

    return newCurrent;

}

record** deleteRecord(){
    if (sizeOfDatabase == 0) {
      fprintf(stderr, "There is nothing in the Database.\n");
      return NULL;
    }
    record **newRecord = NULL;
    if (sizeOfDatabase > 1) {
      newRecord = malloc((sizeOfDatabase - 1) * (sizeofRec));
    }
    sizeOfDatabase--;


    for (int i = 0; i < sizeOfDatabase; i++) {
      strncpy(newCurrent[i]->firstName, current[i]->firstName, 100);
      strncpy(newCurrent[i]->lastName, current[i]->lastName, 100);
      newCurrent[i]->age = current[i]->age;
    }
    free(current);
    accessesToTheDatabase++;

}

record createNewRecord() {
  char first[100];
  char last[100];
  int age;
  printf("Enter first name:\n");
  scanf("%s", &first);
  printf("Enter last name:\n");
  scanf("%s", &last);
  printf("Enter age:\n");
  scanf("%d", &age);
  record rec;
  strncpy(rec.firstName, first, 100);
  strncpy(rec.lastName, last, 100);
  rec.age = age;
  printf("first: %s\n", rec.firstName);
  printf("last: %s\n", rec.lastName);
  printf("age: %d\n", rec.age);

  return rec;
}

void printDatabase(record **database){
  for (int i = 0; i < sizeOfDatabase; i++) {
    fprintf(stderr, "Record #%d\n\tFirstname: %s\n\tLastname: %s\n\tAge: %d\n", database.firstName, database.lastName, database.age);

  }
  accessesToTheDatabase++;

}
