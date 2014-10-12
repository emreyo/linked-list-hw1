/* emreyo */
#include <iostream>
using namespace std;

template <class T>   // adt node struct( definition)
struct node
{
       T info;       // info field of the node
       node <T> *link;      // link field of the node (- pointer to a node)
};


template <class T>          // adt LinkedList class
class Linkedlist
{
      protected:            // protected filed:
                node <T> *head, *last; // head and last pointers
                int count; // counter to hold number of elements
      public:              //public field
             Linkedlist() // constructor function of the LinkedList class
             {
                         head = last = NULL; // initialize data members 'head' and 'last' with NULL - there' s no element
                         count = 0;          //initialize data member 'count' to 0 - there' s no element yet
             }
             
             bool emptylist() // list is empty or not - empty is 1
             {
                  return (head == NULL); //returns 1 or 0, empty or not empty
             }
             
             int length() // element number of the LinkedList
             {
                 return count; // returns number of elements - data member 'count'
             }
             
             void destroylist();  // destroys the LL
             ~Linkedlist()        // destructor
             {
                          destroylist(); // destructor calls the 'destroylist()' function
             }
             void insertfirst(T&);       // insertion an element before others
             void insertlast(T&);        // insertion an element after others
             void deletenode(T&);        // deletes node - by the argument
             friend ostream & operator <<(ostream &,Linkedlist <T>&);      // overloaded << operator func defn

             node<T> *search(T&); // search function
};

template <class T>
void Linkedlist<T>::destroylist() // destroylist() function - destroy LL, all the elements
{
     node <T> *p;                 // we need a pointer
     while(head != NULL)          // while 'head' is not NULL, loop            
     {
                      p = head;   // p looks to the same element with head
                      head = head -> link; // head goes to the next element
                      delete p;            // the element which p looks is deleted
     }
     last = NULL; // 'head' is already NULL, so does 'last' with this statement
     count = 0;   // there is no element, so 'count' is 0
}

template <class T>
void Linkedlist<T>::insertfirst(T& num) // insertfirst() function
{
     node <T> *p;                  // 'p', the pointer
     p = new node<T>;              // 'p' points to a new node
     
     p->info = num;               // and 'p''s info field is 'num'
     p->link = head;               // 'p' is the first element
     head = p;                     // 'head' points to an element which 'p' points to
     
     if(last == NULL)              // if 'last' is NULL, i mean there' s no element
             last = p;             // then, last points to what p points to
     count++;                      // increase count, because a new node is added
}

template <class T>
void Linkedlist<T>::insertlast(T& num)
{
     node <T> *p;                 // 'p' points to a new node
     p = new node<T>;
     
     p->info = num;               // new node' s info field is 'num'
     p->link = NULL;              // , and there' s no element after if (up to the next addidion)
     
     if(head != NULL)             // if there' s one or more element(s)
     {
                   last->link = p;   // last element' s (!!not 'last' pointer!!) next element is new node. (*p) 
                   last = p;         // last shows 'p' (the new node, which' s info field is num)
     }
     
     else                            // otherwise, 
         head = last = p;            // 'head' and 'last' points to what 'p' points to
     count++;                        // increase 'count', new element added
}

template <class T>                   // overloaded << operator
ostream& operator << (ostream &os, Linkedlist <T> &list)
{
        node <T> *p;
        p = list.head;        // 'p' shows coming argument' s head
        
        while (p != NULL)     // loop until 'p' is NULL, shows nothing
        {
              os << p->info;  // print the value (info field) of the first node 
              p = p->link;    // go to next node, until 'p' is NULL 
        }
        
        return os;
}

template <class T>
node<T>* Linkedlist<T>::search(T& num)
{
                                     bool found = false;
                                     
                                     node<T> *p;
                                     p = head;
                                     
                                     while((p != NULL) && !found)
                                     {
                                                             if(p->info == num) // if 'p' shows 'num'
                                                                        found = true; // 'found' is true
                                                             else
                                                                 p = p->link;         // otherwise, go to next element
                                     }
                                     if(found)                   // if found
                                              return p;          // return 'p'
                                     else                        // otherwise, 
                                         return NULL;            // return NULL
}

template <class T>
void Linkedlist<T>::deletenode(T& num)
{
     node<T> *p, *q;
     bool found = false;
     
     if(head == NULL)   // if 'head'
                   cout << "List is empty";
     else if(head->info == num)
     {
          p = head;
          head = head->link;
          delete p;
          count--;
     }
     if(head == NULL)
                   last = NULL;
     else
     {
         p = head;
         q = head->link;
         
         while(q != NULL && !found)
         {
                       if(q->info == num)
                                  found = true;
                       
                       else
                       {
                           p = q;
                           q = q->link;
                       }
                       
         }
         
         if(found)
         {
                  p->link = q->link;
                  count--;
                  if(last == q)
                             last = p;
                  delete q;
         }
     }
}
