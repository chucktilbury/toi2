.PHONY: all pretty clean all_clean

TARGETS	=	utils \
			parser \
			abstract_tree \
			expressions \
			main

all:
	@for target in $(TARGETS); do \
		make -C $$target; \
	done

pretty:
	@for target in $(TARGETS); do \
		cp .indent.pro $$target; \
		make -C $$target pretty; \
	done

clean:
	@for target in $(TARGETS); do \
		make -C $$target clean; \
	done

all_clean:
	@for target in $(TARGETS); do \
		make -C $$target all_clean; \
	done
