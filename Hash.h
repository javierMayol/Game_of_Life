#ifndef HASH_H
#define HASH_H

#include<iostream>
#include<algorithm>
#include<string>
#include"dList.h"
using namespace std;

template <typename L>
class HashT
{
  private:
    doubleList<L> *array;
    int length;

    HashT()
    {
      array = new doubleList <L>();
      length = -1;
    }

    int hash(L &itemKey)
    {
      int value = 0;
      int len = sizeof(itemKey)/sizeof(L);
      for( int i = 0; i < len; i++)
         value = itemKey[i];
      return(value * len) % length;
    }

    int hashInt(L &itemKey)
    {
      int value = itemKey;
      int len = sizeof(itemKey)/sizeof(L);
      return(value * len) % length;
    }

  
  public:
    HashT(int tableLength)
    {
      if(tableLength <= 0) tableLength = 10;
      array = new doubleList<L>[tableLength];
      length = tableLength; 
    }

    void insertItem (Node <L> *newItem)
    {
      int index = hash(newItem->data);
      array[index].push_back(newItem->data);
    }

    void insertIntItem (Node <L> *newItem)
    {
      int index = hashInt(newItem->data);
      array[index].push_back(newItem->data);
    }

    void removeItem ( L &itemKey)
    {
      int index = hash( itemKey);
      return array[index].remove_first(itemKey);
    }

    Node<L>* get_by_key( L & itemKey)
    {
      int index = hash(itemKey);
      return array[index].getItem(itemKey);
    }

    void printTable()
    {
       cout<<endl;
       for(int i = 0; i < length; i++)
       {
         cout<<"bucket" << i <<" : ";
         array[i].print();
       }
    }

    void histogram_print()
    {
       cout<<"Histogram of table ";
       cout<< getNumberOfItems()<<" total elements.\n"; 
       for(int i = 0; i <length; i++)
       {
          cout<<i + 1<<":\t";
          for(int j = 0; j < array[i].get_length(); j++)
             cout<<" X";
          cout<<endl;
       }
    }
 
    int getLength()
    {
       return length;
    }

    int getNumberOfItems()
    {
       int count = 0;
       for(int i = 0; i < length; i++)
       {
         if(array[i].get_length() < 0)
            count = count;
  	 else
         count += array[i].get_length();
       }
       return count;
    }

    ~HashT()
    {
       delete [] array;
    }

};

#endif
