#include <bits/stdc++.h>
#define more_storage long long int
#define s struct
using namespace std;

s vansh_double_ll_nodes {
   more_storage data;
   s vansh_double_ll_nodes* next;
   s vansh_double_ll_nodes* prev;
};

void insert_at_first_pos(s vansh_double_ll_nodes** VC, more_storage new_elementdata){
   s vansh_double_ll_nodes* newNode = new vansh_double_ll_nodes;
   newNode->data = new_elementdata;
   newNode->next = (*VC);
   newNode->prev = NULL;
   if ((*VC) != NULL)
   (*VC)->prev = newNode;
   (*VC) = newNode;
}

void insert_After(s vansh_double_ll_nodes* prev_node, more_storage new_elementdata){
   if (prev_node == NULL) {
   cout<<"Prev is NULL";
   return;
   }
   s vansh_double_ll_nodes* newNode = new vansh_double_ll_nodes;
   newNode->data = new_elementdata;
   newNode->next = prev_node->next;
   prev_node->next = newNode;
   newNode->prev = prev_node;
   if (newNode->next != NULL)
   newNode->next->prev = newNode;
}
  
void insert_at_end_pos(s vansh_double_ll_nodes** VC, more_storage new_elementdata){
   s vansh_double_ll_nodes* newNode = new vansh_double_ll_nodes;
   s vansh_double_ll_nodes* last = *VC;
   newNode->data = new_elementdata;
   newNode->next = NULL;
   if (*VC == NULL) {
   newNode->prev = NULL;
   *VC = newNode;
    return;
    }   
    while (last->next != NULL)
    last = last->next;
    last->next = newNode;
    newNode->prev = last;
    return;
}

more_storage length_of_double_LL(s vansh_double_ll_nodes *node){
   more_storage res = 0;
   while (node != NULL)
   {
       res++;
       node = node->next;
   }
   return res;
}

void helper_delete_node(s vansh_double_ll_nodes** head_ref, s vansh_double_ll_nodes* del){
    if (*head_ref == NULL || del == NULL){
        return;
    }
    if (*head_ref == del){
        *head_ref = del->next;
    }
    if (del->next != NULL){
        del->next->prev = del->prev;
    }
    if (del->prev != NULL){
        del->prev->next = del->next;
    }
    free(del);
}

void delete_at_a_given_position(s vansh_double_ll_nodes** head_ref, more_storage n){
    if (*head_ref == NULL || n <= 0){
        return;
    }
    s vansh_double_ll_nodes* current = *head_ref;
    more_storage i;
    for (more_storage i = 1; current != NULL && i < n; i++){
        current = current->next;
    }
    if (current == NULL){
        return;
    }
    helper_delete_node(head_ref, current);
}


void showing(s vansh_double_ll_nodes* node) {
   s vansh_double_ll_nodes* last;
  
   while (node != NULL){
      cout<< node->data <<" ";
      last = node;
      node = node->next;
   }
   cout << endl;
}
  
int main() {
   s vansh_double_ll_nodes* VC = NULL;
   insert_at_end_pos(&VC, 40);
   insert_at_first_pos(&VC, 20);
   insert_at_first_pos(&VC, 100);
   insert_at_end_pos(&VC, 50);
   insert_After(VC->next, 30);
   insert_After(VC->next, 330);
  
   cout<<"Doubly linked list is as follows: ";
   showing(VC);
   cout << length_of_double_LL(VC) << '\n';

   delete_at_a_given_position(&VC,2);
   cout<<"Doubly linked list is as follows: ";
   showing(VC);
   cout << length_of_double_LL(VC) << '\n';

   delete_at_a_given_position(&VC,3);
   cout<<"Doubly linked list is as follows: ";
   showing(VC);
   cout << length_of_double_LL(VC) << '\n';
   return 0;
}