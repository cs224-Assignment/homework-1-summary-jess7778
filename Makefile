all:
	g++ main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o sortingComparison
	./sortingComparison

compile:
	g++ main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o sortingComparison

run:
	./sortingComparison

clean:
	rm -f sortingComparison evaluator_tests sorting_tests

test-eval:
	g++ test_evaluator.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o evaluator_tests
	./evaluator_tests
	rm -f evaluator_tests

test-sorting:
	g++ test_sorting.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o sorting_tests
	./sorting_tests
	rm -f sorting_tests