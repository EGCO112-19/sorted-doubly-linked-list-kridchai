                   
struct Node {                                      
   int data; 
   struct Node *nextPtr;
   struct Node *prevPtr; 
};                     

typedef struct Node LLnode;
typedef LLnode* LLPtr; 

int deletes( LLPtr *sPtr, int value );
int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int value );
void printList( LLPtr currentPtr );
void printRList( LLPtr currentPtr );
void instructions( void );





void instructions( void )
{ 
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
} 


void insert( LLPtr *sPtr, int value )
{ 
   LLPtr newPtr;
   LLPtr previousPtr; 
   LLPtr currentPtr; 

   newPtr =(LLPtr) malloc( sizeof( LLnode ) ); 

   if ( newPtr != NULL ) { 
      newPtr->data = value; 
      newPtr->nextPtr = NULL; 
      if(*sPtr ==NULL) //add this statement
        newPtr->prevPtr == NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

            
      while ( currentPtr != NULL && value > currentPtr->data ) {
         previousPtr = currentPtr;              
         currentPtr = currentPtr->nextPtr;  
      }                                        

     
      if ( previousPtr == NULL ) { 
         if(*sPtr==NULL)
         {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
         }
         else{
            *sPtr = newPtr;
            newPtr->nextPtr = currentPtr;
            newPtr->prevPtr = NULL;
            currentPtr->prevPtr = newPtr;
         }
      
      } 
      else {  
         if(currentPtr==NULL)
         {
           previousPtr->nextPtr = newPtr;
           newPtr->prevPtr = previousPtr;//add this line
           newPtr->nextPtr = currentPtr;
         }
         else
         {
           previousPtr->nextPtr = newPtr;
           newPtr->nextPtr = currentPtr;
           newPtr->prevPtr = previousPtr;
           currentPtr->prevPtr = newPtr;
         
         }
      } 
   } 
   else {
      printf( "%d not inserted. No memory available.\n", value );
   }
   
} 


int deletes( LLPtr *sPtr, int value )
{ 
   LLPtr previousPtr; 
   LLPtr currentPtr; 
   LLPtr tempPtr; 

   //case there is 1 node only
  if((*sPtr)->nextPtr ==NULL&&value==( *sPtr )->data){
    free(*sPtr);
    *sPtr = NULL;
    return value; 
  }   
   
   // delete first node
   if ( value == ( *sPtr )->data ) { 
      tempPtr = *sPtr; 
      *sPtr = ( *sPtr )->nextPtr;
      ( *sPtr )->prevPtr = NULL;//add this line
      free( tempPtr ); 
      return value;
   } 
   else { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->data != value ) { 
         previousPtr = currentPtr; 
         currentPtr = currentPtr->nextPtr;  
      } // end while

      // delete node at currentPtr
      if ( currentPtr != NULL&&currentPtr->nextPtr!=NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         currentPtr = currentPtr->nextPtr;// add this line
         currentPtr->prevPtr = previousPtr;//add this line
         free( tempPtr );
         return value;
      } 
      //delete last node
      if ( currentPtr != NULL&&currentPtr->nextPtr==NULL ) { 
         free( currentPtr );
         previousPtr->nextPtr = NULL;
         return value;
      } 
   }

   return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int isEmpty( LLPtr sPtr )
{ 
   return sPtr == NULL;
} 


void printList( LLPtr currentPtr )
{ 
 
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } 
   else { 
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr != NULL ) { 
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;   
      } 

      puts( "NULL\n" );
   } 
}


void printRList( LLPtr currentPtr )
{  
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } 
   else { 
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr->nextPtr != NULL ) { 
         currentPtr = currentPtr->nextPtr;   
      }
      printf("NULL --> ");
      while(currentPtr->prevPtr!=NULL){
          printf( "%d --> ",currentPtr->data);
        currentPtr = currentPtr->prevPtr;
      }
      printf("%d\n",currentPtr->data); 
      
   } 
} 
