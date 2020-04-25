all: sil derle bagla

sil:
	rm -f ./lib/soru1.o
	rm -f ./lib/soru2.o

derle:
	gcc -g -I./include -c ./src/soru1.c -o ./lib/soru1.o
	gcc -g -I./include -c ./src/soru2.c -o ./lib/soru2.o

bagla:
	
	gcc -g ./lib/soru1.o ./lib/libfdr.a -o ./soru1 
	gcc -g ./lib/soru2.o ./lib/libfdr.a -o ./soru2 
