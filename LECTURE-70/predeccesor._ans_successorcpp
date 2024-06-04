/*
  Question :- https://www.naukri.com/code360/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
*/


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pre=-1,succ = -1;

    //find pre
    TreeNode * temp = root;
    while(temp){
        //left me jao bada hain key se
        if(temp->data>=key){
            temp=temp->left;
        }
        else{           //ans ho sakta hain but isse bada  or right me check karo
            pre = temp->data;
            temp = temp->right;
        }
    }

    //find succ
    temp = root;
    while(temp){
        //right me jao chota hain key se 
        if(temp->data <= key){
            temp = temp->right;
        }
        else{                   //ans ho sakta hain but isse chota check karo
            succ = temp->data;
            temp = temp->left;
        }
    }

    return {pre,succ};
}
