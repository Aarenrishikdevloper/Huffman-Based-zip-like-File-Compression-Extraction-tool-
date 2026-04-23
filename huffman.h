#ifndef HUFFMAN_H  
#define HUFFMAN_H    
#define MAX_SIZE 256
#include<stdio.h>  
#include<stdlib.h>   
#include<string.h>
typedef struct Node {
    unsigned char data; 
    unsigned long freq;  
    struct Node *left, *right;
}Node;    
//tree-related
Node*buildHuffmanTree(unsigned long freq[]);  
void generateCodes(Node*root, char*code, int depth, char codes[MAX_SIZE][MAX_SIZE]);  
void freeTree(Node*root);        
//Bitwise I/O operation     
void writeBit(FILE *out, int bit);     
void flushBuffer(FILE *out); 
int readBit(FILE *in);  
//compression and  decompression  
void compressFile(const char *inputFile, const char *outputFile);  
void decompressFile(const char*inputFile, const char*outputFile);
#endif
