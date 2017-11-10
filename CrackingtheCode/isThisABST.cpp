/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
    bool helperBST(Node* node, int min, int max){
        if (node==NULL) {
            return true;
        }
        if (node->data < min || node->data > max){
            return false;}
        
        return isBSTUtil(node->left, min, node->data - 1) &&  
            isBSTUtil(node->right, node->data + 1, max);
    }

   bool checkBST(Node* root) {
       if (root == NULL){
           return true;
       }
       if (root->left){
           root
       }
   }

