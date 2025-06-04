all: laptop_recommender

laptop_recommender: main.cpp
	g++ -o laptop_recommender main.cpp

clean:
	rm -f laptop_recommender
