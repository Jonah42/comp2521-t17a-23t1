int i = 10; // initialisation
while (i >= 0) { // condition
    printf("%d\n", i); // code
    i--; // increment
}

for (int i = 10; i >= 0; i--) {
    printf("");
}

// Input:
// - a is a valid pointer to the start of an array of ints
// - n is a positive int indicating how many elements in a[]
// Output:
// - returns true if a[i] <= a[i + 1] for all i in [0..n - 2]
bool isSorted(int *a, int n) {
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            return false;
        }
    }
    return true;
}







char *numToDay(int n) {
    assert(0 <= n && n <= 6);
    char *day;
    if (n == 0) {
        day = "Sun";
    } else if (n == 1) {
        day = "Mon";
    } else if (n == 2) {
        day = "Tue";
    } else if (n == 3) {
        day = "Wed";
    } else if (n == 4) {
        day = "Thu";
    } else if (n == 5) {
        day = "Fri";
    } else if (n == 6) {
        day = "Sat";
    }
    return day;
}

switch (n) {
    case 0: 
        day = "Sun"; \
        break;
    case 1:
        day = "Mon";
        break;
    ...
    default:
        day = "???";
        break;

}


[<cond> ? <true_val> : <false_val>]

int ch = getchar();

char *type;

type = isdigit(ch) ? "digit" : "non-digit";

if (isdigit(ch)) {
    type = "digit";
} else {
    type = "non-digit";
}

printf("'%c' is a %s\n", ch, type);


typedef int Integer;

int x = 0;
Integer x = 0;

struct point {
    int x;
    int y;
};
typedef struct point Point;

struct point p = {0,1};
Point p = {0,1};

struct node {
    int value;
    struct node *next;
};
typedef struct node *Node;

struct node * curr = NULL;
Node curr = NULL;







typedef struct node {
    int value;
    struct node *next;
} Node;

typedef Node *List; // pointer to first node

int sumList(Node list) {
    int sum = 0;
    for (List curr = list; curr != NULL; 
            curr = curr->next) {
        sum += curr->value;
    }
    return sum;
}

struct node n;
Node n2;


struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

void listDelete(struct list *l, int value) {
    if (l->head == NULL) {
        return;
    } else if (l->head->value == value) {
        struct node * deleteMe = l->head;
        l->head = l->head->next;
        free(deleteMe);
    } else {
        for (struct node * curr = l->head; curr->next != NULL; curr = curr->next) {
            if (curr->next->value == value) {
                struct node * deleteMe = curr->next;
                curr->next = curr->next->next;
                free(deleteMe);
                break;
            }
        }
    }
}

 - empty list
 - first
 - last
 - middle
 - not in there

Use gdb for segfaULTS!!
