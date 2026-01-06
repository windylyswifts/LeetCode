/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    int queueCapacity = 15000; 
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * queueCapacity);
    int front = 0; 
    int rear = 0; 
    queue[rear++] = root;
    int level = 0;
    int mx = INT_MIN;
    int level_number = 0;
    while (front < rear) {
        int k = rear - front;
        level++;
        int sum = 0;

        while (k--) {
    
            struct TreeNode* x = queue[front];
           
            front++; 

            sum += x->val;

            if (x->left != NULL) {
                queue[rear++] = x->left;
            }
            if (x->right != NULL) {
                queue[rear++] = x->right;
            }
        }

        
        if (mx < sum) {
            mx = sum;
            level_number = level;
        }
    }

    // Clean up memory used for the queue
    free(queue);

    return level_number;
}