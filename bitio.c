#include "huffman.h"  
static unsigned char buffer =0; 
static int bitCount =0;   
//writting a single bit    
void writeBit(FILE*out, int bit){
    buffer = (buffer << 1) | bit;    
    bitCount++ ; 
    if(bitCount == 8){
        fwrite(&buffer,1,1,out); 
        bitCount = 0; 
        buffer = 0;
    }
}
//flushing remaing bit
void flushBuffer(FILE*out){
    if(bitCount > 0){
        buffer <<= (8 - bitCount); 
        fwrite(&buffer, 1,1,out); 
        buffer = 0; 
        bitCount = 0;
    }
} 
//read a single bit  
int readBit(FILE*in){
    static unsigned char buffer; 
    static int bitsleft = 0;  
    int bit; 
    if(bitsleft == 0){
        if(fread(&buffer,1,1,in) != 1)  
          return -1; 
        bitsleft = 8;  
    } 
    bit = (buffer >> 7) & 1; 
    buffer <<= 1; 
    bitsleft--; 
    return bit;
}