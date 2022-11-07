#include "includes.h"

void main() {
	ChessEngine engine;
	ChessConclient client(&engine);

	client.run();
}
