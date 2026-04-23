#include "huffman.h"   
static Node*createNode(unsigned char data, unsigned long freq, Node*left, Node*right){
    Node *node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->freq = freq; 
    node->left = left; 
    node->right = right; 
    return node;
}    
//Build the huffman tree
Node*buildHuffmanTree(unsigned long freq[]){
    Node*nodes[MAX_SIZE]; 
    int n = 0; 
    for(int i =0; i < MAX_SIZE; i++){
        if(freq[i] > 0){
            nodes[n++] = createNode((unsigned char)i, freq[i], NULL,NULL); 

        }
    }   
    while(n > 1){//combining  two nodes with the smallest frequencies  unit only node (the root) remains
         int min1 =0, min2 = 1;     
         if(nodes[min2]->freq < nodes[min1]->freq){
            int tmp = min1; min1 = min2; min2= tmp;
         }  
         for(int i =2; i <n; i++){
            if(nodes[i]->freq < nodes[min1]->freq){
                min2 = min1;  
                min1 = i;
            }
            else if(nodes[i]->freq < nodes[min2]->freq){
                min2 = i;
            }
         } 
         Node*combined = createNode(0, nodes[min1]->freq + nodes[min2]->freq, nodes[min1], nodes[min2]);  
         nodes[min1] = combined; 
         nodes[min2] = nodes[--n];

    } 
    return (n==1)?nodes[0]:NULL;
}  
//Genrearte huffman codes recurivly  
void generateCodes(Node*root, char*code, int depth, char codes[MAX_SIZE][MAX_SIZE]){
    if(!root){
        return;
    }  
    if(!root->left && !root->right){
        code[depth] = '\0' ;   
        strcpy(codes[root->data], code); 
        return;
    }    
    if(root->left){
        code[depth] = '0'; 
        generateCodes(root->left, code, depth + 1, codes);
    } 
    if(root->right){
        code[depth] ='1'; 
        generateCodes(root->right, code, depth+1, codes);
    }
}   
// Free Tree memory
void freeTree(Node*root){
    if(!root) return;
    freeTree(root->left);    
    freeTree(root->right); 
    free(root);
 
}