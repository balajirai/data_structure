#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// inorder
void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Maximum in BST
Node* findMax(Node* root){
    if(!root) return NULL;
    Node* temp = root;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}

// Minimum in BST
Node* findMin(Node* root){
    if(!root) return NULL;
    Node* temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

// deletion from BST
Node* deleteFromBST(Node* root, int target){
    // base case
    if(!root) return NULL;

    if(root->data == target){
        // 0 child/subtree
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // 1 child/subtree
        // left child
        if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        else if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child/subtree
        else if(!root->left && !root->right){
            // minimun of right subtree
            int mini = findMin(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if(root->data > target){
        root->left = deleteFromBST(root->left, target);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, target);
        return root;
    }

    return root;
}

// insertion in BST : O(log(n))
Node* insertIntoBST(Node* root, int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data) root->right =  insertIntoBST(root->right, d);
    else root->left = insertIntoBST(root->left, d);

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

int main(){
    Node *root = NULL;

    // tree : 10 8 21 7 27 5 4 3 -1
    cout<<"Enter data for BST : ";
    takeInput(root);

    int target;
    cout<<"Enter data for deletion : ";
    cin>>target;

    // tree before deletion
    cout<<"\nInorder before deletion : ";
    inorder(root);

    deleteFromBST(root, target);

    // tree after deletion
    cout<<"\nInorder after  deletion : ";
    inorder(root);

return 0;
}