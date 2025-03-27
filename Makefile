all:
	g++ main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o sortingComparison
	./sortingComparison

compile:
	g++ main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o sortingComparison

run:
	./sortingComparison

clean:
	rm -f sortingComparison