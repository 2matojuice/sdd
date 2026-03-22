#include <stdio.h> // printf; scanf; etc.
#include <stdlib.h> // malloc; free; calloc ...
#include <string.h> // strcpy; strlen;  ...

/*
 * --- STRUCTURES ---
 * Structures group different data types together.
 */
typedef struct {
    char *name;
    int age;
} Student;

/*
 * --- CALL STACK DEMO ---
 * Let's create a call stack of height 3: main -> first_step -> second_step -> third_step.
 */
void third_step(int x) {
    // BREAKPOINT HERE: Observe the call stack in your debugger
    printf("  [Step 3] Reached with value %d. Look at the \"Call Stack\" panel!\n", x);
}

void second_step(int b) {
    int c = b * 2;
    printf("  [Step 2] Input %d, doubling to %d\n", b, c);
    third_step(c);
}

void first_step(int a) {
    int b = a + 5;
    printf("  [Step 1] Input %d, adding 5 to get %d\n", a, b);
    second_step(b);
}

/*
 * --- CONDITIONS and LOOPS ---
 */
void conditions_loops_demo() {
    printf("\n--- Conditions and Loops ---\n");
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            printf("  Iteration %d: Even\n", i);
        } else {
            printf("  Iteration %d: Odd\n", i);
        }
    }
}

/*
 * --- STRINGS ---
 */
void strings_demo() {
    printf("\n--- Strings ---\n");
    char message[] = "Hello";
    char name[20];
    strcpy(name, "C Learner");
    printf("  %s, %s!\n", message, name);
}

/*
 * --- POINTERS (MALLOC, FREE) ---
 */
void pointers_malloc_demo() {
    printf("\n--- Pointers (malloc/free) ---\n");
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL) return;

    *p = 42;
    printf("  Pointer p stores address %p and value %d\n", (void *)p, *p);
    free(p);
}

/*
 * --- STRUCTURES and POINTERS ---
 */
void structures_demo() {
    printf("\n--- Structures ---\n");
    Student s;
    s.name = "Alice";
    s.age = 20;
    printf("  Static struct: %s, age %d\n", s.name, s.age);

    Student *ps = (Student *)malloc(sizeof(Student));
    if (ps != NULL) {
        ps->name = strdup("Bob");
        ps->age = 22;
        printf("  Dynamic struct: %s, age %d\n", ps->name, ps->age);
        free(ps->name);
        free(ps);
    }

    ps = &s; // Pointing to the static struct
    printf("  Pointer to static struct: %s, age %d\n", ps->name, ps->age);
}

/*
 * --- DOUBLE POINTERS ---
 */
void double_pointers_demo() {
    printf("\n--- Double Pointers ---\n");
    int count = 3;
    // An array of pointers (double pointer)
    int **array = (int **)malloc(count * sizeof(int *));
    if (array == NULL) return;

    for (int i = 0; i < count; i++) {
        array[i] = (int *)malloc(sizeof(int));
        *array[i] = i * 100;
    }

    for (int i = 0; i < count; i++) {
        printf("  array[%d] points to value %d\n", i, *array[i]);
    }

    // Cleanup: free nested pointers first!
    for (int i = 0; i < count; i++) {
        free(array[i]);
    }
    free(array);
}

void my_function() {
    char* str = "Hello World";
    char * str2 = str;
    free(str);
    printf("%s\n", str2);

}

void my_fucntion() {
    char* str = (char*)malloc(sizeof(char)*100);

    *str = 'H';
    *(str + 1) = "e";
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] =' ';

    char* str2 = str+6;
    *str2 = 'W';
    
    //strcpy(str, "Hello Wolrd");

    int size = strlen(str);
    printf("%s (length is %d)\n", str, size);
    free(str);
}

int main(int argc, char **argv) {
    
    int x = 3;
    my_function(x);
    
    printf("%d\n", x);
    return 0;
}

