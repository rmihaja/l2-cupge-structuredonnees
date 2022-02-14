DEST=./bin
SRC=./src
INCLUDE=./include
MODULE=./module

# * program launch

run: $(DEST)/cc1
	$<
	rm $<

# * dependency compile

$(MODULE)/%.o: $(SRC)/%.c
	gcc -Wall -I $(INCLUDE) -c $< -o $@

# * program compile

$(DEST)/%: $(MODULE)/quaternion.o $(SRC)/%.c
	gcc -Wall -I $(INCLUDE) $^ -o $(DEST)/$*