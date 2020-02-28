
all:
	make -C utils
	make -C parser
	make -C abstract_tree
	make -C main

pretty:
	cp ../.indent.pro parser
	cp ../.indent.pro main
	cp ../.indent.pro utils
	make -C utils pretty
	make -C parser pretty
	make -C abstract_tree pretty
	make -C main pretty

clean:
	make -C utils clean
	make -C abstract_tree clean
	make -C parser clean
	make -C main clean