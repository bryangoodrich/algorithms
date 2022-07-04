#ifndef CUSTOM_DLLIST_H
#define CUSTOM_DLLIST_H

/*! @class DLList
 *  @brief A custom doubly-linked list implementation.
 *
 *  A custom implementation of a doubly-linked list aimed at exploring the 
 *  List data structure and its behavior, entirely for pedagogical purposes.
 *
 *  @author Bryan Goodrich
 *  @version 0.2
 *  @date 2013/12/14
 */
template <class T>
class DLList
{
    /*! @struct node
     *  @brief A node in a doubly-linked list.
     *
     *  A node in a doubly-linked list that contains node pointers to its
     *  neighbors. If there is no adjacent node, the pointer is NULL,
     *  representing the end of list. This is either before the head or
     *  after the last node in the list.
     *
     *  @typedef ItemType declares the type of data storage.
     */
    struct node
    {
        node*    prev;  /*!< Pointer to previous node or end of list */
        node*    next;  /*!< Pointer to next node or end of list */
        T item;         /*!< Stored data in node */

        /*!
         *  @brief Default Node Constructor
         */
        node (node* p, node* n, const T);
    };
    node*   head;  /*!< Pointer to the head of the list */
    node* cursor;  /*!< Pointer to the currently active list node */
 
public:

    /*!
     *  @brief Default List Constructor.
     *  @post The head and cursor are set to NULL.
     */
    DLList ( );
 
    /*!
     *  @brief Default List Destructor.
     *  @post All list nodes are deleted.
     */
    ~DLList ( );
 
    /*!
     *  @brief Check List content.
     *  @return True, if head is NULL.
     */
    bool IsEmpty ( ) const;
 
    /*!
     *  @brief Check cursor status.
     *  @return True, if cursor is NULL.
     */
    bool EndOfList ( ) const;
 
    /*!
     *  @brief Reset Cursor.
     *  @pre The list is non-empty.
     *  @post The cursor points to head of list.
     */
    void Head ( );
 
    /*!
     *  @brief Move cursor forward.
     *  @pre The list is non-empty and the cursor is not at the end of list.
     *  @post The cursor points to next pointer.
     */
    void Next ( );
 
    /*!
     *  @brief Move cursor backward.
     *  @pre The list is non-empty and the cursor is not at the end of list.
     *  @post The cursor points to previous pointer.
     */
    void Previous ( );
 
    /*!
     *  @brief Return data.
     *  @return The data pointed to by the cursor node.
     *  @pre The list is non-empty and the cursor is not at the end of list.
     *  @throws int
     */
    T Item ( );
 
    /*!
     *  @brief Delete node.
     *  @pre The list is non-empty and the cursor is not at the end of list.
     *  @post The node pointed to by the cursor is deleted after the cursor
     *        points to next pointer. If cursor pointed to last item in list,
     *        then head and cursor are set to NULL.
     */
    void Delete ( );
 
    /*!
     *  @brief Insert data before cursor.
     *  @param[in] item Data to be stored in list.
     *  @post If list is empty or cursor is at end of list, item is inserted
     *        at the head of list. Otherwise, item is inserted at previous 
     *        pointer of cursor. Cursor then points to inserted item. 
     */
    void InsertBefore (const T& item);
 
    /*!
     *  @brief Insert data after cursor.
     *  @param[in] item Data to be stored in list.
     *  @post If list is empty, item is inserted at head of list. If cursor
     *        is at end of list, item is inserted as last item in the list.
     *        Otherwise, item is inserted at next pointer of cursor. Cursor
     *        then points to inserted item.
     */
    void InsertAfter (const T& item);
};
#endif // CUSTOM_DLLIST_H



/**************************************************************************
*  Template Functions for this Object                                     *
**************************************************************************/

template <class T>
DLList<T>::node::node (node* p = NULL, node* n = NULL, const T i = T())
:prev(p), next(n), item(i) {}

template <class T>
DLList<T>::DLList ( ) 
{
    head    = NULL;
    cursor  = NULL;
}

template <class T>
DLList<T>::~DLList ( ) 
{
    while ( !IsEmpty() ) 
    {
        Head();
        Delete();
    }
}



template <class T> 
bool DLList<T>::IsEmpty ( ) const 
{
    return !head;
}

template <class T> 
bool DLList<T>::EndOfList ( ) const 
{
    return !cursor;
}

template <class T> 
void DLList<T>::Head ( ) 
{
    if ( !IsEmpty() ) 
        cursor = head;
}

template <class T>
void DLList<T>::Next ( ) 
{
    if ( !IsEmpty() && !EndOfList() ) 
        cursor = cursor->next;
}

template <class T> 
void DLList<T>::Previous ( ) 
{
    if ( !IsEmpty() && !EndOfList() ) 
        cursor = cursor->prev;
}

template <class T> 
T DLList<T>::Item ( ) 
{
    if ( !IsEmpty() && !EndOfList() ) 
        return cursor->item;
    else
        throw 1;
}

template <class T>
void DLList<T>::Delete ( ) 
{
    if ( IsEmpty() || EndOfList() ) return;

    node* temp = cursor;
    Next();
    if ( temp->prev   ) temp->prev->next = temp->next;
    if ( temp->next   ) temp->next->prev = temp->prev;
    if ( temp == head ) head = cursor;

    delete temp;
}

template <class T> 
void DLList<T>::InsertBefore (const T& item) 
{
    if ( IsEmpty() ) 
    {
        cursor = new node(NULL, NULL, item);
        head = cursor;
    } else if ( EndOfList() ) 
    {
        cursor = new node(NULL, head, item);
        head->prev = cursor;
        head = cursor;
    } else 
    {
        node* temp = new node(cursor->prev, cursor, item);
	if ( cursor->prev ) cursor->prev->next = temp;
        cursor->prev = temp;
        if ( cursor == head ) head = temp;
        cursor = temp;
    }
}

template <class T> 
void DLList<T>::InsertAfter (const T& item) 
{
    if ( IsEmpty() ) 
    {
        cursor = new node(NULL, NULL, item);
        head = cursor;
    } else if ( EndOfList() ) 
    {
        Head();
        while ( cursor->next ) Next();
        node* temp = new node(cursor, cursor->next, item);
        cursor->next = temp;
        cursor = temp;
    } else 
    {
        node* temp = new node(cursor, cursor->next, item);
	if ( cursor->next ) cursor->next->prev = temp;
        cursor->next = temp;
        cursor = temp;
    }
}


