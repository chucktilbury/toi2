
.PHONY: all pretty clean all_clean

all:
	make -C src

pretty:
	make -C src pretty

clean:
	make -C src clean

all_clean:
	make -C src all_clean