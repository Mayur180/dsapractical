#include <iostream>
using namespace std;
class TreeNode
{
public:
 char val;
 TreeNode *left, *right;
 TreeNode()
 {
 this->left = NULL;
 this->right = NULL;
 }
 TreeNode(char val)
 {
 this->val = val;
 this->left = NULL;
 this->right = NULL;
 }
};
class Stack
{
public:
 TreeNode *treeNode;
 Stack *next;
 Stack(TreeNode *treeNode)
 {
 this->treeNode = treeNode;
 next = NULL;
 }
};
class ExpressionTree
{
private:
 Stack *top;
public:
 ExpressionTree()
 {
 top = NULL;
 }
 void push(TreeNode *ptr)
 {
 if (top == NULL)
 top = new Stack(ptr);
 else
 {
 Stack *nptr = new Stack(ptr);
 nptr->next = top;
 top = nptr;
 }
 }
 TreeNode *pop()
 {
 TreeNode *ptr = top->treeNode;
 top = top->next;
 return ptr;
 }
 TreeNode *peek()
 {
 return top->treeNode;
 }
 void insert(char val)
 {
 if (isOperand(val))
 {
 TreeNode *nptr = new TreeNode(val);
 push(nptr);
 }
 else if (isOperator(val))
 {
 TreeNode *nptr = new TreeNode(val);
 nptr->left = pop();
 nptr->right = pop();
 push(nptr);
 }
 }
 bool isOperand(char ch)
 {
 return ch >= '0' && ch <= '9' || ch>='A' && ch<='Z' || ch>='a' && ch<='z';
 }
 bool isOperator(char ch)
 {
 return ch == '+' || ch == '-' || ch == '*' || ch == '/';
 }
 void construct(string eqn)
 {
 for (int i = eqn.length() - 1; i >= 0; i--)
 insert(eqn[i]);
 }
 void inOrder(TreeNode *ptr)
 {
 if (ptr != NULL)
 {
 inOrder(ptr->left);
 cout<<ptr->val;
 inOrder(ptr->right);
 }
 }
 void postOrder(TreeNode *ptr)
 {
 if (ptr != NULL)
 {
 postOrder(ptr->left);
 postOrder(ptr->right);
 cout<<ptr->val;
 }
 }
 
};
int main()
{
 string exp;
 ExpressionTree et;
 cout<<"Enter expression in Prefix form: \n";
 cin>>exp;
 et.construct(exp);
 cout<<"\nIn-order Traversal of Expression Tree : ";
 et.inOrder(et.peek());
 cout<<"\nPOst-order Traversal of Expression Tree : ";
 et.postOrder(et.peek());
 return 0;
};