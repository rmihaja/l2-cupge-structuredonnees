DEST=./bin
SRC=./src

run/%: $(DEST)/%
	$<

$(DEST)/%: $(SRC)/%.c
	gcc -Wall $(SRC)/$*.c -o $(DEST)/$*

test/sum: $(DEST)/sum
	$< 256 31
	$< 21 21
	$< 21 -21
	$< 1024 1024
# $< 10 2 1
# $< qsd 3 9
# $< 0 3d 9
