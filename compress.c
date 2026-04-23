#include "huffman.h"      
//Compression Convert text->bits
void compressFile(const char*inputFile, const char*outputFile){
      FILE*in = fopen(inputFile, "rb"); 
      if(!in){
         printf("Error:Can't open %s\n", inputFile); 
         return;
      }   
      printf("Calculating frequencies...\n");
      unsigned long freq[MAX_SIZE] = {0}; 
      unsigned char byte;  
      while(fread(&byte,1,1,in)){
         freq[byte]++; 
      }
         Node*root = buildHuffmanTree(freq); 
         char codes[MAX_SIZE][MAX_SIZE]  = {0}; //stores the huffman code  (sequence of 9s and 1s  for each byte  
         char code[MAX_SIZE]; 
         generateCodes(root, code,0,codes); //A=0,B=11, C=10    
         //write frequecy table  
         FILE*out = fopen(outputFile, "wb");   
         fwrite(freq, sizeof(freq),1,out);  

        //Encode 
        rewind(in);  
        while(fread(&byte,1,1,in)){
            char *symbolCode = codes[byte]; 
            for(int i =0; symbolCode[i]; i++) 
              writeBit(out , symbolCode[i] - '0');
        } 
        flushBuffer(out); 
        fclose(in); 
        fclose(out); 
        freeTree(root); 
        printf("Compresssion complete: %s -> %s\n", inputFile, outputFile);
}