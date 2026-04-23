#include"huffman.h" 
int main(){
    int choice;
    char inputFile[100], outputFile[100];

    printf("==== HUFFMAN FILE COMPRESSION SYSTEM ====\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFile);
    printf("Enter output file name: ");
    scanf("%s", outputFile);
    if(choice == 1){
         compressFile(inputFile, outputFile);
    }    
    else if(choice == 2){
           decompressFile(inputFile, outputFile); 
    }
    else{
        printf("invalid operation");
    }
    return 0;
}