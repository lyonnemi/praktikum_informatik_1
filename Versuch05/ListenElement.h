//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* prev;// Neues Attribut für das vorherige Element

public:
    ListenElement(Student pData, ListenElement* pNext);

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrev(ListenElement* pPrev); // Neue Methode zum Setzen des vorherigen Elements


    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrev() const;// Neue Methode zum Abrufen des vorherigen Elements

};

#endif
