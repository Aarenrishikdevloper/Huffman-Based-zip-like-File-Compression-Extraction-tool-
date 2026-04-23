  CC = gcc
  CFLAGS = -Wall

  OBJS = main.o compress.o decompress.o tree.o bitio.o

  huffman: $(OBJS)
	 $(CC) $(CFLAGS) -o huffman $(OBJS)

  main.o: main.c huffman.h
	 $(CC) $(CFLAGS) -c main.c

  compress.o: compress.c huffman.h
	  $(CC) $(CFLAGS) -c compress.c

  decompress.o: decompress.c huffman.h
	    $(CC) $(CFLAGS) -c decompress.c

  tree.o: tree.c huffman.h
	  $(CC) $(CFLAGS) -c tree.c

  bitio.o: bitio.c huffman.h
	   $(CC) $(CFLAGS) -c bitio.c

   clean:
	del /f *.o huffman.exe