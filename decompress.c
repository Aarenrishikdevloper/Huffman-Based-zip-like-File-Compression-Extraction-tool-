#include "huffman.h" 
//decompression converts bits->text  
void decompressFile(const char*inputFile, const char*outputFiles){
    FILE *in = fopen(inputFile,"rb"); 
    if(!in){
        printf("Error: Can't open %s\n", inputFile);
        return;
    }   
    unsigned long freq[MAX_SIZE]; 
    fread(freq, sizeof(freq),1,in); 
     Node*root = buildHuffmanTree(freq); 
     Node*current = root;  
     FILE*out = fopen(outputFiles, "wb");  
     unsigned long total =0;
     for(int i =0; i < MAX_SIZE; i++)   
         total += freq[i];
     for(unsigned long count =0; count < total;){
        int bit = readBit(in); 
        if(bit == -1) break;  
        current = (bit == 0)? current->left : current->right; 
        if(current && !current->left && !current->right){
            fwrite(&current->data,1,1,out); 
            current = root; 
            count++;
        }
     }  
     fclose(in); 
     fclose(out); 
     freeTree(root); 
      printf("decompresssion complete: %s -> %s\n", inputFile, outputFiles);
} 