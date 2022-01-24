DEST=./bin
SRC=./src
INCLUDE=./include
MODULE=./module

build/%: $(MODULE)/%
	$<

run/%: $(DEST)/%
	$<

$(MODULE)/%.o: $(SRC)/%.c
	gcc -Wall -I $(INCLUDE) -c $< -o $@

$(DEST)/%: $(MODULE)/pile.o $(SRC)/%.c
	gcc -Wall -I $(INCLUDE) $^ -o $(DEST)/$*

test/sum: $(DEST)/sum
	$< # insérer les données tests
