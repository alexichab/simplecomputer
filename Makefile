DIRGUARD = @mkdir -p $(@D)

all: bin/main
.PHONY: bin/main
bin/main: *.c
	$(DIRGUARD)
	gcc -Wall -Wextra -o $@ $^
