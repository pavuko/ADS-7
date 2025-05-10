// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
  if (!first) {
    first = new Car{light, nullptr, nullptr};
    first->next = first;
    first->prev = first;
  } else {
    Car* temp = first->prev;
    Car* add = new Car{light, first, temp};
    temp->next = add;
    first->prev = add;
  }
 }

int Train::getLength() {
   countOp = 0;
   int steps = 1;
   Car* temp = first;
   temp->light = true;

   while (true) {
     temp = temp->next;
     countOp++;
     if (temp->light) {
       temp->light = false; 
       int back = steps;
       while (back--) {
         temp = temp->prev;
         countOp++;
       }
       if (!temp->light) {
         return steps;
       }
       steps = 1;
       temp->light = true;  
     } else {
       steps++;  
     }
   }
 }

int Train::getOpCount() { return countOp; }
