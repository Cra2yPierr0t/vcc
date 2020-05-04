CC := gcc
vcc: vcc.o Tokenizer.o Parser.o sema.o CodeGenerator.o
clean:
	$(RM) *.o
