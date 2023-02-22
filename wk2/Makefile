tw: tw.o Dict.o stemmer.o
	gcc tw.o Dict.o stemmer.o -o tw
tw.o: tw.c Dict.h WFreq.h stemmer.h
	gcc -c tw.c -o tw.o
Dict.o: Dict.c Dict.h WFreq.h
	gcc -c Dict.c -o Dict.o
stemmer.o: stemmer.c stemmer.h
	gcc -c stemmer.c -o stemmer.o

