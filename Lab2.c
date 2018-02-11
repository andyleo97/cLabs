#include <stdio.h>
#include <stdlib.h>
static int numOfRecords;
static int sizeOfDatabase;
static int accessesToTheDatabase;

struct record{
  char firstName[100];
  char lastName[100];
  int age;
};

int main(int argc, char const *argv[]) {
while (1) {
  int choice;
  printf("MENU\n=======\n");
  printf("1. Print all records\n2. Print number of record\n");
  printf("3. Print size of database\n4. Add record\n");
  printf("5. Delete record\n");
  printf("6. Print number of accesses to database\n7. Exit\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    exit(0);
  }
}
  return 0;
}
