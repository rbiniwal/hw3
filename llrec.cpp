#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if (head == NULL)
  {
    smaller = NULL;
    larger = NULL;
    return;
  }
    Node* n = head;
    head = head->next;
  if (n->val <= pivot)
  {
    if(smaller != NULL)
    {
      smaller = n; 
    }   
    llpivot(head, smaller->next, larger, pivot);
  }
  else
  {   
    if(larger != NULL)
    {
      larger = n;
    }
    llpivot(head, smaller, larger->next, pivot);
  }
}

