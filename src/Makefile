.PHONY: all pretty clean all_clean

all:
	make -C utils
	make -C parser
	make -C abstract_tree
	make -C main

pretty:
	cp .indent.pro parser
	cp .indent.pro main
	cp .indent.pro utils
	cp .indent.pro abstract_tree
	make -C utils pretty
	make -C parser pretty
	make -C abstract_tree pretty
	make -C main pretty

clean:
	make -C main clean
	make -C utils clean
	make -C abstract_tree clean
	make -C parser clean

all_clean:
	make -C main all_clean
	make -C utils all_clean
	make -C abstract_tree all_clean
	make -C parser all_clean
