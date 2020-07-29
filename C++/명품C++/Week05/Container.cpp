//Container.cpp
#include <iostream>
#include "Container.h"
void Container::fill() {size = 10;}
void Container::consume() {size--;}
int Container::getSize() {return size;}
