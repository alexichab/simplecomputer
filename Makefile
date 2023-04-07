DIRGUARD = @mkdir -p $(@D)

all: bin/simplecomputer
.PHONY: bin/simplecomputer
bin/simplecomputer: src/main.c lib/bc.a lib/prototype.a lib/readkey.a lib/term_gui.a lib/term.a
	$(DIRGUARD)
	gcc -Wall -Wextra -I src -o $@ $^ -lm

lib/term_gui.a: obj/term_gui.o obj/bc.o
	$(DIRGUARD)
	ar rcs $@ $^

lib/%.a: obj/%.o
	$(DIRGUARD)
	ar rcs $@ $<

obj/%.o: src/%.c
	$(DIRGUARD)
	gcc -Wall -Wextra -c -o $@ $<

test: bin/test
.PHONY: bin/test
bin/test: test/*.c lib/bc.a lib/prototype.a lib/readkey.a lib/term_gui.a lib/term.a
	$(DIRGUARD)
	gcc -Wall -Wextra -I src -MMD -I thirdparty -o $@ $^ -lm

.PHONY: clean
clean:
	rm -rf bin/ lib/ obj/