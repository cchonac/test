// avltree.h 

#ifndef AVLTREE_H_
#define AVLTREE_H_

#define DISALLOW_COPY_AND_ASSIGN(AvlTree) \
  AvlTree(const AvlTree&);                 \
  void operator=(const AvlTree&)

#include <string>

// Node 구조체 정의: AvlTree의 각 노드를 나타냅니다.
struct Node {
  int key;      // 노드의 키 값
  int height;   // 노드의 높이
  int depth;    // 노드의 깊이
  Node* left;   // 왼쪽 자식 노드
  Node* right;  // 오른쪽 자식 노드
  Node* parent; // 부모 노드

  Node(int key_value); // 주어진 키로 Node를 생성합니다.
};

// AVLTree 클래스 정의: AVL 트리 구조로 데이터를 관리합니다.
class AvlTree {
 public:
  AvlTree(); // 트리 생성자
  ~AvlTree(); // 트리 소멸자

  // Find: 해당 노드의 깊이와 높이의 합을 반환합니다. 만약 노드 x가 존재하지 않는다면, 0을 출력합니다.
  int Find(int key) const;

  // Insert: 트리에 새로운 노드를 추가하고, 추가된 노드의 깊이와 높이의 합을 반환합니다.
  int Insert(int key);

  // Empty: 트리가 비어 있는지 확인하여 1(비어 있음) 또는 0(비어 있지 않음)을 반환합니다.
  int Empty() const;

  // Size: 트리에 있는 노드의 개수를 반환합니다.
  int Size() const;

  // Height: 트리의 전체 높이를 반환합니다. 트리가 비어 있으면 -1을 반환합니다.
  int Height() const;

  // Ancestor: 노드 𝑥 (1 ≤ 𝑥 ≤ 300,000) 의 깊이와 높이의 합, 𝑥 의 부모로부터 루트까지의 경로의 노드들의 key 값들의 합을 공백으로 구분하여 출력합니다.
  std::string Ancestor(int key) const;

  // Average: 주어진 키를 가진 노드의 서브트리에서 최소 키와 최대 키의 평균을 반환합니다.
  double Average(int key) const;

 private:
  Node* root_;         // 트리의 루트 노드
  int node_count_;     // 트리에 있는 노드의 개수


  // UpdateHeightAndDepth: 노드의 높이와 깊이를 업데이트합니다. 
  void UpdateHeightAndDepth(Node* node);

  // BalanceNode: 노드의 균형을 맞추기 위해 회전 연산을 수행합니다. 
  Node* BalanceNode(Node* node);

  // GetBalance: 노드의 균형 인수를 계산하여 반환합니다. (private 함수 BalanceNode에서 사용)
  int GetBalance(const Node* node) const;

  // RotateLeft: 노드를 기준으로 좌회전하여 트리의 균형을 맞춥니다. (private 함수 BalanceNode에서 사용)
  Node* RotateLeft(Node* z);

  // RotateRight: 노드를 기준으로 우회전하여 트리의 균형을 맞춥니다. (private 함수 BalanceNode에서 사용)
  Node* RotateRight(Node* z);

  // FindMinMax: 서브트리에서 최소 키와 최대 키를 찾습니다. (public 함수 Average에서 사용)
  std::pair<int, int> FindMinMax(const Node* node) const;

  DISALLOW_COPY_AND_ASSIGN(AvlTree);

};

#endif 
