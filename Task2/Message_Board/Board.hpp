#include <iostream>
#include <stdexcept>

#include "Direction.hpp"


using namespace std;
namespace ariel {
	// Defines a Board constructor
	class Board {
		private:
			unsigned int row=1;
			unsigned int column=1;
			Direction direction=Direction::Horizontal;
			vector<vector<string>> vec_board;
		public:
		static void post(unsigned int row, unsigned int column, Direction direction,std::string const &message);
		static std::string read(unsigned int row, unsigned int column, Direction direction, int length);
		static void show();
		// // Constructors:
		Board(){}
		~Board(){}
	};
}
