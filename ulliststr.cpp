#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  if (tail_ == NULL || tail_->last == ARRSIZE) {
    Item* new_Item = new Item;

    if (tail_ == NULL) {
      head_ = new_Item;
    }
    else {
      tail_->next = new_Item;
      new_Item->prev = tail_;
      
    }
    tail_ = new_Item;

  }

  tail_->val[tail_->last] = val;
  ++tail_->last;
  ++size_;
}

void ULListStr::push_front(const std::string& val)
{
  if (head_ == NULL || head_->first == 0) {
    Item* new_Item = new Item;

    if (head_ == NULL) {
      tail_ = new_Item;
    }
    else {
      head_->prev = new_Item;
      new_Item->next = head_;
    }
    head_ = new_Item;

  }
  
  --head_->first;
  head_->val[head_->first] = val;
  ++size_;
}

void pop_back()
{
  if(empty()) {
    throw std::runtime_error("list is empty");
  }

  --tail_->last;
  --size_;
  if(tail_->last == tail_->first) {
    if(tail_ == head_) {
      head_ = NULL;
      tail_ = NULL;
    }
    else {
      tail_ = tail_->prev;
      tail_->next = NULL;
    }
  }
}

void pop_front()
{
  if(empty()) {
    throw std::runtime_error("list is empty");
  }

  --head_->front;
  --size_;
  if(head_->last == head_->first) {
    if(tail_ == head_) {
      head_ = NULL;
      tail_ = NULL;
    }
    else {
      head_ = head_->next;
      head_->prev = NULL;
    }
  }
}

std::string const & back() const 
{
  if(empty()) {
    throw std::runtime_error("list is empty");
  }

  return tail_->val[tail_->last - 1];
}

std::string const & front() const 
{
if(empty()) {
    throw std::runtime_error("list is empty");
  }

  return head_->val[head_->first];
}

std::string* getValAtLoc(size_t loc) const 
{
  if(empty()) {
    return NULL;
  }
  else if(loc >= size_) {
    return NULL;
  }

num_Over = size_ - loc;

Item* curr = tail_;

while(curr != NULL) {
  curr_Size = curr->last - curr->first;
  num_Over -= curr_Size;
  if(num_Over == 0) {
    return &curr->val[curr->last];
  }
  else if (num_Over < 0) {
    return &curr->val[curr->last + num_Over];
  }
  else {
    curr = curr->next;
  }
}


return NULL
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
