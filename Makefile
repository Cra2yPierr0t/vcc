CC := gcc
vcc: vcc.o Tokenizer.o Parser.o sema.o
clean:
	$(RM) *.o
