# Place holder for tests makefile

TARGETS	= instrument_tests language_tests

.PHONY: all $(TARGETS) clear

all: $(TARGETS)

instrument_tests:
	./test_driver instrument_tests

language_tests:
	./test_driver language_tests

clear:
	@for dn in $(TARGETS); do \
		cd $$dn; \
		if [ -f *.proof ]; then \
			rm *.proof; \
		fi; \
		for fn in *.errors; do \
			if [ -f $$fn ]; then \
				rm $$fn; \
			fi; \
		done; \
		cd ..; \
	done