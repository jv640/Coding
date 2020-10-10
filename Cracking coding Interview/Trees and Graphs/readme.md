Q-1       Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
Approach  we can simply apply BFS or DFS on 2 given nodes and can get answer.

Q-2       Validate BST: Implement a function to check if a binary tree is a binary search tree
Approach  take two range values max and min whenever node's value go out of range return false and change range in every recursive call

Q-3       Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. 
          You may assume that each node has a link to its parent. 
Approach  if right of given tree is not null then smallest value in right subtree is ans else traverse from root to given node whenever you find node with val > given node's val
          then this will be your answer

Q-4       Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of projects, where the second project is dependent on the first                 project). All of a project's dependencies must be built before the project is. Find a build order that will allow the projects to be built. 
          If there is no valid build order, return an error. 
Approach  if cycle is present in given graph then its not possible else it is just select node with minimum incoming edge and traverse from these.

Q-5       First Common Ancestor: Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. 
          Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree. 
Approach  if current node matches with any of node erturn that node or if node get found in left and right subtree then also return that node else recur for left and right subtree

Q-6       Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an algorithm to determine if T2 is a subtree of Tl.
          A tree T2 is a subtree ofTi if there exists a node n in Ti such that the subtree of n is identical to T2.
          That is, if you cut off the tree at node n, the two trees would be identical. 
Approach  we can check if values of root of 1 is same with root of 2nd then compare whether they are identical or not else recur for left and right subtree
          Another approach is to do pre and inorder traversal of both tree and if we can find same string in both traversal of both tree then it is subtree else not
          
Q-7       Random Node: You are implementing a binary tree class from scratch which, in addition to insert, find, and delete, has a method getRandomNode() 
          which returns a random node from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm for getRandomNode, 
          and explain how you would implement the rest of the methods. 
Approach  either you store node in an array then return value from node using rand() or store count of children in each node and generate randome number from 0-children in root
          if(left->children) == count then root is ans else if count < left->child then recur in left tree else recur in right tree but change value of count to left->child - 1.
