#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left,*right;
}*root,*temp,*temp2;
node *insert(int d){
    node *temp=new node();
    temp->right=temp->left=NULL;
    temp->data=d;
    return temp;
}
 node*create( node *temp,int d){
    if(temp==NULL){
        temp=insert(d);
    }
    else if(temp->data>d){
        temp->left=create(temp->left,d);
    }
    else if(temp->data<d){
        temp->right=create(temp->right,d);
    }
    else{
        return NULL;
    }
}
void insertion(){
    int d;
    cout<<"enter value to be inserted:";
    cin>>d;
    create(root,d);
}
node *searching(node *temp,int d){
    if(temp==NULL){
        cout<<"DATA NOT FOUND\n";
        return NULL;
    }
    else if(temp->data>d){
        searching(temp->left,d);
    }
    else if(temp->data<d){
        searching(temp->right,d);
    }
    else if(temp->data==d){
        cout<<d<<" FOUND IN THE LIST\n";
    }
}
void preorder(node *temp){
    if(temp!=NULL){
        cout<<temp->data<<"\t";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(node *temp){
    if(temp!=NULL){
        inorder(temp->left);
        cout<<temp->data<<"\t";
        inorder(temp->right);
    }
}
void postorder(node *temp){
    if(temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<"\t";
    }
}
int maxdepth(node *temp){
    if(temp==NULL){
        return 0;
    }
    int ldepth=maxdepth(temp->left);
    int rdepth=maxdepth(temp->right);
    if(ldepth>rdepth)
        return ldepth+1;
    else
        return rdepth+1;    
}
node* getSuccessor(node* curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

// This function deletes a given data x from
// the give BST and returns modified root of
// the BST (if it is modified)
node * delNode(node *root, int x)
{

    // Base case
    if (root == NULL)
        return root;

    // If data to be searched is in a subtree
    if (root->data > x)
        root->left = delNode(root->left, x);
    else if (root->data < x)
        root->right = delNode(root->right, x);

    // If root matches with the given data
    else {

        // Cases when root has 0 children
        // or only right child
        if (root->left == NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // When root has only left child
        if (root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // When both children are present
        node *succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}
void currentlevel(node *temp,int l){
    if(temp==NULL){
        return ;
    }
    if(l==1){
        cout<<temp->data<<" ";
    }
    else{
        currentlevel(temp->left,l-1);
        currentlevel(temp->right,l-1);
    }
}
void bfs(node *temp){
    int h=maxdepth(root);
    for(int i=1;i<=h;i++){
        currentlevel(temp,i);
    }
}
int main(){
    int ch=1,d;
    while(ch){
        cout<<"enter value:";
        cin>>d;
        if(root==NULL){
            root=create(root,d);
        }
        else{
            create(root,d);
        }
        cout<<"enter 1 or 0 to continue:";
        cin>>ch;
    }
    do{
    cout<<"ENTER \n1 FOR DISPLAY\n2 FOR INSERTION\n3 FOR DELETION\n4 FOR SEARCHING\n5 FOR FINDING HEIGHT\n6 FOR EXITING:";
    cin>>ch;
    switch(ch){
        case 1:cout<<"PREORDER:";
                preorder(root);
               cout<<'\n';
               cout<<"INORDER:";
               inorder(root);
               cout<<'\n';
               cout<<"POSTORDER:";
               postorder(root);
               cout<<'\n';
               break;
        case 2:insertion();
               break;
        case 3: int d;
                cout<<"enter number to be deleted:";
                cin>>d;
                delNode(root,d);
                break;
        case 4: cout<<"enter number to be searched:";
                cin>>d;
                searching(root,d);
                break;
        case 5: cout<<"HEIGHT OF THE TREE IS:"<<maxdepth(root)<<'\n';
                break;
        case 6:cout<<"exiting...\n";
               break;       
        default:cout<<"NO COMMAND FOUND\n";
               break;        
    }
    }while(ch!=6);
    bfs(root);
    return 0;
}