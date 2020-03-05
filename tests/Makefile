# Place holder for tests makefile

TARGETS	= instrument_tests language_tests

.PHONY: all clear #$(TARGETS) clear

all: #$(TARGETS)
	@./test_driver $(TARGETS)

# instrument_tests:
# 	@./test_driver instrument_tests

# language_tests:
# 	@./test_driver language_tests

clear:
	@for dn in $(TARGETS); do \
		cd $$dn; \
		for pn in *.proof; do \
			if [ -f $$pn ]; then \
				rm $$pn; \
			fi; \
		done; \
		for fn in *.errors; do \
			if [ -f $$fn ]; then \
				rm $$fn; \
			fi; \
		done; \
		cd ..; \
	done