
.PHONY: all pretty clean all_clean tests

all:
	make -C src

pretty:
	make -C src pretty

clean:
	make -C src clean

all_clean:
	make -C src all_clean

tests: all
	make -C tests