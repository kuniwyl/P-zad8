all:
	gcc  --pedantic src/*.c -o bin/gauss

test1: all
	@echo "Test 1 - poprawne dane 2x2:"
	bin/gauss dane/A dane/b

test2: all 
	@echo "Test 2 - poprawne dane 5x5:"
	bin/gauss dane/C dane/d

test3: all
	@echo "Test 3 - dane 1x1:"
	bin/gauss dane/E dane/f

test4: all 
	@echo "Test 4 - niepoprawne dane(macierz osobliwa) 3x3:"
	bin/gauss dane/G dane/h

test5: all
	@echo "Test 5 - niepoprawne dane 3x2:"
	bin/gauss dane/I dane/j

.SILENT:

clean:
	rm -f test1
	rm -f test2
	rm -f test3
	rm -f test4
	rm -f test5
