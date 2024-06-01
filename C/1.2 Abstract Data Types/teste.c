// typedef struct Node{ // Assim deixa mais explícito o nome da struct
//     int element; // O elemento armazenado no nó
//     struct Node* next; // Ponteiro para o próximo nó
// } Node;

// typedef struct List{ 
//     Node* head;
//     Node* tail;
//     Node* curr;
//     int count;          // list size
// } List;

// // Ponteiros:
// Node* create_node(Node* n, int num); // Função q retorna um ponteiro para a struct "Node"
// Node* create_header(Node* nextval);
// List* create_list();

// // Operações:
// void insert(List* l, int num);
// void move_to_start(List* l);
// void move_to_end(List* l);
// void movecurr(List* l);
// void prev(List* l);
// void next(List* l);
// void printlist(List* l);
// void clear(List* l);
// int  del(List* l);
// int  length(List* l);
// int  curr_pos(List* l);
