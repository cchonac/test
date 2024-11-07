#include<iostream>
#include <string>
#include <algorithm>

struct Node {
  int key;
  int height;
  int depth;
  Node* left;
  Node* right;
  Node* parent;

  explicit Node(int key_value) 
      : key(key_value), height(1), depth(0), left(nullptr), right(nullptr), parent(nullptr) {}
};