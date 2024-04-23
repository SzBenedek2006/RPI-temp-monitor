temp: temp.c
	gcc -o temp temp.c

clean: temp
	rm -f temp
